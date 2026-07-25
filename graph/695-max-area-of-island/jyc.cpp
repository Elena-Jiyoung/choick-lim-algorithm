class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // initialize all necessary variables
        // directions (to check each neighbor == 1), max_area (int), count (int) - so if count == 0 return 0, rows, cols to iterate over all cell

        vector<pair<int, int>> dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
        int max_area = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        // BFS to find islands


        for (int r=0; r < rows; r ++) {
            for (int c=0; c <cols; c ++) {
                if (grid[r][c] == 1) {
                    int this_island_area = 1;
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    grid[r][c] = 0;
                    
                    while (!q.empty()) {
                        auto curr = q.front();
                        q.pop();
                        for (auto& dir : dirs) {
                            int nr = dir.first + curr.first;
                            int nc = dir.second + curr.second;
                            if (nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]==1) {
                                q.push({nr, nc});
                                this_island_area ++;
                                grid[nr][nc]=0;
                            }
                        }
                    }
                    max_area = max(max_area, this_island_area);
                }
            }
        }
        return max_area;
    }
};
