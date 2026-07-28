class Solution {
public:
    int dfs(pair<int, int> rc, vector<vector<int>>& grid) {
        int r = rc.first;
        int c = rc.second;
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;

        return 1 +
            dfs({r, c - 1}, grid) +
            dfs({r + 1, c}, grid) +
            dfs({r, c + 1}, grid) +
            dfs({r - 1, c}, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int max_area = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, dfs({i, j}, grid));
                }
            }
        }

        return max_area;
    }
};