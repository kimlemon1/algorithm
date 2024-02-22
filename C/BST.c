#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int val;
    struct node *left, *right;
};
 
// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->val = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to insert
// a new node with given key in BST
struct node* insert(struct node* node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);
 
    // Otherwise, recur down the tree
    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
 
    // Return the (unchanged) node pointer
    return node;
}
 
// Utility function to search a key in a BST
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->val == key)
        return root;
 
    // Key is greater than root's key
    if (root->val < key)
        return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
 
struct node* deleteNode(struct node* root, int key)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->val > key) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if (root->val < key) {
        root->right = deleteNode(root->right, key);
        return root;
    }
 
    // We reach here when root is the node
    // to be deleted.
 
    // If one of the children is empty
    if (root->left == NULL) {
        struct node* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        struct node* temp = root->left;
        free(root);
        return temp;
    }
 
    // If both children exist
    else {
 
        struct node* succParent = root;
 
        // Find successor
        struct node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->val = succ->val;
 
        // Delete Successor and return root
        free(succ);
        return root;
    }
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

// Driver Code
int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    // Key to be found
    int key = 6;
 
    // Searching in a BST
    if (search(root, key) == NULL)
        printf("%d not found\n", key);
    else
        printf("%d found\n", key);
 
    key = 60;
 
    // Searching in a BST
    if (search(root, key) == NULL)
        printf("%d not found\n", key);
    else
        printf("%d found\n", key);
    
    deleteNode(root, 60);
    deleteNode(root, 50);
    
    return 0;


}