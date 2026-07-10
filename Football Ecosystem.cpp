#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// ================= PLAYER BASE CLASS =================
class Player
{
protected:
    string name;
    int age;
    string nationality;
    int matchesPlayed;
    int goals;
    int assists;

public:
    Player(string n, int a, string nat)
    {
        name = n;
        age = a;
        nationality = nat;
        matchesPlayed = 0;
        goals = 0;
        assists = 0;
    }

    string getName()
    {
        return name;
    }

    int getGoals()
    {
        return goals;
    }

    int getPerformance()
    {
        return goals * 4 + assists * 2;
    }

    void addGoal()
    {
        goals++;
    }

    void addAssist()
    {
        assists++;
    }

    void addMatch()
    {
        matchesPlayed++;
    }

    virtual void displayStats()
    {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nNationality: " << nationality;
        cout << "\nMatches: " << matchesPlayed;
        cout << "\nGoals: " << goals;
        cout << "\nAssists: " << assists << endl;
    }

    bool operator>(Player &p)
    {
        return getPerformance() > p.getPerformance();
    }

    friend ostream &operator<<(ostream &out, Player &p);

    virtual ~Player() {}
};

ostream &operator<<(ostream &out, Player &p)
{
    out << "\n--------------------";
    out << "\nName: " << p.name;
    out << "\nGoals: " << p.goals;
    out << "\nAssists: " << p.assists;
    return out;
}

// ================= GOALKEEPER =================
class Goalkeeper : public Player
{
private:
    int cleanSheets;

public:
    Goalkeeper(string n, int a, string nat)
        : Player(n, a, nat)
    {
        cleanSheets = 0;
    }

    void displayStats()
    {
        cout << "\n=== GOALKEEPER ===";
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nNationality: " << nationality;
        cout << "\nMatches: " << matchesPlayed;
        cout << "\nGoals: " << goals;
        cout << "\nAssists: " << assists;
        cout << "\nClean Sheets: " << cleanSheets << endl;
    }
};

// ================= DEFENDER =================
class Defender : public Player
{
private:
    int tackles;

public:
    Defender(string n, int a, string nat)
        : Player(n, a, nat)
    {
        tackles = 0;
    }

    void displayStats()
    {
        cout << "\n=== DEFENDER ===";
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nNationality: " << nationality;
        cout << "\nMatches: " << matchesPlayed;
        cout << "\nGoals: " << goals;
        cout << "\nAssists: " << assists;
        cout << "\nTackles: " << tackles << endl;
    }
};

// ================= MIDFIELDER =================
class Midfielder : public Player
{
public:
    Midfielder(string n, int a, string nat)
        : Player(n, a, nat)
    {
    }

    void displayStats()
    {
        cout << "\n=== MIDFIELDER ===";
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nNationality: " << nationality;
        cout << "\nMatches: " << matchesPlayed;
        cout << "\nGoals: " << goals;
        cout << "\nAssists: " << assists << endl;
    }
};

// ================= STRIKER =================
class Striker : public Player
{
public:
    Striker(string n, int a, string nat)
        : Player(n, a, nat)
    {
    }

    void displayStats()
    {
        cout << "\n=== STRIKER ===";
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nNationality: " << nationality;
        cout << "\nMatches: " << matchesPlayed;
        cout << "\nGoals: " << goals;
        cout << "\nAssists: " << assists << endl;
    }
};

// ================= COACH =================
class Coach
{
private:
    string name;
    int experience;

public:
    Coach(string n, int e)
    {
        name = n;
        experience = e;
    }

    void display()
    {
        cout << "\nCoach: " << name;
        cout << "\nExperience: " << experience << " Years\n";
    }
};

// ================= CLUB =================
class Club
{
private:
    string name;
    string country;
    Coach coach;

    Player *players[50];
    int totalPlayers;

public:
    Club(string n, string c, Coach co)
        : coach(co)
    {
        name = n;
        country = c;
        totalPlayers = 0;
    }

    string getName()
    {
        return name;
    }

    void addPlayer(Player *p)
    {
        if (totalPlayers < 50)
        {
            players[totalPlayers] = p;
            totalPlayers++;
        }
    }

    void displayClubInfo()
    {
        cout << "\nClub Name: " << name;
        cout << "\nCountry: " << country;
        cout << "\nTotal Players: " << totalPlayers << endl;
    }

    void displayPlayers()
    {
        displayClubInfo();
        coach.display();

        for (int i = 0; i < totalPlayers; i++)
        {
            (*players[i]).displayStats();
        }
    }
};

