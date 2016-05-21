//rootming@live.cn
#include <iostream>
#include <cstdio>
#define MAXSIZE 1000

using namespace std;

template <typename T>
class Stack
{
    public:
        Stack()
        {
            top = -1;
        }

        T* pop(void)
        {
            if(!isEmpty())
                return &store[top--];
            else
                return NULL;
        }

        int push(const T &data)
        {
            if(top < MAXSIZE - 1){
                store[++top] = data;
                return 0;
            }
            else{
                return -1;
            }
        }

        void clear(void)
        {
            top = -1;
        }

        bool isEmpty(void)
        {
            if(top == -1)
                return true;
            return false;
        }

    private:
        int top;
        T store[MAXSIZE];

};

int main()
{
    Stack<char> test;
    test.push('a');
    test.push('b');
    test.push('c');
    cout << *test.pop() << '\n';
    cout << *test.pop() << '\n';
    cout << *test.pop() << '\n';
    return 0;
}
