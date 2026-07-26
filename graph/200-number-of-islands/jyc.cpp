class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int,int>> direction = {{1,0},{0,1},{-1,0},{0,-1}};
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    count ++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        for (auto [dx, dy] : direction) {
                            int new_x = x+dx, new_y=y+dy;
                            if (0 <= new_x && new_x < rows && 0<= new_y && new_y < cols && grid[new_x][new_y] == '1') {
                                grid[new_x][new_y] = '0';
                                q.push({new_x, new_y});   
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
