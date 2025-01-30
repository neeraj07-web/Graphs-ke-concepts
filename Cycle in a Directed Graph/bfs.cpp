// dekho KAHN's algo apply hota tha DAG pe (Directed Acyclic)
// matlab agar KHAN's algo nahi laga toh matlab graph cyclic hai

// this is similar to KAHN's algo

bool isCyclic(int V, vector<vector<int>> adj) {
       int N=adj.size();
       
       int count =0;// to calculate how many no. of nodes have been reached out or visited

       queue<int>que;
       // step 1 : calcualting the indegree of all the nodes
       vector<int>indegree(N,0);
       
       for(int u=0;u<N;u++){
           for(int &v : adj[u]){
               indegree[v]++;
           }
       }
       
       // step 2: if in degree is 0 , then push them into the queue
       for(int i=0;i<N;i++){
           if(indegree[i] == 0){
               que.push(i);
               count ++;// queue mei kisse push karte hai jo visit ho jata hai
           }
       }
       
       // step 3 :simple BFS traversal]
       
       while(!que.empty()){
           int u=que.front();
           que.pop();
           
           for(int &v :adj[u]){
               indegree[v]--;
               
               if(indegree[v] == 0){
                   que.push(v);
                   count++; // queue meipush hogya uska matlab woh node vist hogya hai
                   // therefore count ++
               }
               }
           }
           if(count == N){ // that mean sare ke sare nodes viited ho gaye hai , matlab cycle nahi rha hoga
           // there we retrurn as false
                   return false;
       }
       return true;
    }
};