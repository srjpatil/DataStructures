#include<iostream>

using namespace std;

/*An element is leader if it is greater than all the elements to its right side.
And the rightmost element is always a leader. 
For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.*/

void printLeaders(int *arr, int n)
{
	int max_from_right = arr[n - 1];

	cout << max_from_right << " ";

	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] > max_from_right)
		{
			max_from_right = arr[i];
			cout << max_from_right;
		}
	}
	cout << endl;
}


int main()
{
	int arr[] = { 16, 17, 4, 3, 5, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printLeaders(arr, n);
}