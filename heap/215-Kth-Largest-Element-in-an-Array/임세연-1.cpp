// 내장함수 써서 정렬 때림 (근데 sort함수 있는거 검색해보고 사용함 이게 아쉽)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
        
    }
};
