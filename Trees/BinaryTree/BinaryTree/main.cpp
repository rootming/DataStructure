#include <iostream>
#include <stack>

using namespace std;

struct Node 
{
    Node()
    {
        leftChild = NULL;
        rightChild = NULL;
        cout << "Add node\n";
    }
    Node *leftChild;
    Node *rightChild;
    char data;
};


class BinaryTree
{
    public:
        enum TYPE {FIRST, NOTFIRST};
        BinaryTree()
        {
            point = new Node();
        }

        Node *creatTree(BinaryTree::TYPE isFirst = NOTFIRST)
        {
            char option;
            Node *tp;
            if(isFirst == FIRST)
                tp = point;        
            else 
                tp = new Node();

            cout << "Input value:\n";
            cin >> tp->data;    
            cout << "Add child ? Y or N\n";
            cin >> option;
            if(option == 'Y'){
                tp->leftChild = creatTree();
                tp->rightChild = creatTree();
            }
            return tp;
        }

        /*
        void frontPrintTree(Node *first)
        {
            if(first != NULL){
                cout << first->data << " ";
                frontPrintTree(first->leftChild);             
                frontPrintTree(first->rightChild);
            }
        }
        */
        void frontPrintTree(Node *first)
        {
            stack<Node *> store;
            store.push(first);
            while(store.size() == 0){
                if(store.top().leftChild == NULL){
                    cout << 
                }
            }
        }

        void midPrintTree(Node *first)
        {
            if(first != NULL){
                midPrintTree(first->leftChild);
                cout << first->data << " ";
                midPrintTree(first->rightChild);
            }
        }

        void lastPrintTree(Node *first)
        {
            if(first != NULL){ 
                lastPrintTree(first->rightChild);
                lastPrintTree(first->leftChild);
                cout << first->data << " ";
            }
        }

        void printTree()
        {
            cout << "前序遍历:\n";
            frontPrintTree(point);
            cout << "\n";
            cout << "中序遍历:\n";       
            midPrintTree(point);
            cout << "\n";
            cout << "后序遍历:\n";
            lastPrintTree(point);
            cout << "\n";
        }

    private:
        Node *point; 
}; 
int main(void)
{ 
    BinaryTree test; 
    test.creatTree(BinaryTree::FIRST); 
    test.printTree(); 
    return 0; 
}
