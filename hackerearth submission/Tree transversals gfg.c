// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct node
{
     int val;
     struct node* left;
     struct node* right;
}n;

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
     struct node* node = (struct node*)
                                  malloc(sizeof(struct node));
     node->val = data;
     node->left = NULL;
     node->right = NULL;

     return(node);
}

void inorder(n* root)    // my implementation of in order.
{
    if(root->left!=NULL)
    {
            inorder(root->left);
            printf("%d ",root->val);
            inorder(root->right);
    }
    else
        printf("%d ",root->val);

}

int main()
{
     struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5);

     //printf("\nPreorder traversal of binary tree is \n");
     //printPreorder(root);

     printf("\nInorder traversal of binary tree is \n");
     inorder(root);

     //printf("\nPostorder traversal of binary tree is \n");
     //printPostorder(root);

     return 0;
}
