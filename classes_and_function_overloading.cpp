// Warm Up exercise week 8 Q2 (as well as Q1)

#include <iostream>
#include <string>

using namespace std;

class student
{
private:
	string name;
	int rollNo;
	int total_marks;
	int year;

	//New attributes (Week 8 Q2-i)
	double mathMark;
	double computingMark;
	double physicsMark;

public:

	//Constructors (Week 8 Q1-ii)
	student();
	student(string Name);
	student(string Name, int Roll_Number);
	student(string Name, int Roll_Number, int Total_Marks);
	student(string Name, int Roll_Number, int Total_Marks, int Year);

	//Destructor
	~student();

	//Mutator/Setter Function for name (Week 8 Q1-iii)
	void setName(string Name);

	//Mutator/Setter Function for year (Week 8 Q1-iv)
	void setYear(int Year);

	//Getter Function (Week 8 Q1-i)
	void getDetails(void);

	//Print Function
	void putDetails(void);

	//Function for average mark calculation (Week 8 Q2-ii)
	double averageMark(void);

	//Function for Grade Mark (Week 8 Q2-iii)
	void gradeMark(int mathIn, int compIn, int physicsIn);

	//Function for Grade Mark (Week 8 Q2-iv)
	void gradeMark(int mark1, int mark2);
};

//------------Constructors (Week 8 Q1-ii)------------
student::student() : name(), rollNo(0), total_marks(0), year(0) {}
student::student(string Name) : name(Name), rollNo(0), total_marks(0), year(0) {}
student::student(string Name, int Roll_Number) : name(Name), rollNo(Roll_Number), total_marks(0), year(0) {}
student::student(string Name, int Roll_Number, int Total_Marks) : name(Name), rollNo(Roll_Number), total_marks(Total_Marks), year(0) {}
student::student(string Name, int Roll_Number, int Total_Marks, int Year) : name(Name), rollNo(Roll_Number), total_marks(Total_Marks), year(Year) {}

//------------Destructor------------
student::~student() {}

//------------Mutator/Setter Function for name (Week 8 Q1-iii)------------
void student::setName(string Name) { name = Name; }

//------------Mutator/Setter Function for year (Week 8 Q1-iv)------------
void student::setYear(int Year)
{
	if (Year > 4) {
		cout << "Student advised to leave the university" << endl;
	}
	else {
		year = Year;
	}
}

//------------Getter Function - getDetails (Week 8 Q1-i)------------
void student::getDetails(void)
{
	cout << "Name: " << name << endl;
	cout << "Roll Number: " << rollNo << endl;
	cout << "Total Marks: " << total_marks << endl;
	cout << "Year: " << year << endl;

}

//------------Print Function------------
void student::putDetails(void)
{
	string Tempoary_Name;
	int Temporary_RollNo;
	int Temporary_TotalMarks;
	int Temporary_Year;

	cout << "Enter the name: ";
	getline(cin >> ws, Tempoary_Name);

	cout << "Enter the roll number: ";
	cin >> Temporary_RollNo;

	cout << "Enter the Total Marks: ";
	cin >> Temporary_TotalMarks;

	cout << "Enter the Year: ";
	cin >> Temporary_Year;
	cout << endl;

	//Using existing setters for name and year
	setName(Tempoary_Name);
	setYear(Temporary_Year);

	//Direct assignment for member without setters
	rollNo = Temporary_RollNo;
	total_marks = Temporary_TotalMarks;
}

//------------Function for average mark calculation (Week 8 Q2-ii)------------
double student::averageMark(void)
{
	return (mathMark + computingMark + physicsMark) / 3.0;
}

//Function for Grade Mark (Week 8 Q2-iii)
void student::gradeMark(int mathIn, int compIn, int physicsIn)
{
	mathMark = mathIn;
	computingMark = compIn;
	physicsMark = physicsIn;

	double avg = averageMark();

	cout << "Average Mark: " << avg << endl;

	if (avg >= 70) {
		cout << "First-Class Honours" << endl;
	}
	else if (avg >= 60 && avg < 70) {
		cout << "Upper Second-Class Honours" << endl;
	}
	else if (avg >= 50 && avg < 60) {
		cout << "Lower Second-Class Honours" << endl;
	}
	else if (avg >= 40 && avg < 50) {
		cout << "Third-Class Honours " << endl;
	}
	else {
		cout << "U" << endl;
	}
}

//Function for Grade Mark (Week 8 Q2-iv)
void student::gradeMark(int mark1, int mark2)
{
	double avg = (mark1 + mark2) / 2.0;

	cout << "Average Mark: " << avg << endl;

	if (avg >= 70) {
		cout << "First-Class Honours" << endl;
	}
	else if (avg >= 60 && avg < 70) {
		cout << "Upper Second-Class Honours" << endl;
	}
	else if (avg >= 50 && avg < 60) {
		cout << "Lower Second-Class Honours" << endl;
	}
	else if (avg >= 40 && avg < 50) {
		cout << "Third-Class Honours " << endl;
	}
	else {
		cout << "U" << endl;
	}

}

//------------Main Function - Array of Student Objects (Week 8 Q1-v)------------
int main()
{
	//Array object
	student S[2];

	//Q1-v: Input details for 10 students using putDetails()
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter details for student " << (i + 1) << ":\n";
		S[i].putDetails(); //Q1-v: calls setName(), setYear(), etc
	}

	for (int i = 0; i < 2; i++)
	{
		cout << "\nDetails of the student " << (i + 1) << " are" << ":\n";
		//Q1-i: getDetails() prints name, roll number, total marks, year
		//Q1-ii: Also shows averageMark() in getDetails()
		S[i].getDetails();

		// Q2-iii: Grade classification for 3 subjects
		cout << "Grade based on 3 subjects:\n";
		S[i].gradeMark(75, 65, 70);

		// Q2-iv: Grade classification for 2 subjects overloaded
		cout << "Grade based on 2 subjects:\n";
		S[i].gradeMark(63, 86);
	}

	return 0;
}