
// Approach 1 : using the KAHN's Algo (using the BFS)

class Solution {
public:

vector<int> topoSort(unordered_map<int,vector<int>> &adj,int n, vector<int> &indegree){
    queue<int>que;
    vector<int>result;
      int count =0;

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            que.push(i);
            count ++;
            result.push_back(i);
        }
    }

    while(!que.empty()){
        int u=que.front();
        que.pop();

        for(int &v : adj[u]){

             indegree[v]--;

            if(indegree[v]==0){
                count++;
                que.push(v);
                result.push_back(v);
            }
        }
    }
    if (count == n){ // i have visited all the nodes (i.e i've taken all the course )
        return result;
    }
    return {};
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);
        
        for(auto &vec: prerequisites){
            int a= vec[0];
            int b=vec[1];

            // (a,b) la matlab tha b pe jane k liye pehle a pe jana padta tha
            // i.e b-------->a

            adj[b].push_back(a);

            // arrow jaa rha hai a mein
            indegree[a]++;
        }

         return topoSort(adj,numCourses,indegree);
    }
};

// Approach 2 : using the DFS

class Solution {
public:
    bool hasCycle = false;
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, stack<int>& st, vector<bool>& inRecursion) {
	    visited[u] = true;
        inRecursion[u] = true;
	    
	    
	    //pehle mere ('u' ke node ke ) bachho ko daalo
	    for(int &v : adj[u]) {
            if(inRecursion[v] == true) {
                hasCycle = true;
                return;
            }
            
	        if(!visited[v])
	            DFS(adj, v, visited, st, inRecursion);
	    }
	    
	    
	    //ab mujhe daalo stack me
	    st.push(u);
        inRecursion[u] = false;
	    
	}
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        hasCycle = false;
        
        stack<int> st;
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b--->a
            adj[b].push_back(a);
        }
        
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i])
                DFS(adj, i, visited, st, inRecursion);
        }
        
        vector<int> result;
        
        if(hasCycle)
            return {};
        
	    while(!st.empty()) {
	        result.push_back(st.top());
	        st.pop();
	    }
	    
	    return result;
    }
};