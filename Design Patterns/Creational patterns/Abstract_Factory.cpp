#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>

using namespace std;

class Albums
{
protected:
	Albums() {}
	virtual void print_albums() = 0;
public:
	vector<pair<string, string>> data_albums;
	virtual ~Albums() {};
};

class Artists
{
protected:
	Artists() {}
	virtual void print_artists() = 0;
public:
	vector<string> data_artists;
	virtual ~Artists() {};
};

class Songs
{
protected:
	Songs() {}
	virtual void print_songs() = 0;
public:
	vector<pair<string, string>> data_songs;
	virtual ~Songs() {};
};

class RockAlbums : public Albums
{
public:
	RockAlbums()
	{
		data_albums =
		{
			make_pair("AC/DC","Back In Black"), make_pair("AC/DC","Highway To Hell"),
			make_pair("The Beatles","Abbey Road"), make_pair("The Beatles","A Hard Day's Night"),
			make_pair("Black Sabbath","Paranoid"), make_pair("Chris Rea","Auberge"),
			make_pair("Guns N' Roses","Appetite For Destruction"), make_pair("Guns N' Roses","Use Your Illusion I"),
			make_pair("Led Zeppelin","IV"), make_pair("Lordi","The Arockalypse"),
			make_pair("Metallica","The Black Album"), make_pair("Metallica","Hardwired... to Self-destruct"),
			make_pair("Metallica","Ride The Lightning"), make_pair("Metallica","Reload"),
			make_pair("Motorhead","Ace of Spades"),	make_pair("Nirvana","Nevermind"),
			make_pair("Pink Floyd","The Dark Side of the Moon"), make_pair("Pink Floyd","The Wall"),
			make_pair("Pink Floyd","Wish You Were Here"), make_pair("Queen","A Night at the Opera"),
			make_pair("Radiohead","OK Computer"), make_pair("Rammstein","Mutter"),
			make_pair("Scorpions","Love at First Sting"), make_pair("Smokie","Midnight Cafe"), make_pair("System of a Down","Toxicity")
		};
	}
private:
	void print_albums() override
	{
		cout << "Rock Albums List\n";
		for (const auto& x : data_albums)
			cout << x.first << " - " << x.second << "\n";
	}
};

class BluesAlbums : public Albums
{
public:
	BluesAlbums()
	{
		data_albums =
		{
			make_pair("Albert Collins","Ice Pickin"), make_pair("Albert King", "Born Under a Bad Sign"),
			make_pair("B.B.King","Live at the Regal"), make_pair("Buddy Guy","I Was Walking Through the Woods"),
			make_pair("Buddy Guy","Sweet Tea"), make_pair("Chris Barber","Good Morning Blues"),
			make_pair("Chuck Berry","One Dozen Berrys"), make_pair("Cream","Wheels of Fire"),
			make_pair("Elmore James","Blues Master Works"),	make_pair("Elmore James","The Sky is Crying"),
			make_pair("Etta James", "At Last"), make_pair("Eric Clapton","From the Cradle"),
			make_pair("Eric Clapton & B.B. King", "Riding with the King"), make_pair("Etta James", "I'd Rather Go Blind"),
			make_pair("Gary Moore","Still Got The Blues"), make_pair("Howlin' Wolf","Moanin' in the Moonlight"),
			make_pair("Jimi Hendrix","Blues"), make_pair("John Lee Hooker", "It Serves You Right To Suffer"),
			make_pair("Johny Winter","Second Winter"), make_pair("Jonny Lang","Lie to Me"),
			make_pair("Jonny Lang","Wander This World"), make_pair("Muddy Waters","The Folk Singer"),
			make_pair("Muddy Waters","Hard Again"), make_pair("Robert Johnson","King of the Delta Blues Singers"),
			make_pair("Stevie Ray Vaughan","Texas Flood")
		};
	}

private:
	void print_albums() override
	{
		cout << "Blues Albums List\n";
		for (const auto& x : data_albums)
			cout << x.first << " - " << x.second << "\n";
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
		cout << "Rock Artists List\n";
		for (const auto& x : data_artists)
			cout << x << "\n";
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
		cout << "Blues Artists List\n";
		for (const auto& x : data_artists)
			cout << x << "\n";
	}
};

class RockSongs : public Songs
{
public:
	RockSongs()
	{
		data_songs =
		{
			make_pair("AC/DC","Hell's Bells"), make_pair("Aerosmith","Dream On"),
			make_pair("Black Sabbath", "Loner"), make_pair("The Beatles","Come Together"),
			make_pair("Blur","Song 2"), make_pair("Chris Rea","The Road to Hell"),
			make_pair("The Cranberries","Zombie"), make_pair("Creedence Clearwater Revival","Have You Ever Seen the Rain?"),
			make_pair("Deep Purple", "The Cut Runs Deep"), make_pair("Dio","Rainbow in the Dark"),
			make_pair("Europe","The Final Countdown"), make_pair("Foo Fighters","The Pretender"),
			make_pair("Guns N' Roses","Don't Cry"), make_pair("Led Zeppelin","Immigrant Song"),
			make_pair("Marylin Manson","Personsal Jesus"), make_pair("Metallica","For Whom the Bell Tolls"),
			make_pair("Motorhead","Overkill"), make_pair("Muse","Supermassive Black Hole"),
			make_pair("Pink Floyd","Time"), make_pair("Rammstein","Mein Herz Brennt"),
			make_pair("Scorpions","When the is Going Down"), make_pair("System of a Down","B.Y.O.B."),
			make_pair("Survivor","Eye of the Tiger"), make_pair("The White Stripes","Seven Nation Army"),
			make_pair("ZZ Top","Bad to the Bone")
		};
	}
private:
	void print_songs() override
	{
		cout << "Rock Songs List\n";
		for (const auto& x : data_songs)
			cout << x.first << " - " << x.second << "\n";
	}
};

