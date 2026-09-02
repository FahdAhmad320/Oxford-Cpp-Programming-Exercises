//Week 6, Warm Up Exercise 5

#include <iostream>
#include <iomanip>

using namespace std;


class complex
{
//class attributes
private:
	double a;
	double b;

public:

	//Constructors
	complex();
	complex(double real, double imj);

	//destructor
	~complex();

	//getters
	double get_real() const;
	double get_img() const;

	//setters
	void set_real(double real);
	void set_img(double img);

	//Display method
	void Display() const;

	//Add method
	complex operator+(const complex& other) const;

	//Subtraction method
	complex operator-(const complex& other) const;

	//multiplication method
	complex operator*(const complex& other) const;

	//Division method
	complex operator/(const complex& other) const;
};

//Constructors
complex::complex(): a(0.0), b(0.0) {}
complex::complex(double real, double imj): a(real), b(imj) {}

//destructor
complex::~complex() {}

//getters
double complex::get_real() const { return a; }
double complex::get_img() const { return b; }

//setters
void complex::set_real(double real) { a = real; }
void complex::set_img(double img) { b = img; }

//Display method
void complex::Display() const
{
	cout << a;
	if (b >= 0)
		cout << " + " << b << "i" << endl;
	else
		cout << " - " << -b << "i" << endl;
}

//Add method
complex complex::operator+(const complex& other) const {
	return complex(a + other.a, b + other.b);
}

//Subtraction method
complex complex::operator-(const complex& other) const
{
	return complex(a - other.a, b - other.b);
}

//Multiplication method
complex complex::operator*(const complex& other) const
{
	double real = (a * other.a) - (b * other.b);
	double imj = (a * other.b) + (b * other.a);
	return complex(real, imj);
}

//Division method
complex complex::operator/(const complex& other) const
{
	double real = ((a * other.a) + (b * other.b)) / ((other.a * other.a) + (other.b * other.b));
	double imj = ((b * other.a) - (a * other.b)) / ((other.a * other.a) + (other.b * other.b));
	return complex(real, imj);
}

int main()
{
	//complex number objects
	complex C1(4, -3);
	complex C2(2, 7);

	//complex number function calls for all 4 operations
	complex C_ADD = C1 + C2;
	complex C_SUB = C1 - C2;
	complex C_MUL = C1 * C2;
	complex C_DIV = C1 / C2;

	cout << "C1 = ";
	C1.Display();
	
	cout << "C2 = ";
	C2.Display();

	cout << "C_ADD = C1 + C2 = ";
	C_ADD.Display();
	
	cout << "C_SUB = C1 - C2 = ";
	C_SUB.Display();

	cout << "C_MUL = C1 * C2 = ";
	C_MUL.Display();

	cout << "C_DIV = C1 / C2 = ";
	C_DIV.Display();

	return 0;
}