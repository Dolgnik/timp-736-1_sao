#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
        struct tree* right;
        struct tree* left;
        int value;
	int key;
} tree;

tree* CreateTree()
{
        tree* creation = (tree*)malloc(sizeof(tree));
        if(creation == NULL) return NULL;
	creation->left = NULL;
	creation->right = NULL;
        creation->key = -1;
	return creation;
}

void add(tree *root, int key, int value)
{
	for(;;)
	{
		if(root->key == -1)
		{
			root->key = key;
			root->value = value;
			break;
		}
		if(root->key == key)
		{
			root->key == key;
			break;
		}
		if(key > root->key)
		{
			if(root->right == NULL)
			{
				tree *ptr = CreateTree();
				root->right = ptr;
				ptr->key = key;
				ptr->value = value;
				break;
			}
			else
			{
				root = root->right;
			}
		}
		else
		{
			if(root->left == NULL)
                        {
                                tree *ptr = CreateTree();
                                root->left = ptr;
                                ptr->key = key;
                                ptr->value = value;
                                break;
                        }
                        else
                        {
                                root = root->left;
                        }
		}
	}
}

void print(tree *root, int key)
{
	int count = 0;
	for(;;)
	{
		if(key == root->key)
		{
			printf("%d %d", count, root->value);
			break;
		}
		if(key > root->key)
		{
			if(root->right == NULL)
			{
				printf("-1");
				break;
			}
			else
			{
				root = root->right;
				count++;
			}
		}
		else
		{
			if(root->left == NULL)
                        {
                                printf("-1");
                                break;
                        }
                        else
                        {
                                root = root->left;
                                count++;
                        }
		}
	}
	printf("\n");
}

int main()
{
	int n, a, b, c, key, value;
	
	tree *root = CreateTree();
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &key);
		scanf("%d", &value);
		add(root, key, value);
	}
	scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
     	print(root, a);
	print(root, b);
	print(root, c);
	return 0;
}
