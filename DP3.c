#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};
struct tree *insert(struct tree *,int);
void inorder(struct tree *);
void postorder(struct tree *);
void preorder(struct tree *);
struct tree *delet(struct tree *,int);
struct tree *search(struct tree *);
int main(void) {
	printf("Coded by Deepak(04335304421)"\n);
	struct tree *root;
	int choice, item,item_no;
	root = NULL;
	do {
		do {
			printf("\n \t 1. Insert in Binary Tree  ");
			printf("\n\t 2. Delete from Binary Tree ");
			printf("\n\t 3. Inorder traversal of Binary tree");
			printf("\n\t 4. Postorder traversal of Binary tree");
			printf("\n\t 5. Preorder traversal of Binary tree");
			printf("\n\t 7. Exit ");
			printf("\n\t Enter choice : ");
			scanf(" %d",&choice);
			if(choice<1 || choice>7)
			      printf("\n Invalid choice - try again");
		}
		while (choice<1 || choice>7);
		switch(choice) {
			case 1:
				   printf("\n Enter new element: ");
			scanf("%d", &item);
			root= insert(root,item);
			printf("\n root is %d",root->info);
			printf("\n Inorder traversal of binary tree is : ");
			inorder(root);
			break;
			case 2:
				  printf("\n Enter the element to be deleted : ");
			scanf(" %d",&item_no);
			root=delet(root,item_no);
			inorder(root);
			break;
			case 3:
				  printf("\n Inorder traversal of binary tree is : ");
			inorder(root);
			break;
			case 4:
				  printf("\n Postorder traversal of binary tree is : ");
			postorder(root);
			break;
			case 5:
				  printf("\n Preorder traversal of binary tree is : ");
			preorder(root);
			break;
			default:
				   printf("\n End of program ~~Deepak~~ ");
		}
	}
	while(choice !=7);
	return(0);
}
struct tree *insert(struct tree *root, int x) {
	if(!root) {
		root=(struct tree*)malloc(sizeof(struct tree));
		root->info = x;
		root->left = NULL;
		root->right = NULL;
		return(root);
	}
	if(root->info > x)
	     root->left = insert(root->left,x); else {
		if(root->info < x)
			root->right = insert(root->right,x);
	}
	return(root);
}
void inorder(struct tree *root) {
	if(root != NULL) {
		inorder(root->left);
		printf(" %d",root->info);
		inorder(root->right);
	}
	return;
}
void postorder(struct tree *root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf(" %d",root->info);
	}
	return;
}
void preorder(struct tree *root) {
	if(root != NULL) {
		printf(" %d",root->info);
		preorder(root->left);
		preorder(root->right);
	}
	return;
}
struct tree *delet(struct tree *ptr,int x) {
	struct tree *p1,*p2;
	if(!ptr) {
		printf("\n Node not found ");
		return(ptr);
	} else {
		if(ptr->info < x) {
			ptr->right = delet(ptr->right,x);
			
		} else if (ptr->info >x) {
			ptr->left=delet(ptr->left,x);
			return ptr;
		} else                     
				 {
			if(ptr->info == x)    
					 {
				if(ptr->left == ptr->right) 
					 {
					free(ptr);
					return(NULL);
				} else if(ptr->left==NULL)  
				 {
					p1=ptr->right;
					free(ptr);
					return p1;
				} else if(ptr->right==NULL)   
										 {
					p1=ptr->left;
					free(ptr);
					return p1;
				} else {
					p1=ptr->right;
					p2=ptr->right;
					while(p1->left != NULL)
						    p1=p1->left;
					p1->left=ptr->left;
					free(ptr);
					return p2;
				}
			}
		
		}
		
	}
	return(ptr);
}