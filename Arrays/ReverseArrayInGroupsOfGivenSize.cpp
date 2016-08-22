#include<iostream>

using namespace std;

void reverse(int *arr, int n, int k)
{
	for (int i = 0; i < n; i = i + k)
	{
		int start = i, end = i + k - 1;
		if (end > n - 1)
			end = n - 1;
		int mid = (start + end) / 2;
		//while (start <= mid) //this also works :)
		while(start < end)
		{
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp; //arr[start];
			start++;
			end--;
		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	//int k = 10;
	int k = 3;
	int n = sizeof(arr) / sizeof(arr[0]);

	reverse(arr, n, k);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}