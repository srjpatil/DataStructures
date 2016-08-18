#include<iostream>

using namespace std;

//This is an implementation of Moore's voring algorithm.

int findCandidate(int *arr, int size)
{
	int maj_index = 0, count = 1;
	int i;
	for (i = 1; i < size; i++)
	{
		if (arr[i] == arr[maj_index])
			count++;
		else
			count--;

		if (count == 0)
		{
			maj_index = i;
			count = 1;
		}
	}

	return arr[maj_index];
}

int isMajority(int *arr, int size, int cand)
{
	int i, count = 0;

	for (i = 0; i < size; i++)
	{
		if (arr[i] == cand)
			count++;
	}

	if (count > size / 2)
		return 1;
	else
		return 0;

}

void printMajority(int *arr, int size)
{
	int cand = findCandidate(arr, size);

	if (isMajority(arr, size, cand))
		cout << "Majority element is : " << cand << endl;
	else
		cout << "No Majority Element" << endl;
}

int main()
{
	int a[] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 };
	int size = (sizeof(a)) / sizeof(a[0]);
	printMajority(a, size);
	//getchar();
	return 0;
}