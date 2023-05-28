//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
     void dfs(int i,int visited[],vector<pair<int,int>> adj[],stack<int> &stk){
         
         visited[i] = 1;
         
         for(auto it : adj[i]){
             int current = it.first;
             if(!visited[current]){
                 dfs(current,visited,adj,stk);
             }
         }
         stk.push(i);
     }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        //first converting  graph into adjacency list
        vector<pair<int,int>> adj[N];
        
        for(int i=0;i<M;i++){
            int first = edges[i][0];
            int second = edges[i][1];
            int weight = edges[i][2];
            adj[first].push_back({second,weight});
        }
        
        //now simply calculating topo sort using dfs technique
        int visited[N] = {0};
        stack<int> stk;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                dfs(i,visited,adj,stk);
            }
        }
        
        vector<int> dist(N,1e9);
        dist[0] = 0;
        //removing those nodes which are above source node which is 0 because they will be unreachable
        for (int i = 0; i < N; i++) {
            if(stk.top() !=  0){
                int node = stk.top();
                dist[node] = -1;
                stk.pop();
            }
            else break;
        }
        
        //remove elements from the stack and check if the distance using that node reaching its adjacent node could be reduced
        while(!stk.empty()){
            int ele = stk.top();
            stk.pop();
            
            for(auto it: adj[ele]){
                if(dist[ele] + it.second < dist[it.first]){
                    dist[it.first] = dist[ele] + it.second;
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends