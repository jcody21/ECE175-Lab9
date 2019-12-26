#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//  Author: John Cody
//  Date created: 04/04/2018
//  Program Description: This program 

typedef struct node_s {
	int x;
	struct node_s *listp;
} node;

void swap(node *pt, int i, int j);
int rand_gen(int count);

int main(void) {

	int userNum = 0, counter = 0, i;
	char again = 'y';
	node *headptr = NULL, *tailptr = NULL, *temp = NULL;

	srand((int)time(NULL));

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
			counter++;
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

	temp = headptr;
	while (temp != NULL) {
		printf(" %d", temp->x);
		temp = temp->listp;
	}

	printf("\nEnter the number of swaps: ");
	scanf(" %d", &userNum);

	for (i = 0; i < userNum; i++) {
		swap(headptr, rand_gen(counter), rand_gen(counter));
	}

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

void swap(node *pt, int i, int j) {
	int x = 0, save;
	node *pt1 = pt, *pt2 = pt;
	for (x = 0; x < i; x++) {
		pt1 = pt1->listp;
	}
	for (x = 0; x < j; x++) {
		pt2 = pt2->listp;
	}
	save = pt1->x;
	pt1->x = pt2->x;
	pt2->x = save;
}

int rand_gen(int count) {
	double frac;
	frac = (double)rand() / ((double)RAND_MAX + 1);
	return floor(count * frac); //random number in [0, count]
}
