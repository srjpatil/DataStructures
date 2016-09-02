#include<iostream>

using namespace std;

void printMaxActivities(int *start, int *finish, int n)
{
	int i = 0;
	cout << i <<endl;

	for (int j = 1; j < n; j++)
	{
		if (start[j] > finish[i])
		{
			cout << j << endl;
			i = j;
		}
	}
}

int main()
{
	int start[] = { 1, 3, 0, 5, 8, 5 };
	int finish[] = { 2, 4, 6, 7, 9, 9 };

	int n = sizeof(start) / sizeof(start[0]);

	printMaxActivities(start, finish, n);

}