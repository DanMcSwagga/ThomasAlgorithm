/*
 * [A] x = b
 * N = 10
 */

#include "Header.h"

#define CURR_MOD 0
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
		a[i] = lhs[i + 1][0]; // under diagonal -- first element is missing: [1; N-1]
		b[i] = lhs[i][1] * modif[CURR_MOD]; // main diagonal: [0; N-1]
		c[i] = lhs[i][2]; // over diagonal: [0; N-2]
		d[i] = rhs[i][CURR_MOD]; // rhs: [0; N-1]
	}
	b[N - 1] = lhs[N - 1][1]; // main diagonal
	d[N - 1] = rhs[N - 1][CURR_MOD]; // rhs



	Thomas(N, a, b, c, d, res);
	outputAll(N, res, cor, modif[CURR_MOD]);

	// refill arrays
	for (int i = 0; i < N; i++) // refill arrays to start over with different mod
	{
		b[i] = lhs[i][1] * modif[CURR_MOD + 1]; // main diagonal: [0; N-1]
		d[i] = rhs[i][CURR_MOD + 1]; // rhs: [0; N-1]
	}

	Thomas(N, a, b, c, d, res);
	outputAll(N, res, cor, modif[CURR_MOD + 1]);

	// refill arrays
	for (int i = 0; i < N; i++)
	{
		b[i] = lhs[i][1] * modif[CURR_MOD + 2]; // main diagonal: [0; N-1]
		d[i] = rhs[i][CURR_MOD + 2]; // rhs: [0; N-1]
	}

	Thomas(N, a, b, c, d, res);
	outputAll(N, res, cor, modif[CURR_MOD + 2]);


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



/*// Manual fill of values of LHS
for (int i = 0; i < N - 1; i++)
{
	a[i] = i * 0.1 + 0.4;
	b[i] = i * (-0.1) - 5.5;
	c[i] = i * 0.2 + 0.5;
}
b[N - 1] = -6.4;*/


/*// Output diagonal arrays [temporary]
cout << "       a[]        b[]        c[]  |        d[]" << endl << endl;
for (int i = 0; i < N; i++)
{
	if (i != N - 1)
	{
		cout << setw(10) << a[i] << " ";
		cout << setw(10) << b[i] << " ";
		cout << setw(10) << c[i] << "  | ";
		cout << setw(10) << d[i] << " ";
		cout << endl;

	}
	else
	{
		cout << setw(10) << " - " << " ";
		cout << setw(10) << b[i] << " ";
		cout << setw(10) << " - " << "  | ";
		cout << setw(10) << d[i] << " ";
		cout << endl << endl << endl;

	}
}*/


/*// Output lhs, rhs from file [temporary]
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
cout << endl << endl << endl;*/