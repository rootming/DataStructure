//
//  tree.cpp
//  HFTree
//
//  Created by rootming on 16/4/27.
//  Copyright © 2016年 rootming. All rights reserved.
//

#include "tree.hpp"
#include <algorithm>

using namespace std;

bool compareMin(const Node &data1, const Node &data2)
{
    return data1.data.weight < data2.data.weight;
}

Data::Data()
{
    data = 0;
    weight = -1;
}

Node::Node()
{
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
    //noParent = true;
    pos = 0;
}

Node::~Node()
{
}

Tree::Tree()
{
    
}

Tree::~Tree()
{
    
}
//Data:     A, B, C, D, E
//Weight:   2, 3, 4, 5, 6
//          2-3, 4, 5, 6
//          4-5, 5, 6
//          5-6, 9
//          9-11
//          20
//         /  \
//        9    11
//       / \  /  \
//      4   5 5   6
//           / \
//          2   3


void Tree::createTree(const vector<Data> &raw)
{
    nodeCount = raw.size();
    leafCount = 2 * nodeCount - 1;
    values = raw;
    nodes = new Node[leafCount];
    for(int i = 0; i < nodeCount; i++){
        nodes[i].data = raw[i];
    }
    for(size_t i = nodeCount; i < leafCount; i++){
        //        while(values.size() > 1){
        //            auto it = min_element(values.begin(), values.end(), compareMin);
        //            nodes[i].data = *it;
        //            values.erase(it);
        //            it = min_element(values.begin(), values.end(), compareMin);
        //            nodes[i + 1].data = *it;
        //            values.erase(it);
        //            nodes[i + 2].data.weight = nodes[i].data.weight +
        //                                        nodes[i + 1].data.weight;
        //            nodes[i + 2].leftChild = &nodes[i];
        //            nodes[i + 2].rightChild = &nodes[i + 1];
        //
        //            values.push_back(nodes[i + 2].data);
        auto it = findMin();
        nodes[i].leftChild = it;
        //it->noParent = false;
        it->parent = &nodes[i];
        it->pos = 0;
        cout << it->data.weight << " ";
        it = findMin();
        nodes[i].rightChild = it;
        //it->noParent = false;
        it->parent = &nodes[i];
        it->pos = 1;
        cout << it->data.weight << "\n";
        nodes[i].data.weight = nodes[i].leftChild->data.weight +
        nodes[i].rightChild->data.weight;
        
        //        }
    }
    
}



Node * Tree::findMin()
{
    int min = 0;
    Node *minNode = nullptr;
    for(int i = 0; i < leafCount; i++){
        if(nodes[i].parent == NULL){
            minNode = &nodes[i];
            min = nodes[i].data.weight;
            break;
        }
    }
    for(size_t i = 0; i < leafCount; i++){
        if(nodes[i].data.weight < min && nodes[i].parent == NULL && nodes[i].data.weight != -1){
            min = nodes[i].data.weight;
            minNode = &nodes[i];
        }
    }
    return minNode;
}

void Tree::print()
{
    Node *tmp = nullptr;
    for(int i = 0; i < nodeCount; i++){
        tmp = &nodes[i];
        vector<int> path;
        while(tmp != NULL && tmp != &nodes[leafCount - 1]){
            if(tmp->leftChild == NULL && tmp->rightChild == NULL){
                cout << tmp->data.data;
                path.push_back(tmp->pos);
            }
            else
                path.push_back(tmp->pos);
            tmp = tmp->parent;
        }
        auto it = path.end();
        while(it != path.begin())
            cout << (*--it);
        cout << "\n";
    }
}

void Tree::printPath(Node *arg)
{
    if(arg != NULL){
        if(arg->leftChild == NULL && arg->rightChild == NULL)
            cout << arg->data.data << "\n";
        
        else{
            if(arg->leftChild != NULL){
                cout << "0";
                printPath(arg->leftChild);
            }
            if(arg->rightChild != NULL){
                cout << "1";
                printPath(arg->rightChild);
            }
        }
    }
}

