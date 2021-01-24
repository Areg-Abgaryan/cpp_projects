#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <ctime>

class Team;

enum Question_Status
{
	Won,
	Lost,
	Not_Played
};

class Question
{
private:
	std::string question, answer;
	Question_Status status = Not_Played;

public:
	friend class Host;
	Question() {};
	~Question() {};
};

class Person
{
protected:
	std::string name, city;
	Person() {}
	friend class Host;

	virtual void get_info() {};
	virtual ~Person() {}
};

class Host : public Person
{
private:
	Host() { name = "Borik Kryuk"; }
	~Host() = default;

	Host(const Host&) = delete;
	Host& operator=(const Host&) = delete;
	Host(const Host&&) noexcept = delete;
	Host& operator=(const Host&&) noexcept = delete;

	friend class What_Where_When;

	static Host& get_instance()
	{
		static Host object;
		return object;
	}
	void present_the_team(const std::unique_ptr<Team>& obj);

	std::string read_question(const Question& quest) const { return quest.question; }
	std::string read_answer(const Question& quest) const { return quest.answer; }

	void set_status(Question& quest, Question_Status _status) { quest.status = _status; }
	Question_Status get_status(const Question& quest) { return quest.status; }
};

class Player : public Person
{
protected:
	friend class Team;
	friend class Host;

	std::string give_versions_for_the_question()
	{
		std::string idea;
		return idea;
	}
	void get_info() override
	{
		std::cout << name << " " << city << "\n";
	}

public:
	Player() {}
	~Player() {};
};

class Captain : public Player
{
private:
	friend class Team;

	Captain() {}
	std::string choose_version(const std::vector<std::string>& versions) const;
	
	void get_info() override
	{
		std::cout << "The team's captain is" << name << " " << city << "\n";
	}

public:
	~Captain() {}
};

class Team
{
private:
	Team() {}
	std::shared_ptr<Player> p1{ new Player{} }, p2{ new Player{} }, p3{ new Player{} }, p4{ new Player{} }, p5{ new Player{} };
	std::shared_ptr<Captain> cpt1{ new Captain{} };
	const std::vector<std::shared_ptr<Player>> members{ std::move(cpt1), std::move(p1), std::move(p2), std::move(p3), std::move(p4), std::move(p5) };
	std::string give_versions() const;
	friend class Host;
	friend class What_Where_When;

public:
	~Team() {}
};

std::string Captain::choose_version(const std::vector<std::string>& versions) const
{
	return versions[rand() % versions.size()];
}

std::string Team::give_versions() const
{
	std::vector<std::string> versions;
	for (size_t i = 0; i < 10; ++i)
	{
		versions.push_back(members[rand() % 6]->give_versions_for_the_question());
	}
	return cpt1->choose_version(versions);
}

void Host::present_the_team(const std::unique_ptr<Team>& obj)
{
	for (size_t i = 0; i < 6; ++i)
		obj->members[i]->get_info();
}

class Break
{
protected:
	Break() {}
	friend class What_Where_When;
	virtual void make_a_break() = 0;

public:
	~Break() {}
};

class Musical_Break : public Break
{
private:
	class Singer
	{
	public:
		void sing_a_song() {}
		Singer() {};
	};

	std::unique_ptr<Singer> performer{};
	
	void make_a_break() override
	{
		performer->sing_a_song();
	}
};

class Coffee_Break : public Break
{
private:
	std::unique_ptr<Team> team{};
	void treat_team_to_coffee(std::unique_ptr<Team> team) {}

	void make_a_break() override
	{
		treat_team_to_coffee(move(team));
	}
};

class Commercial_Break : public Break
{
private:
	void make_a_break() override
	{
		std::cout << "Some ad\n";
	}
};

class Score
{
private:
	unsigned short experts{}, viewers{};
	friend class What_Where_When;
	
	Score()
	{
		experts = 0;
		viewers = 0;
	}
	
	void know_winning_team()
	{
		if (experts == 6)
			std::cout << "Today experts' team won\n";
		else
			std::cout << "Today viewers' team won\n";
	}
	~Score() {};
};

class What_Where_When
{
private:
	unsigned short round_count{ 0 };
	std::unique_ptr<Break> stop{};
	std::unique_ptr<Team> current_team{ new Team{} };
	Score score_table{};
	Host& kryuk = Host::get_instance();
	std::vector<Question> question_set{}, who_won{};
public:
	What_Where_When() { question_set.resize(13); }

	void start_game()
	{
		stop = std::make_unique<Commercial_Break>();
		stop->make_a_break();
		kryuk.present_the_team(current_team);

		if (round_count == 2)
			stop->make_a_break();

		if (round_count == 4)
		{
			stop = std::make_unique<Coffee_Break>();
			stop->make_a_break();
		}
		if (round_count == 6)
		{
			stop = std::make_unique<Commercial_Break>();
			stop->make_a_break();
		}

		while (score_table.experts != 6 && score_table.viewers != 6)
		{
			short rand_question = rand() % question_set.size();

			kryuk.read_question(question_set[rand_question]);

			if (current_team->give_versions() == kryuk.read_answer(question_set[rand_question]))
			{
				++score_table.experts;
				kryuk.set_status(question_set[rand_question], Lost);
			}
			else
			{
				++score_table.viewers;
				kryuk.set_status(question_set[rand_question], Won);
			}

			if (kryuk.get_status(question_set[rand_question]) == Won)
				who_won.push_back(question_set[rand_question]);

			question_set.erase(question_set.begin() + rand_question);

			++round_count;
		}
		score_table.know_winning_team();

		stop = std::make_unique<Musical_Break>();
		stop->make_a_break();
	}
	~What_Where_When() {};
};

int main()
{
	srand(time(0));

	What_Where_When instance{};
	instance.start_game();
}