// ================= NATIONAL TEAMS =================
class NationalTeam
{
public:
    void display()
    {
        cout << "\n========== FIFA WORLD NATIONAL TEAMS ==========\n";

        cout << "\n1. Argentina";
        cout << "\n   Captain: Lionel Messi";
        cout << "\n   FIFA Ranking: 1";
        cout << "\n   World Cups: 3";

        cout << "\n\n2. France";
        cout << "\n   Captain: Kylian Mbappe";
        cout << "\n   FIFA Ranking: 2";
        cout << "\n   World Cups: 2";

        cout << "\n\n3. Brazil";
        cout << "\n   Captain: Vinicius Jr";
        cout << "\n   FIFA Ranking: 5";
        cout << "\n   World Cups: 5";

        cout << "\n\n4. England";
        cout << "\n   Captain: Harry Kane";
        cout << "\n   FIFA Ranking: 4";
        cout << "\n   World Cups: 1";

        cout << "\n\n5. Portugal";
        cout << "\n   Captain: Cristiano Ronaldo";
        cout << "\n   FIFA Ranking: 7";
        cout << "\n   World Cups: 0";

        cout << "\n\n6. Spain";
        cout << "\n   Captain: Alvaro Morata";
        cout << "\n   FIFA Ranking: 8";
        cout << "\n   World Cups: 1";

        cout << "\n\n7. Germany";
        cout << "\n   Captain: Ilkay Gundogan";
        cout << "\n   FIFA Ranking: 3";
        cout << "\n   World Cups: 4";

        cout << "\n\n8. Belgium";
        cout << "\n   Captain: Kevin De Bruyne";
        cout << "\n   FIFA Ranking: 6";
        cout << "\n   World Cups: 0";

        cout << "\n\n9. Netherlands";
        cout << "\n   Captain: Virgil Van Dijk";
        cout << "\n   FIFA Ranking: 9";
        cout << "\n   World Cups: 0";

        cout << "\n\n10. Croatia";
        cout << "\n    Captain: Luka Modric";
        cout << "\n    FIFA Ranking: 10";
        cout << "\n    World Cups: 0";

        cout << endl;
    }
};

// ================= ACADEMY =================
class Academy
{
public:
    void display()
    {
        cout << "\n========== FOOTBALL ACADEMY ==========\n";
        cout << "\nPlayer Name            Age     Position       Potential";
        cout << "\n---------------------------------------------------------";
        cout << "\nLamine Yamal            17      Winger            95";
        cout << "\nEndrick                 18      Striker           94";
        cout << "\nEstevao Willian         17      Winger            93";
        cout << "\nArda Guler              19      Midfielder        92";
        cout << "\nWarren Zaire            18      Midfielder        91";
        cout << "\nPau Cubarsi             18      Defender          91";
        cout << "\nKobbie Mainoo           19      Midfielder        90";
        cout << "\nEthan Nwaneri           17      Midfielder        89";
        cout << "\nAlejandro Garnacho      20      Winger            89";
        cout << "\nYoussoufa Moukoko       20      Striker           88";
        cout << endl;
    }
};

// ================= MATCH SIMULATION =================
class Match
{
public:
    void simulate()
    {
        cout << "\n========== FIFA WORLD CUP RESULTS ==========\n";

        cout << "\n--- Round of 16 ---\n";
        cout << "\nArgentina    2 - 0   Australia";
        cout << "\nFrance       3 - 1   Poland";
        cout << "\nBrazil       4 - 1   South Korea";
        cout << "\nEngland      3 - 0   Senegal";
        cout << "\nPortugal     6 - 1   Switzerland";
        cout << "\nNetherlands  3 - 1   USA";
        cout << "\nCroatia      1 - 0   Japan";
        cout << "\nMorocco      0 - 0   Spain    (3-0 Pen)";

        cout << "\n\n--- Quarter Finals ---\n";
        cout << "\nArgentina    2 - 1   Netherlands";
        cout << "\nFrance       2 - 1   England";
        cout << "\nCroatia      1 - 1   Brazil   (4-2 Pen)";
        cout << "\nMorocco      1 - 0   Portugal";

        cout << "\n\n--- Semi Finals ---\n";
        cout << "\nArgentina    3 - 0   Croatia";
        cout << "\nFrance       2 - 0   Morocco";

        cout << "\n\n--- Final ---\n";
        cout << "\nArgentina    3 - 3   France";
        cout << "\nArgentina won 4-2 on penalties";

        cout << "\n\nWinner: Argentina" << endl;
    }
};

