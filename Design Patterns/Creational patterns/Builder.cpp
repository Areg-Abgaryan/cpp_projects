#include <iostream>
#include <string>
#include <memory>

class Movie_Character
{
private:
	std::string street_address{}, city{}, company_name{}, position{};
	int annual_income = 0, post_code = 0;
protected:
	Movie_Character(const std::string& _street_address, const int _post_code, const std::string& _city,
		const std::string& _company_name, const std::string& _position, const int _annual_income) :
		street_address{ _street_address }, post_code{ _post_code }, city{ _city },
		company_name{ _company_name }, position{ _position }, annual_income{ _annual_income } {}
public:
	friend class Movie_Character_Builder;
	friend class Movie_Character_Address_Builder;
	friend class Movie_Character_Job_Builder;

	Movie_Character() = default;
	~Movie_Character() = default;
};

class Movie_Character_Builder
{
protected:
	std::unique_ptr<Movie_Character> person{ nullptr };
	Movie_Character_Builder() { person = std::make_unique<Movie_Character>(); }
public:
	std::unique_ptr<Movie_Character> getCharacter()
	{
		return move(person);
	}

	Movie_Character_Builder(Movie_Character_Builder&&) = default;

	virtual void at(const std::string& street_address) {}
	virtual void post_code(const int post_code) {}
	virtual void in(const std::string& city) {}

	virtual void company(const std::string& company_name) {}
	virtual void as_a(const std::string& position) {}
	virtual void salary(const int annual_income) {}
};

class Movie_Character_Address_Builder : public Movie_Character_Builder
{
public:
	Movie_Character_Address_Builder() = default;

	void at(const std::string& street_address) override
	{
		person->street_address = street_address;
	}
	void post_code(const int post_code) override
	{
		person->post_code = post_code;
	}
	void in(const std::string& city) override
	{
		person->city = city;
	}

	~Movie_Character_Address_Builder() = default;
};

class Movie_Character_Job_Builder : public Movie_Character_Builder
{
public:
	Movie_Character_Job_Builder() = default;

	void company(const std::string& company_name) override
	{
		person->company_name = company_name;
	}
	void as_a(const std::string& position) override
	{
		person->position = position;
	}
	void salary(const int annual_income) override
	{
		person->annual_income = annual_income;
	}

	~Movie_Character_Job_Builder() = default;
};

class Director
{
private:
	std::unique_ptr<Movie_Character_Builder> builder{ nullptr };
public:
	Director(std::unique_ptr<Movie_Character_Builder>& b)
	{
		builder = std::move(b);
	}

	std::unique_ptr<Movie_Character> createCharacter()
	{
		builder->at("Wollestraat 41-47");
		builder->post_code(8310);
		builder->in("Bruges");
		builder->company("Harry Waters");
		builder->as_a("Killer");
		builder->salary(60000);
		return builder->getCharacter();
	}
};

int main()
{
	std::unique_ptr<Movie_Character_Builder> builder1 = std::make_unique<Movie_Character_Address_Builder>();
	std::unique_ptr<Movie_Character_Builder> builder2 = std::make_unique<Movie_Character_Job_Builder>();

	std::unique_ptr<Director> eng = std::make_unique<Director>(builder1);
	eng->createCharacter();

	eng = std::make_unique<Director>(builder2);
	eng->createCharacter();
}
