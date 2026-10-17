class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int x : nums) {
            int sum = 0, temp = x;

            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            arr.push_back({sum, x});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == arr[i].second)
                continue;

            int j = mp[arr[i].second];

            swap(nums[i], nums[j]);

            mp[nums[j]] = j;
            mp[nums[i]] = i;

            swaps++;
        }

        return swaps;
    }
};