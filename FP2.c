#include<stdio.h>
#include<stdlib.h>
struct stud{
	char name[20];
	float marks;
};
void main(){
	FILE *fptr;
	
	struct stud obj;
//	fptr=fopen("stud.txt","w");
//	fwrite(&obj,sizeof(obj),1,fptr);
//	fclose(fptr);
	fptr=fopen("stud.txt","r");
	fread(&obj,sizeof(obj),1,fptr);
	printf("%s %f", obj.name,obj.marks);
}
