//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	
	void helper(string s, int ind, int n, string curr, vector<string>&res){
	    
	    if(ind == n) {
	        res.push_back(curr);
	        return;
	    }
	    //include
	    helper(s, ind+1, n, curr+s[ind], res);    //curr is for subseq ab
	    
	    //exclude
	    helper(s, ind+1, n,curr, res );
	    
	}
		vector<string> AllPossibleStrings(string s){
		    
		    vector<string>res;
		    helper(s, 0, s.size(), "", res);
		    sort(res.begin(), res.end());
		    res.erase(res.begin());
		    return res;
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends