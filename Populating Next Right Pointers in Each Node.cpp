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
        
    Node* connect(Node* root) {
        Node* ans = root;
        Node* first = new Node();
        Node* dummy = first;
        bool flag = false;
        while(root){
            while(root){
                if(!flag && root->left){
                    dummy->next = root->left;
                    dummy = dummy->next;
                    //cout<<dummy->val<<" ";
                }
                else if(flag && root->right){
                    dummy->next = root->right;
                    dummy = dummy->next;
                    //cout<<dummy->val<<" ";
                }
                
                if(flag)
                   root = root->next;
                flag = !flag;
            }
            cout<<endl;
            
            root = first->next;
            first->next = NULL;
            dummy = first;
        }
     return ans;   
    }
};