class Codec {
public:

    void serializeHelper(TreeNode *root, string &s){
        if(!root) return;
        if(s.size()){
            s+=" ";
        }
        s+=to_string(root->val);

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string enc = "";
        serializeHelper(root, enc);
        return enc;
    }

    TreeNode* decodeHelper(int &pos, vector<int> &data, int mn, int mx){
        if(pos==data.size()) return NULL;
        if(mn > data[pos] || data[pos] > mx) return NULL;
        TreeNode *r = new TreeNode(data[pos]);
        pos++;
        r->left = decodeHelper(pos,data, mn, r->val);
        r->right = decodeHelper(pos,data,r->val, mx);

        return r;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        vector<int> d;
        int temp;
        while(s>>temp){
            d.push_back(temp);
        }
        int pos=0;
        return decodeHelper(pos, d, INT_MIN, INT_MAX);
    }
};
