#include <stdio.h>

typedef enum month{ jan, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec} month;
typedef struct date{ month m; int d;} date;

//function to print the month legibly
void	printmonth(month m)
{
	switch(m)
	{
	case jan: printf("January "); break;
        case feb: printf("February "); break;
        case mar: printf("March "); break;
        case apr: printf("April "); break;
        case may: printf("May "); break;
        case jun: printf("June "); break;
        case jul: printf("July "); break;
        case aug: printf("August "); break;
        case sept: printf("September "); break;
        case oct: printf("October "); break;
        case nov: printf("November "); break;
	case dec: printf("December "); break;
	}
}

//function to print the error if there is no such day in the month
void	print_error(int a, month m)
{
	printmonth(m);
	printf("has only %d days\n", a);
}

//function where everything happens (structure is the same in any cases)
void    printdate(date *today)
{
	if ((today->m == 3) || (today->m == 5) || (today->m == 8) || (today->m == 10))
	{
		if (today->d == 30)
			printmonth((today->m + 1) % 12);    //print the name of the next month if its the last day
		if (today->d > 30)
		{
			print_error(30, today->m);          //print error if this day doesn't exist
			return ;                            //return to the main function
		}
		else if (today->d != 30)
			printmonth(today->m);               //print the name of the month if its not the last day
		printf("%d\n", ((today->d + 1) % 30));      //print the day
	}
	else if (today->m == 1)
	{
		if (today->d == 28)
			printmonth((today->m + 1) % 12);
		if (today->d > 28)
		{
			print_error(28, today->m);
			return ;
		}
		else if (today->d != 28)
			printmonth(today->m);
		printf("%d\n", ((today->d + 1) % 28));
	}
	else
	{
		if (today->d == 31)
			printmonth((today->m + 1) % 12);
		if (today->d > 31)
		{
			print_error(31, today->m);
			return ;
		}
		else if (today->d != 31)
			printmonth(today->m);
		printf("%d\n", ((today->d + 1) % 31));
	}
}

//checking if the date is valid
int	check_date(date *today)
{
	if ((today->d <= 0) || (today->m >= 12))
        {
                printf("Date error\n");
                return (-1);
        }
	return (1);
}

//main function
int main()
{
	date today_1 = {dec, 12};
	if (check_date(&today_1) == 1)
	{
		printmonth(today_1.m);
		printf("%d\n", today_1.d);
		printdate(&today_1);
	}
	
	date today_2 = {jan, 1};
        if (check_date(&today_2) == 1)
        {
                printmonth(today_2.m);
                printf("%d\n", today_2.d);
                printdate(&today_2);
        }
	
	date today_3 = {feb, 28};
        if (check_date(&today_3) == 1)
        {
                printmonth(today_3.m);
                printf("%d\n", today_3.d);
                printdate(&today_3);
        }
	
	date today_4 = {mar, 14};
        if (check_date(&today_4) == 1)
        {
                printmonth(today_4.m);
                printf("%d\n", today_4.d);
                printdate(&today_4);
        }

	date today_5 = {oct, 31};
        if (check_date(&today_5) == 1)
        {
                printmonth(today_5.m);
                printf("%d\n", today_5.d);
                printdate(&today_5);
        }

	date today_6 = {dec, 31};
        if (check_date(&today_6) == 1)
        {
                printmonth(today_6.m);
                printf("%d\n", today_6.d);
                printdate(&today_6);
        }
	return 0;
}
