class Solution {
public:
    bool DFS(vector<vector<int>>& graph,int curNode, vector<int> &color, int currColor){
        color[curNode] = currColor; // set the color of the curNode with the currColor

        for(int &v: graph[curNode]){
            if(color[v] == color[curNode]) // if tehe color of the v node is same as the cur node then we will return it as false
               return false;

           if(color[v] == -1){ // if we have never visited (never colored it before)
           int  colorOfV = 1-color[curNode]; // if color of curnode is 0 then color of v will became 1 and vice versa

           if(DFS(graph, v, color,colorOfV) == false){
            return false;
           }
           }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
          vector<int>color(n,-1); // we will initialize a vector color of size n and initialle it with no color
          // -1 means no color , 
          // let us take 1-------> red color , 0 ----------->green color
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(DFS(graph,i,color,1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
