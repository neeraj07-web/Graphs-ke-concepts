// using the DFS

 class Solution {
  public:

// this code is by using the dfs
  bool isCycleDFS( vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion){
      visited[u]=true;
      inRecursion[u]=true;
      
      for(int &v : adj[u]){
          // if not visited then we will check for cycle in DFS
          // agar visited nahi hai toh DFS mar k check kar liye ki cycle hai ya nahi
          if(visited[v] == false && isCycleDFS(adj,v,visited,inRecursion)){
              return true;
          }else if(inRecursion[v] == true )// agar woh visited and inRecursion mei true nikal gya toh bhi woh cycle bana rha hai
          return true;
      }
      inRecursion[u] = false;// jab ek dfs se bahar aa jayenge toh vapis se inRecusrion ko false kar denga na
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> visited(V,false);
        vector<bool> inRecursion(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i] && isCycleDFS(adj,i,visited,inRecursion)){
                return true;
            }
        }
        return false;
    }
};
