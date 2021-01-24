#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>

class Albums
{
protected:
	Albums() {}
	virtual void print_albums() = 0;

public:
	std::vector<std::pair<std::string, std::string>> data_albums{};
	virtual ~Albums() {};
};

class Artists
{
protected:
	Artists() {}
	virtual void print_artists() = 0;

public:
	std::vector<std::string> data_artists{};
	virtual ~Artists() {};
};

class Songs
{
protected:
	Songs() {}
	virtual void print_songs() = 0;

public:
	std::vector<std::pair<std::string, std::string>> data_songs{};
	virtual ~Songs() {};
};

class RockAlbums : public Albums
{
public:
	RockAlbums()
	{
		data_albums =
		{
			std::make_pair("AC/DC","Back In Black"), std::make_pair("AC/DC","Highway To Hell"),
			std::make_pair("The Beatles","Abbey Road"), std::make_pair("The Beatles","A Hard Day's Night"),
			std::make_pair("Black Sabbath","Paranoid"), std::make_pair("Chris Rea","Auberge"),
			std::make_pair("Guns N' Roses","Appetite For Destruction"), std::make_pair("Guns N' Roses","Use Your Illusion I"),
			std::make_pair("Led Zeppelin","IV"), std::make_pair("Lordi","The Arockalypse"),
			std::make_pair("Metallica","The Black Album"), std::make_pair("Metallica","Hardwired... to Self-destruct"),
			std::make_pair("Metallica","Ride The Lightning"), std::make_pair("Metallica","Reload"),
			std::make_pair("Motorhead","Ace of Spades"), std::make_pair("Nirvana","Nevermind"),
			std::make_pair("Pink Floyd","The Dark Side of the Moon"), std::make_pair("Pink Floyd","The Wall"),
			std::make_pair("Pink Floyd","Wish You Were Here"), std::make_pair("Queen","A Night at the Opera"),
			std::make_pair("Radiohead","OK Computer"), std::make_pair("Rammstein","Mutter"),
			std::make_pair("Scorpions","Love at First Sting"), std::make_pair("Smokie","Midnight Cafe"),
			std::make_pair("System of a Down","Toxicity")
		};
	}

private:
	void print_albums() override
	{
		std::cout << "Rock Albums List\n";
		
		for (const auto& x : data_albums)
			std::cout << x.first << " - " << x.second << "\n";
	}
};

class BluesAlbums : public Albums
{
public:
	BluesAlbums()
	{
		data_albums =
		{
			std::make_pair("Albert Collins","Ice Pickin"), std::make_pair("Albert King", "Born Under a Bad Sign"),
			std::make_pair("B.B.King","Live at the Regal"), std::make_pair("Buddy Guy","I Was Walking Through the Woods"),
			std::make_pair("Buddy Guy","Sweet Tea"), std::make_pair("Chris Barber","Good Morning Blues"),
			std::make_pair("Chuck Berry","One Dozen Berrys"), std::make_pair("Cream","Wheels of Fire"),
			std::make_pair("Elmore James","Blues Master Works"), std::make_pair("Elmore James","The Sky is Crying"),
			std::make_pair("Etta James", "At Last"), std::make_pair("Eric Clapton","From the Cradle"),
			std::make_pair("Eric Clapton & B.B. King", "Riding with the King"), std::make_pair("Etta James", "I'd Rather Go Blind"),
			std::make_pair("Gary Moore","Still Got The Blues"), std::make_pair("Howlin' Wolf","Moanin' in the Moonlight"),
			std::make_pair("Jimi Hendrix","Blues"), std::make_pair("John Lee Hooker", "It Serves You Right To Suffer"),
			std::make_pair("Johny Winter","Second Winter"), std::make_pair("Jonny Lang","Lie to Me"),
			std::make_pair("Jonny Lang","Wander This World"), std::make_pair("Muddy Waters","The Folk Singer"),
			std::make_pair("Muddy Waters","Hard Again"), std::make_pair("Robert Johnson","King of the Delta Blues Singers"),
			std::make_pair("Stevie Ray Vaughan","Texas Flood")
		};
	}

private:
	void print_albums() override
	{
		std::cout << "Blues Albums List\n";
		
		for (const auto& x : data_albums)
			std::cout << x.first << " - " << x.second << "\n";
	}
};

class RockArtists : public Artists
{
public:
	RockArtists()
	{
		data_artists =
		{
			{
				"AC/DC", "Aerosmith", "The Beatles", "Bon Jovi",
				"Black Sabbath", "Chris Rea", "The Doors", "Deep Purple",
				"Foo Fighters", "Guns N' Roses", "Green Day", "Jimmy Hendrix",
				"Kiss","Led Zeppelin", "Lordi", "Metallica",
				"Motorhead", "Nirvana", "Queen", "Radiohead",
				"Rammstein", "Pink Floyd", "Scorpions", "Smokie", "System of a Down"
			}
		};
	}

private:
	void print_artists() override
	{
		std::cout << "Rock Artists List\n";
		
		for (const auto& x : data_artists)
			std::cout << x << "\n";
	}
};

