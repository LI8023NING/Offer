#include <iostream>

using namespace std;

struct ListNode {     
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* tempRes = new ListNode(0);
    ListNode* resultNode = tempRes;
    ListNode* one = l1;
    ListNode* two = l2;
    int carry = 0;

    while (one != NULL || two != NULL)
    {
        //逐位计算
        int x = (one != NULL) ? one->val : 0;
        int y = (two != NULL) ? two->val : 0;

        int sum = x + y + carry;

        //进位
        carry = sum / 10;

        //给最终结果的链表装值
        tempRes->next = new ListNode(sum % 10);
        tempRes = tempRes->next;

        if (one != NULL)
            one = one->next;
        if (two != NULL)
            two = two->next;
    }

    //最后一位相加如果存在进位，则在结果集上在加一个节点
    if (carry > 0)
    {
        tempRes->next = new ListNode(carry);
    }

    return resultNode->next;
}

int main()
{
    ListNode* l1 = new ListNode(9);

    ListNode* node2 = new ListNode(1);
    ListNode* l2 = node2;
    for (int i = 0; i < 9; i++)
    {
        ListNode* node = new ListNode(9);
        node2->next = node;
        node2 = node2->next;
    }
    
    ListNode* nodeSuccess = addTwoNumbers(l1, l2);
    while (nodeSuccess->next != NULL)
    {
        cout << nodeSuccess->val << endl;
        nodeSuccess = nodeSuccess->next;
    }

    return 0;
}
