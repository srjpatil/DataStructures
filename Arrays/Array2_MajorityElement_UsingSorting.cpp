#include<iostream>
#include<algorithm>

using namespace std;
//Majority element in an array A[] of size n is an element
//that appears more than n/2 times.(**hence there is at most one such element).

//This method works if we are sure that there exists a majority element.
//It doesn't work if there is no majority element.

void printMajority(int *arr, int size)
{
	sort(arr, arr + size);

	cout << "Sorted array : " << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << endl;

	cout << "Majority element : " << arr[size / 2] << endl;
}

int main()
{
	int arr[] = { 3, 3, 4, 2, 4, 4, 2, 4, 4 };
	//int arr[] = { 1, 3, 3, 1, 2 }; doesn't work for this, it doesn't have majority element.
	int size = sizeof(arr) / sizeof(arr[0]);

	printMajority(arr, size);
}