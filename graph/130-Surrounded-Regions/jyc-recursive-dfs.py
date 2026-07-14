class Solution(object):
    def solve(self, board):
        if not board or not board[0]:
            return
        
        rows = len(board)
        cols = len(board[0])
        
        def dfs(r, c):
            if 0 <= r < rows and 0 <= c < cols and board[r][c] == 'O':
                board[r][c] = 'E'  # mark as safe
                dfs(r+1, c)
                dfs(r-1, c)
                dfs(r, c+1)
                dfs(r, c-1)
        
        # Step 1: Mark all border-connected 'O's as 'E'
        for i in range(rows):
            if board[i][0] == 'O':
                dfs(i, 0)
            if board[i][cols-1] == 'O':
                dfs(i, cols-1)
        
        for j in range(cols):
            if board[0][j] == 'O':
                dfs(0, j)
            if board[rows-1][j] == 'O':
                dfs(rows-1, j)
        
        # Step 2: Flip remaining 'O' to 'X', and 'E' back to 'O'
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == 'E':
                    board[i][j] = 'O'