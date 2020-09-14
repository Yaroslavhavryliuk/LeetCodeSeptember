
#include <iostream>
using namespace std;

struct ListNode
{
	int data;
	ListNode* next = nullptr;
};

struct List
{
	ListNode* beg = nullptr;
	ListNode* end = nullptr;
};

ListNode* addNode(List& list, int data)
{
	ListNode* newNode = new ListNode;
	newNode->data = data;
	if (list.end)
	{
		list.end->next = newNode;
		list.end = newNode;
	}
	else
	{
		list.beg = newNode;
		list.end = newNode;
	}
	return newNode;
}

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode ret;
		ret.data = l1->data + l2->data;
		return &ret;
	}
	int listSize(List& list)
	{
		int i = 0;
		ListNode* curr = list.beg;
		while (curr)
		{
			i++;
			curr = curr->next;
		}
		return i;
	}
	List* addLists(List l1, List l2)
	{
		List ret;
		if (((listSize(l1)!=1)&&(l1.end->data == 0)) || ((listSize(l2) != 1) && (l2.end->data == 0)))
		{
			addNode(ret, -1);
			return &ret;
		}
		
		bool plus1=false;
		if (listSize(l1) >= listSize(l2))
		{
			ListNode* cn2 = l2.beg;
			for (ListNode* cn1 = l1.beg; cn1; cn1 = cn1->next)
			{
				if (cn2 != nullptr)
				{
					ListNode* res = addTwoNumbers(cn1, cn2);
					if (!plus1)
					{
						if (res->data >= 10)
						{
							plus1 = true;
						}
						else
						{
							plus1 = false;
						}
						addNode(ret, (res->data) % 10);
					}
					else
					{
						res->data += 1;
						if (res->data >= 10)
						{
							plus1 = true;
						}
						else
						{
							plus1 = false;
						}
						addNode(ret, (res->data) % 10);
					}
					cn2 = cn2->next;
				}
				else
				{
					ListNode* res = cn1;
					if (!plus1)
					{
						if (res->data >= 10)
						{
							plus1 = true;
						}
						else
						{
							plus1 = false;
						}
						addNode(ret, (res->data) % 10);
					}
					else
					{
						res->data += 1;
						if (res->data >= 10)
						{
							plus1 = true;
						}
						else
						{
							plus1 = false;
						}
						addNode(ret, (res->data) % 10);
					}
				}
			}
		}
		else
		{
			ListNode* cn1 = l1.beg;
			for (ListNode* cn2 = l2.beg; cn2; cn2 = cn2->next)
			{
				if (cn1 != nullptr)
				{
					ListNode* res = addTwoNumbers(cn1, cn2);
					if (!plus1)
					{
						if (res->data >= 10)
						{
							plus1 = true;
						}
						else
						{
							plus1 = false;
						}
						addNode(ret, (res->data) % 10);
					}
					else
					{
						res->data += 1;
						if (res->data >= 10)
						{
							plus1 = true;
						}
						else
						{
							plus1 = false;
						}
						addNode(ret, (res->data) % 10);
					}
					cn1 = cn1->next;
				}
				else
				{
					ListNode* res = cn2;
					if (!plus1)
					{
						if (res->data >= 10)
						{
							plus1 = true;
						}
						else
						{
							plus1 = false;
						}
						addNode(ret, (res->data) % 10);
					}
					else
					{
						res->data += 1;
						if (res->data >= 10)
						{
							plus1 = true;
						}
						else
						{
							plus1 = false;
						}
						addNode(ret, (res->data) % 10);
					}
				}
			}
		}
		if (plus1)
		{
			addNode(ret, 1);
		}
		return &ret;
	}
};

void printList(List& l)
{
	for (ListNode* currNode = l.beg; currNode; currNode = currNode->next)
		cout << currNode->data << "\t";
	cout << endl;
}

int main()
{
	List l1, l2, l3;
	addNode(l1, 0);
	addNode(l1, 2);
	addNode(l1, 1);
	addNode(l2, 1);
	addNode(l2, 5);
	addNode(l2, 6);
	Solution sl;
	l3 = *sl.addLists(l1, l2);
	printList(l3);
    return 0;
}

