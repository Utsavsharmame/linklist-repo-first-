/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        vector<int> v;

        while (list1 != NULL) {
            v.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != NULL) {
            v.push_back(list2->val);
            list2 = list2->next;
        }

        sort(v.begin(), v.end());
        ListNode* head = new ListNode(v[0]);
        ListNode* temp = head;

        for (int i = 1; i < v.size(); i++) {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if (head == 0 || head->next == 0) {
            return head;
        }

        // break LL into the two parts
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = 0;

        // sort RE
        left = sortList(left);
        right = sortList(right);

        // merge ll
        ListNode* mergeLL = merge(left, right);
        return mergeLL;
    }
};