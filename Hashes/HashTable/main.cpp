#include <iostream>
#include "hash.h"
#include <cstdlib>

int main(void)
{
    Hash test;
    Hash test2;
    srand(time(NULL));
    for(int i = 0; i < 100000; i++){
        test.insert(rand()%1000000);
    } 
    test.showCount();
     int raw[] = { 1, 3, 4, 1, 1, 2, 4};
     for(auto i:raw){
        test2.insert(i);
     }
    test2.showCount();

    return 0;
}

