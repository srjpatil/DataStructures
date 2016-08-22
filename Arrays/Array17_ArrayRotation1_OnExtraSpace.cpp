#include<iostream>

using namespace std;

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int d = 2;
	int n = 7;

	int *temp = new int[d];

	for (int i = 0; i < d; i++)
	{
		temp[i] = arr[i];
	}

	cout << "temp array : " << endl;
	for (int i = 0; i < d; i++)
		cout << temp[i] << "\t";
	cout << endl;

	for (int i = 0; i < n - d; i++)
	{
		arr[i] = arr[d + i];
	}

	cout << "Original array after shifting to start : " << endl;
	for (int i = 0; i < n - d; i++)
		cout << arr[i] << "\t";
	cout << endl;

	cout << "Adding temp array elements at the end of the shifted array" << endl;
	for (int i = 0; i < d; i++)
	{
		arr[n - d + i] = temp[i];
	}

	cout << "Final arrays after rotation :" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
	cout << endl;

}