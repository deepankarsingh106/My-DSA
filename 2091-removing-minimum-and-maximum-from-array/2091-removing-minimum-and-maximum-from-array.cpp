class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int a = max_element(begin(nums), end(nums)) - begin(nums);
        int b = min_element(begin(nums), end(nums)) - begin(nums);
        int N = nums.size();
        if (a > b) swap(a, b);
    return min({ a + 1 + N - b, b + 1, N - a });}
};