#include "Header.h"

#include <iostream>
using namespace std;


void outputAll(int N, double* res, double* cor, double C)
{
	for (int i = 0; i < 95; i++) cout << '#';
	cout << endl;
	cout << "\t\t\t\t\t|C = " << C << '|' << endl << endl;
	outputSingle(N, res, "Result:", 'X');
	outputSingle(N, cor, "Correct:", 'X');
	outputErrors(N, res, cor);
}

void outputSingle(int N, double* array, string intro, char symbol)
{
	cout << intro << endl;
	for (int i = 0; i < N; i++)
	{
		cout << symbol << i + 1 << " = " << setw(11) << array[i] << " , ";
		if (i == 4) cout << endl;
	}
	cout << endl << endl << endl;
}

void outputErrors(int N, double* cor, double* res)
{
	cout << "Absolute error:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "A" << i + 1 << " = " << setw(11) << abs(cor[i] - res[i]) << " , ";
		if (i == 4) cout << endl;
	}
	cout << endl << endl << endl;

	cout << "Relative error (%):" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "E" << i + 1 << " = " << setw(11) << abs((cor[i] - res[i]) * 100 / res[i]) << "\%, ";
		if (i == 4) cout << endl;
	}
	cout << endl << endl << endl;
}