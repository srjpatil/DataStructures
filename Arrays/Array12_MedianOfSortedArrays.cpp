#include<iostream>

using namespace std;

int getMedian(int *arr1, int *arr2, int n)
{
	int count;
	int i = 0;	//current index of arr1
	int j = 0;	//current index of arr2
	int m1 = -1, m2 = -1;
	for (count = 0; count <= n; count++)
	{
		if (i == n)
		{
			m1 = m2;
			m2 = arr2[0];
			break;
		}
		else if (j == n)
		{
			m1 = m2;
			m2 = arr1[0];
			break;
		}

		if (arr1[i] < arr2[j] || j == n)
		{
			m1 = m2;
			m2 = arr1[i];
			i++;
			
		}
		else
		{
			m1 = m2;
			m2 = arr2[j];
			j++;
			
		}
	}

	return (m1 + m2) / 2;
}

int main()
{
	int ar1[] = { 1, 12, 15, 26, 38 };
	int ar2[] = { 2, 13, 17, 30, 45 };

	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	if (n1 == n2)
		printf("Median is %d", getMedian(ar1, ar2, n1));
	else
		printf("Doesn't work for arrays of unequal size");
	getchar();
	return 0;
}