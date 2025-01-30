// using thr DFS concept

class Solution {
  public:
  
  bool isCycleDFS(vector<vector<int>>& adj,int u, vector<bool>&visited, int parent){
      visited[u]=true;
      
      for(int &v :adj[u]){
          if(v==parent) continue;
          if(visited[v]) return true; // agar already visited kar chuke and fir se uske paas ja rahay hai pata chal jayega ki cycle ban rha yhai
          if(isCycleDFS(adj,v,visited,u)){// v ke liye uska parent u hi hoga nah
              return true;
          }
      }
      return false;
  }
 // BFS CODE
  bool isCycleBFS(vector<vector<int>>& adj,int u, vector<bool>&visited){
     queue<pair<int,int>>que;
     
     
     que.push({u,-1}); // initially u ka parent -1
     visited[u]=true;
     
     while(!que.empty()){
         pair<int,int> P =que.front(); // jo bhi nikalte jayenge woh as a pair banke hi toh bahar ayega
         que.pop();
         
         int source = P.first;
         int parent= P.second;
         
         for(int &v :adj[source]){
             if(visited[v] == false){// agar visted nahi hai toh
                 visited[v]=true;// visit karlo and
                 que.push({v,source});// queue mei push kardo
             }else if(v != parent){// agar woh already visited and woh us node ka parent nahi hai toh matlab cycle ban gya hai
                 return true;
             }
         }
     }
     return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int V=adj.size();
        
        vector<bool>visited(V,false);
        
        for(int i=0;i<V;i++){ // for looop isliye talki kabhi kabhi na ek complete graph na deke uske badle mei alag alag component mmei graph de diya jatya hai
        // isliye for loop laga rhay hai taki sare k sare cover up ho jaye 
            if(!visited[i] && isCycleDFS(adj,i,visited,-1)){
                return true;
            }
        }
        return false;
    }
}; 

