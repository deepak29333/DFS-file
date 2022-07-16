#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//creating structure of a tree node
struct node
{
	int data;
	struct Node *left;
	struct Node *right;
};

typedef struct node Node;

Node *root = NULL;

Node *newNode(int);
Node *insert(Node *,int);
Node *minNode(Node *);
Node *deleteNode(Node *,int);
void preorder(Node *);
void inorder(Node *);
void postorder(Node *);
int leafNode(Node *);

Node *newNode(int item)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = item;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

Node * insert(struct node *root,int item)
{
	if(root==NULL)
	{
		return newNode(item);
	}
	
	if(item < root->data)
	{
		root->left = insert(root->left,item);
	}
	else
		root->right = insert(root->right,item);
		
	return root;
}

Node *minNode(Node *node)
{
	Node *curr = node;
	
	while(curr && curr->left!=NULL)
		curr = curr->left;
		
	return curr;
}

Node *deleteNode(Node *root,int item)
{
	if(root == NULL)
		return root;
		
	if(item < root->data)
		root->left = deleteNode(root->left,item);
		
	else if(item > root->data)
		root->right = deleteNode(root->right,item);
		
	else
	{
		if(root->left == NULL)
		{
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			Node *temp = root->left;
			free(root);
			return temp;
		}
		Node *temp = minNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right,temp->data);
	}
	return root;
}

void preorder(Node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void postorder(Node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

int leafNode(Node *root)
{
	if(root==NULL);
		return 0;
	
	if(root->left == NULL && root->right == NULL)
		{
		return 1;
		}
	else
		{
			return leafNode(root->left) + leafNode(root->right);	
		}		
}

//main function
int main()
{
	int ch,item;
	do{
		printf("\n\n\t\tMENU");
		printf("\n1.INSERT AN ITEM IN THE TREE");
		printf("\n2.DELETE AN ITEM FROM THE TREE");
		printf("\n3.PREORDER TRAVERSAL");
		printf("\n4.INORDER TRAVERSAL");
		printf("\n5.POSTORDER TRAVERSAL");
		printf("\n6.DETERMINE TOTAL NUMBER OF LEAF NODE IN THE TREE");
		printf("\n7.EXIT...");
		printf("\n  Input your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the item to insert : ");
					scanf("%d",&item);
					root = insert(root,item);
					printf("Item inserted successfully");
					break;
			
			case 2: printf("\nEnter the item to delete : ");
					scanf("%d",&item);
					root = deleteNode(root,item);
					printf("Item deleted successfully");
					break;
			
			case 3: printf("\nPREORDER TRAVERSAL : ");
					preorder(root);
					break;
					
			case 4: printf("\nINORDER TRAVERSAL : ");
					inorder(root);
					break;
					
			case 5: printf("\nPOSTORDER TRAVERSAL : ");
					postorder(root);
					break;
					
			case 6: printf("Leaf count of the tree is %d", leafNode(root));
					break;
					
			case 7: exit(0);
					break;
					
			default : printf("INVALID CHOICE!!!");		
		}
	}while(ch!=7);
	
	return 0;
}
