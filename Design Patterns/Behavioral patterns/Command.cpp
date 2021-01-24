#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <memory>

class Operation_System;
class Media_Player;

class Logs
{
private:
	friend class Operation_System;

	std::deque<std::string> history{};

	void add_log(const std::string &s)
	{
		if (history.size() == 1000)
		{
			history.pop_front();
			history.push_back(s);
		}
		else
			history.push_back(s);
	}

	void read_logs()
	{
		for (const auto &x : history)
			std::cout << x << "\n";
	}

	static Logs& get_instance()
	{
		static Logs object;
		return object;
	}

	Logs() = default;
	~Logs() = default;

public:
	Logs(const Logs&) = delete;
	Logs& operator=(const Logs&) = delete;

	Logs(const Logs&&) noexcept = delete;
	Logs& operator=(const Logs&&) noexcept = delete;
};

class Song
{
private:
	friend class Media_Player;
	void play_song() const { std::cout << song_name << " by " << artist_name << "\n"; }

public:
	double size{};
	std::string artist_name{};
	std::string song_name{};

	Song(const Song&) = delete;
	Song& operator=(const Song&) = delete;

	Song() = default;
	~Song() = default;
};

class Command
{
public:
	virtual void execute() = 0;
	virtual void close() = 0;
	virtual ~Command() = default;
};

class Media_Player : public Command
{
private:
	std::vector<Song> songs{};

public:
	Media_Player() = default;

	void execute() override
	{
		std::cout << "Media player executed\n";

		for (const auto &x : songs)
			x.play_song();
	}

	void close() override { std::cout << "Media player closed\n"; }

	~Media_Player() = default;
};

class Web_Browser_Tab_Prototype : public Command
{
public:
	virtual void execute() override = 0;
	virtual void close() override = 0;
	virtual std::unique_ptr<Web_Browser_Tab_Prototype> clone() = 0;

	Web_Browser_Tab_Prototype() = default;
	virtual ~Web_Browser_Tab_Prototype() = default;
};

class Simple_Tab : public Web_Browser_Tab_Prototype
{
private:
	std::unique_ptr<Web_Browser_Tab_Prototype> clone() override
	{
		return std::make_unique<Simple_Tab>(*this);
	}

	void execute() override { std::cout << "A new tab is opened\n"; }
	void close() override { std::cout << "Tab is closed\n"; }

public:
	Simple_Tab() = default;
	~Simple_Tab() = default;
};

class Incognito_Tab : public Web_Browser_Tab_Prototype
{
private:
	void execute() override { std::cout << "Incognito tab is opened\n"; }
	void close() override { std::cout << "Incognito tab is closed\n"; }

	std::unique_ptr<Web_Browser_Tab_Prototype> clone() override
	{
		return std::make_unique<Incognito_Tab>(*this);
	}

public:
	Incognito_Tab() = default;
	~Incognito_Tab() = default;
};

class Web_Browser_Tabs_Factory
{
private:
	friend class Operation_System;

	std::unique_ptr<Web_Browser_Tab_Prototype> make_tab_and_execute(std::unique_ptr<Web_Browser_Tab_Prototype> &ptr)
	{
		std::unique_ptr<Web_Browser_Tab_Prototype> temp = ptr->clone();
		temp->execute();
		return temp;
	}

public:
	Web_Browser_Tabs_Factory() = default;
	~Web_Browser_Tabs_Factory() = default;
};

class Operation_System
{
private:
	Logs &inst = Logs::get_instance();
	Media_Player player{};

	std::unique_ptr<Web_Browser_Tab_Prototype> browser{};
	std::unique_ptr<Web_Browser_Tabs_Factory> tabs_factory{};

	void shut_down()
	{
		browser.get_deleter();
		tabs_factory.get_deleter();
	}

public:
	void boot()
	{
		inst.add_log("OS boot");

		std::cout << " '1' : Open a new tab\n"
			<< " '2' : Open a new incognito tab\n"
			<< " '3' : Open logs\n"
			<< " '4' : Media player\n"
			<< " '5' : Shut down\n";

		short numeral{};

		for (;;)
		{
			std::cin >> numeral;

			switch (numeral)
			{
			case 1:
				browser = std::make_unique<Simple_Tab>();
				tabs_factory->make_tab_and_execute(browser);
				inst.add_log("Browser tab opened");
				break;
			case 2:
				browser = std::make_unique<Incognito_Tab>();
				tabs_factory->make_tab_and_execute(browser);
				break;
			case 3:
				inst.read_logs();
				inst.add_log("Log reading");
				break;
			case 4:
				player.execute();
				inst.add_log("Media player opened");
				break;
			case 5:
				inst.history = {};
				this->shut_down();
				return;
				break;
			default:
				std::cout << "No such command!\n";
				break;
			}
		}
	}

	Operation_System() { std::cout << "OS is starting\n"; }
	~Operation_System() { std::cout << "OS is shutting down\n"; }
};

int main()
{
	Operation_System os{};
	os.boot();
}
