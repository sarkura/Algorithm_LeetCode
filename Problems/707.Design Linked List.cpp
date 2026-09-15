/*
 * @lc app=leetcode id=707 lang=cpp
 * @lcpr version=30404
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedListNode 
{
public:
    int val;
    MyLinkedListNode* next = nullptr;
    MyLinkedListNode* prev = nullptr;
    MyLinkedListNode(int val) : val(val), next(nullptr), prev(nullptr) {}
};


class MyLinkedList 
{
public:
    MyLinkedList() 
    {
        virtualhead = new MyLinkedListNode(0);
        virtualtail = new MyLinkedListNode(0);
        virtualhead->next = virtualtail;
        virtualtail->prev = virtualhead;
        size = 0;
    }

    ~MyLinkedList()
    {
        MyLinkedListNode* node = virtualhead;
        while (node)
        {
            MyLinkedListNode* next = node->next;
            delete node;
            node = next;
        }
    }

    int get(int index) 
    {
        if (index < 0 || index >= size ) 
            return -1;
        MyLinkedListNode* node = virtualhead->next;
        while (index--)
            node = node->next;
        return node->val;
    }
    
    void addAtHead(int val) 
    {
        MyLinkedListNode* newhead = new MyLinkedListNode(val);
        MyLinkedListNode* oldhead = virtualhead->next;
        newhead->next = oldhead;
        oldhead->prev = newhead;
        virtualhead->next = newhead;
        newhead->prev = virtualhead;
        size++;
    }
    
    void addAtTail(int val)
    {
        MyLinkedListNode* newtail = new MyLinkedListNode(val);
        MyLinkedListNode* oldtail = virtualtail->prev;
        newtail->prev = oldtail;
        oldtail->next = newtail;
        virtualtail->prev = newtail;
        newtail->next = virtualtail;
        size++;
    }
    
    void addAtIndex(int index, int val) 
    {
        if (index < 0 || index > size) 
            return;
        MyLinkedListNode* node = virtualhead->next;
        while (index--)
            node = node->next;
        MyLinkedListNode* newnode = new MyLinkedListNode(val);
        newnode->next = node;
        newnode->prev = node->prev;
        node->prev->next = newnode;
        node->prev = newnode;
        size++;
    }
    
    void deleteAtIndex(int index) 
    {
        if (index < 0 || index >= size) 
            return;
        MyLinkedListNode* node = virtualhead->next;
        while (index--)
            node = node->next;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        size--;
    }

private:
    MyLinkedListNode* virtualhead = nullptr;
    MyLinkedListNode* virtualtail = nullptr;
    int size = 0;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyLinkedList","addAtHead","deleteAtIndex","addAtTail","get"]\n[[],[1],[0],[2],[0]]\n
// @lcpr case=end

 */

