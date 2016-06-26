//rootming@live.cn
#ifndef __LINK_H__
#define __LINK_H__
#include <iostream>
using namespace std;

/*
   []-> []-> []-> []-> []-> nullptr
   head----------------tail


*/

template <typename T>
class Link
{
    public:
        Link()
        {
            head = nullptr;
            tail = nullptr;
        }


        void addNode(const T &input)
        {
            if (head == nullptr) {
                cerr << "Note: list empty, Now init.\n";
                head = new Node(input);
                tail = head;
            }
            else {
                tail->next = new Node(input);
                tail = tail->next;
            }
        }

        void insertNode(const int pos, const T &input)
        {
            Node *thead = head;
            int i = 0;
            if (thead == nullptr) {
                cerr << "Note: list empty, Need init.\n";
                return;
            }
            else {
                while (thead->next != nullptr && i != pos) {
                    thead = thead->next;
                    i++;
                }
                if (i != pos) {
                    cerr << "Note: out of range.\n";
                    return;
                }
                Node *tmp = new Node(input);
                tmp->next = thead;
                head = tmp;
            }
        }

        void delNode(const int pos)
        {

            Node *thead = head;
            Node *tmp;
            //int i = 0;
            if (thead == nullptr) {
                cerr << "Note: list empty, Need init.\n";
                return;
            }
            else {
                /* if(pos == 0){
                   tmp = thead->next;
                   delete thead;
                   head = tmp;
                   }
                   else{
                   while(thead->next != nullptr && i != pos - 1){
                   thead = thead->next;
                   i++;
                   }
                   if(i != pos - 1){
                   cerr << "Out of range.\n";
                   return;
                   }
                   if(thead->next == tail)
                   tail = thead;
                   tmp = thead->next->next;
                   delete thead->next;
                   thead->next = tmp;
                   }
                   */
                for (int i = 0; i < pos; i++) {
                    if (thead->next != nullptr) {
                        tmp = thead;
                        thead = thead->next;
                    }
                    else {
                        cerr << "Note: out of range.\n";
                        return;
                    }
                }
                if (thead == head) {
                    if (thead == tail) {
                        delete thead;
                        head = tail = nullptr;
                    }
                    else {
                        head = thead->next;
                        delete thead;
                    }
                }

                else if(tmp->next == tail){
                    delete tail;
                    tmp->next = nullptr;
                    tail = tmp;
                }
                else {
                    tmp->next = thead->next;
                    delete thead;
                }
            }
        }

        void eraseList(void)
        {
            Node *tmp;
            while (head != nullptr) {
                tmp = head->next;
                delete head;
                head = tmp;
            }
            head = tail = nullptr;
        }

        struct Node
        {
            Node()
            {
                next = nullptr;
            }

            Node(const T &data)
            {
                this->data = data;
                next = nullptr;
            }

            Node(const Node &source)
            {
                data = source.data;
                next = source.next;
            }

            T data;
            Node *next;

        };

    protected:
        Node *head;
        Node *tail;
};

#endif
