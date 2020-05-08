#include <iostream>
#include <memory>
#include <vector>
#include <ctime>

using namespace std;

class Garbage_Chute
{
public:
	static unique_ptr<Garbage_Chute> generate_a_policeman();
	virtual void reaction_to_street_art() = 0;
	virtual ~Garbage_Chute() {}
};

class Good_Policeman : public Garbage_Chute
{
public:
	void reaction_to_street_art() override { cout << "Wow, cool\n"; }
};

class Bad_Policeman : public Garbage_Chute
{
public:
	void reaction_to_street_art() override { cout << "Vandals..Only the streets are spoiled\n"; }
};

class Ugly_Policeman : public Garbage_Chute
{
public:
	void reaction_to_street_art() override { cout << "What the hell's that? Send the author to jail\n"; }
};

unique_ptr<Garbage_Chute> Garbage_Chute::generate_a_policeman()
{
	vector<unique_ptr<Garbage_Chute>> polmangenerator;
	polmangenerator.reserve(3);

	polmangenerator.push_back(make_unique<Good_Policeman>());
	polmangenerator.push_back(make_unique<Bad_Policeman>());
	polmangenerator.push_back(make_unique<Ugly_Policeman>());

	return move(polmangenerator[rand() % 3]);
}

class Street_Object
{
public:
	virtual void decorate() = 0;
	virtual ~Street_Object() {}
};

class Wall : public Street_Object
{
public:
	Wall() = default;
	void decorate() override { cout << "street_wall\n"; }
	~Wall() = default;
};

class Street_Art : public Street_Object
{
protected:
	unique_ptr<Street_Object> object;
public:
	bool status;		// Street art is legal(true) or not(false)

	Street_Art(unique_ptr<Street_Object> ptr, bool _status)
		: object{ move(ptr) }, status{ _status } {}

	void decorate() override {}
	~Street_Art() = default;
};

class Graffiti : public Street_Art
{
public:
	using Street_Art::Street_Art;
	void decorate() override { cout << "The street object is decorated with graffiti.\n"; }
	~Graffiti() = default;
};

class Posters : public Street_Art
{
public:
	using Street_Art::Street_Art;
	void decorate() override { cout << "The street object is decorated with posters.\n"; }
	~Posters() = default;
};

////	This function i used from
////	https://gist.github.com/SergNikitin/9b55f4400111742dac1e2cf9ea7206bc

unique_ptr<Street_Art> dynamic_ptr_cast(unique_ptr<Street_Object>&& base)
{
	if (auto derived = dynamic_cast<Street_Art*>(base.get()))
	{
		base.release();
		return unique_ptr<Street_Art>(derived);
	}
	return nullptr;
}

void function(unique_ptr<Street_Object>& so)
{
	unique_ptr<Street_Art> temp = dynamic_ptr_cast(move(so));

	if (temp->status == 0)
	{
		Garbage_Chute::generate_a_policeman()->reaction_to_street_art();
	}
}

int main()
{
	srand(time(0));
	unique_ptr<Street_Object> wall = make_unique<Wall>();
	unique_ptr<Street_Object> graffiti = make_unique<Graffiti>(move(wall), false);
	graffiti->decorate();
	function(graffiti);
}
