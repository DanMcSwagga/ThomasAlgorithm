/*
 * [A] x = b
 * N = 10
 */

#include "Header.h"
using namespace std;

int main()
{
	int N = 10;
	double* d = new double[N];

	double** lhs = new double*[N];
	for (int i = 0; i < N; i++)
		lhs[i] = new double[3];

	double** rhs = new double*[N];
	for (int i = 0; i < N; i++)
		rhs[i] = new double[3];

	double c[3] = { 1.0, 0.1, 0.001 };


	// Read LHS and RHS from files
	ReadFromFile(lhs, N, "inputLHS.txt");
	ReadFromFile(rhs, N, "inputRHS.txt");

	// Modify LHS with c
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			if ((i == 0 && j == 0) ||
				(i != 0 && i != (N - 1) && j == 1) ||
				(i == N - 1 && j == N - 1))
				lhs[i][j] = c[0] * lhs[i][j];
	


	// Output
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


	cin.get();
	return 0;
}


void ReadFromFile(double** matrix, int N, string path)
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

//void Output()
//{
//	//cout << setprecision(12);
//
//	// step
//	cout << "H = " << h << endl << endl;
//
//	// header
//	cout << " Xk              " << left << endl;
//	for (int i = 0; i < 100; i++) cout << "-"; // header line
//	cout << endl;
//
//	// body
//	for (int it = 0; it < N; it++)
//	{
//		cout << " " << setw(16) << xk[it] << " | " << endl;
//	}
//}