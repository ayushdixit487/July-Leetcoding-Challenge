class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int peri =0;
        int m = grid[0].size();
        for(int i = 0; i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
               return dfs(grid , i,j , n ,m);
            }
        }
        return peri;
    }
     int dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        int count = 0;
        if(grid[i][j]==1){
            grid[i][j]=-1;
            if(i<n-1){count += dfs(grid, i+1, j, n, m);}
            if(i>0){count +=   dfs(grid, i-1, j, n, m);}
            if(j<m-1){count += dfs(grid, i, j+1, n, m);}
            if(j>0){count +=   dfs(grid, i, j-1, n, m);}
            
            if(i==0 || grid[i-1][j]==0){count++;}
            if(j==0 || grid[i][j-1]==0){count++;}
            if(i==n-1 || grid[i+1][j]==0){count++;}
            if(j==m-1 || grid[i][j+1]==0){count++;}
        }
        return count;
    }
};
