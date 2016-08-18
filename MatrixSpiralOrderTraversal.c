#include<stdio.h>
#include<malloc.h>

void printSpiralOrder(int arr[][4], int m, int n)
{
	int T = 0, B = m - 1, L = 0, R = n - 1;
	int dir = 0;
	int i;

	while (T <= B && L <= R)
	{
		if (dir == 0)
		{
			for (i = L; i <= R; i++)
			{
				printf("%d\t", arr[T][i]);
			}
			T++;
			dir = 1;
		}
		else if (dir == 1)
		{
			for (i = T; i <= B; i++)
			{
				printf("%d\t", arr[i][R]);
			}
			R--;
			dir = 2;
		}
		else if (dir == 2)
		{
			for (i = R; i >= L; i--)
			{
				printf("%d\t", arr[B][i]);
			}
			B--;
			dir = 3;
		}
		else if (dir == 3)
		{
			for (i = B; i >= T; i--)
			{
				printf("%d\t", arr[i][L]);
			}
			L++;
			dir = 0;
		}
	}
}

int main()
{
	int arr[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	printSpiralOrder(arr, 4, 4);
}