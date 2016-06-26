#include <iostream>
using namespace std;

class Queue
{
    public:
        Queue(int size)
        { 
            initQueue(size);
        }
        virtual ~Queue()
        {
            delete []data;
        }
        void initQueue(int size)
        {
            this->len = size + 1;
            this->data = new int[size + 1];
            this->head = 0;
            this->tail = 0;
        }
        void enQueue(int value)
        {
            int pos = (tail + 1) % len;
            if(isFull()){
                cout << "Queue full\n";
            }
            else{
                data[tail] = value; 
                tail = pos;
            }

        }
        int deQueue(void)
        {
            int tmp;
            if(isEmpty()){
                cout << "Queue empty\n";
            }
            else{
                tmp = data[head];
                head = (head + 1) % len;
            }
            return tmp;

        }
        bool isEmpty() const { return head == tail; }
        bool isFull() const { return (tail + 1) % len == head; }
    private:
        int len;
        int head, tail;
        int *data;

};

int main()
{
    Queue test(5);
    test.enQueue(1);
    test.enQueue(2);
    test.enQueue(3);
    test.enQueue(4);
    test.enQueue(5);
    cout << test.deQueue() << "\n";
    cout << test.deQueue() << "\n";
    cout << test.deQueue() << "\n";
    cout << test.deQueue() << "\n";
    cout << test.deQueue() << "\n";
    cout << "Is empty: " << test.isEmpty() << "\n";
    return 0;
}

