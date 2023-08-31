//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	bool helper(string &S, int l, int h){
	    if(l>=h) return true ;
	    if(S[l] != S[h]){
	        return false;
	    }
	    return helper(S, l+1, h-1);
	}
	
	int isPalindrome(string S)
	{
	     return helper(S,0, S.size()-1)?1:0;
	     
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends