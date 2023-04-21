//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution {
public:


 int pos(int in[], int start , int end , int key){
            for(int i=start; i<=end;i++)
                if(in[i] == key)
                    return i;
                    
            return -1;
        }
     
     
     Node* solve(int in[], int pre[], int &index, int instart,int inend,int n)
     {
         if(instart > inend || index >=n)
            return NULL;
            
        int element = pre[index];
        index++;
        
        int position = pos(in,instart,inend,element);
        
        Node* root= new Node(element);
        root->left = solve(in,pre,index,instart,position-1,n);
        root->right = solve(in,pre,index,position+1,inend,n);
        
        return root;
     }
     
        
     
     
    Node* buildTree(int in[],int pre[], int n)
    {
     int preorderIndex=0;
     
     Node* ans= solve(in,pre,preorderIndex,0,n-1,n);
     return ans;
    }
};






//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends