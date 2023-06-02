

| 双指针 | Medium | 19.删掉链表倒数第N个结点 |
| ------ | ------ | ------------------------ |
|        |        |                          |
|        |        |                          |
|        |        |                          |

## 19.删掉链表倒数第N个结点

一个指针跑到前n的位置，一个是head位置，这样就能直接删除倒数第n个

```c++
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head, *del=nullptr;
        int i = 0;
        while(i<n){
            temp = temp->next;
            i++;
        }
        del = head;
        ListNode *del_prev = nullptr;
        while(temp){
            temp = temp->next;
            del_prev = del;
            del = del->next;
        }
        if(del_prev==nullptr)
            return head = head->next;
        del_prev->next = del->next;
        return head;
    }
};
```

