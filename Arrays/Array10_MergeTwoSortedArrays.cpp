#include<iostream>

using namespace std;

#define NA -1

void moveToEnd(int *arr, int size)
{
	int i, j = size - 1;
	for (i = size - 1; i >= 0; i--)
	{
		if (arr[i] != NA)
		{
			arr[j] = arr[i];
			j--;
		}
	}
}

void merge(int *mPlusN, int *N, int m, int n)
{
	int i = n;//current index of i/p part of mPlusN[]
	int j = 0; //current index of N[]
	int k = 0;

	while (k < (m + n))
	{
		if ((i < (m + n) && mPlusN[i] <= N[j]) || (j == n))
		{
			mPlusN[k] = mPlusN[i];
			i++;
			k++;
		}
		else
		{
			mPlusN[k] = N[j];
			j++;
			k++;
		}
	}
}

void printArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int main()
{
	int mPlusN[] = { 2, 8, NA, NA, NA, 13, NA, 15, 20 };
	int N[] = { 5, 7, 9, 25 };
	int n = sizeof(N) / sizeof(N[0]);
	int m = sizeof(mPlusN) / sizeof(mPlusN[0]) - n;

	/*Move the m elements at the end of mPlusN*/
	moveToEnd(mPlusN, m + n);

	/*Merge N[] into mPlusN[] */
	merge(mPlusN, N, m, n);

	/* Print the resultant mPlusN */
	printArray(mPlusN, m + n);
}