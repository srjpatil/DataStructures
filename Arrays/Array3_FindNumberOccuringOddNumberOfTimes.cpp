#include<iostream>

using namespace std;

int getOddOccurrence(int *arr, int size)
{
	int i, result = 0;

	for (i = 0; i < size; i++)
		result ^= arr[i];

	return result;
}

int main()
{
	int ar[] = { 2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2 };
	int n = sizeof(ar) / sizeof(ar[0]);
	
	cout << getOddOccurrence(ar, n) << endl;
	return 0;
}