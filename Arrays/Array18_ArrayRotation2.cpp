#include<iostream>

using namespace std;

void printArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

void leftRotate(int *arr, int d, int n)
{
	int i = 0;
	int j = 0;
	int count = 1;

	while (d > 0)
	{
		int temp = arr[0];

		for (j = 1; j < n ; j++)
		{
			arr[j - 1] = arr[j];
		}
		//cout << "j = " << j <<" and temp = "<<temp<< endl;
		arr[j - 1] = temp;
		//cout << "after iteration : " << count << endl;
		//printArray(arr, n);
		//count++;
		d--;
	}
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	leftRotate(arr, 3, 7);
	cout << "Array after rotation" << endl;
	printArray(arr, 7);
	
	return 0;
}