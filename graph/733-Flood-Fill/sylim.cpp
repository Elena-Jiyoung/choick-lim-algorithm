class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
       
        int dr[4] = {-1, 0 , 1, 0};
        int dc[4] = {0, 1, 0, -1};

        int m = image.size();
        int n = image[0].size();

        int cr = sr;
        int cc = sc;
        

        queue<pair<int,int>> q;
        q.push({cr, cc});
        int originalColor = image[cr][cc];
        image[cr][cc] = color;
        

        if (originalColor == color) { // point : 예외처리 !!
            return image;
        }
        
        while (!q.empty()) {
            cr = q.front().first;
            cc = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (image[nr][nc] == originalColor) {
                        image[nr][nc] = color;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return image;
        
    }
};
