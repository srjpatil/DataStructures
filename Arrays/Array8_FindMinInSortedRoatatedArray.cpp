#include<iostream>

using namespace std;

int findMin(int *arr, int left, int right)
{
	// if array is not rotated at all
	if (right < left) return arr[0];

	// if there is only one element
	if (left == right)
		return arr[left];

	int mid = (left + right)/2;

	if (left < mid && arr[mid] < arr[mid - 1])
		return arr[mid];

	if (mid < right && arr[mid] > arr[mid + 1])
		return arr[mid + 1];

	/*if (arr[left] < arr[mid])
		return findMin(arr, mid + 1, right);
	else
		return findMin(arr, left, mid - 1);
	*/

	if (arr[right] > arr[mid])
		return findMin(arr, left, mid - 1);
	else
		return findMin(arr, mid + 1, right);
}

int main()
{
	int arr1[] = { 5, 6, 1, 2, 3, 4 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	printf("The minimum element is %d\n", findMin(arr1, 0, n1 - 1));
	

	int arr2[] = { 1, 2, 3, 4 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	printf("The minimum element is %d\n", findMin(arr2, 0, n2 - 1));

	int arr3[] = { 1 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	printf("The minimum element is %d\n", findMin(arr3, 0, n3 - 1));

	int arr4[] = { 1, 2 };
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	printf("The minimum element is %d\n", findMin(arr4, 0, n4 - 1));

	int arr5[] = { 2, 1 };
	int n5 = sizeof(arr5) / sizeof(arr5[0]);
	printf("The minimum element is %d\n", findMin(arr5, 0, n5 - 1));

	int arr6[] = { 5, 6, 7, 1, 2, 3, 4 };
	int n6 = sizeof(arr6) / sizeof(arr6[0]);
	printf("The minimum element is %d\n", findMin(arr6, 0, n6 - 1));
	
	int arr7[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n7 = sizeof(arr7) / sizeof(arr7[0]);
	printf("The minimum element is %d\n", findMin(arr7, 0, n7 - 1));

	int arr8[] = { 2, 3, 4, 5, 6, 7, 8, 1 };
	int n8 = sizeof(arr8) / sizeof(arr8[0]);
	printf("The minimum element is %d\n", findMin(arr8, 0, n8 - 1));

	int arr9[] = { 3, 4, 5, 1, 2 };
	int n9 = sizeof(arr9) / sizeof(arr9[0]);
	printf("The minimum element is %d\n", findMin(arr9, 0, n9 - 1));
	
}