#include "stdio.h"
#include "stdlib.h"

typedef struct Josephus{

	int value;
	struct Josephus *next;

} Josephus;

typedef struct CircularList
{
	int size;
	Josephus *begin;

} CircularList;

void insertAfter(CircularList *CircularList, int value);
void displayListValues(CircularList *List);
CircularList *startCircularList();

int main(int argc, char const *argv[])
{

	CircularList *CircularList = startCircularList();

	for (int i = 0; i < 20; ++i)
	{

		insertAfter(CircularList, i);

	}

	printf("%d\n", CircularList->begin->value);
	printf("Hellou\n");

	displayListValues(CircularList);

	return 0;
}


void insertAfter(CircularList *CircularList, int value){

	Josephus *newJosephus = malloc(sizeof(Josephus));

	newJosephus->value = value;

	if(CircularList->begin == NULL){

		CircularList->begin = newJosephus;
		newJosephus->next = CircularList->begin;

	} else {

		newJosephus->next = CircularList->begin->next;
		CircularList->begin->next = newJosephus;
		CircularList->begin = CircularList->begin->next;

	}

	(CircularList->size)++;

}

void displayListValues(CircularList *List){

	Josephus *runThrough = List->begin->next;

	for(int i = 0; i < List->size; i++){

		printf("%d\n", runThrough->value);
		runThrough = runThrough->next;

	}

}

CircularList *startCircularList(){

	CircularList *newCircularList = malloc(sizeof(CircularList));
	newCircularList->size = 0;
	newCircularList->begin = NULL;

	return newCircularList;
}
