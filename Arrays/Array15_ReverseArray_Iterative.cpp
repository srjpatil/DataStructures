#include<iostream>

using namespace std;

void printArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

void reverseArray(int *arr, int start, int end)
{
	int temp;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	printArray(arr, 6);
	int size = sizeof(arr) / sizeof(arr[0]);
	reverseArray(arr, 0, size-1);
	printf("Reversed array is \n");
	printArray(arr, 6);
	return 0;
}