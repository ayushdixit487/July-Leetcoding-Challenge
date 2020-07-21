class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        if(n==0)
            return false;
        for(int i = 0;i<n;i++){
            for(int j = 0; j<board[i].size();j++){
                if(board[i][j]==word[0] && dfs(board ,i,j,0,word))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>&board , int i,int j , int k, string word){
        if(i==-1 || i==board.size() || j==-1 || j==board[i].size() || board[i][j]!=word[k])
            return false;
        if(k==word.size()-1)
            return true;
        char ch = board[i][j];
        board[i][j]= '#';
        bool exist = dfs(board ,i+1,j,k+1,word) || dfs(board ,i-1 ,j,k+1 ,word)
            || dfs(board ,i ,j+1 ,k+1,word) || dfs(board, i,j-1,k+1,word);
        board[i][j] = ch;
        return exist;
    }
};
