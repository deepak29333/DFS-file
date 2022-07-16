#include<stdio.h>

int adjMat[9][9],vCount=0;
int queue[9],front=-1,rear=-1,visited[9], stack[10], stackSize=9, top = 1;


void push(int v){
if( top == stackSize ) printf("\nStack Overflow!");
else {
stack[top] = v; top++;
}
}
int peek() {
return stack[top-1];
}

void resetVisited() {
int i;
for(i=1; i<= vCount; i++) { visited[i] = 0;
}
}

int stackisEmpty(){ if( top == 1)
return 1; else
return 0;
}

int pop(){
if( stackisEmpty() ) 
{ printf("\nStack is Empty!"); return 0;
}
else {
top--;
int n = stack[top]; stack[top] = 0; return n;
}
}


void insVertex(int v)
{
int i;
vCount = vCount+1; 
adjMat[vCount][0]=v; 
adjMat[0][vCount]=v; 
for(i=1; i<=vCount; i++)
{
adjMat[vCount][i] = 0;
adjMat[i][vCount] = 0;
}
}

void delVertex(int v)
{
int i,j,k; j=0;
for(i=1;i<=vCount;i++)
{
if(adjMat[i][j]==v)
{
adjMat[i][j] = 0; for(k=1; k<=vCount; k++)
{
adjMat[i][k] = 0;
}
}
}
i=0;
for(j=1;j<=vCount;j++)
{
if(adjMat[i][j]==v)
{
adjMat[i][j] = 0; for(k=0;k<=vCount;k++)
{
adjMat[k][j] = 0;
}
}
}
}

void insEdge(int sE, int dE)
{
adjMat[sE][dE] = 1;
adjMat[dE][sE] = 1;
}

void delEdge(int sE, int dE)
{
adjMat[sE][dE] = 0;
adjMat[dE][sE] = 0;
}

void disMatrix()
{
int i,j;
for(i=0; i<=vCount; i++)
{
for(j=0; j<=vCount; j++)
{
printf("\t%d",adjMat[i][j]);
}
printf("\n");
}
}

void enqueue(int x)
{
if(front==-1)
{
front=rear=0;
}
else
{
rear=rear+1;
}
queue[rear] = x;
}

int dequeue()
{
int temp;
temp = queue[front]; if(rear==front)
{
front=rear=-1;
}
else
{
front = front+1;
}
return temp;
}

int isEmpty()
{
if(front==-1) return 1;
else
return 0;
}


void main()
{
printf("Coded by Deepak(04335304421)\n");
int v,choice = 0,sE,dE,source; 
do
{
	resetVisited();
	
	printf("\n*** MENU ***"); 
	printf("\n1. INSERT A VERTEX"); 
	printf("\n2. DELETE A VERTEX"); 
	printf("\n3. INSERT AN EDGE"); 
	printf("\n4. DELETE AN EDGE"); 
	printf("\n5. CALCULATION OF DEGREE OF EACH VERTEX"); 
	printf("\n6. CALCULATION OF SELF-LOOPS");
	printf("\n7. EXIT"); 
	printf("\n\nINPUT YOUR CHOICE: ");
	scanf("%d",&choice); 
	switch(choice)
	{
		case 1: printf("\nINPUT THE VERTEX TO INSERT: ");
				scanf("%d",&v); 
				insVertex(v); 
				break;
		case 2: printf("\nINPUT THE VERTEX TO DELETE: ");
				scanf("%d",&v); 
				delVertex(v); 
				break;
		case 3: printf("\nINPUT THE SOURCE VERTEX: "); scanf("%d",&sE);
				printf("\nINPUT THE DESTINATION VERTEX: ");
				scanf("%d",&dE); 
				insEdge(sE,dE); 
				break;
		case 4: printf("\nINPUT THE SOURCE VERTEX: "); scanf("%d",&sE);
				printf("\nINPUT THE DESTINATION VERTEX: ");
				scanf("%d",&dE); 
				delEdge(sE,dE); 
				break;

		case 5: printf("\nCALCULATE DEGREE OF VERTEX: "); 
				scanf("%d", &source); 
				break;
				
		case 6: printf("\nCALCULATE SELF LOOPS "); 
				scanf("%d", &source); 
				break;
				
		case 7: printf("\n\nExiting...");
				choice = 0; 
				break;
		
		default: printf("\nInvalid Choice!\n");

}
}while(choice);
}
