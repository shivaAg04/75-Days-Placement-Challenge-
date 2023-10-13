class Solution{

public:
    int floor(Node* root, int x) {
        int ans = -1;
       
        while(root){
            
            int a = root->data;
            if(a == x) return x;
            if(a<x){
                ans = a;
                root= root->right;
                
            }else{
                root = root->left;
            }
        }
        return ans;
    }
};

