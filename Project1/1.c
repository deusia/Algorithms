#include<stdio.h>
#include<windows.h>
void to_base_n(int num, int n);
int main(void)
{
	int num, n;
	printf("enter a number:");
	scanf_s("%d", &num);
	printf("enter a div:");
	scanf_s("%d", &n);

	printf("outcome is ");
	to_base_n(num, n);
	system("pause");
	return 0;
}
void to_base_n(int num, int n)
{
	int r;
	r = num % n;
	if (num >= n)
		to_base_n(num/n, n);
	printf("%d", r);
}