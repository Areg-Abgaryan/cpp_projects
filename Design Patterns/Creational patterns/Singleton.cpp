#include <iostream>
#include <string>

class Russia_President
{
private:
	std::string name = { "Putin" };

protected:
	Russia_President() = default;
	~Russia_President() = default;
public:
	Russia_President(const Russia_President&) = delete;
	Russia_President& operator=(const Russia_President&) = delete;

	Russia_President(const Russia_President&&) noexcept = delete;
	Russia_President& operator=(const Russia_President&&) noexcept = delete;

	std::string get_value() const
	{
		return name;
	}

	void send_president_to_vacation()
	{
		name = "Medvedev";
		std::cout << "\nMaybe for 4 years only.\n";
	}

	static Russia_President& getinstance()
	{
		static Russia_President object;
		return object;
	}
};

int main()
{
	Russia_President &rp = Russia_President::getinstance();
	rp.send_president_to_vacation();
	std::cout << rp.get_value();
}
