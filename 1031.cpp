class Solution {
public:
    /***
     * DP问题的根本就是能不能找到从子问题推出原问题的状态转移方程
     * 以下用S[i]表示i的解，那么再多加一个元素j，那么
     * S[i+1]的值有两种情况，第一种是不取j，那么S[i+1] = S[i];
     * 第二种是取j，那么S[i+1] = Lmax + R(M), 那么状态转移方程为：
     *      S[i+1] = max(S[i], Lmax + R(M))
     *      Lmax[i+1] = max(Lmax[i], Last(L))
     * 其中Lmax 为后M个元素前的最大连续L-length的子序列，R(M)为最右边的
     * M个元素的值，由于L和M没有先后顺序，所以需要计算两次
     */
    
    int maxSumTwoNoOverlapSerial(vector<int> &prefix_sum, int L, int M) {
        int size = prefix_sum.size();
        int res = prefix_sum[L + M - 1];
        int lmax = prefix_sum[L - 1];
        for (int i = L + M; i < size; ++i) {
            lmax = max(lmax, prefix_sum[i - M] - prefix_sum[i - L - M]);
            res = max(res, lmax + prefix_sum[i] - prefix_sum[i - M]);
        }

        return res;
    }
    
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        // the prefix sum array
        for (size_t i = 1; i < A.size(); ++i) {
            A[i] += A[i - 1];
        }

        return max(maxSumTwoNoOverlapSerial(A, L, M), maxSumTwoNoOverlapSerial(A, M, L));
    }

};
