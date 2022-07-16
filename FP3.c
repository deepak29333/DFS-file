#include<stdio.h>
#include<stdlib.h>

#define size 7

struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];
void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    int key = value % size;

    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
   printf("\nCoded by Deepak(04335304421)\n");
    int i,arr[20]={10,20,30,40,10,23,44,43,67,43,6,76,20,54,49,67,87,12,45,34};
     //init array of list to NULL
    init();
	for(i=0;i<20;i++){
		 insert(arr[i]);
	}
    print();
    return 0;
}
