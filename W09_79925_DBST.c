#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int key;
    struct Node *left, *right;
} Node;

Node *minValueNode(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);

            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);

            return temp;
        }

        Node *temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

Node *newNode(int item)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;

    return temp;
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Base Tree\n");
    printf("Preorder     : ");
    preOrder(root);
    printf("\n");
    printf("Inorder      : ");
    inOrder(root);
    printf("\n");
    printf("Postorder    : ");
    postOrder(root);
    printf("\n");

    printf("Deleting node 20\n");
    deleteNode(root, 20);
    printf("Preorder     : ");
    preOrder(root);
    printf("\n");
    printf("Inorder      : ");
    inOrder(root);
    printf("\n");
    printf("Postorder    : ");
    postOrder(root);
    printf("\n");

    printf("Deleting node 30\n");
    deleteNode(root, 30);
    printf("Preorder     : ");
    preOrder(root);
    printf("\n");
    printf("Inorder      : ");
    inOrder(root);
    printf("\n");
    printf("Postorder    : ");
    postOrder(root);
    printf("\n");

    printf("Deleting node 70\n");
    deleteNode(root, 70);
    printf("Preorder     : ");
    preOrder(root);
    printf("\n");
    printf("Inorder      : ");
    inOrder(root);
    printf("\n");
    printf("Postorder    : ");
    postOrder(root);
    printf("\n");

    return 0;
}