// ================= PLAYER COMPARISON =================
class PlayerComparison
{
public:
    void compare()
    {
        cout << "\n========== PLAYER COMPARISON ==========\n";
        cout << "\nPlayer                Goals     Assists";
        cout << "\n----------------------------------------";
        cout << "\nLionel Messi           821        361";
        cout << "\nCristiano Ronaldo      895        257";

        cout << "\n\nWorld Cups";
        cout << "\nMessi      : 1";
        cout << "\nRonaldo    : 0";

        cout << "\n\nBallon d'Or";
        cout << "\nMessi      : 8";
        cout << "\nRonaldo    : 5";

        cout << "\n\nChampions League";
        cout << "\nMessi      : 4";
        cout << "\nRonaldo    : 5";

        cout << "\n\nResult:";
        cout << "\nMessi leads in Ballon d'Ors and World Cup titles.";
        cout << "\nRonaldo leads in goals and Champions League titles." << endl;
    }
};

// ================= HELPER: read a valid integer from cin =================
// Returns true if a valid integer was read, false if input was non-numeric.
// On failure it clears the error flag and flushes the bad input.
bool readInt(int &value)
{
    if (!(cin >> value))
    {
        cout << "\nInvalid Input! Please enter a number.";
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

// ================= MAIN =================
int main()
{
    srand(time(NULL));

    // ----- coaches -----
    Coach pep("Pep Guardiola", 20);
    Coach ancelotti("Carlo Ancelotti", 25);

    // ----- clubs -----
    Club city("Manchester City", "England", pep);
    Club madrid("Real Madrid", "Spain", ancelotti);

    // ----- Manchester City players -----
    Striker    haaland  ("Erling Haaland",   24, "Norway");
    Midfielder debruyne ("Kevin De Bruyne",  33, "Belgium");
    Defender   ruben    ("Ruben Dias",        28, "Portugal");
    Goalkeeper ederson  ("Ederson",           31, "Brazil");

    haaland.addGoal();   haaland.addGoal();   haaland.addAssist();
    debruyne.addGoal();  debruyne.addAssist(); debruyne.addAssist();

    city.addPlayer(&haaland);
    city.addPlayer(&debruyne);
    city.addPlayer(&ruben);
    city.addPlayer(&ederson);

    // ----- Real Madrid players -----
    Striker    vinicius  ("Vinicius Jr",      24, "Brazil");
    Midfielder bellingham("Jude Bellingham",  21, "England");
    Defender   militao   ("Eder Militao",     26, "Brazil");
    Goalkeeper courtois  ("Thibaut Courtois", 32, "Belgium");

    vinicius.addGoal();   vinicius.addGoal();   vinicius.addGoal();
    vinicius.addAssist(); vinicius.addAssist();
    bellingham.addGoal(); bellingham.addGoal(); bellingham.addAssist();

    madrid.addPlayer(&vinicius);
    madrid.addPlayer(&bellingham);
    madrid.addPlayer(&militao);
    madrid.addPlayer(&courtois);

    // ----- other objects -----
    NationalTeam    nationalTeams;
    Academy         academy;
    Match           worldCup;
    PlayerComparison comparison;

    int choice;

    do
    {
        // ---- print main menu ----
        cout << "\n\n========== FOOTBALL ECOSYSTEM ==========";
        cout << "\n1. Clubs";
        cout << "\n2. National Teams";
        cout << "\n3. Academy";
        cout << "\n4. FIFA World Cup Simulation";
        cout << "\n5. Compare Players";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";

        // ---- validate main menu input ----
        if (!readInt(choice))
        {
            continue;  
        }

        switch (choice)
        {
        case 1:
        {
            // ---- clubs sub-menu ----
            int clubChoice;

            cout << "\n===== CLUBS =====";
            cout << "\n1. Manchester City";
            cout << "\n2. Real Madrid";
            cout << "\nEnter Choice: ";

            // validate club sub-menu input
            if (!readInt(clubChoice))
            {
                break;  // go back to main menu on bad input
            }

            if (clubChoice == 1)
                city.displayPlayers();
            else if (clubChoice == 2)
                madrid.displayPlayers();
            else
                cout << "\nInvalid Choice! Please enter 1 or 2.";

            break;
        }

        case 2:
            nationalTeams.display();
            break;

        case 3:
            academy.display();
            break;

        case 4:
            worldCup.simulate();
            break;

        case 5:
            comparison.compare();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please enter a number between 1 and 6.";
        }

    } while (choice != 6);

    return 0;
}
