#include <iostream>
#include <cstdio>
#define MAXSIZE 1000

using namespace std;


struct Data
{
	char c;
};

struct Link
{
	Data *data;
	Link *next;
};

class Stack
{
	public:
		Stack()
		{
			initLink();
		}

		Data pop(void)
		{
			if(!isEmpty()){
				Link *last = findLastSec();
				Data tmp = *last->data;
				deleteLastNode();
				return tmp;
			}
			else
				cout << "Empty" << "\n"; 
		}

		int push(const Data &data)
		{

			insertLast(&data);

		}

		void clear(void)
		{
		}

		bool isEmpty(void)
		{
			if(store == NULL)
				return true;
			return false;
		}

	private:
		Link *store;
		void initLink(void)
		{
			store = new Link;
			store->data = new Data;
			store->next = NULL;

		}

		Link *findLast(void)
		{
			Link *pLink;
			pLink = store;
			while(pLink->next != NULL)
				pLink = pLink->next;
			return pLink;

		}

		Link *findLastSec(void)
		{
			Link *pLink;
			pLink = store;
			while(pLink->next != NULL){
				if(pLink->next->next == NULL)
					break;
				else
					pLink = pLink->next;
			}
			return pLink;

		}


		void deleteLastNode(void)
		{
			Link *pLink;
			pLink = findLastSec();
			delete pLink->next->data;
			delete pLink->next;
			pLink->next = NULL;

		}

		void insertLast(const Data *raw)
		{
			Link *pLink;
			pLink = findLast();
			pLink->next = new Link;
			pLink->data = new Data(*raw);
			pLink->next->next = NULL;

		}

};

int main()
{
	Stack test;
	Data test2;
	test2.c = 'a';
	test.push(test2);
	test2.c = 'b';
	test.push(test2);
	test2.c = 'c';
	test.push(test2);
	Data tmp;
	tmp = test.pop();
	cout << tmp.c << '\n';
	tmp = test.pop();
	cout << tmp.c << '\n';
	tmp = test.pop();
	cout << tmp.c << '\n';


	return 0;
}
