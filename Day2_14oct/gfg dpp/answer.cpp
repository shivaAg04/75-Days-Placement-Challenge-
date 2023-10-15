//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector<int>root1data;
    vector<int>root2data;
    void a(Node *root1){
        if(!root1) return;
        root1data.push_back(root1->data);
        a(root1->left);
        a(root1->right);
    }
     void b(Node *root1){
         
        if(!root1) return;
        root2data.push_back(root1->data);
        b(root1->left);
        b(root1->right);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int>ans;
        a(root1);
        b(root2);
        int i = 0 ; int j = 0 ;
        sort(root1data.begin() , root1data.end());
        sort(root2data.begin() , root2data.end());
        while(i<root1data.size()&&j<root2data.size()){
             int p = root1data[i];
        int q = root2data[j];
        if(p==q){i++;
        j++;
            ans.push_back(p);
            
        }else if(p>q){
            j++;
        }else{
            i++;
        }
            
        }
       
        
        return ans;
      
    }
};
  
  
  
  



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }

	return 1;
}
// } Driver Code Ends