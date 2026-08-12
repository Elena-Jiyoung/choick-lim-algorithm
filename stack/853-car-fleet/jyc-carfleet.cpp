class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs(position.size());
        for (int i = 0; i < position.size(); i++) {
            pairs[i] = {position[i], speed[i]};
        }
        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        stack<double> st;
        for (int i = 0; i < pairs.size(); i ++) {
            double time = (target - pairs[i].first)/ (double)pairs[i].second;
            // If this car takes longer than the car ahead, it can't catch up
            // → it becomes a new fleet (push it)
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
            // if time <= st.top(), it catches up and becomes the same fleet ahead
            // don't push (it's part of the fleet)

        }
        return st.size();
    }   
};
