class Solution {
public:
    /***
     * DP的的两种方式，一个是forward，一个是backword，几乎所有问题都适宜用其中
     * 一种方式去解，此种方式能够保留继续推理的信息，所以DP的本质是用空间换取
     * 时间，避免重复计算而将子问题结果缓存，本问题无法用backword解，也没有
     * optimal value function, 一直往后计算就能得到最终解，本问题的难点在于
     * 怎么去存储中间结果避免search map
     */
    int longestArithSeqLength(vector<int>& A) {
        vector<unordered_map<int, int> > dp(A.size());
        int length = 0, diff = 0;
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                diff = A[i] - A[j];
                if (dp[j][diff] == 0)
                    dp[i][diff] = 2;
                else
                    dp[i][diff] = dp[j][diff] + 1;

                length = max(length, dp[i][diff]);
            }
        }

        return length;
    }
};
