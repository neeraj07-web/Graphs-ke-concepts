// Dijkstra Algorith from GFG

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int V=adj.size();
        
        // priority queue
         priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; // min heap
         
         vector<int>result(V,INT_MAX); // to store the final result
         result[src]=0;
         pq.push({0,src}); // 0 distance lagta hai source se source tak phunchne mei

         while(!pq.empty()){
             
             int d= pq.top().first; // pair mei jo pehla element hoga na woh distance hoga
             int node =pq.top().second; // pair mei jo second element hoga na woh node hoga 
              pq.pop(); // pop karenge to get the neighbouring nodes

            for(auto &vec : adj[node]){
                // vec k jo adjacent nodes hai  ( node -------------> { neighbour, their distance} )
                int adjNode =vec.first; // adj node jo tha woh vec[0] meki store tha
                int wt= vec.second; // weight jo tha woh vec[1] mei store tha
                
                if(d + wt < result[adjNode]){ // agar ek node se dusre node jane mei distance kam aa rha hai than the initial distance toh usse update kar denghe with the new distance
                    result[adjNode]= d+wt; // new distance
                    pq.push({d+wt, adjNode}); // agar less distance wla ayega than prvious one toh usse priority queue mei push karte jayenge
                }
            }
         }
            return result; // finallly result vector return kar denge
    }
};