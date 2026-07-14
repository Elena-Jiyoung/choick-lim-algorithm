// 1로 둘러싸인 island 갯수 리턴
// BFS
// visited 방문은 언제 할 것인가? -> 큐에 넣을때. (한번 방문한 노드는 재방문할 필요 없음)
// 큐에 무슨 정보를 넣을 것인가? -> 현재 좌표
// 시간복잡도 O(n^2)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0; // 섬이 하나도 없으면 0을 리턴

        queue<pair<int, int>> q;

        int m = grid.size(); // row
        int n = grid[0].size(); // col

        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '1') {
                    continue;
                }
                q.push({i, j});
                num++;
                grid[i][j] = -1; // visited
                while(!q.empty()) {
                    int cRow = q.front().first;
                    int cCol = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nRow = cRow + dRow[k];
                        int nCol = cCol + dCol[k];
                        if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n) {
                            if (grid[nRow][nCol] == '1') {
                                q.push({nRow, nCol});
                                grid[nRow][nCol] = -1; // visited
                            }
                        }
                    }
                }
            }
        }
        return num;
    }
};