class BluesArtists : public Artists
{
public:
	BluesArtists()
	{
		data_artists =
		{
			"Albert King", "B.B. King", "Beth Hart", "Bessie Smith",
			"Buddy Guy", "Elmore James", "Elvis Presley", "Eric Clapton",
			"Etta James", "Gary Moore", "Howlin' Wolf", "Janis Joplin",
			"Joe Bonamassa", "John Lee Hooker", "Jonny Lang", "Kenny Wayne Shepherd",
			"Lightnin' Hopkins", "Little Walter", "Lonnie Johnson", "Muddy Waters",
			"Robert Johnson", "Stevie Ray Vaughan", "The Jimi Hendrix Experience", "Walter Trout", "W.C. Handy"
		};
	}

private:
	void print_artists() override
	{
		std::cout << "Blues Artists List\n";
		
		for (const auto& x : data_artists)
			std::cout << x << "\n";
	}
};

class RockSongs : public Songs
{
public:
	RockSongs()
	{
		data_songs =
		{
			std::make_pair("AC/DC","Hell's Bells"), std::make_pair("Aerosmith","Dream On"),
			std::make_pair("Black Sabbath", "Loner"), std::make_pair("The Beatles","Come Together"),
			std::make_pair("Blur","Song 2"), std::make_pair("Chris Rea","The Road to Hell"),
			std::make_pair("The Cranberries","Zombie"), std::make_pair("Creedence Clearwater Revival","Have You Ever Seen the Rain?"),
			std::make_pair("Deep Purple", "The Cut Runs Deep"), std::make_pair("Dio","Rainbow in the Dark"),
			std::make_pair("Europe","The Final Countdown"), std::make_pair("Foo Fighters","The Pretender"),
			std::make_pair("Guns N' Roses","Don't Cry"), std::make_pair("Led Zeppelin","Immigrant Song"),
			std::make_pair("Marylin Manson","Personsal Jesus"), std::make_pair("Metallica","For Whom the Bell Tolls"),
			std::make_pair("Motorhead","Overkill"), std::make_pair("Muse","Supermassive Black Hole"),
			std::make_pair("Pink Floyd","Time"), std::make_pair("Rammstein","Mein Herz Brennt"),
			std::make_pair("Scorpions","When the Smoke is Going Down"), std::make_pair("System of a Down","B.Y.O.B."),
			std::make_pair("Survivor","Eye of the Tiger"), std::make_pair("The White Stripes","Seven Nation Army"),
			std::make_pair("ZZ Top","Bad to the Bone")
		};
	}

private:
	void print_songs() override
	{
		std::cout << "Rock Songs List\n";
		
		for (const auto& x : data_songs)
			std::cout << x.first << " - " << x.second << "\n";
	}
};

class BluesSongs : public Songs
{
public:
	BluesSongs()
	{
		data_songs =
		{
			std::make_pair("Albert King","Born Under a Bad Sign"), std::make_pair("B.B. King","Sweet Little Angel"),
			std::make_pair("B.B. King","The Thrill Is Gone"), std::make_pair("Cream","Sunshine of Your Love"),
			std::make_pair("Etta James","All I Could Do Was Cryin"), std::make_pair("Etta James","At Last"),
			std::make_pair("Etta James","I'd Rather Go Blind"), std::make_pair("Howlin' Wolf","How Many More Years"),
			std::make_pair("John Lee Hooker","Boogie Chillin"), std::make_pair("John Lee Hooker","One Bourbon, One Scotch, One Beer"),
			std::make_pair("Jonny Lang","Lie To Me"), std::make_pair("Leadbelly","Where Did You Sleep Last Night?"),
			std::make_pair("Lightnin' Hopkins","Bring Me My Shotgun"), std::make_pair("Little Walter","My Babe"),
			std::make_pair("Lonnie Johnson","Too Late To Cry"), std::make_pair("Muddy Waters","Hoochie Coochie Man"),
			std::make_pair("Muddy Waters","Mannish Boy"), std::make_pair("Otis Rush","I Can't Quit You Baby"),
			std::make_pair("Robert Johnson","Crossroad Blues"), std::make_pair("Robert Johnson","Sweet Home Chicago"),
			std::make_pair("Robert Johnson","Travelling Riverside Blues"), std::make_pair("Roosevelt Skykes","Forty Four Blues"),
			std::make_pair("Son House","Pearline"), std::make_pair("T-Bone Walker","Stormy Monday"), std::make_pair("W.C. Handy","Memphis Blues")
		};
	}

private:
	void print_songs() override
	{
		std::cout << "Blues Songs List\n";

		for (const auto& x : data_songs)
			std::cout << x.first << " - " << x.second << "\n";
	}
};

