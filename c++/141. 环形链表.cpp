/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
 两个指针，一个每次移动一个，另一个每次移动两个，如果有环，迟早会追上。
 引申问题：
 判断两个单向链表是否相交，如果相交，求出交点。：把两个单向链表的头连在一起，就可以看有没有环
 在一个有环链表中，如何找出链表的入环点？  ：https://www.cnblogs.com/fankongkong/p/7007869.html
 第一步，找环中相汇点。分别用fast，slow指向链表头部，slow每次走一步，fast每次走二步，直到fast==slow找到在环中的相汇点。
第二步，找环的入口。接上步，当fast==slow时，fast所经过节点数为2x,slow所经过节点数为x,设环中有n个节点，fast比slow多走r圈有2x=rn+x; x=rn;（r为圈数，n为一圈的结点数）
可以看出slow实际走了多个环的步数，再让fast指向链表头部，slow位置不变。
假设链表开头到环接口的距离是y，那么x-y表示slow指针走过的除链表开头y在环中走过的距离，那么slow再走y步，此时fast结点与slow结点相遇，fast == slow ，x-y+y=x = rn，即此时slow指向环的入口。
 
 */ 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* second = head->next;
        while(second != NULL && second->next != NULL)
        {
            if(second->val == head->val)
                return true;
            second = second->next->next;
            head = head->next;
            
        }
        return false;
    }
};
