/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
 ����ָ�룬һ��ÿ���ƶ�һ������һ��ÿ���ƶ�����������л��������׷�ϡ�
 �������⣺
 �ж��������������Ƿ��ཻ������ཻ��������㡣�����������������ͷ����һ�𣬾Ϳ��Կ���û�л�
 ��һ���л������У�����ҳ�������뻷�㣿  ��https://www.cnblogs.com/fankongkong/p/7007869.html
 ��һ�����һ������㡣�ֱ���fast��slowָ������ͷ����slowÿ����һ����fastÿ���߶�����ֱ��fast==slow�ҵ��ڻ��е����㡣
�ڶ������һ�����ڡ����ϲ�����fast==slowʱ��fast�������ڵ���Ϊ2x,slow�������ڵ���Ϊx,�軷����n���ڵ㣬fast��slow����rȦ��2x=rn+x; x=rn;��rΪȦ����nΪһȦ�Ľ������
���Կ���slowʵ�����˶�����Ĳ���������fastָ������ͷ����slowλ�ò��䡣
��������ͷ�����ӿڵľ�����y����ôx-y��ʾslowָ���߹��ĳ�����ͷy�ڻ����߹��ľ��룬��ôslow����y������ʱfast�����slow���������fast == slow ��x-y+y=x = rn������ʱslowָ�򻷵���ڡ�
 
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
