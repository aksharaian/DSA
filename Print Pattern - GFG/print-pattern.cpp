//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   
   void helper(vector<int>& res ,int N, int present, bool inc){
       res.push_back(present);
       
       if(inc){
           if(present == N)
              return;
           else helper(res, N, present + 5, true);
       }else {
           if(present - 5> 0) helper(res, N, present-5, false);
       else helper(res, N, present -5, true);
       
       }
   }
    
    vector<int> pattern(int N){
        
     vector<int>res;
     helper(res, N, N, false);
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