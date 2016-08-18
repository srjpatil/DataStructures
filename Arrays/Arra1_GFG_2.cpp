#include<iostream>
#include<algorithm>

#define MAX 100000

using namespace std;

void printPairs(int *A, int size, int sum)
{
	int i, temp;
	int binMap[MAX] = { 0 };

	for (i = 0; i < size; i++)
	{
		temp = sum - A[i];

		if (temp >= 0 && binMap[temp] == 1)
			cout << "Pair with given sum " << sum << " is " << A[i] << " and " << temp << endl;

		binMap[A[i]] = 1;
	}

}

int main()
{
	int A[] = {1, 4, 5, 6, 10, 8};
	int sum = 16;
	int size = sizeof(A) / sizeof(A[0]);

	printPairs(A, size, sum);
}