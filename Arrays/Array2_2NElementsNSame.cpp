#include<iostream>
using namespace std;

//Given an array of 2n elements of which n elements are same and the remaining n elements are all different. 
//Write a C program to find out the value which is present n times in the array. 
//There is no restriction on the elements in the array. 
//They are random (In particular they not sequential).

int main()
{
	int arr[] = { 5,2,5,3,5,4,1,5};
	//int arr[] = { 5,2,3,4,1,1,1,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i, count;
	int maj_index, maj_index_prev;

	maj_index = 0, count = 1;

	for (i = 1; i < size; i++)
	{
		if (arr[i] == arr[maj_index])
		{
			count++;
		}
		else
		{
			count--;
		}

		if (count == 0)
		{
			maj_index_prev = i - 1;
			maj_index = i;
			count = 1;
		}
	}


	cout << "arr[maj_index] : " << arr[maj_index] << endl;
	cout << "arr[maj_index_prev] : " << arr[maj_index_prev] << endl;

	cout << "count is " << count << endl;

	if (count == 1)
	{
		cout << "Either of the above elements are probable candidates" << endl;

		cout << "Checking for two candidates " << endl;

		int num1 = arr[maj_index], num2 = arr[maj_index_prev], count1 = 0, count2 = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == arr[maj_index])
				count1++;
			if (arr[i] == arr[maj_index_prev])
				count2++;
		}

		if (count1 == size / 2)
			cout << "Majority element is : " << arr[maj_index] << endl;

		else if (count2 == size / 2)
			cout << "Majority element is : " << arr[maj_index_prev] << endl;
	}
	else if (count > 1)
		cout << "Majority element : " << arr[maj_index] << endl;
}