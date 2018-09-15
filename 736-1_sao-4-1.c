#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	struct queue* next;
	struct queue* prev;
	int value;
} q;

typedef struct HeadAndTail
{
	struct queue* head;
	struct queue* tail;
	int size;
} HaT;

HaT* CreateQueue()
{
	HaT* creation = (HaT*)malloc(sizeof(HaT));
	creation->head = creation->tail = NULL;
	creation->size = 0;
	return creation;
}

void DestroyList(HaT** list)
{
	q* first = (*list)->head;
	q* ptr;
	while(first)
	{
		ptr = first->next;
		free(first);
		first = ptr;
	};
	free(*list);
	(*list) = NULL;
}

void Write(HaT* queue , int newvalue)
{
	q* element = (q*)malloc(sizeof(q));
	if(queue->size == 0)
	{
		queue->tail = queue->head = element;
		element->value = newvalue;
		element->prev = element->next = NULL;
		queue->size++;
		return;
	}
	element->prev = queue->tail;
	element->next = NULL;
	element->value = newvalue;
	queue->tail->next = element;
	queue->tail = element;
	queue->size++;
}

bool IsEmpty(HaT* queue)
{
	return (queue == NULL || queue->size == 0);
}

int Read(HaT* queue)
{
	if (IsEmpty(queue))
		 exit(1);
	return (queue->head->value);
}

void DeleteElem(HaT* queue)
{
	if (IsEmpty(queue))
		return;
	if(queue->size == 1)
	{
		free(queue->head);
		queue->head = queue->tail = NULL;
		queue->size = 0;
		return;
	}
	queue->head = queue->head->next;
	free(queue->head->prev);
	queue->head->prev = NULL;
	queue->size--;
}

void ShowList(HaT* list)
{
	if(IsEmpty(list))
		return;
	q* first = list->head;
	while(first)
	{
		printf("%d ",first->value);
		first = first->next;
	}
	printf("\n");
}

int main()
{
	HaT* queue = CreateQueue();
	for(int i = 1; i<=10; ++i)
	{
		Write(queue , i);
	}
	ShowList(queue);
	while(!IsEmpty(queue))
	{
		printf("%d %d\n" , Read(queue) , queue->size);
		DeleteElem(queue);
	}
	return 0;
}
