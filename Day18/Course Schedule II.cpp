class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> Q;
        vector<int> Order;
        for(int i = 0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }

        for(int i = 0; i<degree.size(); i++){
            if(degree[i] == 0){
                Q.push(i);
                Order.push_back(i);
            }
        }

        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            for(int i = 0; i<graph[node].size(); i++){
                int connectedNode = graph[node][i];
                degree[connectedNode]--;
                if(degree[connectedNode] == 0){
                    Q.push(connectedNode);
                    Order.push_back(connectedNode);
                }
            }
        }
        if(Order.size() != numCourses){
            return vector<int>();
        }
        return Order;
    }
};
