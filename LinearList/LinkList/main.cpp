#include <iostream>

using namespace std;

typedef struct _Node 
{
    int data;
    _Node *next;
} Node;

void CreatListHead(Node *head, int *array, int length)
{
    Node *tmp;
    head->next = NULL;
    for(int i = 0; i < length; i++){
        tmp = new Node;
        tmp->data = array[i];
        tmp->next = head->next;
        head->next = tmp;
    }
}

void CreatListTail(Node *head, int *array, int length)
{
    Node *tmp, *tmp2;
    tmp = head;
    for(int i = 0; i < length; i++){
        tmp2 = new Node;
        tmp2->data = array[i];
        tmp->next = tmp2;
        tmp = tmp2;
    }
    tmp->next = NULL; 
}
void DisplayList(Node *head)
{
    Node *tmp;
    tmp = head;
    while((head = head->next) != NULL){
        cout << head->data << "\n";
    }
}

int main()
{
    int test[] = { 1, 2, 3, 4, 5};
    int test2[] = { 1, 2, 3, 4, 5};
    Node List, List2;
    CreatListHead(&List, test, 5);
    CreatListTail(&List2, test2, 5);
    DisplayList(&List);
    DisplayList(&List2);
}
