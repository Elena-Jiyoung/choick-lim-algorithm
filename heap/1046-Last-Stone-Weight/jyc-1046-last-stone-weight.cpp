#include <queue>
#include <vector>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        // 1. Build max-heap
        std::priority_queue<int> maxHeap;
        for (int s : stones) {
            maxHeap.push(s);
        }

        // 2. Simulate smashes
        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();

            if (first != second) {
                maxHeap.push(first - second);
            }
        }

        // 3. Handle empty heap case
        maxHeap.push(0);
        return maxHeap.top();
    }
};