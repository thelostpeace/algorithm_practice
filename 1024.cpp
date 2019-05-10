#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/***
 * 其实这个问题不太适合用DP去解，反而用Greedy的方式解更加自然，当然一般遇到此类问题首先会
 * 以DP的方式forward或者backward的方式推，以求找到子问题，但是找子问题的过程中会发现Greedy
 * 的方式解顺其自然
 */

bool vectorCompare(vector<int> l, vector<int> r) {
    if (r[1] > l[1])
        return true;
    if (r[1] == l[1] && r[0] > l[0])
        return true;

    return false;
}

class Solution {
public:

    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), vectorCompare);
        // 第一个问题是T，贪心最大剪辑时长后，子问题会变为min({sub, T})
        int sub_problem = T;
        int pos = clips.size() - 1; // 记录已经读取过的clips
        int res = 0;
        while (pos >= 0 && sub_problem != 0) {
            // 每次检查子问题是否有解
            if (clips[pos][1] < sub_problem)
                return -1;

            int min_val = sub_problem;
            for (; pos >= 0 && clips[pos][1] >= sub_problem && min_val != 0; --pos) {
                min_val = min(min_val, clips[pos][0]);
            }
            sub_problem = min_val;
            cout <<"pos: "<<pos<<"\t"<<"sub_problem: "<<sub_problem<<endl;
            ++res;
        }

        return sub_problem == 0 ? res : -1;
    }
};

int main(int argc, char **argv) {
    vector<vector<int> > vv = {{0,1}, {6,8}, {0,2}, {5,6}, {0,4}, {0,3}, {6,7}, {1,3}, {4,7}, {1,4}, {2,5}, {2,6}, {3,4}, {4,5}, {5,7}, {6,9}};
    Solution s;
    cout << s.videoStitching(vv, 9) << endl;;

    return 0;
}
