#include <iostream>

using namespace std; 

struct node { 
    int key; 
    struct node *left;  
    struct node *right; 
}; 

  

// creating a node 

struct node *createNode(int val) { 
    struct node *tempNode =  (struct node *)malloc(sizeof(struct node)); 
    tempNode->key = val; 
    tempNode->left = tempNode->right = NULL; 
    return tempNode; 
} 

  

// Inorder traversal 

void traverseInOrder(struct node *root) { 
    //recurse to bootom node
    if (root != NULL) { 
        traverseInOrder(root->left); 
        cout << root->key << " "; 
        traverseInOrder(root->right); 
    } 
} 

// Insert a node 

struct node *insertNode(struct node *node, int key) { 
    // check If the tree is empty
    if (node == NULL)  
        return createNode(key); 
    if (key < node->key) { 
        node->left = insertNode(node->left, key); 
    } else if (key > node->key) { 
        node->right = insertNode(node->right, key); 
  } 
  return node; 
} 

  

// Deleting a node 

struct node *deleteNode(struct node *root, int key) {
  // checking if tree is empty
  if (root == NULL) {
    return root;
  }

  if (key < root->key) {
      
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
      
    root->right = deleteNode(root->right, key);
    
  } else { 
  
    // search whether node has no children
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    }
    
    // search whether node has one child
    else if (root->left == NULL) {
      struct node *tempNode = root;
      root = root->right;
      delete tempNode;
    } else if (root->right == NULL) {
      struct node *tempNode = root;
      root = root->left;
      delete tempNode;
    }
    
    // search whether node has two children
    else {
      struct node *tempNode = root->right;
      while (tempNode->left != NULL) {
        tempNode = tempNode->left;
      }
      root->key = tempNode->key;
      root->right = deleteNode(root->right, tempNode->key);
    }
  }
  return root;
}


  

// Driver code 
int main() { 
  struct node *root = NULL; 
  int operation; 
  int operand; 
  cin >> operation; 
  while (operation != -1) { 
    switch(operation) { 
      case 1: // insert 
        cin >> operand; 
        root = insertNode(root, operand); 
        cin >> operation; 
        break; 
      case 2: // delete 
        cin >> operand; 
        root = deleteNode(root, operand); 
        cin >> operation; 
        break; 
      default: 
        cout << "Invalid Operator!\n"; 
        return 0; 
    } 
  } 
  traverseInOrder(root); 
} 
