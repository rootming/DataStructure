#include <iostream>

using namespace std;

class Queue
{

    public:
        Queue()
        {
            head = NULL;
            tail = NULL;
            initQueue();
        }

        virtual ~Queue()
        {

            while(head != NULL){
                Node *p;
                p = head->next;
                delete head;
                head = p;
            }

        }

        void initQueue(void)
        {
            if(head == NULL){
                head = new Node();
                tail = head;
            }
        }

        void enQueue(int value)
        {
            tail->value = value;
            tail->next = new Node();
            tail = tail->next;
        }
        
        int deQueue(void)
        {
            if(!isEmpty()){
                int tmp = head->value;
                Node *pt = head->next;
                delete head;
                head = pt;
                return tmp;
            }
            else{
                cout << "Queue empty\n";
                return -1;//不够优雅
            }

        }

        bool isEmpty(void)
        {
            return head->next == NULL;
        }

    private:
        struct Node
        {
            Node()
            {
                next = NULL;
            }
            Node *next;
            int value;
        };
        Node *head;
        Node *tail;
};



int main()
{
    Queue test;
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
    cout << test.deQueue() << "\n";
    cout << "Is empty: " << test.isEmpty() << "\n";
    return 0;
}

