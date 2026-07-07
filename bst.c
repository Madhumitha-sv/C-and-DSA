#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node* insert(struct node* root, int value)
{
    if(root == NULL)
    {
        struct node *newnode;

        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}
void search(struct node* root, int key) 
{
    if (root == NULL) 
	{
        printf("Element not found\n");
        return;
    }

    if (key == root->data) 
	{
        printf("Element found\n");
        return;
    }

    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

struct node *min(struct node *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node* deleteNode(struct node* root, int key) 
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) 
		{
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL) 
		{
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = min(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct node* root) 
{
    if (root != NULL) 
	{
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) 
{
    if (root != NULL) 
	{
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) 
{
    if (root != NULL) 
	{
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() 
{
    struct node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
