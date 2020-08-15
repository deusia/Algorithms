#include<iostream>
#include<cstdlib>
using namespace std;
int main(void)
{
	int arr[20];
	int temp;
	int min;
	for (int i = 0; i < 20; i++)
	{
		arr[i] = rand() % 20;
		cout << "  " << arr[i];
	}
////////////////////////////////////////////////
	cout << endl;
	for (int i = 0; i < 19; i++)
	{
		min=i;
		for (int k = i+1; k < 20; k++)
			if (arr[min]<arr[k])
				min = k;
///////////////////////////////////////////////
		temp=arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
//////////////////////////////////////////////
	for (int i = 0; i < 20; i++)
		cout << "  " << arr[i];
	system("pause");
}