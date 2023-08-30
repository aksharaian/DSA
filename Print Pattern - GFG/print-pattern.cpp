//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   
   void helper(vector<int>& res , int present){
      
      if(present <= 0){
          res.push_back(present);
          return;
      }
      res.push_back(present);
      helper(res, present - 5);
      res.push_back(present);
    
   }
    
    vector<int> pattern(int N){
        
     vector<int>res;
     helper(res, N);
     return res;
     
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends