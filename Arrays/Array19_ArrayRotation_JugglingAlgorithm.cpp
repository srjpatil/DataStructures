#include<iostream>

using namespace std;

//Instead of moving one by one, divide the array in different sets
//where number of sets is equal to GCD of n and d
//and move the elements within the sets

void printArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;

	cout << endl;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

void leftRotate(int *arr, int d, int n)
{
	int i, j, k;
	int __gcd = gcd(d, n);

	for (i = 0; i < __gcd; i++)
	{

	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int d = 2;
	int n = 7;

	leftRotate(arr, d, n);
	cout << "Array after rotation : " << endl;
	printArray(arr, n);
}