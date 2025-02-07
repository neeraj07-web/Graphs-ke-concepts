class Solution {
  public:
  
   vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int x, int y){
        int x_parent=find(x);
        int y_parent = find(y);

        if(x_parent== y_parent){
            return;
        }
        else if(rank[x_parent] > rank[y_parent]){
            parent[y_parent]=x_parent;
        }
          else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
             parent[x_parent]=y_parent;// kisi ek lo parent bana denge
             rank[y_parent]++;
        }
    }
    
  // using kruskal algo , already done through the prims algo. go and check out tyhe submisiion section
  
  int Kruskal(vector<vector<int>> &vec){
      int sum=0; // initialize the sum to 0

      // now traverse through all the nodes

      for(auto &temp:vec){
          int u=temp[0];
          int v=temp[1];
          int wt =temp[2];
          
          int parent_u= find(u);
          int parent_v =find(v);
          
          if(parent_u != parent_v){ // if they are in 2 diff sets
              Union(u,v);
              sum +=wt;
          }
      }
      return sum;// final sum ko return kar denge
  }
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        parent.resize(V);
        rank.resize(V,0);
        
        for(int i=0;i<V;i++){
            parent[i] =i;
        }

       vector<vector<int>> vec;
       
       for(int u=0 ;u<V;u++){ // u-------> v se kon konn si edges hai
           for(auto &temp : adj[u]){
               int v=temp[0];
               int wt=temp[1];
               
       vec.push_back({u,v,wt});
           }
       }

       // self declaring comparator (sorting on the basis of wt)
       
       auto comparator=[&] (vector<int>& vec1 , vector<int>& vec2){ // comparator will be between 2 vectors na
       return vec1[2] < vec2[2]; // [2] pe weight haina , jiska weight kam hoga woh return karenge
       };

       sort(begin(vec) , end(vec) , comparator);// sorting on the basis of weights
       
       return Kruskal(vec);
    }
};