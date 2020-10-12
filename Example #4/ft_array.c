#include <stdio.h>
#include <stdlib.h>
#define MAX_HW 200

void ft_print(FILE *ofp)
{
	int c;
	rewind(ofp);
	while ((c = getc(ofp)) != EOF)
		putc (c, stdout);
}

void read_data(FILE *ptr, int d[], int *size)
{
	*size = 0;
	while (fscanf(ptr, "%d", &d[*size]) == 1)
		(*size)++;
}

double average(int d[],int size)
{
	int i;
	double avr;
	i = 1;
	avr = 0.0;
	while (i <= size)
	{
		avr += d[i];
		i++;
	}
	return (avr/size);
}

int ft_max(int d[], int size)
{
	int i;
	int b;
	i = 1;
	b = d[1];
	while (i <= size)
	{
		if (d[i] > b)
			b = d[i];
		i++;
	}
	return (b);
}

int main(int argc, char *argv[])
{
	int sz, amo, max;
	int data[MAX_HW];
	double num;
	FILE *ifp;
	FILE *ofp;

	if (argc != 2)
		exit(1);

	ifp = fopen(argv[1], "r+"); //open the file
	read_data(ifp, data, &sz); //to count the number of arguments in file

	amo = data[0]; //to define how many arguments to count

	if (sz <= amo)
		exit(1); //to check if we have enough arguments
	else
	{
		max = ft_max(data, amo); //find max
		num = average(data, amo); //find average

		ofp = fopen("answer_hw3", "w+"); //open or create file to write numbers in

		fprintf(ofp, "%f %d\n", num, max); //write number into the file
		ft_print(ofp); //print the numbers
		fclose(ofp); 
	}
	fclose(ifp);
	return (0);
}