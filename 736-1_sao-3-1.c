#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node 
{	
	int value;
	struct node *next;
	struct node *prev;

} node;

typedef struct list
{
	node *head;
}list;

list* init()
{
	list *root = (list*) malloc(sizeof(list));
	root->head  = NULL;
	return root;
}

void destroy(list* root)
{
	node *ptr = root->head;
	node *ptr2;
	
	while(ptr != NULL)
	{
		ptr2 = ptr->next;
		free(ptr);
		ptr = ptr2;
	}
	root = NULL;
	ptr = NULL;
	ptr2 = NULL;
}

bool isEmpty(list* root)
{
	if(root->head == NULL)
		return true;
	else
		return false;
}

int find(node* root, int val)
{
	while(root != NULL)
	{
		if(root->value == val)
			return (root->value);
		else
			root = root->next;
	}
	return 0;
}

void append(list *root, int count, int val)
{
	int count_1 = 1;
	node *ptr = root->head;
	node *ptr2 = (node*)malloc(sizeof(node));
	
	if(ptr == NULL)
	{
		ptr2->next = NULL;
		ptr2->prev = NULL;
		ptr2->value = val;
		root->head = ptr2;
	}

	while(ptr != NULL)
	{
		if(count_1 == count)
		{
			if(ptr->next == NULL)
			{
				ptr->next = ptr2;
				ptr2->prev = ptr;
				ptr2->next = NULL;
			}
			else
			{
				ptr->next->prev = ptr2;
				ptr2->next = ptr->next;
				ptr->next = ptr2;
				ptr2->prev = ptr;
			}
			ptr2->value = val;
			break;
		}
		count_1++;
		ptr = ptr->next;
	}
	root = NULL;
	ptr = NULL;
	ptr2 = NULL;
}
void prepend(list *root, int count, int val)
{
	int count_1 = 1;
        node *ptr = root->head;
        node *ptr2 = (node*)malloc(sizeof(node));;

        while(ptr != NULL)
        {
                if(count_1 == count)
                {
                        if(ptr->prev == NULL)
                        {
                                ptr->prev = ptr2;
                                ptr2->next = ptr;
                                ptr2->prev = NULL;
				root->head = ptr2;
                        }
                        else
                        {
                                ptr->prev->next = ptr2;
                                ptr->prev = ptr2;
				ptr2->next = ptr;
                                ptr2->prev = ptr->prev;
                        }
                        ptr2->value = val;
                        break;
                }
                count_1++;
                ptr = ptr->next;
        }
        root = NULL;
        ptr = NULL;
	ptr2 = NULL;
}

void print(list *root)
{
	int prin;
	node *ptr = root->head;
	
	while(ptr != NULL)
	{
		prin = ptr->value;
		printf("%d ", prin);
		ptr = ptr->next;
	}
	printf("\n");
	root = NULL;
	ptr = NULL;
}
void rem(list *root, int count)
{
	int count1 = 1;
	node* ptr = root->head;
	while(ptr != NULL)
	{
		if(count1 == count)
		{
			if((ptr->next != NULL) && (ptr->prev != NULL))
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
			if(ptr->prev == NULL)
			{
				ptr->next->prev = NULL;
				root->head = ptr->next;
			}
			if(ptr->next == NULL)
			{
				ptr->prev->next = NULL;
			}
			free(ptr);
			break;
		}
		count1++;
		ptr = ptr->next;
	}
	ptr = NULL;
	root = NULL;
}

void delete(list *root, int val)
{
        node* ptr = root->head;
        while(ptr != NULL)
	{
                if(ptr->value == val)
		{
			if((ptr->next != NULL) && (ptr->prev != NULL))
                        {
                                ptr->prev->next = ptr->next;
                                ptr->next->prev = ptr->prev;
                        }
                        if(ptr->prev == NULL)
                        {
                                ptr->next->prev = NULL;
				root->head = ptr->next;
                        }
                        if(ptr->next == NULL)
                        {
                         	ptr->prev->next = NULL;
                        }
			free(ptr);
                        break;
        	}
		ptr = ptr->next;
	}
	ptr = NULL;
        root = NULL;

}

int main(){
	int n, a, b;
	list *root = init();

	scanf("%d", &n); //Ввод n
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a);
		append(root, i, a);
	};

	print(root);
	
	scanf("%d", &a);
	rem(root, a);//Удаление по номеру

	print(root);
	
       	scanf("%d", &a);
        delete(root, a);//Удаление по значению

	print(root);
	
	scanf("%d", &a);//Вставка после
        scanf("%d", &b);
        append(root, a, b);
	
	print(root);

	scanf("%d", &a);//Ввод значения и номера. Вставка перед
        scanf("%d", &b);
        prepend(root, a, b);
	
	print(root);

	destroy(root);
	
	root = NULL;
	return 0;
}
