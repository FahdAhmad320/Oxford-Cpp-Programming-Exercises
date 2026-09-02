// Warm Up exercises week 9 Q4

#include <iostream>

using namespace std;

class Sports_Person {
private:
	string Name;
	int Age;
	int Wins;

protected:
	//----------Constructors----------
	Sports_Person(): Name("No Name"), Age(0), Wins(0) { }
	Sports_Person(const string &name, int age, int wins) : Name(name), Age(age), Wins(wins) { }

	//----------Getters----------
	int getAge() const { return Age; }
	int getWins() const { return Wins; }
	string getName() const { return Name;  }
	string getStatus() const {
		if (Wins >= 10) { 
			return "Pro Athlete"; }
		else { 
			return "Amatuer Athlete"; }
	}

public:
	//----------Destructor----------
	virtual ~Sports_Person() {}

	//----------Display Function----------
	virtual void Display() const {
		cout << "Name: " << Name << endl;
		cout << "Age: " << Age << endl;
		cout << "Wins: " << Wins << endl;
		cout << "Status: " << getStatus() << endl;
	}

	//----------Add Win Function----------
	virtual void Add_Win() { Wins++; }
};

class Tennis_Player :public Sports_Person {
private:
	string Racket_Type;

public:
	//----------Constructors----------
	Tennis_Player() : Racket_Type("No Type") { }
	Tennis_Player(const string &name, int age, int wins, const string &racket_type) : Sports_Person(name, age, wins), Racket_Type(racket_type) { }

	//----------Destructor----------
	~Tennis_Player() {}

	//----------Override Display Function----------
	void Display() const override {
		cout << "Tennis Player Details:" << endl;
		Sports_Person::Display();
		cout << "Racket Type: " << Racket_Type << endl;
	}

	void skill_level() const {
		cout << getName() << " serves with racket type " << Racket_Type << "!" << endl;
	}

	void rounds() {
		cout << getName() << " has won this round using the racket type " << Racket_Type << endl;
		Add_Win();
	}
};

class Football_Player :public Sports_Person {
private:
	string pitch_position;

public:
	//----------Constructors----------
	Football_Player() : pitch_position("No Position Declared") {}
	Football_Player(const string& name, int age, int wins, const string& pos) : Sports_Person(name, age, wins), pitch_position(pos) {}

	//----------Destructor----------
	~Football_Player() {}

	//----------Override Display Function----------
	void Display() const override {
		cout << "Football Player Details:" << endl;
		Sports_Person::Display();
		cout << "Football Pitch Position: " << pitch_position << endl;
	}

	void Goal_Score() {
		cout << getName() << " scored a goal as a " << pitch_position << "!" << endl;
		Add_Win();
	}

};

int main() {
	Tennis_Player TP("Federer", 35, 10, "Power Racket");
	Football_Player FP("Ronaldo", 40, 5, "Striker");



	cout << "\n=====================Tennis Player=====================\n" << endl;

	TP.skill_level();
	TP.rounds();
	TP.Add_Win();
	TP.Display();

	cout << "\n=====================Football Player=====================\n" << endl;

	FP.Goal_Score();
	FP.Add_Win();
	FP.Display();

}