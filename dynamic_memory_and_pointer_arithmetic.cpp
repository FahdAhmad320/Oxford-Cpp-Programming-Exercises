//Week 7 Warmup Exercise Q7

#include <iostream>

using namespace std;

int main()
{
	int n;

	//user input for array size
	cout << "Enter the size of the array: ";
	cin >> n;

	//dynamic memory allocation for array of size n
	int* arr = new int[n];

	//Input elements from user
	cout << "Enter " << n << " Integers: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//Use pointer arithmetic and while loop to print array elements
	int* ptr = arr;
	int* end = arr + n;
	int index = 0;

	cout << "Array elements using pointer arithmetic:\n";
	while (ptr < end)
	{
		cout << "Element " << index << " = " << *ptr << endl;
		ptr++;
		index++;
	}

	//Free dynamically allocated memory
	delete[] arr;

	return 0;
}

