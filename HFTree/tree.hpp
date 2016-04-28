//
//  tree.hpp
//  HFTree
//
//  Created by rootming on 16/4/27.
//  Copyright © 2016年 rootming. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <iostream>
#include <vector>

using namespace std;

class Tree;
class Node;

bool compareMin(const Node &data1, const Node &data2);
struct Data
{
    char data;
    int weight;
    Data();
};

class Node
{
public:
    Node();
    ~Node();
    friend class Tree;
    friend bool compareMin(const Node &data1, const Node &data2);
private:
    Node *leftChild;
    Node *rightChild;
    Node *parent;
    int pos;
    //bool noParent;
    Data data;
};

class Tree
{
public:
    Tree();
    ~Tree();
    void createTree(const vector<Data> &raw);
    void print();
private:
    size_t nodeCount;
    size_t leafCount;
    int minValue1, minValue2;
    vector<Data> values;
    void printPath(Node *arg);
    Node *nodes;
    Node *findMin();
    
};



#endif /* tree_hpp */
