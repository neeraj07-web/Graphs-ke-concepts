class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
      int V=adj.size();
      vector<int> indegree(V,0);
      
      queue<int>que;
      
      // Step 1:indegree calculate karenge.. 
      // u------> v jane pe v ki hi indegree badhegi, therefore indegree[v]++
      for(int u=0;u<V;u++){
          for(int &v : adj[u]){
              indegree[v]++;
          }
      }
      
      // Step 2:fill the queue , with those having the indegreee as 0
      for(int i=0;i<V;i++){
          if(indegree[i] == 0){
              que.push(i);
          }
      }
      
      // step 3 - Simple BFS
      vector<int>result;
      while(!que.empty()){
          int u=que.front();
          
          // jo queue se niklega usse resullt mei store karte jayenge
          result.push_back(u);
          
          que.pop(); // u queue se pop ho gya hai toh isliye hum uske jitne bhi neighbours hai un ki indegree kam karte jayenge
      
          for(int &v : adj[u]){
              indegree[v]--;
              
              if(indegree[v] == 0){
                  que.push(v);
              }
          }
      }
      return result;
    }
};