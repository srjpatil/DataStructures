#include<iostream>

using namespace std;

//Algorithm doesn't work for all negative numbers.
//It simply returns 0 if all numbers are negative. 
//For handling this we can add an extra phase before actual implementation. 
//The phase will look if all numbers are negative,
//if they are it will return maximum of them (or smallest in terms of absolute value). 
//There may be other ways to handle it though.

int maxSubArraySum(int *arr, int size)
{
	int max_sum = 0;
	int max_ending_here = 0;

	for (int i = 0; i < size; i++)
	{
		max_ending_here += arr[i];

		if (max_ending_here < 0)
			max_ending_here = 0;
		if (max_ending_here > max_sum)
			max_sum = max_ending_here;
	}

	return max_sum;
}

int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum << endl;
	return 0;
}