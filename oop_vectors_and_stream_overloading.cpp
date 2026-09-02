// Warm Up exercises week 9 Q2

#include <iostream>
#include <iomanip>
#include <string>
#include<vector>

using namespace std;

class BankAccount
{
	friend std::ostream& operator<<(std::ostream& os, const BankAccount& account);
private:
	string name;
	string IDNumber;
	double Amount;

public:
	//----------Constructors----------
	BankAccount();
	BankAccount(string Acc_Name, string Acc_ID_no);
	BankAccount(string Acc_Name, string Acc_ID_no, double initial_amount);

	//----------Destructor----------
	~BankAccount();

	//----------Deposit Function----------
	void deposit(double amount);

	//----------Withdraw Function----------
	void withdraw(double amount);

	//----------Account Transfer Function----------
	void account_transfer(double amount, BankAccount &account);

	//----------Print Balance Function----------
	void Print_Balance() const;

	//----------Interest Calc Function----------
	double calc_interest(double amount, double percent);

	//----------Getters----------
	double getBalance() const;
	void getDetails() const;
};

//----------Friend function----------
ostream& operator<<(ostream& os, const BankAccount& account) {
	os << "[Account Name   : " << account.name << "]" << '\n'
	   << "[Account Number : " << account.IDNumber << "]" << '\n'
	   << "[Account Balance: GBP " << account.Amount << "]" << '\n';
	return os;
}

//----------Constructors----------
BankAccount::BankAccount() 
	: name("Unnamed"), IDNumber("No Number"), Amount(0.0) { }
BankAccount::BankAccount(string Acc_Name, string Acc_ID_no) 
	: name(Acc_Name), IDNumber(Acc_ID_no), Amount(0.0) { }
BankAccount::BankAccount(string Acc_Name, string Acc_ID_no, double initial_amount)
	: name(Acc_Name), IDNumber(Acc_ID_no), Amount(initial_amount) { }
	
//----------Destructor----------
BankAccount::~BankAccount() { }

//----------Deposit Function----------
void BankAccount::deposit(double amount) {
	if (amount > 0) {
		Amount += amount;
		cout << "Deposited GBP " << amount << " to account" << IDNumber << endl;
	}
	else {
		cout << "Invalid deposit amount.\n" << endl;
	}
}

//----------Withdraw Function----------
void BankAccount::withdraw(double amount) {
	if (amount <= Amount && amount > 0) {
		Amount -= amount;
		cout << "Withdrew GBP " << amount << " from account" << IDNumber << endl;
	}
	else {
		cout << "Insufficient Funds.\n" << endl;
	}
}

//----------Account Transfer Function----------
void BankAccount::account_transfer(double amount, BankAccount& account) {
	if (amount <= Amount && amount > 0) {
		Amount -= amount;
		account.Amount += amount;
		cout << "Transferred GBP " << amount << " to account " << account.IDNumber << endl;
	}
	else {
		cout << "Account Transfer not possible due to insufficient funds.\n" << endl;
	}
}

//----------Print Balance Function----------
void BankAccount::Print_Balance() const {
	cout << "Balance of Account " << IDNumber << ": GBP " << Amount << endl;
}

//----------Interest Calc Function----------
double BankAccount::calc_interest(double amount, double percent){
	if (percent < 0) return 0;
	return amount * (percent / 100.0);
}

//----------Getters----------
void BankAccount::getDetails() const {
	cout << "Account Name: " << name << endl;
	cout << "Account Number: " << IDNumber << endl;
	cout << "Account Balance: " << Amount << endl;
}
double BankAccount::getBalance() const {
	return Amount;
}

//----------Driver Program (int main)----------
int main() {

	cout.precision(2);
	cout << fixed;

	//vector object of 3 elements
	vector<BankAccount> bank_accounts;
	bank_accounts.push_back(BankAccount{}); // unnamed
	bank_accounts.push_back(BankAccount{ "Lewis", "20022002" }); //2 argument constructor
	bank_accounts.push_back(BankAccount{ "Mark", "30033003", 2000 }); //3 argument constructor
	bank_accounts.push_back(BankAccount{ "Chris", "40044004", 5000 }); //3 argument constructor

	// range based for loop through accounts vector and call up class member functions
	for (size_t i = 0; i < bank_accounts.size(); ++i) {
		cout << "\n==========================================\n" << endl;
		cout << "Account #" << i + 1 << " Details (invoke friend function):\n";
		cout << bank_accounts[i];

		cout << "\nDepositing GBP 1000 (In Progress):\n";
		bank_accounts[i].deposit(1000);

		cout << "Withdrawing GBP 300 (In Progress):\n";
		bank_accounts[i].withdraw(300);

		cout << "Printing balance (In Progress):\n";
		bank_accounts[i].Print_Balance();

		cout << "Interest (6.75% on current balance): GBP "
			<< bank_accounts[i].calc_interest(bank_accounts[i].getBalance(), 6.75) << "\n";
	}

	cout << "\n==========================================\n" << endl;
	cout << "Demonstrating Transfer GBP 250 (Lewis to Chris)...\n";

	// Transfer from index 1 to 3 (Lewis to Chris)
	bank_accounts[1].account_transfer(250, bank_accounts[3]);

	// Account Details Post Transfer
	cout << "\nUpdated Accounts:\n";
	cout << bank_accounts[1];
	cout << bank_accounts[3];
	cout << "\n==========================================\n" << endl;

	return 0;


}