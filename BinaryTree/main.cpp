#include <iostream>

using namespace std;

struct Tree
        {
            Tree()
            {
                leftChild = NULL;
                rightChild = NULL;
                cout << "Add node\n";
            }
            Tree *leftChild;
            Tree *rightChild;
            int data;
        };


class BinaryTree
{
    public:
        enum TYPE {FIRST, NOTFIRST};
        BinaryTree()
        {
            point = new Tree();
        }

        Tree *creatTree(BinaryTree::TYPE isFirst = NOTFIRST)
        {
            int temp;
            char option;
            Tree *tp;
            if(isFirst == FIRST)
                tp = point;
            else 
                tp = new Tree();
            cout << "Add child ? Y or N\n";
            cin >> option;
            if(option == 'Y'){
                cout << "Input value:\n";
                cin >> temp;
                tp->data = temp;
                tp->leftChild = creatTree();
                tp->rightChild = creatTree();

            }
            else{
                delete tp;
                tp = NULL;
            }
            return tp;
        }


    private:
        Tree *point;
};

int main(void)
{
    BinaryTree test;
    test.creatTree(BinaryTree::FIRST);
    return 0;
}
