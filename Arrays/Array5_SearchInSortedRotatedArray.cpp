#include<iostream>

using namespace std;

int findPivot(int *arr, int left, int right)
{
	int mid = (left + right) / 2;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid < right && arr[mid] > arr[mid + 1])
			return mid;
		if (left < mid && arr[mid] < arr[mid - 1])
			return mid - 1;

		if (arr[left] >= arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;
}

int binarySearch(int *arr, int left, int right, int key)
{
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == key)
			return mid;
		if (key < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
}

int pivotedBinarySearch(int *arr, int n, int key)
{
	int pivot = findPivot(arr, 0, n-1);
	cout << "Pivot is : " << pivot << endl;
	
	if (pivot == -1)
	{
		cout << "Array is not rotated at all" << endl;
		return binarySearch(arr, 0, n - 1, key);
	}

	if (arr[pivot] == key)
		return pivot;
	if (key >= arr[0])
	{
		return binarySearch(arr, 0, pivot - 1, key);
	}
	else
		return binarySearch(arr, pivot + 1, n - 1, key);


	//return pivot;
}

int main()
{
	int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
	//int arr1[] = { 9, 10, 1,2,3,4,5,6,7,8 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	cout << "size of array : " << n << endl;
	int key = 3;
	printf("Index: %d\n", pivotedBinarySearch(arr1, n, key));
	return 0;
}