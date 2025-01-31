
// Approach 1 : using the KAHN's Algo - using the BFS

class Solution {
public:
bool topoSort(unordered_map<int,vector<int>> &adj, int n, vector<int> &indegree){

    queue<int>que;
    int count =0;
    
    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            que.push(i);
              count ++;// jis jis ko que mei push karte thay na usse count ko ++ karte jatay thay
        }
    }

    // step 3: simple BFS
    while(!que.empty()){
        int u=que.front();
        que.pop();

        for(int &v : adj[u]){
            indegree[v]--;

            if(indegree[v]==0){
                que.push(v);
                count++;
            }
        }
    }
 if(count == n){ //I was able to visit all nodes (course)
    return true;
 }
 return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // self declare adj list
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);

        for(auto &vec: prerequisites){
            int a= vec[0];
            int b=vec[1];

            // (a,b) la matlab tha b pe jane k liye pehle a pe jana padta tha
            // i.e b-------->a

            adj[b].push_back(a);

            // arrow jaa rha hai a mein
            indegree[a]++;
        }
      // if cycle is present then it is not possible
      return topoSort(adj,numCourses,indegree);

    }
};


// Approach 2: using DFS

class Solution {
public:
    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        
        for(int &v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if(inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b ---> a
            adj[b].push_back(a);
        }
        
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
                return false;
        }
        
        return true;
    }
};