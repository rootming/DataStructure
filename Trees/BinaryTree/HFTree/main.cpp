//
//  main.cpp
//  HFTree
//
//  Created by rootming on 16/4/26.
//  Copyright © 2016年 rootming. All rights reserved.
//

#include <iostream>
#include "tree.hpp"

int main(int argc, const char * argv[]) {

    vector<Data> testdata(5);
    for(int i = 0; i < 5; i++){
        testdata[i].weight = 6 - i;
        testdata[i].data = 'A' + 4 - i;
    }
    //Data: 2, 3, 4, 5, 6
    //      2-3, 4, 5, 6
    //      4-5, 5, 6
    //      5-6, 9
    //      9-11
    //          20
    //         /  \
    //        9    11
    //       / \  /  \
    //      4   5 5   6
    //         / \
    //        2   3
    Tree tree;
    tree.createTree(testdata);
    tree.print();
}
