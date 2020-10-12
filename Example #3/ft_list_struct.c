#include<stdio.h> 
#include<stdlib.h> 
  
typedef struct list {int data; struct list *next;} list;
  
// to insert an element at the beginning of a list
void push_front(list **begin_list, int data) 
{ 
	list *elem = (list*)malloc(sizeof(list)); 

	elem->data = data; 
	elem->next = *begin_list; 
	*begin_list = elem; 
} 
  
void ft_print(list *start) 
{ 
	int i;
	i = 0;
	list *temp = start;  

	while (temp!=NULL) 
	{ 
		printf("%d ", temp->data); 
        	temp = temp->next;
		i++;
		if ((i % 5) == 0)
			printf("\n");
	}
} 

// function to swap data
void swap(list *a, list *b) 
{ 
	int temp = a->data; 
	a->data = b->data; 
	b->data = temp; 
} 

// to bubble sort
void buble_sort(list *start) 
{ 
	int k;
	list *elem; 
	list *lptr = NULL; 
 
	k = 1;
	if (start == NULL) 
		return ; 
	
	while (k)
	{ 
		k = 0;
		elem = start; 
  
		while (elem->next != lptr) 
		{ 
			if (elem->data > elem->next->data) 
			{  
				swap(elem, elem->next); 
				k = 1; 
			} 
			elem = elem->next; 
		} 
		lptr = elem;
	} 
} 

int main() 
{ 
	int data[100] = {100, 2, 6, 451, 4, 8, 5, 7, 9, 3,
			 89, -4, 1, 1987, -19, 3, 476, 61, 13, 52,
			 434, 1, 1432, 33, 21, 124, 14, 147, 53, -85,
			 32, 234, 2, 56, 456, 4, 256, 1, 4, 53,
			 24, -4, -6, 25, 28, 12, 1213, 14, 97, 57,
			 6, 86, 85, 98, 23, 54, 76, 546, 34, 25,
			 76, 77, 24, 754, 2353, 421, 987, 766, 8654, 234,
			 54, 4657, 856, 12, 987, 768, 977, 989, 65, 803,
			 765, 364, 36, 356, 765, 657, 5673, 253, 122, 564,
			 454, 909, 8, -235, 456, -65, 345, 74, 235, 65};
	int i;
	list *start = NULL;
 
	i = 0;
	while (i < 100)
	{
        	push_front(&start, data[i]);
		i++;
	}
	buble_sort(start); 
	ft_print(start); 
 
	return (0); 
} 