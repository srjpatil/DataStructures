#include<iostream>

using namespace std;

int getMedian(int *arr1, int *arr2, int n)
{

}

int main()
{
	int ar1[] = { 1, 2, 3, 6 };
	int ar2[] = { 4, 6, 8, 10 };
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	if (n1 == n2)
		printf("Median is %d", getMedian(ar1, ar2, n1));
	else
		printf("Doesn't work for arrays of unequal size");
	return 0;
}