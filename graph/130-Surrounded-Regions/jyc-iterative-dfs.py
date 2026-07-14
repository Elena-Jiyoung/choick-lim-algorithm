class Solution(object):
    def solve(self, board):
        if not board or not board[0]:
            return
        from collections import deque

        rows = len(board)
        cols = len(board[0])
        queue = deque()

        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        # Add ALL border 'O's to the queue
        for r in [0, rows-1]:
            for c in range(cols):
                if board[r][c] == 'O':
                    board[r][c] = 'E'
                    queue.append((r, c))
        for c in [0, cols-1]:
            for r in range(1, rows-1):
                if board[r][c] == 'O':
                    board[r][c] = 'E'
                    queue.append((r, c))
        
        # CHANGED ONE LINE FROM BFS: popleft() FIFO QUEUE BFS -> pop() LIFO STACK DFS
        while queue:
            r, c = queue.pop()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] == 'O':
                    board[nr][nc] = 'E'
                    queue.append((nr, nc))
    
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == "E":
                    board[r][c] = "O"
                elif board[r][c] == "O":
                    board[r][c] = "X"
