// Eduardo Vencovsky 
// https://github.com/EduVencovsky
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
void movePosition(CircularList *List, int position);
int removeOneAfterCurrent(CircularList *CircularList);
int JosephusProblem(CircularList *List, int M);
CircularList *startCircularList();

int main(int argc, char const *argv[])
{
	int M, n;
	CircularList *CircularList = startCircularList();

	printf("How many soldiers?\n");
	scanf("%d",&n);

	for (int i = 1; i <= n; ++i)
	{

		insertAfter(CircularList, i);

	}

	printf("\nOrder to kill\n");
	scanf("%d", &M);

	printf("\nJosephus should be soldier %d or he whould be dead...\n\n",JosephusProblem(CircularList, M));

	return 0;
}

void movePosition(CircularList *List, int position){

	if(List->size != 0){

		for(int i = 0; i < position; i++){

			List->begin = List->begin->next;

		}

	}

}

int removeOneAfterCurrent(CircularList *List){


	Josephus *aux = List->begin->next;
	int deadJosephus = aux->value;

	List->begin->next = aux->next;
	free(aux);
	(List->size)--;

	return deadJosephus;

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

int JosephusProblem(CircularList *List, int M){

	int i = List->size;
	int deadJosephus;

	while(List->size > 1){

		movePosition(List, M - 1);
		deadJosephus = removeOneAfterCurrent(List);

		printf("Round %d\n", i - List->size);
		printf("Soldier %d dead!\n\n", deadJosephus);

	}

	return List->begin->value;

}

CircularList *startCircularList(){

	CircularList *newCircularList = malloc(sizeof(CircularList));
	newCircularList->size = 0;
	newCircularList->begin = NULL;

	return newCircularList;

}

