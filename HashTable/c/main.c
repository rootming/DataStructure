#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <stdbool.h>
#define LIMIT 100

int count = 0;

typedef struct _node
{
    struct _node *next;
    int value;
} node;

typedef struct _unit
{
    node *data;
} unit;

void init_node(node **p, int key)
{
    *p = malloc(sizeof(node));
    (*p)->value = key;
    (*p)->next = NULL;
}

node *find_node(node *p, int key)
{
    node *temp = p;
    do{
        if(temp->value == key)
            return temp;
        else
            temp = temp->next;
    }while(temp != NULL);
    return NULL;
}

node *last_node(node *p)
{
    node *temp = p;
    do{
        temp = temp->next;
    }while(temp != NULL);

    return temp;

}

void init_hash(unit **table)
{
    *table = malloc(sizeof(unit) * LIMIT);
    for(int i = 0; i < LIMIT; i++){
        (*table)[i].data = NULL;
    }
}

int get_hash(const int key)
{
    return key % 97;
}

void insert_hash(unit *table, const int key)
{
    int index = get_hash(key);
    if(table[index].data == NULL){
        init_node(&table[index].data, key);
        count++;
    }
    else{
        if(find_node(table[index].data, key) == NULL){
            node *temp = last_node(table[index].data);
            init_node(&temp, key);
            count++;
        }
    }
}

bool findKey(unit *table, const int key)
{
    int index = get_hash(key);
    if(table[index].data == NULL){
        return false;
    }
    else{
        if(find_node(table[index].data, key) != NULL){
            return true;
        }
        else{
            return false;
        }

    }


}

void erase_hash(unit *table, const int key)
{

}

int main()
{
    unit *hashtable;
    srand(time(NULL));
    init_hash(&hashtable);
//    for(int i = 0; i < 10000; i++){
//        insert_hash(hashtable, rand() % 1000);
//    }
    insert_hash(hashtable, 1);
    insert_hash(hashtable, 1);
    insert_hash(hashtable, 1);
    insert_hash(hashtable, 1);
    insert_hash(hashtable, 1);
    insert_hash(hashtable, 2);
    insert_hash(hashtable, 2);
    insert_hash(hashtable, 3);
    printf("count :%d\n", count);
    return 0;
}
