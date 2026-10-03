/*
 * @lc app=leetcode id=83 lang=cpp
 * @lcpr version=30404
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
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

// Linked List.md TwoPointer.md
// Linked List TwoPointer

 struct ListNode
 {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* fastnode = head->next;
        ListNode* slownode = head;
        while (fastnode != nullptr && slownode != nullptr)
        {
            if (fastnode->val == slownode->val)
            {
                ListNode* removeNode = fastnode;
                slownode->next = fastnode->next;
                delete removeNode;
                fastnode = slownode->next; 
            }
            else
            {
                slownode = fastnode;
                fastnode = fastnode->next;
            }
        }
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */

