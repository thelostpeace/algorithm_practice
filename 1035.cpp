#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    /***
     * 本题也是一个DP问题，时间复杂度和空间复杂度都是A.size() * B.size(),
     * 解法是forward找结果存储方式以及状态转移方程
     */
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int dp[B.size() + 1][A.size() + 1];
        memset(dp, 0, sizeof(int) * (A.size() + 1) * (B.size() + 1));

        for (int i = 0; i < B.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                if (B[i] == A[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[B.size()][A.size()];
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<int> A = {2, 5, 1, 2, 5};
    vector<int> B = {10, 5, 2, 1, 5, 2};

    cout << sol.maxUncrossedLines(A, B) << endl;

    return 0;
}
