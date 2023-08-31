//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void helper(string &S, int l, int h){
       if(l>=h) return;
        swap(S[l], S[h]);
        helper(S, l+1, h-1);
    }
    
    
    string revStr(string S) {
        helper(S, 0, S.size() -1);
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.revStr(S) << endl;
    }
    return 0;
}

// } Driver Code Ends