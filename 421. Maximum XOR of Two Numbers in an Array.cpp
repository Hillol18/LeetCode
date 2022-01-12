class Solution {
public:
    
    struct node{
        node(){
            zero = NULL;
            one = NULL;
        }
        node* zero;
        node* one;
    };
    
    
    void insertIntoTrie(node *r, int val){
        for(int i = 30; i >= 0; i--){
            if(val & (1<<i)){
                
                if(!r->one){
                    r->one = new node();
                }
                r = r->one;
            }
            else{
                
                if(!r->zero){
                    r->zero = new node();
                }
                r = r->zero;
            }
        }    
    }
    
    int getValue(node *r , int val){
        int ans = 0;
        for(int i = 30; i >= 0 && r; i--){
            if(val & (1<<i)){
                if(r->zero){
                    ans |= (1<<i);
                    r= r->zero;
                }
                else r = r->one;
                
            }
            else{
                if(r->one){
                    ans |= (1<<i);
                    r= r->one;
                }
                else r = r->zero;
            }
        }
        return ans;
    }
    
    
    int findMaximumXOR(vector<int>& nums) {
        node * r = new node();
        insertIntoTrie(r, nums[0]);
        int mx = 0;
        for(int  i = 1; i< nums.size(); i++){
            int v = getValue(r, nums[i]);    
            mx = max(mx, v);
            insertIntoTrie(r, nums[i]);
        }
        return mx;
    }
};