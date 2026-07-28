class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> indexes;
        vector<int> answer(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while(!indexes.empty() && temperatures[i] > temperatures[indexes.top()]
            ) {
                answer[indexes.top()] = i - indexes.top();
                indexes.pop();
            }
            indexes.push(i);
        }

        return answer;
    }
};
