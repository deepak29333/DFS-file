#include <stdio.h>
#include <stdlib.h>
/* Function declarations */
int isEven(const int NUM);
void printRandoms(int lower, int upper,int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
        (upper - lower + 1)) + lower;
        printf("%d ", num);
    }
}



int main()
{
	printf("\ncoded by Deepak(04335304421)\n");
    FILE * fPtrIn, * fPtrEven, * fPtrOdd, * fPtrPrime;
	int lower=1000,upper=2000,count=30;
    int num, success;
	fPtrIn   = fopen("all.txt", "w");
	if(fPtrIn!=NULL){
		int i;
	    for (i = 0; i < count; i++) {
	        int num = (rand() %
	        (upper - lower + 1)) + lower;
	         fprintf(fPtrIn, "%d\n", num);
	    }
	}
	else{
		printf("uunable to open file ");
	}
	fclose(fPtrIn);
    fPtrIn   = fopen("all.txt", "r");
    fPtrEven = fopen("even.txt" , "w");
    fPtrOdd  = fopen("odd.txt"  , "w");

    if(fPtrIn == NULL || fPtrEven == NULL || fPtrOdd == NULL)
    {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }


    printf("File opened successfully. Reading integers from file. \n\n");

    while (fscanf(fPtrIn, "%d", &num) != -1)
    {
       if (isEven(num))
            fprintf(fPtrEven, "%d\n", num);
        else
            fprintf(fPtrOdd, "%d\n", num);
            
    }
    
    fclose(fPtrIn);
    fclose(fPtrEven);
    fclose(fPtrOdd);
    printf("Data written to files successfully.");


    return 0;
}

int isEven(const int NUM)
{
    return !(NUM & 1);
}
