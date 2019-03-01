#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define LEN 20
#define ROW 5
void function_first(char[][LEN]);
void function_second(char[][LEN]);
void function_third(char [][LEN]);
void function_fourth(char[][LEN]);
char* s_gets(char* str, int n);
unsigned int first_size = 0;
int word_number[ROW];
char* temp;
char* com[ROW];
char(*track)[LEN];
char(*track2)[LEN];

int main(void)
{
	int command;
	unsigned int exit = false;
	char str[ROW][LEN];
	printf("Now you need to enter ten strings.\n");
	printf("Enter a string:");
	for (int i = 0; i < ROW; i++)
	{
		for (int k = 0; k < LEN; k++)
		{
			str[i][k] = getchar();
			if (str[i][k] == '\n')
			{
				str[i][k] = '\0';
				break;
			}
		}
		if (ROW - 1 == i)
			continue;
		else
			printf("Enter next string:");
	}
	//part one  *assign task

	printf("*********************************************\n");
	printf("Here comes the command.\n");
	puts(" 1)  print all the strings.");
	puts(" 2)  print all the strings obey the order of ASCII.");
	puts(" 3)  print all the strings according to lenth.");
	puts(" 4)  print all the strings according to the first word. ");
	puts(" 5)  exit.");
	printf("*********************************************\n");
	//part two  *order print  
		//okkokokokokokokokokokokokokokokokokokokokokokokokokokokokokokokokokokokokokokok
	printf("Please enter a number:");
	while (scanf_s("%d", &command) == 1)
	{
		switch (command)
		{
		case 1:///////////////////////////complete!!!!!!!!!
			function_first(str);
			break;
		case 2:
			function_second(str);
			break;
		case 3:
			function_third(str);
			break;
		case 4:///////////////////////////complete!!!!!!!!!
			function_fourth(str);
			break;
		case 5:///////////////////////////complete!!!!!!!!!
			exit = true;
			break;
		}
		if (exit)
			break;
	}
	//part three  *option part

	puts("Done!");
	return 0;
}
//part four  *function design
void function_first(char str[][LEN])
{
	int count = 1;
	const char(*pt)[LEN] = str;           
	for (int i = 0; i < ROW; i++)
		printf("%3d)  %s\n", count + i, pt + i);
	printf("Please Enter next number or Enter 5 to EXIT:");
}
void function_second(char str[][LEN])
{

}
void function_third(char str[][LEN])
{
	unsigned int first_size1 = 0;
	int word_number1[ROW];
	char* temp1;
	char* com1[ROW];
	char(*track1)[LEN]=NULL;
	char(*track21)[LEN];

	if (NULL != strchr(track1, ' '))
	{
		for (int i = 0; i < ROW; i++) {                   //
			for (int k = 0; k < LEN; k++)                 //find the space 
			{                                             //
														  // 
				if (str[i][k] != ' ')                     //
					first_size1++;
				else
					continue;

			}
			word_number1[i] = first_size1;
			first_size1 = 0;                                   //reset the number!!!!!!
			track1++;
		}
	}
	else
	{
		for (int i = 0; i < ROW; i++)
		{
			first_size1 = strlen(track1++);
			word_number1[i] = first_size1;
		}
	}
	//counting the number of strings
	for (int fir = 0; fir < ROW - 1; fir++)
		for (int sec = 1 + fir; sec < ROW; sec++)
		{
			if (word_number1[fir] < word_number1[sec])      //ues the word's size to queue
			{
				temp1 = com1[fir];                          //
				com1[fir] = com1[sec];                      //get the order to queue
				com1[sec] = temp1;                          //track will have the new order!!
			}
		}
		
	for (int c = 0,count=1; c < ROW; c++,count++)
		printf("%3d)  %s\n", count,com1[c] );
	printf("Please Enter next number or Enter 5 to EXIT:");
}
void function_fourth(char str[][LEN])
{

	track = str;
	track2 = str;
	for (int i = 0; i < ROW; i++)
		com[i] = track2+i;                                // get every row's  first address
	if (NULL != strchr(track, ' '))
	{
		for (int i = 0; i < ROW; i++) {                   //
			for (int k = 0; k < LEN; k++)                 //if the string is just word
			{                                             //
				                                          //  or it's a sentence
				if (str[i][k] != ' ')                     //
					first_size++;
				else
					break;

			}
			word_number[i] = first_size;
			first_size = 0;                                   //reset the number!!!!!!
			track++;
		}
	}
	else
	{
		for (int i = 0; i < ROW; i++) {
			first_size = strlen(track++);
			word_number[i] = first_size;
		}
	}
		
	
	//get the length of first word
	for (int fir = 0; fir < ROW - 1; fir++)
		for (int sec = 1 + fir; sec < ROW; sec++)
		{
			if (word_number[fir] < word_number[sec])      //ues the word's size to queue
			{
				temp = com[fir];                          //
				com[fir] = com[sec];                      //get the order to queue
				com[sec] = temp;                          //track will have the new order!!
			}
		}
	for (int c = 0, count = 1; c < ROW; c++, count++)
		printf("%3d)  %s\n", count, com[c]);
	printf("Please Enter next number or Enter 5 to EXIT:");
}
char* s_gets(char* str, int n)
{
	char* ret_val;
	int i = 0;

	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			str[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}