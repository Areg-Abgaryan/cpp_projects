#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FBI_Archives
{
public:
	virtual string get_data() const = 0;
	virtual ~FBI_Archives() {}
};

class FBI_Database;
class FBI_Database_Access;

class FBI_Agent
{
private:
	friend class FBI_Database;

	string name, surname, birth_year;
	string address, passport_id;
	string password;
	vector<string> info;
	
	FBI_Agent() = default;
public:
	~FBI_Agent() = default;
};

class FBI_Database : FBI_Archives
{
private:
	friend class FBI_Database_Access;

	vector<string> secret_data{ "Imagine a huuuge amount of data here" };
	vector<FBI_Agent> agents;

	FBI_Database() = default;
	
	FBI_Database(const FBI_Database&) = delete;
	FBI_Database& operator=(const FBI_Database&) = delete;
	FBI_Database(const FBI_Database&&) = delete;
	FBI_Database& operator=(const FBI_Database&&) = delete;

	static FBI_Database& get_instance()
	{
		static FBI_Database object;
		return object;
	}

	string get_data() const override
	{
		cout << "Real db\n";
		string s = secret_data[rand()%secret_data.size()];
		return s;
	}

	~FBI_Database() = default;
};

class FBI_Database_Access: public FBI_Archives
{
private:
	FBI_Database &dbinst = FBI_Database::get_instance();
public:
	FBI_Database_Access() = default;

	FBI_Database_Access(const FBI_Database_Access&) = delete;
	FBI_Database_Access& operator=(const FBI_Database_Access&) = delete;
	FBI_Database_Access(const FBI_Database_Access&&) = delete;
	FBI_Database_Access& operator=(const FBI_Database_Access&&) = delete;

	string get_data() const override
	{
		cout << "Proxy access\n";
		return dbinst.get_data();
	}

	~FBI_Database_Access() = default;
};

int main()
{
	FBI_Database_Access hacker;
	hacker.get_data();
}