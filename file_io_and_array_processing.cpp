//Warm Up Exercise Week 4 Q2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	fstream outFile;
	string outputFileName = "Text File for Warm Up Exercise Week 4";

	string file_inputs[10];

	cout << "Enter a series of 10 inputs:\n";
	for (int i = 0; i < 10; i++) {
		cout << "Input " << (i + 1) << ": ";
		getline(cin, file_inputs[i]);
	}

	//outFile.open(outputFileName);
	outFile.open(outputFileName, ios::out);

	if (outFile.is_open()) 
	{
		for (int i = 0; i < 10; i++) 
		{
			outFile << "File input " << (i + 1) << ": " << file_inputs[i] << endl;
		}
		
		outFile.close();
	} 
	else 
	{
		cout << "Could not create file: " << outputFileName << endl;
	}

	return 0;
}