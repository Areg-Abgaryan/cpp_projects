#include <iostream>
#include <memory>

using namespace std;

class Ship_Size
{
protected:
	void description() { cout << "Ship size is: "; }
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
		cout << "big\n";
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
		cout << "small\n";
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
	unique_ptr<Ship_Size> shsz;
public:
	Vikingskipet(unique_ptr<Ship_Size>&& ptr) : shsz(move(ptr)) {}

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
	Knarr(unique_ptr<Ship_Size>& knsz) : Vikingskipet(move(knsz)) {}

	void ship_mission() override
	{
		cout << "Merchant ship is built.\n";
		this->shsz->ship_construction();
	}
};

class Langskip : public Vikingskipet
{
public:
	Langskip(unique_ptr<Ship_Size>& lngsz) : Vikingskipet(move(lngsz)) {}

	void ship_mission() override
	{
		cout << "Warship is built.\n";
		this->shsz->ship_construction();
	}
};

int main()
{
	unique_ptr<Ship_Size> sz = make_unique<Big>();
	unique_ptr<Vikingskipet> vksh = make_unique<Knarr>(sz);
	vksh->ship_mission();
}