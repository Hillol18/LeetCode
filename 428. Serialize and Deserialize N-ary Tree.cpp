//** Hillol **//

/**

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, the above tree may be serialized as [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].

You do not necessarily need to follow the above suggested formats, there are many more different formats that work so please be creative and come up with different approaches yourself.
**/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Codec {
public:
    // Encodes a tree to a single string.

    void encode(Node *r , string &enc, int &cur){
        if(!r){
         return;
        }

        enc[cur]='[';
        cur++;
        string temp = to_string(r->val);
        for(int i=0;i<temp.size();i++){
            enc[cur++]= temp[i];
        }
        for(int i=0;i<r->children.size();i++){
          encode(r->children[i], enc, cur);
        }

          enc[cur]=']';
          cur++;

    }

    string serialize(Node* root) {
        string enc;
        enc.resize(40000);
        int cur = 0;
        encode(root, enc, cur);
        enc.resize(cur);
    return enc;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int len = data.size();
        stack<Node*>st;
        int number = 0;
        Node *temp =nullptr;
        int cur = 0;
        cout<<data<<endl;
        while(cur<len){
            if(data[cur]== '['){
                number = 0;
                temp = new Node();
                cur++;
                while(cur <len && data[cur] >='0' && data[cur] <='9' ){
                    number *=10;
                    number+=(data[cur++]-'0');
                }
                temp->val = number;
                st.push(temp);
                continue;
            }

            if(data[cur] == ']'){
             temp = st.top();
                st.pop();
                if(st.empty()){
                    return temp;
                }
                else{
                    st.top()->children.push_back(temp);

                }
               cur++;
            }
        }
        return temp;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
