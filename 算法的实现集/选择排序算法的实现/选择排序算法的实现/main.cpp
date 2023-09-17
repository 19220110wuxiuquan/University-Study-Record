#include<iostream>
#include<algorithm>
#include"Student.h"
using namespace std;
/*void selectionsort(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
			swap(arr[i], arr[minIndex]);
		}
	}
}*/

//使用模版（泛型）编写算法
template<typename T>
void selectionsort(T arr[], int n)
{
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
			swap(arr[i], arr[minIndex]);
		}
	}
}

int main()
{
	int a[10] = { 4,2,6,3,7,1,9,10,8,5 };
	selectionsort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << endl;
	}
	float b[5] = { 2,6,3,8,5 };
	selectionsort(b, 5);
	for (int j = 0; j<5; j++)
	{
		cout << b[j] << endl;
	}

	Student stu[4] = { {"A",60},{"B",90},{"C",85},{"D",80} };
	selectionsort(stu, 4);
	for (int k = 0; k < 4; k++)
	{
		cout << stu[k] << endl;
	}

	return 0;
}