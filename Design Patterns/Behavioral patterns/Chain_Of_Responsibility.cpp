#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <ctime>

enum Worker_State
{
	BUSY, AVAILABLE
};

enum Request_Type
{
	I, II, III
};

class Bank_Worker
{
protected:
	Worker_State check_availability() { return Worker_State(rand() % 2); }

public:
	std::string name{};
	Bank_Worker(const std::string& _name) : name{ _name } {}

	virtual void wait()
	{
		if (this->check_availability() == BUSY)
		{
			std::cout << "Please, wait a little.\n";

			while (this->check_availability() != AVAILABLE)
				this->check_availability();
		}
	}

	virtual bool handle_a_request(const Request_Type &type) = 0;

	virtual ~Bank_Worker() = default;
};

class Bank_Teller : public Bank_Worker
{
public:
	using Bank_Worker::Bank_Worker;

	bool handle_a_request(const Request_Type &t) override
	{
		this->wait();

		if (t == I)
			std::cout << "Bank teller will solve your problem\n";
		else
			return false;
	}

	~Bank_Teller() = default;
};

class Loan_Officer : public Bank_Worker
{
public:
	using Bank_Worker::Bank_Worker;

	bool handle_a_request(const Request_Type &t) override
	{
		this->wait();

		if (t == II)
			std::cout << "Loan Officer will solve your problem\n";
		else
			return false;
	}

	~Loan_Officer() = default;
};

class Financial_Analyst : public Bank_Worker
{
public:
	using Bank_Worker::Bank_Worker;

	bool handle_a_request(const Request_Type& t) override
	{
		this->wait();

		if (t == III)
			std::cout << "Financial analyst will solve your problem\n";
		else
			return false;
	}

	~Financial_Analyst() = default;
};

class Bank
{
private:
	std::vector<std::unique_ptr<Bank_Worker>> workers_chain;

public:
	Bank()
	{
		workers_chain.emplace_back(std::make_unique<Bank_Teller>("John"));
		workers_chain.emplace_back(std::make_unique<Loan_Officer>("Mike"));
		workers_chain.emplace_back(std::make_unique<Financial_Analyst>("Adam"));
	}

	void help_client()
	{
		std::cout << "Choose the help you need:   1  2  3\n";

		short n{};
		std::cin >> n;

		for (const auto& x : workers_chain)
		{
			switch (n)
			{
			case 1:
				x->handle_a_request(I);
				break;
			case 2:
				x->handle_a_request(II);
				break;
			case 3:
				x->handle_a_request(III);
				break;
			default:
				throw("Error!\n");
				break;
			}
		}
	}
};

int main()
{
	srand(time(0));
	Bank b{};
	b.help_client();
}
