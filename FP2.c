#include <stdio.h>
#include <conio.h>
struct student{
    double marks;
    char name[30];

}s[10];
void main()
{
    printf("Coded by Deepak(04335304421)\n");

    FILE *f1;
    int num, size=0,i;
    double max=0.0,second=0.0,third=0.0;
    f1 = fopen("students.txt", "r");
    if(f1==NULL){
    	printf("Error");
	}
    while (!feof(f1))
    {
        fscanf(f1,"%lf",&s[size].marks);
        fscanf(f1,"%s",&s[size].name);
        
        size++;

    }
    for(i=0;i<size;i++)
    {
        if(max<s[i].marks)
            max=s[i].marks;
    }
    printf("\nThe highest marks: %.2f",max);

    printf("\n\nThe list of students having highest grade: ");
    for(i=0;i<size;i++)
    {
        if(s[i].marks==max)
            printf("\n%s",s[i].name);
    }

     
    for (i = 0; i < size; i++)
        if (s[i].marks > second && s[i].marks < max)
            second = s[i].marks;
 

    for (i = 0; i < size; i++)
        if (s[i].marks > third && s[i].marks < second)
            third = s[i].marks;
 
    printf("\n\nThe third Largest element is %.2f\n", third);  
    
}
