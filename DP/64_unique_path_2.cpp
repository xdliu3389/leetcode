class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid.front().size();
        if(obstacleGrid.front().front() == 1 || obstacleGrid.back().back() == 1)
            return 0;

        //The currentRow will be set 0 after meet obstacle (break)
        vector<int> currentRow(c, 0);
        for(int j=0; j<c; j++) {
            if (obstacleGrid[0][j] == 0)
                currentRow[j] = 1;
            else
                break;
        }

        for(int i=1; i<r; i++) {
            for(int j=1; j<c; j++) {
                //The current one is obstacle
                if(obstacleGrid[i][j] == 1)
                    currentRow[j] = 0;
                //The left column element is obstacle.
                //We don't need to change the currentRow[j], because you can only come from up size which is currentRow[j]
                if(obstacleGrid[i][j-1] == 1)
                    currentRow[j - 1] = 0;
                //The left and up is non-obstacle/
                if(obstacleGrid[i][j] != 1 && obstacleGrid[i][j-1] != 1)
                    currentRow[j] += currentRow[j-1];
            }
        }

        return currentRow[c-1];
    }
};
