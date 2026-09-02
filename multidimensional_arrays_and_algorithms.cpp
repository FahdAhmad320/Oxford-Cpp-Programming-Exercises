//Week 7 Warmup Exercise Q5

#include<iostream>

using namespace std;

//Global constant
const int N = 4;

//Function Prototype
bool isMagicSquare(int matrix[N][N]);

int main()
{

	int matrix1[N][N] = {
		{16, 9, 2, 7},
		{6, 3, 12, 13},
		{11, 14, 5, 5},
		{1, 8, 15, 10}
	};

	int matrix2[N][N] = {
	{16, 2, 3, 13},
	{5, 11, 10, 8},
	{9, 7, 6, 12},
	{4, 14, 15, 1}
	};

	if (isMagicSquare(matrix1))
		cout << "The matrix 1 is a magic square." << endl;
	else
		cout << "The matrix 1 is NOT a magic square." << endl;

	if (isMagicSquare(matrix2))
		cout << "The matrix 2 is a magic square." << endl;
	else
		cout << "The matrix 2 is NOT a magic square." << endl;

	return 0;
}

//Function Definition
bool isMagicSquare(int matrix[N][N]) {
	int sumDiagonal1 = 0, sumDiagonal2 = 0;

	// First Diagonal sum calculation
	for (int i = 0; i < N; i++)
	{
		sumDiagonal1 += matrix[i][i];
		sumDiagonal2 += matrix[i][N - i - 1];
	}

	// if the diagonal sums do not match, matrix is not a magic square
	if (sumDiagonal1 != sumDiagonal2)
		return false;

	// Sums of rows and columns
	for (int i = 0; i < N; i++)
	{
		int rowSum = 0, colSum = 0;
		for (int j = 0; j < N; j++)
		{
			rowSum += matrix[i][j];
			colSum += matrix[j][i];
		}

		if (rowSum != sumDiagonal1 || colSum != sumDiagonal1)
			return false;
	}

	return true;
}