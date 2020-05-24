#include <iostream>
#include <queue>
#include <string>
#include <memory>

using namespace std;

class Operation_System;
class Media_Player;

class Logs
{
private:
	friend class Operation_System;

	deque<string> history{};

	void add_log(const string &s)
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
			cout << x << "\n";
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
	void play_song() const { cout << song_name << " by " << artist_name << "\n"; }

public:
	double size{};
	string artist_name{};
	string song_name{};

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
	vector<Song> songs{};

public:
	Media_Player() = default;

	void execute() override
	{
		cout << "Media player executed\n";

		for (const auto &x : songs)
			x.play_song();
	}

	void close() override { cout << "Media player closed\n"; }

	~Media_Player() = default;
};

class Web_Browser_Tab_Prototype : public Command
{
public:
	virtual void execute() override = 0;
	virtual void close() override = 0;
	virtual unique_ptr<Web_Browser_Tab_Prototype> clone() = 0;

	Web_Browser_Tab_Prototype() = default;
	virtual ~Web_Browser_Tab_Prototype() = default;
};

class Simple_Tab : public Web_Browser_Tab_Prototype
{
private:
	unique_ptr<Web_Browser_Tab_Prototype> clone() override
	{
		return make_unique<Simple_Tab>(*this);
	}

	void execute() override { cout << "A new tab is opened\n"; }
	void close() override { cout << "Tab is closed\n"; }

public:
	Simple_Tab() = default;
	~Simple_Tab() = default;
};

class Incognito_Tab : public Web_Browser_Tab_Prototype
{
private:
	void execute() override { cout << "Incognito tab is opened\n"; }
	void close() override { cout << "Incognito tab is closed\n"; }
	
	unique_ptr<Web_Browser_Tab_Prototype> clone() override
	{
		return make_unique<Incognito_Tab>(*this);
	}

public:
	Incognito_Tab() = default;
	~Incognito_Tab() = default;
};

class Web_Browser_Tabs_Factory
{
private:
	friend class Operation_System;

	unique_ptr<Web_Browser_Tab_Prototype> make_tab_and_execute(unique_ptr<Web_Browser_Tab_Prototype> &ptr)
	{
		unique_ptr<Web_Browser_Tab_Prototype> temp = ptr->clone();
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

	unique_ptr<Web_Browser_Tab_Prototype> browser{};
	unique_ptr<Web_Browser_Tabs_Factory> tabs_factory{};
	
	void shut_down()
	{
		browser.get_deleter();
		tabs_factory.get_deleter();
	}

public:
	void boot()
	{
		inst.add_log("OS boot");

		cout << " '1' : Open a new tab\n"
			 << " '2' : Open a new incognito tab\n"
			 << " '3' : Open logs\n"
			 << " '4' : Media player\n"
			 << " '5' : Shut down\n";

		short numeral{};

		for (;;)
		{
			cin >> numeral;

			switch (numeral)
			{
				case 1:
					browser = make_unique<Simple_Tab>();
					tabs_factory->make_tab_and_execute(browser);
					inst.add_log("Browser tab opened");
					break;
				case 2:
					browser = make_unique<Incognito_Tab>();
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
					cout << "No such command!\n";
					break;
			}
		}
	}

	Operation_System() { cout << "OS is starting\n"; }
	~Operation_System() { cout << "OS is shutting down\n"; }
};

int main()
{
	Operation_System os;
	os.boot();
}