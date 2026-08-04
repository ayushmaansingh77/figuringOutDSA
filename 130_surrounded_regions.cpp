class Solution {
public:
void dfs(vector<vector<char>>& board,int r,int c,vector<vector<int>>& vis)
{
    int n = board.size();
    int m = board[0].size();

    vis[r][c] = 1;

    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};

    for(int i=0;i<4;i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr>=0 && nr<n &&
           nc>=0 && nc<m &&
           !vis[nr][nc] &&
           board[nr][nc]=='O')
        {
            dfs(board,nr,nc,vis);
        }
    }
}
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        // Left & Right boundaries
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && !vis[i][0])
                dfs(board,i,0,vis);

            if(board[i][m-1]=='O' && !vis[i][m-1])
                dfs(board,i,m-1,vis);
        }

        // Top & Bottom boundaries
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O' && !vis[0][j])
                dfs(board,0,j,vis);

            if(board[n-1][j]=='O' && !vis[n-1][j])
                dfs(board,n-1,j,vis);
        }

        // Convert enclosed O to X
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};