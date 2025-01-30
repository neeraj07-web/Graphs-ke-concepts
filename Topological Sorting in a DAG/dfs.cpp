// topological sorting is possible only in directed Acyclic Graph...

class Solution {
  public:
  void topoDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st){
     
     visited[u]=true;
     
      // u : pehle mere bacho ko dalo stack mei fir mujhe dalna stack mei
      for(int &v :adj[u]){
          if(!visited[v]){
              topoDFS(adj,v,visited,st);
          }
      }
      // ab mujhe daal do stack mei
      st.push(u);
  }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int V=adj.size();
        
        vector<bool>visited(V,false);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topoDFS(adj,i,visited,st);
            }
        }
        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());// top wale to dalte gaye result mei 
            st.pop();// and har step pe pop karte gaye
        }
        return result;
    }
};