class Solution {
public:
    int m,n;

    bool dfs(vector<vector<int>>& grid,int r, int c){
        if(r < 0 || r >= m || c < 0 || c >= n){ // Out of bound
            return false; //Not closed
        }

        if(grid[r][c] == 1){ //water
            return true; // closed in this side
        }

        grid[r][c] = 1; // Mark visited

        bool isLeftCLosed = dfs(grid,r,c-1);
        bool isRightCLosed = dfs(grid,r,c+1);
        bool isUpCLosed = dfs(grid,r-1,c);
        bool isDownCLosed = dfs(grid,r+1,c);

        return isLeftCLosed && isRightCLosed && isUpCLosed && isDownCLosed; 
        // If all the result gives true then the result of ands will be also true means closed and count will increase
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    if(dfs(grid,i,j) == true){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};