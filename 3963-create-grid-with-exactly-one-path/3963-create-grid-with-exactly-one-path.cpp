class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m,string(n,'#'));

        // Make the first row free
        for(int i = 0;i<n-1;i++){
            grid[0][i] = '.';
        }

        // Make the last column free
        for(int i = 0;i<m;i++){
            grid[i][n-1] = '.';
        }

        return grid;
    }
};