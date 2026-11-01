class Solution {

    void calculateRow(int i, int &m, int &n,
                      vector<vector<int>>& points,
                      vector<vector<long long>>& dp) {

        if (i == 0) {
            for (int j = 0; j < n; j++) {
                dp[0][j] = points[0][j];
            }
            return;
        }

        if (dp[i][0] != -1) return;

        // Calculate previous row
        for (int j = 0; j < n; j++) {
            calculateRow(i - 1, m, n, points, dp);
        }

        vector<long long> leftMax(n);
        vector<long long> rightMax(n);

        leftMax[0] = dp[i - 1][0];

        for (int j = 1; j < n; j++) {
            leftMax[j] = max(leftMax[j - 1],
                             dp[i - 1][j] + j);
        }

        rightMax[n - 1] = dp[i - 1][n - 1] - (n - 1);

        for (int j = n - 2; j >= 0; j--) {
            rightMax[j] = max(rightMax[j + 1],
                              dp[i - 1][j] - j);
        }

        // Calculate current row
        for (int j = 0; j < n; j++) {

            long long left = leftMax[j] - j;
            long long right = rightMax[j] + j;

            dp[i][j] = points[i][j] + max(left, right);
        }
    }

public:
    long long maxPoints(vector<vector<int>>& points) {

        int m = points.size();
        int n = points[0].size();

        vector<vector<long long>> dp(
            m, vector<long long>(n, -1)
        );

        calculateRow(m - 1, m, n, points, dp);

        return *max_element(dp[m - 1].begin(),
                            dp[m - 1].end());
    }
};