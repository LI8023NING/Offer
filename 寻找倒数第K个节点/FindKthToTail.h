#pragma once

ListNode* FindKthToTail(ListNode* pHead, unsigned int k)
{
	if (pHead == nullptr || k == 0)
		return nullptr;

	ListNode *pAhead = pHead;
	ListNode *pBehind = nullptr;

	for (size_t i = 0; i < k - 1; ++i)
	{
		if (pAhead->next != nullptr)  //Ѱ�ҵ�Kû������
			pAhead = pAhead->next;
		else
		{
			return nullptr;
		}
	}

	pBehind = pHead;
	while (pAhead->next != nullptr)
	{
		pBehind = pBehind->next;
		pAhead = pAhead->next;
	}

	return pBehind;
}