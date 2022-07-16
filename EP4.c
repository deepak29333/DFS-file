#include<stdio.h>
#include<conio.h>
#define INF 999
int min(int,int);
void floyds(int p[6][6],int n) {
	int i,j,k;
	for (k=1;k<=n;k++)
	  for (i=1;i<=n;i++)
	   for (j=1;j<=n;j++)
	    if(i==j)
	     p[i][j]=0; else
	     p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
int min(int a,int b) {
	if(a<b)
	  return(a); else
	  return(b);
}
void main() {
	printf("Coded By Deepak(04335304421)\n");
	int w,n,e,u,v,i,j;
	n=6;
	int p[6][6]={
					{INF,3,9,INF,INF,INF},
					{3,INF,8,9,11,INF},
					{9,8,INF,1,INF,2},
					{INF,9,1,INF,6,9},
					{INF,9,INF,6,INF,7},
					{INF,INF,2,9,7,INF}
				};
	printf("\n Matrix of input data:\n");
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++)
		   printf("%d \t",p[i][j]);
		printf("\n");
	}
	printf("\n The shortest paths are:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++) {
		if(i!=j)
		    printf("\n <%d,%d>=%d",i,j,p[i][j]);
	}
}
