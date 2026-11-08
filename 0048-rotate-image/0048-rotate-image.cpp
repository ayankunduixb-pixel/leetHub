class Solution {
private:
    void bruteForceApproach(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> rotated(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rotated[j][n-i-1]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=rotated[i][j];
            }
        }
    }

    void optimalApproach(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // Transpose the matrix
        for(int i=0;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // reverse each rows
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        // bruteForceApproach(matrix);
        optimalApproach(matrix);
    }
};