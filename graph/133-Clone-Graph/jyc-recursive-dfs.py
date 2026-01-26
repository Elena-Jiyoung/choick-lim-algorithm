
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution(object):
    def cloneGraph(self, node):
        """
        Use recursion with a visited dictionary that maps original → clone.

        Step-by-step logic:
        1. If node is None, return None.
        2. If node is already cloned (in visited), return the clone.
        3. Otherwise:
            Create a new clone with empty neighbors.
            Add it to visited.
            For each neighbor in the original node:
                Recursively clone the neighbor.
                Append the cloned neighbor to the current clone’s neighbors.
        4. Return the clone.
        """
        # Use a visited dict: { original_node: cloned_node }
        # No matter which node you start from, as long as the graph is connected:
            # The visited map ensures each node is cloned exactly once
            # All connections are faithfully reproduced
            # The recursion naturally handles cycles by returning existing clones

        if node == None:
            return None
        
        visited = {}
        def dfs(original_node):
            
            if original_node in visited:
                return visited[original_node]
            
            cloned_node = Node(original_node.val)
            visited[original_node] = cloned_node
            for original_neighbor in original_node.neighbors:
                cloned_node.neighbors.append(dfs(original_neighbor))
            
            return cloned_node

        return dfs(node)


        