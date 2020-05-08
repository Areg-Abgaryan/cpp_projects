#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;

enum Zuma_Ball_Color
{
	Red, Green, Blue, Yellow
};

class Zuma_Balls_Factory;

class Zuma_Ball_Prototype
{
protected:
	bool status;
	friend class Zuma_Balls_Factory;

	Zuma_Ball_Prototype(bool active) : status(active) {}
	virtual unique_ptr<Zuma_Ball_Prototype> clone() = 0;
public:
	Zuma_Ball_Prototype() = default;
	virtual ~Zuma_Ball_Prototype() = default;
};

class Red_Ball : public Zuma_Ball_Prototype
{
public:
	Red_Ball(bool active) : Zuma_Ball_Prototype(status) { cout << "red ball\n"; }

private:
	unique_ptr<Zuma_Ball_Prototype> clone() override
	{
		return make_unique<Red_Ball>(*this);
	}
};

class Green_Ball : public Zuma_Ball_Prototype
{
public:
	Green_Ball(bool active) : Zuma_Ball_Prototype(status) { cout << "green ball\n"; }

private:
	unique_ptr<Zuma_Ball_Prototype> clone() override
	{
		return make_unique<Green_Ball>(*this);
	}
};

class Blue_Ball : public Zuma_Ball_Prototype
{
public:
	Blue_Ball(bool active) : Zuma_Ball_Prototype(status) { cout << "blue ball\n"; }

private:
	unique_ptr<Zuma_Ball_Prototype> clone() override
	{
		return make_unique<Blue_Ball>(*this);
	}
};

class Yellow_Ball : public Zuma_Ball_Prototype
{
public:
	Yellow_Ball(bool active) : Zuma_Ball_Prototype(status) { cout << "yellow ball\n"; }

private:
	unique_ptr<Zuma_Ball_Prototype> clone() override
	{
		return make_unique<Yellow_Ball>(*this);
	}
};

class Zuma_Balls_Factory
{
private:
	unordered_map<Zuma_Ball_Color, unique_ptr<Zuma_Ball_Prototype>> list;
public:
	Zuma_Balls_Factory()
	{
		list[Red] = make_unique<Red_Ball>(true);
		list[Green] = make_unique<Green_Ball>(true);
		list[Blue] = make_unique<Blue_Ball>(true);
		list[Yellow] = make_unique<Yellow_Ball>(true);
	}
	unique_ptr<Zuma_Ball_Prototype> make_ball(const Zuma_Ball_Color &p)
	{
		return list[p]->clone();
	}
};

vector<unique_ptr<Zuma_Ball_Prototype>> game(const unique_ptr<Zuma_Balls_Factory> f)
{
	vector<unique_ptr<Zuma_Ball_Prototype>> vec;
	for (int i = 0; i < 200; ++i)
	{
		Zuma_Ball_Color temp = Zuma_Ball_Color(rand() % 4);
		unique_ptr<Zuma_Ball_Prototype> ptr = f->make_ball(temp);
		vec.push_back(move(ptr));
	}
	return vec;
}

int main()
{
	unique_ptr<Zuma_Balls_Factory> prtf = make_unique<Zuma_Balls_Factory>();
	vector<unique_ptr<Zuma_Ball_Prototype>> level = game(move(prtf));
}