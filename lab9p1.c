#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//  Author: John Cody
//  Date created: 04/04/2018
//  Program Description: This program takes input from a user and uses it to create a dynamiaclly linked list, and then outputs the data given. 

typedef struct node_s {
	int x;
	struct node_s *listp;
} node;

int main(void) {

	int userNum = 0;
	char again = 'y';
	node *headptr = NULL, *tailptr = NULL, *temp = NULL;

	while (again == 'y') {
		printf("Enter an integer : ");
		scanf(" %d", &userNum);
		
		temp = (node *)malloc(sizeof(node));
		
		if (headptr == NULL) {
			headptr = temp;
		}
		
		temp->x = userNum;
		temp->listp = NULL;

		if (temp != headptr) {
			tailptr->listp = temp;
		}
		
		tailptr = temp;

		printf("Do you want to enter another integer(y/n) ? ");
		scanf(" %c", &again); 
		
		while ((again != 'y') && (again != 'n')) { 
			printf("That input was not one of the options. Please try again. \n");
			printf("\nWould you like to print out the information of another student (y/n)? ");  
			scanf(" %c", &again);
		}
	}

	printf("\nThe integers entered are:");

	temp = headptr;

	while (temp != NULL) {
		printf(" %d", temp->x);
		temp = temp->listp;
	}

	while (headptr != NULL) {
		temp = headptr;
		headptr = temp->listp;
		free(temp);
	}

	printf("\n\n");

	return 0;
}