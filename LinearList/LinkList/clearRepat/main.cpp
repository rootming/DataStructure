#include <string>
#include <map>
#include "link.h"

using namespace std;

template <typename T>
class EXList: public Link<T>
{
    public:
        void clearRepat(void)
        {
            if (this->head == nullptr) {
                cerr << "Note: need init.\n";
                return;
            }
            auto tmp = this->head;
            map <T, int> nodeStore;

                while (tmp != nullptr) {
                    nodeStore[tmp->data]++;
                    tmp = tmp->next;
                }
            this->eraseList();
            for (auto it = nodeStore.begin(); it != nodeStore.end(); ++it)
                cout << "Note: node value: " << it->first << " times: " << it->second << endl;
            for (auto it = nodeStore.begin(); it != nodeStore.end(); ++it)
                this->addNode(it->first);
        }

        void printAll(void)
        {
            if (this->head == nullptr) {
                cerr << "Note: need init.\n";
                return;
            }
            auto tmp = this->head;
            while (tmp != nullptr) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << "\n";
        }
};


int main(void)
{
    string input;
    EXList<char> test;
    cout << "Please input value:\n";
    cin >> input;
    for(auto i : input)
        test.addNode(i);
    cout << "Print all:\n";
    test.printAll();
    test.clearRepat();
    cout << "Print all:\n";
    test.printAll();

    return 0;
}
