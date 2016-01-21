#include <iostream>
using namespace std;

template <typename T>
void sort(T *raw, int length)
{
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i - 1; j++){
            if(raw[j] > raw[j + 1]){
                T temp;
                temp = raw[j + 1];
                raw[j + 1] = raw[j];
                raw[j] = temp;
            }
        }
    }

}
int main(void)
{
    int value[] = { 1, 2, 1, 0, 7, 9, 3 };
    size_t length = sizeof(value) / sizeof(int);
    cout <<  "Before:\n";
    for(auto it: value)
        cout << it <<"\n";
    cout <<  "After:\n";
    sort(value, length);
    for(auto it: value)
        cout << it <<"\n";
    return 0;
}

