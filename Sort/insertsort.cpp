//rootming@live.cn
#include <iostream>

using namespace std;

template <typename T>
void sort(T *raw, int length)
{
    int i, key;
    for(int j = 0; j < length; j++){
        key = raw[j];
        i = j - 1;
        while(i >= 0 && raw[i] > key){
            raw[i + 1] = raw[i];
            i--;
            raw[i + 1] = key;
        }
    }
}

int main(void)
{
    int test[] = {1, 2, 1, 0, 5, 7, 3};
    cout << "Raw:\n";
    for(auto it:test)
        cout << it << endl;
    sort(test, 7);
    cout << "Sorted:\n";
    for(auto it:test)
        cout << it << endl;

    return 0;
}
