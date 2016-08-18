#include<iostream>
#include<algorithm>

using namespace std;

int hasArrayTwoCandidates(int *A, int size, int num)
{
	sort(A, A + size);

	cout << "Sorted array : " << endl;
	for (int i = 0; i < size; i++)
		cout << A[i] << "  ";
	cout << endl;

	int left = 0, right = size - 1;

	while (left < right)
	{
		cout << "A[left]" << A[left] << "\t" << "A[right]" << A[right] << endl;
		if (A[left] + A[right] == num)
			return 1;
		else if (A[left] + A[right] < num)
			left++;
		else
			right--;
	}

	return 0;
}

int main()
{
	int A[] = { 2, 4, 45, 6, 10, -8 };

	int size = sizeof(A) / sizeof(A[0]);

	int num = 6;

	//cout << "Size of the array : " << size << endl;

	//sort(A, A + size);

	if (hasArrayTwoCandidates(A, size, num))
		cout << "Array has two elements with sum " << num << endl;
	else
		cout << "Array doesn't have two elements with sum " << num << endl;

	/*for (int i = 0; i < size; i++)
		cout << A[i] << "\t";
	cout << endl;*/


}