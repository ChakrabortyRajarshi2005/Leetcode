/*
Day-01 of studying Binary tree 
Code to just build a binary tree using C++ */
/*
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
    // creating Node class , user defined data type to create an node of a binary tree
    class Node {
        public:
            int data;
            Node* left;
            Node* right;
        // constructor to initialize data in the
        Node(int data){
            this->data= data;
            this->left= NULL;
            this->right= NULL;
        }
    };
    // recursive function to print the binary tree
    void printBinaryTree(Node* root){
            if(root == NULL){
                return;

                }
        cout<<root->data<<" ";
        printBinaryTree(root->left);
        printBinaryTree(root->right);
        return;
    }
int main(){
    // creating nodes
    Node *a = new Node(1);
    Node *b = new Node(8);
    Node *e = new Node(7);
    Node *c = new Node(6);
    Node *d = new Node(5);
    Node *f = new Node(4);
    Node *g = new Node(3);
    Node *h = new Node(2);
    // making connections between the nodes
    a->left = b;
    b->left = c;
    c->right = d;
    d->right = e;
    e->left=f;
    f->right = g;
    g->left = h;
    // calling printBinaryTree function
    printBinaryTree(a);
    return 0;
};
*/

// Some basic operations performed in a binary tree
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// creating node class , user defined data type to build a tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // constructor to initialize data
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
// recursive function to print the binary tree (PreOrder Traversal)
void printBinaryTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printBinaryTree(root->left);
    printBinaryTree(root->right);
    return;
}

// function to calculate the sum of all nodes of a binary tree
int calculateSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = calculateSum(root->left);
    int rightSum = calculateSum(root->right);
    int sum = root->data + leftSum + rightSum;
    return sum;
}

// recursive function to calculate size of a tree
int calculateSize(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // int leftSize = calculateSize(root->left);
    // int rightSize = calculateSize(root->right);
    // int size = 1 + leftSize + rightSize;
    int size = 1 + calculateSize(root->left) + calculateSize(root->right);
    return size;
}

// recursive function to calculate node with maximum value in a tree
int calculateMaximum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftmax = calculateMaximum(root->left);
    int rightmax = calculateMaximum(root->right);
    int maxx = max(root->data, max(leftmax, rightmax));
    return maxx;
}

// Recursive function to calculate height of a tree
int calculateHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    int height = 1 + max(leftHeight, rightHeight);
    return height;
}

// main function to be executed
int main()
{
    // creating nodes by the help of node class
    Node *a = new Node(1);
    Node *b = new Node(12);
    Node *e = new Node(7);
    Node *c = new Node(6);
    Node *d = new Node(5);
    Node *f = new Node(4);
    Node *g = new Node(3);
    Node *h = new Node(2);
    // making connections between the nodes
    a->left = b;
    b->left = c;
    c->right = d;
    d->right = e;
    e->left = f;
    f->right = g;
    g->left = h;
    // calling sum function to find the sum of all the nodes
   cout << "The sum of the tree is : " << calculateSum(a) << "\n";
    // calling calculateSize function
   //cout << "The size of the tree is : " << calculateSize(a);
 //  cout << calculateMaximum(a);
   // cout << calculateHeight(a);

    // printBinaryTree(a) ;
    return 0;
}
