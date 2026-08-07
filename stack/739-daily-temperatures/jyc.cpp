class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        //build stack for temps
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack; // {temp, index}

        for (int i=0; i < temperatures.size(); i ++) {
            int temp = temperatures[i];
            while (!stack.empty() && temp > stack.top().first) {
                auto popped_pair = stack.top();
                stack.pop();
                res[popped_pair.second] = i - popped_pair.second;
            }
            stack.push({temp, i});
        }
        return res;
    }
};
