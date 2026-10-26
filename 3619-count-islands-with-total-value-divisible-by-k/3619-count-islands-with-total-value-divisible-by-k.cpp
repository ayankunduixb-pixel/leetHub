class Solution {
private:
    long long dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int r,int c){
        visited[r][c] = true;
        long long sum = 0;
        if(r-1 >= 0 && grid[r-1][c] > 0 && !visited[r-1][c]){ // UP
            sum += dfs(grid,visited,r-1,c);
        }
        if(r+1 < grid.size() && grid[r+1][c] > 0 && !visited[r+1][c]){ //Buttom
            sum += dfs(grid,visited,r+1,c);
        }
        if(c-1 >= 0 && grid[r][c-1] > 0 && !visited[r][c-1]){ //Left
            sum += dfs(grid,visited,r,c-1);
        }
        if(c+1 < grid[0].size() && grid[r][c+1] > 0 && !visited[r][c+1]){ // Right
            sum += dfs(grid,visited,r,c+1);
        }
        return grid[r][c] + sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n));
        int count = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j] > 0 && !visited[i][j]){
                    long long sum = dfs(grid,visited,i,j);
                    if(sum % k == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};