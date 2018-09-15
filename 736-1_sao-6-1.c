#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int value;
	int key;
	struct node *left;
	struct node *right;
	struct node *parent;
} node;

node *init()
{
	node *root = malloc(sizeof(node));
	root->value=-1;
	root->key=-1;
	root->left=NULL;
	root->right=NULL;
	root->parent=NULL;
	return root;
}

void add (node *root, int key, int value)
{

	for(;;)
	{
		if (root->key==-1)
		{
			root->key=key;
			root->value=value;
			break;
		}
		
		if (root->key==key)
		{
			root->value=value;
			break;
		}	
	
	
		if (key>root->key)
		{
			if (root->right==NULL)
			{
				node *tmp = init();
				root->right = tmp;
				tmp->key=key;
				tmp->value=value;
				tmp->parent=root;
				break;
			}
			else
			{
				root=root->right;
				continue;
			}
		}
	
	
		if (key<root->key)
		{
			if (root->left==NULL)
			{
				node *tmp = init();
				root->left = tmp;
				tmp->key=key;
				tmp->value=value;
				tmp->parent=root;
				break;
			}
			else
			{
				root=root->left;
				continue;
			}
		}
	}
	
}


void postOrderTravers(node *root)
{
	if (root) {
        	postOrderTravers(root->left);
        	postOrderTravers(root->right);
        	printf("%d ", root->value);
    	}
}

void destroy(node *root)
{
	node *tmp=NULL;
	for(;;)
	{
		if (root->left!=NULL)
		{
			root=root->left;
			continue;
		}
		if (root->right!=NULL)
		{
			root=root->right;
			continue;
		}
		
		tmp=root->parent;
		if (tmp!=NULL)
		{
			if (tmp->key>root->key)
				tmp->left=NULL;
			else
				tmp->right=NULL;
				
			free(root);
			root=tmp;
		}
		else
		{
			free(root);
			break;
		}
	}
}

int main()
{
	int n=0,key=0,value=0;
	
	node *root=init();
	
	scanf("%d",&n);
	
	for (int i=0;i<n;i++) 
	{ 
		scanf ("%d", &key);
		scanf ("%d", &value);
		add(root, key, value); 
	}
	
	postOrderTravers(root);
	
	destroy(root);
	
	return 0;
}
