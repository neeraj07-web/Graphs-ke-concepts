// gfg la prisms algo

class Solution {
  public:
  // define kar lete hai pehle se pair ko
  typedef pair<int,int> P;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
    //   priority_queue<int,vector<int> ,greater<int>> pq;
       // { wt,node ,parent}
       
          priority_queue<P,vector<P> ,greater<P>> pq;
        pq.push({0,0});// wt=0 and node =0 (initialize karna)
        vector<bool> inMST(V,false);
        int sum =0;
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            
            int wt=pq.top().first;
            int node =pq.top().second;
            
            if(inMST[node] == true) // agar already visited hai toh continue kar do
               continue;
            
            inMST[node] =true; // agar nahi hai toh dal do na
            sum += wt; // sum mei wt jod do
            
            for(auto &vec : adj[node]){
                int nghr=vec[0];
                int nghr_wt= vec[1];
                
                if(inMST [nghr] == false){ // aggar visited nahi hai toh
                    pq.push({nghr_wt,nghr}); // priority queue mei push kar do {weight, node}
                }
            }
        }
        return sum;
    }
};