#include "Header.h"

void Thomas(int N, double* a, double* b, double* c, double* d, double* T)
{
	double m;
	for (int i = 1; i < N; i++)
	{
		m = a[i - 1] / b[i - 1];
		b[i] = b[i] - m * c[i - 1];
		d[i] = d[i] - m * d[i - 1];
	}

	T[N - 1] = d[N - 1] / b[N - 1];

	for (int i = N - 2; i >= 0; i--)
	{
		T[i] = (d[i] - c[i] * T[i + 1]) / b[i];
	}

	return;
}