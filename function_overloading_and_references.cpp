///Week 5, Warm Up Exercise 8

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

//Function Protptype 1
vector<double> Quadratic_Eqn(int &a, int &b, int &c);
//Function Protptype 2
vector<double> Quadratic_Eqn(double &a, double &b, double &c);
//Function Protptype 3
void process_calculation(char selection);

//Function call
int main() {

	char Continue_Choice;

	do
	{
		int choice;
		cout << "Selection input type:\n";
		cout << "1. Integer\n";
		cout << "2. Double\n";
		cout << "Enter your choice (1 or 2): ";
		cin >> choice;

		process_calculation(choice);
	
		cout << "\nWould you like to continue? (Y/N)" << endl;
		cin >> Continue_Choice;

	} while (Continue_Choice == 'Y' || Continue_Choice == 'y');

	cout << "\nEnd of Program." << endl;

	return 0;
}

//Function Definition 1
vector<double> Quadratic_Eqn(int& a, int& b, int& c)
{
	double discriminant = ((b * b) - (4 * a * c));
	if (discriminant < 0)
	{
		cout << "Error - The discriminant (b^2 - 4ac) is less than 0" << endl;
		return {}; // return empty vector to indicate failure
	}

	double root1 = (-b + sqrt(discriminant)) / (2 * a);

	double root2 = (-b - sqrt(discriminant)) / (2 * a);

	return { root1, root2 };
}

//Function Definition 2
vector<double> Quadratic_Eqn(double& a, double& b, double& c)
{
	double discriminant = ((b * b) - (4 * a * c));
	if (discriminant < 0)
	{
		cout << "Error - The discriminant (b^2 - 4ac) is less than 0" << endl;
		return {}; // return empty vector to indicate failure
	}

	double root1 = (-b + sqrt(discriminant)) / (2 * a);

	double root2 = (-b - sqrt(discriminant)) / (2 * a);

	return { root1, root2 };
}

void process_calculation(char selection) {

	if (selection == 1)
	{
		int a, b, c;
		cout << "\nInput the values of a, b and c in the quadratic equation: ax^2 + bx + c = 0;" << endl;
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
		cout << "c = ";
		cin >> c;


		if (a != 0)
		{
			vector<double> roots = Quadratic_Eqn(a, b, c);
			if (!roots.empty())
			{
				cout << fixed << setprecision(2) << endl;
				cout << "Solution: x = " << roots[0] << " and x = " << roots[1] << endl;
			}

		}
		else
		{
			cout << "Error - cannot divide by zero" << endl;
		}
	}
	else if (selection == 2)
	{
		double a, b, c;
		cout << "\nInput the values of a, b and c in the quadratic equation: ax^2 + bx + c = 0" << endl;
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
		cout << "c = ";
		cin >> c;
		if (a != 0)
		{
			vector<double> roots = Quadratic_Eqn(a, b, c);
			if (!roots.empty())
			{
				cout << fixed << setprecision(2) << endl;
				cout << "Solution: x = " << roots[0] << " and x = " << roots[1] << endl;
			}
		}
		else
		{
			cout << "Error - cannot divide by zero" << endl;
		}
	}

}