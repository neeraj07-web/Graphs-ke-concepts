
class Solution {

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
public:
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26); // parenrt will be from a to z
        rank.resize(26,0);// rannk also resize to 26 , and initialize it to 0

        for(int i=0;i<26;i++){
            parent[i]=i;
        }
       // ab == walo ko union karna hota haina
        for(string &s :  equations){
            if(s[1] == '='){ // given haina ki bas first index pe jo letter hoga woh either = or ! hoga , if woh = hua toh conform ho jayega na == wqli equation hai
             Union(s[0]-'a' , s[3]-'a');// union karte that na(a==b) mei a and b ka a--->s[0]
             // -a isliye kyuki s[0] is a character na , but we need the index na
            }
        }

        // find != wale cases and check  validity

         for(string &s :  equations){
        if(s[1] == '!'){ // a != b
            char first=s[0]; // a
            char second=s[3]; // b

            int parent_first= find(first - 'a');
            int parent_second = find(second-'a');

            if(parent_first == parent_second)
            return false;
        }
         }
         return true;
    }
};