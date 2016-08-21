#include<iostream>

using namespace std;

//search for element in sorted but rotated array in single pass of Binary Search.

int search(int *arr, int left, int right, int key)
{
	if (left > right)
		return -1;

	int mid = (left + right) / 2;


	if (arr[mid] == key)
		return mid;

	//arr[left...mid] is sorted.
	if (arr[left] <= arr[mid])
	{
		if (key >= arr[left] && key <= arr[mid])
		{
			return search(arr, left, mid - 1, key);
		}
		else
		{
			return search(arr, mid + 1, right, key);
		}
	}
	else //arr[mid...right] is sorted.
	{
		if (key >= arr[mid] && key <= arr[right])
			return search(arr, mid + 1, right, key);
		else
			return search(arr, left, mid - 1, key);
	}

}

int main()
{
	int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 6;
	int i = search(arr, 0, n - 1, key);
	if (i != -1) cout << "Index: " << i << endl;
	else cout << "Key not found\n";
}