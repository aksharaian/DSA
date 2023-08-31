//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    
    int helper(int arr[], int N, int K, int l, int h){
        while(l>h) return -1;
        
        int mid= (l+h)/2;
        if(arr[mid] > K){
            helper(arr, N, K, l, mid-1);
        }else if(arr[mid] < K){
            helper(arr, N, K, mid+1, h);
        }else{
            return 1;
        }
        
    }
    
    int searchInSorted(int arr[], int N, int K) 
    { 
    return helper(arr, N, K , 0, N-1);
                             //l h values
       
    }
};

//{ Driver Code Starts.


int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 

// } Driver Code Ends