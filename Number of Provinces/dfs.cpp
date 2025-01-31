class Solution {
public:

/// it is given that when adj[i][j] = 1 , then the graph is connected and if it is adj[i][j] = 0 , then it is not connected
    void DFS(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited) {
        visited[u] = true; // Mark current city as visited
        
        for (int &v : adj[u]) { 
            if(!visited[v]){
                DFS(adj, v, visited); // Recursive DFS
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Number of cities
        vector<bool> visited(n, false); // Visited array
        int count = 0; // Province counter

        // self declaring adj list

        unordered_map<int,vector<int>> adj;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){ // it is given that they are connected if coneceted[i][j]=1
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};