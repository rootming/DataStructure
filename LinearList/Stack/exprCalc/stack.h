#ifndef __STATCK_H__
#define __STATCK_H__
#include <iostream>
#include <vector>

using namespace std;
//template <typename T>
struct Unit
{
	enum UNITTYPE { NUMBER = 0, SYMBOL };
	UNITTYPE type;
	string strraw;
	int value;
	int weight;
	Unit()
	{
		weight = -1;
	}
};

template <typename T>
class Stack
{
    public:
        Stack()
        {
            pos = -1;
        }
        
        bool push(T &input)
        {
			store.push_back(input);
            pos++;
            return true;
        }

        T pop(void)
        {
                T output = store.at(pos--);
				store.pop_back();
                return output;
        }

        T top(void)
        {
                T output = store.at(pos);
                return output;
        }

        bool isEmpty(void)
        {
            return pos == -1 ? true : false;
        }
private:
	 vector<T> store;
	 int pos;
};

#endif
