class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         vector<vector<int>> res;
        int n = graph.size();
        if (n==0)
            return res;
        vector<int> cur;
        cur.push_back(0);
        dfs(0,cur,n-1,graph,res);
        return res;
        
    }
    void dfs(int src ,vector<int> cur ,int dest , vector<vector<int>>& graph , vector<vector<int>>& res){
        if(src==dest)
        {
            res.push_back(cur);
            return;
        }
        
      for(auto i : graph[src]){
          cur.push_back(i);
          dfs(i ,cur,dest , graph,res);
          cur.pop_back();
      }
    }
};
