#include<stdio.h>
#include<conio.h>

//left child  2i+1, for right child   2i+2;
#define size 10
int heap[10],count=0;
void heapify(int);
void insert(int);
int delet();
void display();
void heapifySort();

void heapify(int i)
{
	int largest,l,r,temp;
	if(count==1){
		printf("\n SINGLE ELEMENT IN HEAP");
	}else{
		largest=i;
		l=(2*i)+1;
		r=(2*i)+2;
		if(l<count && heap[l]>heap[largest]){
			largest=l;
		}
		if(r<count && heap[r]>heap[largest]){
			largest=r;
		}
		if(largest!=i){
			temp=heap[i];
			heap[i]=heap[largest];
			heap[largest]=temp;
			heapify(largest);
		}
		
	}
}
void insert(int item){
	int i;
	if(count==0){
		heap[0]=item;
		count=count+1;
	}else
	{
		heap[count]=item;
		count=count+1;
		for( i=(count-1)/2; i>=0;i--){
			heapify(i);
		}
	}
}
int delet(){
	int temp;
	temp=heap[0];
	heap[0]=heap[count-1];
	heapify(0);
	return temp;
}
 void display(){
 	int i;
 	for(i=0;i<count;i++){
 		printf("%d ", heap[i]);
	 }
 }
 void heapifySort(int n){
 	int i,temp;
 	for(i=n;i>=2;i--){
 		temp=heap[0];
 		heap[0]=heap[i];
 		heap[i]=temp;
 		heapify(i-1);
	 }
 	
 }
 int main(){
 	int choice,num;
 	printf("Coded by Deepak(04335304421)\n");
 	while(1)
    {
        printf("1. Insert Into Heap \n");
        printf("2. Delete From Heap\n");
        printf("3. Display");
        printf("4. Exit\n\n\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter Element to add in Heap:\n");
                scanf("%d", &num);
                insert(num);
 				display();
                break;
        
            case 2:
            	// 	heapifySort(count-1);
                delet();  
                printf("Heap after delete element");
				display();  
				break;  
            case 4:
                printf("\n\n\t\t\Deepak !\n\n\n");
                exit(0);  
        }
    }
 }
