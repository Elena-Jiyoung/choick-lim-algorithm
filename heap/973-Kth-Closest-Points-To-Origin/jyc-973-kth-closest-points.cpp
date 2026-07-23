#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // Maxheap: size K control
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> maxHeap(comp);

        // Push K points
        for (auto& point : points) {
            if (maxHeap.size() <  K) {
                maxHeap.push(point);
            }
            else {
                if (point[0]*point[0] + point[1]*point[1] < 
            maxHeap.top()[0]*maxHeap.top()[0] + maxHeap.top()[1]*maxHeap.top()[1]) {
                maxHeap.pop();
                maxHeap.push(point);
            }
        }
        }

        // Extract K closest
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return result;
    }
};