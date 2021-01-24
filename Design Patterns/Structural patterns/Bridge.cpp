#include <iostream>
#include <memory>

class Ship_Size
{
protected:
	void description() { std::cout << "Ship size is: "; }

public:
	virtual void ship_construction() = 0;
	virtual ~Ship_Size() = default;
};

class Big : public Ship_Size
{
private:
	void construct_big_ship()
	{
		description();
		std::cout << "big\n";
	}

public:
	Big() = default;

	void ship_construction() override
	{
		construct_big_ship();
	}

	~Big() = default;
};

class Small : public Ship_Size
{
private:
	void construct_small_ship()
	{
		description();
		std::cout << "small\n";
	}

public:
	Small() = default;

	void ship_construction() override
	{
		construct_small_ship();
	}

	~Small() = default;
};

class Vikingskipet
{
protected:
	std::unique_ptr<Ship_Size> shsz;

public:
	Vikingskipet(std::unique_ptr<Ship_Size>&& ptr) : shsz(std::move(ptr)) {}

	virtual void ship_mission()
	{
		this->shsz->ship_construction();
	}

	virtual ~Vikingskipet() = 0;
};

Vikingskipet::~Vikingskipet() {}

class Knarr : public Vikingskipet
{
public:
	Knarr(std::unique_ptr<Ship_Size>& knsz) : Vikingskipet(std::move(knsz)) {}

	void ship_mission() override
	{
		std::cout << "Merchant ship is built.\n";
		this->shsz->ship_construction();
	}
};

class Langskip : public Vikingskipet
{
public:
	Langskip(std::unique_ptr<Ship_Size>& lngsz) : Vikingskipet(std::move(lngsz)) {}

	void ship_mission() override
	{
		std::cout << "Warship is built.\n";
		this->shsz->ship_construction();
	}
};

int main()
{
	std::unique_ptr<Ship_Size> sz = std::make_unique<Big>();
	std::unique_ptr<Vikingskipet> vksh = std::make_unique<Knarr>(sz);

	vksh->ship_mission();
}
