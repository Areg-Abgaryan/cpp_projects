#include <iostream>
#include <memory>
#include <string>
#include <map>

typedef unsigned short us;

class Numeral
{
protected:
	char symbol{};
	us height{}, width{};
	std::string pronunciation{};
	
	Numeral(const char c, const std::string& s) : symbol{ c }, pronunciation{ s }
	{
		height = 0;
		width = 0;
	}

public:
	virtual void display(const us h, const us w)
	{
		height = h;
		width = w;
	}

	virtual void read() { std::cout << pronunciation << " "; }
	virtual ~Numeral() = default;
};

class O : public Numeral
{
public:
	O() : Numeral('0', "zero") {}

	~O() = default;
};

class I : public Numeral
{
public:
	I() : Numeral('1', "one") {}

	~I() = default;
};

class II : public Numeral
{
public:
	II() : Numeral('2', "two") {}

	~II() = default;
};

class III : public Numeral
{
public:
	III() : Numeral('3', "three") {}

	~III() = default;
};

class IV : public Numeral
{
public:
	IV() : Numeral('4', "four") {}

	~IV() = default;
};

class V : public Numeral
{
public:
	V() : Numeral('5', "five") {}

	~V() = default;
};

class VI : public Numeral
{
public:
	VI() : Numeral('6', "six") {}

	~VI() = default;
};

class VII : public Numeral
{
public:
	VII() : Numeral('7', "seven") {}

	~VII() = default;
};

class VIII : public Numeral
{
public:
	VIII() : Numeral('8', "eight") {}

	~VIII() = default;
};

class IX : public Numeral
{
public:
	IX() : Numeral('9', "nine") {}

	~IX() = default;
};

class Numerals_Factory
{
private:
	std::map<char, std::shared_ptr<Numeral>> numerals_pool;

public:
	std::shared_ptr<Numeral> get_numeral(const char key)
	{
		if (numerals_pool.find(key) != numerals_pool.end())
			return numerals_pool[key];
		else
		{
			throw("Not a number!\n");
			return nullptr;
		}
	}

	Numerals_Factory()
	{
		numerals_pool.insert(std::make_pair('0', std::shared_ptr<O>(new O())));
		numerals_pool.insert(std::make_pair('1', std::shared_ptr<I>(new I())));
		numerals_pool.insert(std::make_pair('2', std::shared_ptr<II>(new II())));
		numerals_pool.insert(std::make_pair('3', std::shared_ptr<III>(new III())));
		numerals_pool.insert(std::make_pair('4', std::shared_ptr<IV>(new IV())));
		numerals_pool.insert(std::make_pair('5', std::shared_ptr<V>(new V())));
		numerals_pool.insert(std::make_pair('6', std::shared_ptr<VI>(new VI())));
		numerals_pool.insert(std::make_pair('7', std::shared_ptr<VII>(new VII())));
		numerals_pool.insert(std::make_pair('8', std::shared_ptr<VIII>(new VIII())));
		numerals_pool.insert(std::make_pair('9', std::shared_ptr<IX>(new IX())));
	}

	~Numerals_Factory() = default;
};

int main()
{
	std::string document{ "35012837862903471" };

	std::unique_ptr<Numerals_Factory> factory = std::make_unique<Numerals_Factory>();

	us h = { 20 }, w{ 10 };

	size_t docsz = document.size();

	for (size_t t = 0; t < docsz; ++t, ++h, ++w)
	{
		std::shared_ptr<Numeral> character = factory->get_numeral(document[t]);
		character->display(h, w);
		character->read();
	}
}
