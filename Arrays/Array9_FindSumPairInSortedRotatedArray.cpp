#include<iostream>

using namespace std;

int pairInSortedRotated(int *arr, int size, int sum)
{
	int i;
	//Find pivot element
	for (i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			cout << "i = " << i << endl;
			break;
		}
	}

	int left = (i + 1) % size;
	int right = i;

	while (left != right)
	{
		cout << "left = " << left << " right = " << right << endl;
		if (arr[left] + arr[right] == sum)
			return 1;

		if (arr[left] + arr[right] < sum)
			left = (left + 1) % size;
		else
			right = (right - 1 + size) % size;
	}

	return 0;
}

int main()
{
	int arr[] = { 11, 15, 6, 8, 9, 10 };
	int sum = 16;
	int n = sizeof(arr) / sizeof(arr[0]);

	if (pairInSortedRotated(arr, n, sum))
		cout << "Array has two elements with sum 16"<<endl;
	else
		cout << "Array doesn't have two elements with sum 16 "<<endl;

	return 0;
}