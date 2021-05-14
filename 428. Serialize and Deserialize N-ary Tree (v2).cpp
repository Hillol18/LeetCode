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


[1]

*/

class Codec {


private:
    void incode(Node* r, stringstream &ss){
        if(!r) {
            //ss<<"# ";
            return;
        }
        ss<<"[ ";
        ss<<r->val;
        ss<<" ";

        int n = r->children.size();
        for(int i=0;i<n;i++){
            incode(r->children[i], ss);
        }

        ss<<"] ";
    }

    Node* decode(stringstream &ss){
        string s;

        ss>>s;
        //cout<<s<<endl;
        Node *n = new Node(stoi(s));
        while(ss>>s){
            if(s == "["){
                Node *ch = decode(ss);
                if(ch) n->children.push_back(ch);
            }
            else break;

        }

        return n;
    }

public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        stringstream ss;
        incode(root, ss);
        cout<<ss.str()<<endl;
        return ss.str();
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        string s;
        ss>>s;
        if(s != "[") return NULL;
        return decode(ss);
    }
};
