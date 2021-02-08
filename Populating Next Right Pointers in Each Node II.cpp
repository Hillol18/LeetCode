/**
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
**/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    Node* nextNode(Node *node, int &step){
        if(!node){
            return nullptr;    
        }
        
        if(step == 0){
            if(node->left )
                return node;
            return nextNode(node, step = 1);
        }
        if(step == 1){
            if(node->right != nullptr)
                return node;
            return nextNode(node, step = 2);
        }
        else {
           return nextNode(node->next, step = 0);
        }
    }
    
    Node* connect(Node* root) {
        
        Node* lN = nullptr;        
        Node* pN = root;
        Node* fc = nullptr;
        int step = 0;
        while(pN){            
         Node* curr = nextNode(pN, step);           
            if(!curr){
                pN = fc;
                lN = nullptr;
                fc = nullptr;
                step = 0;
                continue;
            }
            pN = curr;
            //cout<<pN->val<<endl;;
            
            Node* cc;
            if(step==0)
                cc = curr->left;
            else if(step == 1)
                cc = curr->right;
         //   cout<<" -- "<<cc->val<<endl;
            if(lN) lN->next = cc;
            lN = cc;
            
            if(!fc) fc = cc;
            step++;
            
        }
        return root;
    }
};
