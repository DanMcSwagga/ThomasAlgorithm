/*
 * [A] x = b
 * N = 10
 */

#include "Header.h"

// starts at 1
#define CURR_MOD 3
#define MOD_AMOUNT 3
using namespace std;

int main()
{
	constexpr int N = 10;
	double a[N - 1];
	double b[N];
	double c[N - 1];
	double d[N];
	double res[N];

	// array of [analytically] correct values
	double cor[N];
	for (int i = 0; i < N; i++)
		cor[i] = -0.4 - i * 0.1;

	// array of different modifiers variants
	double modif[MOD_AMOUNT];
	for (int i = 0; i < MOD_AMOUNT; i++)
		modif[i] = 1.0 * pow(10, -i);

	// 2d array of lhs of the system
	double** lhs = new double*[N];
	for (int i = 0; i < N; i++)
		lhs[i] = new double[3];
	readFromFile(N, lhs, "inputLHS.txt");

	// 2d array of different rhs variants of the system
	double** rhs = new double*[N];
	for (int i = 0; i < N; i++)
		rhs[i] = new double[MOD_AMOUNT];
	readFromFile(N, rhs, "inputRHS.txt");


	// Fill LHS diagonals a[], b[], c[] and RHS d[]
	for (int i = 0; i < N - 1; i++)
	{
		a[i] = lhs[i][0]; // under diagonal
		b[i] = lhs[i][1] * modif[CURR_MOD - 1]; // main diagonal
		c[i] = lhs[i][2]; // over diagonal
		d[i] = rhs[i][CURR_MOD - 1]; // rhs
	}
	b[N - 1] = lhs[N - 1][1]; // main diagonal
	d[N - 1] = rhs[N - 1][CURR_MOD - 1]; // rhs



	// Output lhs, rhs from file [temporary]
	cout << "Overall view [read from files] -- LHS | RHS:" << endl << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << setw(10) << lhs[i][j] << " ";
		}
		cout << " | ";
		for (int j = 0; j < 3; j++)
		{
			cout << setw(10) << rhs[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl << endl;
	// Output diagonal arrays [temporary]
	cout << "    a[]  ,     b[]  ,     c[]  ,     d[]" << endl << endl;
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1)
		{
			cout << setw(7) << a[i] << "  | ";
			cout << setw(7) << b[i] << "  | ";
			cout << setw(7) << c[i] << "  | ";
			cout << setw(7) << d[i] << " ";
			cout << endl;

		}
		else
		{
			cout << setw(7) << " - " << "  | ";
			cout << setw(7) << b[i] << "  | ";
			cout << setw(7) << " - " << "  | ";
			cout << setw(7) << d[i] << " ";
			cout << endl << endl << endl;

		}
	}


	// Main calculating method
	Thomas(N, a, b, c, d, res);


	// Output diagonal arrays [temporary]
	cout << "    a[]  ,     b[]  ,     c[]  ,     d[]" << endl << endl;
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1)
		{
			cout << setw(7) << a[i] << "  | ";
			cout << setw(7) << b[i] << "  | ";
			cout << setw(7) << c[i] << "  | ";
			cout << setw(7) << d[i] << " ";
			cout << endl;

		}
		else
		{
			cout << setw(7) << " - " << "  | ";
			cout << setw(7) << b[i] << "  | ";
			cout << setw(7) << " - " << "  | ";
			cout << setw(7) << d[i] << " ";
			cout << endl << endl << endl;

		}
	}


	// Output
	outputSingle(N, res, "Result:", 'X');
	outputSingle(N, cor, "Correct:", 'X');
	outputErrors(N, res, cor);


	cin.get();
	return 0;
}


void readFromFile(int N, double** matrix, string path)
{
	ifstream in;
	in.open(path);
	if (!in)
	{
		cout << "The destination " << path << " file was not opened." << endl;
		cin.get();
		return ;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			in >> matrix[i][j];
	in.close();
}

void outputSingle(int N, double* array, string intro, char symbol)
{
	cout << intro << endl << endl;
	for (int i = 0; i < N; i++)
	{
		cout << symbol << i + 1 << " = " << setw(10) << array[i] << " , ";
		if (i == 4) cout << endl;
	}
	cout << endl << endl << endl;
}

void outputErrors(int N, double* cor, double* res)
{
	cout << endl << "Absolute error:" << endl << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "A" << i + 1 << " = " << setw(10) << abs(cor[i] - res[i]) << " , ";
		if (i == 4) cout << endl;
	}
	cout << endl << endl << endl;

	cout << "Relative error (%):" << endl << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "E" << i + 1 << " = " << setw(10) << abs((cor[i] - res[i]) * 100 / res[i]) << "\%, ";
		if (i == 4) cout << endl;
	}
	cout << endl << endl << endl;
}



/*// Manual fill of values of LHS
for (int i = 0; i < N - 1; i++)
{
	a[i] = i * 0.1 + 0.4;
	b[i] = i * (-0.1) - 5.5;
	c[i] = i * 0.2 + 0.5;
}
b[N - 1] = -6.4;*/