class Abstract_Music_Quiz_Factory
{
public:
	virtual void guess_album() const = 0;
	virtual void guess_artist() const = 0;
	virtual void guess_song() const = 0;
};

class Rock_Music_Level : public Abstract_Music_Quiz_Factory
{
public:
	Rock_Music_Level() { std::cout << "Rock Music Level Begins!\n"; }

	void survival_mode() const
	{
		bool status{ 1 };
		std::unique_ptr<Albums> albums = std::make_unique<RockAlbums>();

		std::cout << "\nLet's Start!\n";

		for (short i = 0; i < 10; ++i)
		{
			if (!status)
			{
				std::cout << "\tFalse!\t You Lose!";
				break;
			}

			short temp = rand() % albums->data_albums.size();

			std::set<std::string> st{};
			st.insert(albums->data_albums[temp].first);

			while (st.size() != 4)
			{
				short t = rand() % albums->data_albums.size();
				st.insert(albums->data_albums[t].first);
			}

			std::cout << "\n" << i + 1 << ") '" << albums->data_albums[temp].second << "'\n\n";

			std::vector<std::pair<int, std::string>> pv(4);

			for (short i = 0; i < 4; ++i)
			{
				pv[i] = std::make_pair(i + 1, *st.begin());
				st.erase(st.begin());
			}

			for (auto x : pv)
				std::cout << x.first << ".  " << x.second << "\n";

			short answer{};
			std::cin >> answer;

			for (short i = 0; i < 4; ++i)
			{
				if (pv[i].first == answer)
				{
					if (pv[i].second == albums->data_albums[temp].first)
					{
						std::cout << "\tRight!\n";
						break;
					}
					else
						status = 0;
				}
			}
			albums->data_albums.erase(albums->data_albums.begin() + temp);
		}
	}

	void guess_album() const override
	{
		survival_mode();
	}

	void guess_artist() const override
	{
		//	Here could be some implementation with image files		
	}

	void guess_song() const override
	{
		survival_mode();
	}
};

class Blues_Music_Level : public Abstract_Music_Quiz_Factory
{
public:
	Blues_Music_Level()
	{
		std::cout << "Blues Music Level Begins!\n";
	}

	void questions_mode() const
	{
		std::unique_ptr<Albums> albums = std::make_unique<BluesAlbums>();

		unsigned score{ 0 };

		for (short i = 0; i < 10; ++i)
		{
			short temp = rand() % albums->data_albums.size();
			
			std::set<std::string> st{};
			st.insert(albums->data_albums[temp].first);

			while (st.size() != 4)
			{
				short t = rand() % albums->data_albums.size();
				st.insert(albums->data_albums[t].first);
			}

			std::cout << "\n" << i + 1 << ") '" << albums->data_albums[temp].second << "'\n\n";

			std::vector<std::pair<int, std::string>> pv(4);

			for (short i = 0; i < 4; ++i)
			{
				pv[i] = std::make_pair(i + 1, *st.begin());
				st.erase(st.begin());
			}

			for (auto x : pv)
				std::cout << x.first << ".  " << x.second << "\n";

			bool b{ 0 };
			short answer{};
			std::cin >> answer;

			for (short i = 0; i < 4; ++i)
			{
				if (pv[i].first == answer)
				{
					if (pv[i].second == albums->data_albums[temp].first)
					{
						std::cout << "\tRight!\n";
						++score;
						break;
					}
					else
						std::cout << "\tFalse!\n";
				}
			}
			albums->data_albums.erase(albums->data_albums.begin() + temp);
		}
		std::cout << "\n\tYour score is: " << score;
	}


	void guess_album() const override
	{
		questions_mode();
	}

	void guess_artist() const override
	{
		//	Here could be some implementation with image files
	}

	void guess_song() const override
	{
		questions_mode();
	}
};

static std::unique_ptr<Abstract_Music_Quiz_Factory> create(const int n)
{
	if (n == 1)
		return std::make_unique<Rock_Music_Level>();
	if (n == 2)
		return std::make_unique<Blues_Music_Level>();
}

void game(const std::unique_ptr<Abstract_Music_Quiz_Factory> temp)
{
	std::cout << "\tEnter:\n'1' for albums quiz\n'2' for artists quiz\n'3' for songs quiz\n";

	char ch{};
	std::cin >> ch;

	switch (ch)
	{
	case '1':
		temp->guess_album();
		break;
	case '2':
		temp->guess_artist();
		break;
	case '3':
		temp->guess_song();
		break;
	default:
		break;
	}
}

int main()
{
	srand(time(0));
	std::unique_ptr<Abstract_Music_Quiz_Factory> current_game = create(1);
	game(std::move(current_game));
}
