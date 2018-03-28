#ifndef _TREE_HPP_
#define _TREE_HPP_

#include <stack> 
#include <iostream> 
#include <algorithm> 

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

/*
Pre-order[edit]
Display the data part of root element (or current element)
Traverse the left subtree by recursively calling the pre-order function.
Traverse the right subtree by recursively calling the pre-order function.
*/

void Preorder(node *root)
{     
    stack<node*> inspector;
    inspector.push(root); 
    
    while (!inspector.empty())
    {
        node* current = inspector.top();
        inspector.pop();      
        
        if (current)
        {            
            cout << current->data << " ";        
            inspector.push(current->right);
            inspector.push(current->left);
        }
    }       
}

/*In-order (symmetric)[edit]
Traverse the left subtree by recursively calling the in-order function
Display the data part of root element (or current element)
Traverse the right subtree by recursively calling the in-order function*/
void inorder(node *root)
{     
    stack<node*> inspector;
    inspector.push(root); 
    
    while (!inspector.empty())
    {
        node* current = inspector.top();
        inspector.pop();      
        
        if (current)
        {                                
            inspector.push(current->right);
            cout << current->data << " ";
            inspector.push(current->left);
        }
    }       
}

/*Post-order[edit]
Traverse the left subtree by recursively calling the post-order function.
Traverse the right subtree by recursively calling the post-order function.
Display the data part of root element (or current element).
*/
void postOrder(node *root)
{     
    stack<node*> inspector;
    inspector.push(root); 
    
    while (!inspector.empty())
    {
        node* current = inspector.top();
        inspector.pop();      
        
        if (current)
        {  
            inspector.push(current->right);            
            inspector.push(current->left);
            cout << current->data << " ";
        }
    }       
}

#endif // _TREE_HPP_