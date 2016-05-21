#ifndef __UNIT_H__
#define __UNIT_H__

#include <iostream>

using namespace std;

struct Unit
{
    enum UNITTYPE { NUMBER = 0, SYMBOL };
    UNITTYPE type;
    string strraw;
    int value;
    int weight;
    Unit()
    {
        weight = -1;
    }
};



#endif
