#include<iostream>

using namespace std;

void printArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void reverseArray(int *arr, int start, int end)
{
	if (start > end)
		return;
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
	reverseArray(arr, start+1, end-1);
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	printArray(arr, 6);
	reverseArray(arr, 0, 5);
	printf("Reversed array is \n");
	printArray(arr, 6);
	return 0;
}