#include<iostream>

using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int medianSingle(int *arr, int n)
{
	if (n == 0)
		return -1;
	if (n % 2 == 0)
		return (arr[n / 2] + arr[n / 2 - 1]) / 2;
	else
		return arr[n / 2];
}
 
int MO2(int a, int b)
{
	return (a + b) / 2.0;
}

int MO3(int a, int b, int c)
{
	return a + b + c - max(a, max(b, c)) - min(a, min(b, c));
}

int MO4(int a, int b, int c, int d)
{
	int Max = max(a, max(b, max(c, d)));
	int Min = min(a, min(b, min(c, d)));

	return (a + b + c + d - Max - Min)/2.0;
}

// This function assumes that n is smaller than or equal to m.
// This function returns -1 if both arrays are empty.
int findMedianUtil(int *arr1, int n, int *arr2, int m)
{
	if (n == 0)
		return medianSingle(arr2, m);

	if (n == 1)
	{
		//Case 1: If the large array also has one element,
		//simply call MO2().
		if (m == 1)
			return MO2(arr1[0], arr2[0]);

		//Case 2: If the larger array has odd number of elements,
		//then consider the middle 3 elements of larger array and
		//the only element of smaller array
		//Examples : 
		//A[]={9}, B[] = {5, 8, 10, 20, 30};
		//A[]={1}, B[] = {5, 8, 10, 20, 30};
		if (m & 1)
		{
			return MO2(arr2[m / 2], MO3(arr1[0], arr2[m / 2 - 1], arr2[m / 2 + 1]));
		}

		//Case 3 : If the larger array has even number of elements,
		//then the median will be one of the following 3 elements.
		//.. The middle two elements of the larger array.
		//.. The only element of the smaller array.
		return MO3(arr2[m / 2], arr2[m / 2 - 1], arr1[0]);

	}
	else if (n == 2) //If the smaller array has two elements.
	{
		//Case 4: If the larger array also has two elements
		if (m == 2)
			return MO4(arr1[0], arr1[1], arr2[0], arr2[1]);

		//Case 5: If the larger array has odd number of elements,
		//then the median will be one of the following 3 elements:
		//1. Middle element of the larger array.
		//2. Max of first element of smaller array and element
		//	 just before the middle in bigger array.
		//3. Min of second element of smaller array and element
		//   just after middle in bigger array.
		if (m & 1)
		{
			return MO3(arr2[m / 2], max(arr1[0], arr2[m / 2 - 1]), min(arr2[m / 2 + 1], arr1[1]));
		}

		//Case 5:
		return MO4(arr2[m / 2], arr2[m / 2 - 1], max(arr1[0], arr2[m / 2 - 2]), min(arr1[1], arr2[m/2 + 1]));
	}

	int idxA = (n - 1) / 2;
	int idxB = (m - 1) / 2;

	if (arr1[idxA] <= arr2[idxB])
		return findMedianUtil(arr1 + idxA, n / 2 + 1, arr2, m - idxA);
	return findMedianUtil(arr1, n / 2 + 1, arr2 + idxB, m - idxA);
}

int findMedian(int *arr1, int n, int *arr2, int m)
{
	if (n > m)
		return findMedianUtil(arr2, m, arr1, n);
	else
		return findMedianUtil(arr1, n, arr2, m);
}

int main()
{
	int A[] = { 900 };
	int B[] = { 5, 8, 10, 20 };

	int N = sizeof(A) / sizeof(A[0]);
	int M = sizeof(B) / sizeof(B[0]);

	cout << "Median is " << findMedian(A, N, B, M);
}