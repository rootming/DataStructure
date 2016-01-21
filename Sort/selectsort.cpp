//rootming
#include <iostream>

using namespace std;


template <typename T>
void sort(T *raw, int len)
{
    T temp;
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(raw[j] < raw[i]){
                temp = raw[i];
                raw[i] = raw[j];
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


