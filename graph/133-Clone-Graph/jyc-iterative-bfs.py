# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


from collections import deque

class Solution(object):
    "When I discover a new node (not seen before), I clone it, mark it as visited, and add it to the queue to explore its neighbors later."
    def cloneGraph(self, node):
        if not node:
            return None
        
        visited = {}
        queue = deque()
        
        # Clone the start node
        visited[node] = Node(node.val, [])
        queue.append(node)
        
        while queue:
            curr = queue.popleft()
            for neighbor in curr.neighbors:
                if neighbor not in visited:
                    visited[neighbor] = Node(neighbor.val, [])
                    queue.append(neighbor)  # ← only enqueue if not seen
                # Link the cloned neighbor
                visited[curr].neighbors.append(visited[neighbor])
        
        return visited[node]