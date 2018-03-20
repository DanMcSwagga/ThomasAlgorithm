#include "Header.h"

#include <iostream>

void Thomas(int N, double* a, double* b, double* c, double* d, double* res)
{
	for (int i = 1; i < N; i++)
	{
		b[i] = b[i] - a[i] * c[i - 1] / b[i - 1];
		d[i] = d[i] - a[i] * d[i - 1] / b[i - 1];
	}
	res[N - 1] = d[N - 1] / b[N - 1];
	for (int i = N - 2; i > 0; i--)
	{
		res[i] = (d[i] - c[i] * res[i + 1]) / b[i];
	}

	return;
}