//rootming@live.cn
#include <iostream>

using namespace std;

struct Node
{
    struct Node *left;
    struct Node *right;
    int value;
    Node()
    {
        left = NULL;
        right = NULL;
    }
};


void createNode(struct Node **root, const char *raw)
{
    *root = new Node();
    Node *temp;
    temp = *root;
    int pos = 0;
    while(raw[pos] != '\0'){
        pos++;
    }
}
