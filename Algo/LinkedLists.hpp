#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include <unordered_set>

namespace List
{
	struct SList
	{	
		explicit SList(int v):val(v),next(0) {}
		SList* next;
		int val;

		void push_back(SList* item)
		{
			next = item;
		}

		void destroy()
		{
			delete next; 
		}

	//protected:
		~SList() { std::cout << "SList destructor" << std::endl; }
	};

	SList* reverse(SList* current)
	{
		SList* prev = 0;
		while (current)
		{
			SList* next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		return prev;
	}

	inline void slistReverse()
	{
		SList* list = new SList(0);
		SList* head = list;

		for (int i = 1; i < 11; i++)
		{
			SList* newList = new SList(i);
			list->push_back(newList);
			list = newList;
		}

		SList* next = head;
		while (next)
		{
			std::cout << next->val << " " << std::endl;
			next = next->next;
		}

		head = reverse(head);
		std::cout << "Reversed List : " << std::endl;

		next = head;
		while (next)
		{
			std::cout << next->val << " " << std::endl;
			next = next->next;
		}

		SList& s = *head;
		head->destroy();		
	}


    static void removeDuplicatesFromList(SList* head)
    {
        using namespace std;

        SList* prev = 0;
        SList* current = head;
        unordered_set<int> allUnique;

        while (current != 0)
        {
            if (allUnique.find(current->val) != allUnique.end())
            {
                SList* duplicate = current;
                prev->next = current->next;                
                current = current->next;
                delete duplicate;               
            }
            else
            {
                allUnique.insert(current->val);
                prev = current;
                current = current->next;                
            }            
        }
    }
    static void testRemoveDuplicatesFromList()
    {
        using namespace std;

        SList* list = new SList(0);
		SList* head = list;

		SList* newList = new SList(2);
		list->push_back(newList);
        
        SList* newList1 = new SList(3);
		newList->push_back(newList1);

        SList* newList2 = new SList(4);
		newList1->push_back(newList2);

        SList* newList3 = new SList(2);
		newList2->push_back(newList3);

        SList* newList4 = new SList(3);
		newList3->push_back(newList4);

        SList* c = head;
		while (c)
		{
			std::cout << c->val << " " ;
			c = c->next;
		}
        cout << std::endl;

        removeDuplicatesFromList(head);

        c = head;
		while (c)
		{
			std::cout << c->val << " " ;
			c = c->next;
		}
        cout << std::endl;
        
		//list = newList;
		
    }
}

#endif // _LINKED_LIST_HPP_

/*
class Handle 
{ 
int *p_; 
public: 
explicit Handle(int *p) : p_(p) { }
~Handle() { delete p_; } 
};
int main()
{ 
Handle a(new int(5));
Handle b = a; 
return 0;
}
*/