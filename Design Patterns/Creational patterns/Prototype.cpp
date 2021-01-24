#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

enum Zuma_Ball_Color
{
	Red, Green, Blue, Yellow
};

class Zuma_Balls_Factory;

class Zuma_Ball_Prototype
{
protected:
	bool status{};
	friend class Zuma_Balls_Factory;

	Zuma_Ball_Prototype(bool active) : status(active) {}
	virtual std::unique_ptr<Zuma_Ball_Prototype> clone() = 0;
public:
	Zuma_Ball_Prototype() = default;
	virtual ~Zuma_Ball_Prototype() = default;
};

class Red_Ball : public Zuma_Ball_Prototype
{
public:
	Red_Ball(bool active) : Zuma_Ball_Prototype(status) { std::cout << "red ball\n"; }

private:
	std::unique_ptr<Zuma_Ball_Prototype> clone() override
	{
		return std::make_unique<Red_Ball>(*this);
	}
};

class Green_Ball : public Zuma_Ball_Prototype
{
public:
	Green_Ball(bool active) : Zuma_Ball_Prototype(status) { std::cout << "green ball\n"; }

private:
	std::unique_ptr<Zuma_Ball_Prototype> clone() override
	{
		return std::make_unique<Green_Ball>(*this);
	}
};

class Blue_Ball : public Zuma_Ball_Prototype
{
public:
	Blue_Ball(bool active) : Zuma_Ball_Prototype(status) { std::cout << "blue ball\n"; }

private:
	std::unique_ptr<Zuma_Ball_Prototype> clone() override
	{
		return std::make_unique<Blue_Ball>(*this);
	}
};

class Yellow_Ball : public Zuma_Ball_Prototype
{
public:
	Yellow_Ball(bool active) : Zuma_Ball_Prototype(status) { std::cout << "yellow ball\n"; }

private:
	std::unique_ptr<Zuma_Ball_Prototype> clone() override
	{
		return std::make_unique<Yellow_Ball>(*this);
	}
};

class Zuma_Balls_Factory
{
private:
	std::unordered_map<Zuma_Ball_Color, std::unique_ptr<Zuma_Ball_Prototype>> list{};
public:
	Zuma_Balls_Factory()
	{
		list[Red] = std::make_unique<Red_Ball>(true);
		list[Green] = std::make_unique<Green_Ball>(true);
		list[Blue] = std::make_unique<Blue_Ball>(true);
		list[Yellow] = std::make_unique<Yellow_Ball>(true);
	}
	std::unique_ptr<Zuma_Ball_Prototype> make_ball(const Zuma_Ball_Color &p)
	{
		return list[p]->clone();
	}
};

std::vector<std::unique_ptr<Zuma_Ball_Prototype>> game(const std::unique_ptr<Zuma_Balls_Factory> f)
{
	std::vector<std::unique_ptr<Zuma_Ball_Prototype>> vec{};

	for (int i = 0; i < 200; ++i)
	{
		Zuma_Ball_Color temp = Zuma_Ball_Color(rand() % 4);
		std::unique_ptr<Zuma_Ball_Prototype> ptr = f->make_ball(temp);
		vec.push_back(std::move(ptr));
	}
	return vec;
}

int main()
{
	std::unique_ptr<Zuma_Balls_Factory> prtf = std::make_unique<Zuma_Balls_Factory>();
	std::vector<std::unique_ptr<Zuma_Ball_Prototype>> level = game(std::move(prtf));
}
