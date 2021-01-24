#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Basque_Country_Clubs_Fans
{
protected:
	std::string fan_name{};

public:
	virtual void welcome_fan() = 0;
	static std::unique_ptr<Basque_Country_Clubs_Fans> make_fan(const char ch, const std::string &name);
	virtual ~Basque_Country_Clubs_Fans() {}
};

class Athletic_Bilbao_fan : public Basque_Country_Clubs_Fans
{
public:
	Athletic_Bilbao_fan(const std::string& name) { fan_name = name; }
	void welcome_fan() override { std::cout << "Hi, i am " << fan_name << " and i'm an Athletic Bilbao fan!\n"; }
};

class Real_Sociedad_fan : public Basque_Country_Clubs_Fans
{
public:
	Real_Sociedad_fan(const std::string& name) { fan_name = name; }
	void welcome_fan() override { std::cout << "Hi, i am " << fan_name << " and i'm a Real Sociedad fan!\n"; }
};

class Deportivo_Alaves_fan : public Basque_Country_Clubs_Fans
{
public:
	Deportivo_Alaves_fan(const std::string& name) { fan_name = name; }
	void welcome_fan() override { std::cout << "Hi, i am " << fan_name << " and i'm a Deportivo Alaves fan!\n"; }
};

class Osasuna_fan : public Basque_Country_Clubs_Fans
{
public:
	Osasuna_fan(const std::string& name) { fan_name = name; }
	void welcome_fan() override { std::cout << "Hi, i am " << fan_name << " and i'm an Osasuna fan!\n"; }
};

class Eibar_fan : public Basque_Country_Clubs_Fans
{
public:
	Eibar_fan(const std::string& name) { fan_name = name; }
	void welcome_fan() override { std::cout << "Hi, i am " << fan_name << " and i'm an Eibar fan!\n"; }
};

int main()
{
	std::vector<std::unique_ptr<Basque_Country_Clubs_Fans>> allfans{};
	//	Press ctrl+z after entering.
	std::cout << "Become a Basque Country club fan. Choose one of the above, then enter your name.\n" <<
		"Athletic Bilbao (1)\t" <<
		"Real Sociedad (2)\t" <<
		"Deportivo Alaves (3)\t" <<
		"Osasuna (4)\t" <<
		"Eibar (5)\t\n";

	char c{};
	std::string s{};

	while (std::cin >> c >> s)
		allfans.emplace_back(Basque_Country_Clubs_Fans::make_fan(c, s));

	size_t sz = allfans.size();

	for (size_t i = 0; i < sz; ++i)
		allfans[i]->welcome_fan();
}

std::unique_ptr<Basque_Country_Clubs_Fans> Basque_Country_Clubs_Fans::make_fan(const char ch, const std::string &name)
{
	switch (ch)
	{
	case '1':
		return std::make_unique<Athletic_Bilbao_fan>(name);
		break;
	case '2':
		return std::make_unique<Real_Sociedad_fan>(name);
		break;
	case '3':
		return std::make_unique<Deportivo_Alaves_fan>(name);
		break;
	case '4':
		return std::make_unique<Osasuna_fan>(name);
		break;
	case '5':
		return std::make_unique<Eibar_fan>(name);
		break;
	}
}
