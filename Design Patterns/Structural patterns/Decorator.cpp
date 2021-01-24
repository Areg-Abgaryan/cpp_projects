#include <iostream>
#include <memory>
#include <vector>
#include <ctime>

class Garbage_Chute
{
public:
	static std::unique_ptr<Garbage_Chute> generate_a_policeman();
	virtual void reaction_to_street_art() = 0;
	virtual ~Garbage_Chute() {}
};

class Good_Policeman : public Garbage_Chute
{
public:
	void reaction_to_street_art() override { std::cout << "Wow, cool\n"; }
};

class Bad_Policeman : public Garbage_Chute
{
public:
	void reaction_to_street_art() override { std::cout << "Vandals..Only the streets are spoiled\n"; }
};

class Ugly_Policeman : public Garbage_Chute
{
public:
	void reaction_to_street_art() override { std::cout << "What the hell's that? Send the author to jail\n"; }
};

std::unique_ptr<Garbage_Chute> Garbage_Chute::generate_a_policeman()
{
	std::vector<std::unique_ptr<Garbage_Chute>> polmangenerator;
	polmangenerator.reserve(3);

	polmangenerator.push_back(std::make_unique<Good_Policeman>());
	polmangenerator.push_back(std::make_unique<Bad_Policeman>());
	polmangenerator.push_back(std::make_unique<Ugly_Policeman>());

	return std::move(polmangenerator[rand() % 3]);
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
	void decorate() override { std::cout << "street_wall\n"; }
	~Wall() = default;
};

class Street_Art : public Street_Object
{
protected:
	std::unique_ptr<Street_Object> object{};

public:
	bool status{};		// Street art is legal(true) or not(false)

	Street_Art(std::unique_ptr<Street_Object> ptr, bool _status)
		: object{ std::move(ptr) }, status{ _status } {}

	void decorate() override {}
	~Street_Art() = default;
};

class Graffiti : public Street_Art
{
public:
	using Street_Art::Street_Art;
	void decorate() override { std::cout << "The street object is decorated with graffiti.\n"; }
	~Graffiti() = default;
};

class Posters : public Street_Art
{
public:
	using Street_Art::Street_Art;
	void decorate() override { std::cout << "The street object is decorated with posters.\n"; }
	~Posters() = default;
};

////	This function is used from
////	https://gist.github.com/SergNikitin/9b55f4400111742dac1e2cf9ea7206bc

std::unique_ptr<Street_Art> dynamic_ptr_cast(std::unique_ptr<Street_Object>&& base)
{
	if (auto derived = dynamic_cast<Street_Art*>(base.get()))
	{
		base.release();
		return std::unique_ptr<Street_Art>(derived);
	}
	return nullptr;
}

void function(std::unique_ptr<Street_Object>& so)
{
	std::unique_ptr<Street_Art> temp = dynamic_ptr_cast(std::move(so));

	if (temp->status == 0)
	{
		Garbage_Chute::generate_a_policeman()->reaction_to_street_art();
	}
}

int main()
{
	srand(time(0));
	
	std::unique_ptr<Street_Object> wall = std::make_unique<Wall>();
	std::unique_ptr<Street_Object> graffiti = std::make_unique<Graffiti>(move(wall), false);

	graffiti->decorate();
	function(graffiti);
}
