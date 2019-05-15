/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***
 * 这个用stack保存状态比较好
 */
class Solution {
public:
    int getLength(ListNode *head) {
        int length = 0;
        while (head != NULL) {
            ++length;
            head = head->next;
        }

        return length;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result(getLength(head), 0); //记录结果
        int pos, val, index = 0; //index位置
        stack<int> empty_index; //保存未处理的index
        stack<int> unhandled_val; //保存未处理的val

        while (head != NULL) {
            if (empty_index.empty()) {
                empty_index.push(index);
                unhandled_val.push(head->val);
                head = head->next;
                continue;
            }
            while (!empty_index.empty()) {
                pos = empty_index.top();
                val = unhandled_val.top();
                if (head->val > val) {
                    result[pos] = head->val;
                    empty_index.pop(); //处理完弹出
                    unhandled_val.pop();
                } else {
                    break;
                }
            }
            empty_index.push(++index);
            unhandled_val.push(head->val);
            head = head->next;
        }

        return result;
    }
};