class BluesSongs : public Songs
{
public:
	BluesSongs()
	{
		data_songs =
		{
			make_pair("Albert King","Born Under a Bad Sign"), make_pair("B.B. King","Sweet Little Angel"),
			make_pair("B.B. King","The Thrill Is Gone"), make_pair("Cream","Sunshine of Your Love"),
			make_pair("Etta James","All I Could Do Was Cryin"), make_pair("Etta James","At Last"),
			make_pair("Etta James","I'd Rather Go Blind"), make_pair("Howlin' Wolf","How Many More Years"),
			make_pair("John Lee Hooker","Boogie Chillin"), make_pair("John Lee Hooker","One Bourbon, One Scotch, One Beer"),
			make_pair("Jonny Lang","Lie To Me"), make_pair("Leadbelly","Where Did You Sleep Last Night?"),
			make_pair("Lightnin' Hopkins","Bring Me My Shotgun"), make_pair("Little Walter","My Babe"),
			make_pair("Lonnie Johnson","Too Late To Cry"), make_pair("Muddy Waters","Hoochie Coochie Man"),
			make_pair("Muddy Waters","Mannish Boy"), make_pair("Otis Rush","I Can't Quit You Baby"),
			make_pair("Robert Johnson","Crossroad Blues"), make_pair("Robert Johnson","Sweet Home Chicago"),
			make_pair("Robert Johnson","Travelling Riverside Blues"), make_pair("Roosevelt Skykes","Forty Four Blues"),
			make_pair("Son House","Pearline"), make_pair("T-Bone Walker","Stormy Monday"), make_pair("W.C. Handy","Memphis Blues")
		};
	}

private:
	void print_songs() override
	{
		cout << "Blues Songs List\n";
		for (const auto& x : data_songs)
			cout << x.first << " - " << x.second << "\n";
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
	Rock_Music_Level() { cout << "Rock Music Level Begins!\n"; }

	void survival_mode() const
	{
		bool status = 1;
		unique_ptr<Albums> albums = make_unique<RockAlbums>();

		cout << "\nLet's Start!\n";

		for (short i = 0; i < 10; ++i)
		{
			if (!status)
			{
				cout << "\tFalse!\t You Lose!";
				break;
			}

			short temp = rand() % albums->data_albums.size();

			set<string> st;
			st.insert(albums->data_albums[temp].first);

			while (st.size() != 4)
			{
				short t = rand() % albums->data_albums.size();
				st.insert(albums->data_albums[t].first);
			}

			cout << "\n" << i + 1 << ") '" << albums->data_albums[temp].second << "'\n\n";

			vector<pair<int, string>> pv(4);

			for (short i = 0; i < 4; ++i)
			{
				pv[i] = make_pair(i + 1, *st.begin());
				st.erase(st.begin());
			}

			for (auto x : pv)
				cout << x.first << ".  " << x.second << "\n";

			short answer;
			cin >> answer;

			for (short i = 0; i < 4; ++i)
			{
				if (pv[i].first == answer)
				{
					if (pv[i].second == albums->data_albums[temp].first)
					{
						cout << "\tRight!\n";
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
		cout << "Blues Music Level Begins!\n";
	}

	void questions_mode() const
	{
		unique_ptr<Albums> albums = make_unique<BluesAlbums>();

		unsigned score = 0;

		for (short i = 0; i < 10; ++i)
		{
			short temp = rand() % albums->data_albums.size();
			set<string> st;
			st.insert(albums->data_albums[temp].first);
			while (st.size() != 4)
			{
				short t = rand() % albums->data_albums.size();
				st.insert(albums->data_albums[t].first);
			}

			cout << "\n" << i + 1 << ") '" << albums->data_albums[temp].second << "'\n\n";

			vector<pair<int, string>> pv(4);

			for (short i = 0; i < 4; ++i)
			{
				pv[i] = make_pair(i + 1, *st.begin());
				st.erase(st.begin());
			}

			for (auto x : pv)
				cout << x.first << ".  " << x.second << "\n";

			bool b = 0;
			short answer;
			cin >> answer;

			for (short i = 0; i < 4; ++i)
			{
				if (pv[i].first == answer)
				{
					if (pv[i].second == albums->data_albums[temp].first)
					{
						cout << "\tRight!\n";
						++score;
						break;
					}
					else
						cout << "\tFalse!\n";
				}
			}
			albums->data_albums.erase(albums->data_albums.begin() + temp);
		}
		cout << "\n\tYour score is: " << score;
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

static unique_ptr<Abstract_Music_Quiz_Factory> create(const int n)
{
	if (n == 1)
		return make_unique<Rock_Music_Level>();
	if (n == 2)
		return make_unique<Blues_Music_Level>();
}

void game(const unique_ptr<Abstract_Music_Quiz_Factory> temp)
{
	cout << "\tEnter:\n'1' for albums quiz\n'2' for artists quiz\n'3' for songs quiz\n";

	char ch;
	cin >> ch;

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
	unique_ptr<Abstract_Music_Quiz_Factory> current_game = create(1);
	game(std::move(current_game));
}