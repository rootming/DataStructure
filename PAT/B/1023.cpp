#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int temp;
    int count[10];
    vector<int> number;
    for(int i = 0; i < 10; i++){
        cin >> count[i];
    }
    for(int i = 1; i < 10; i++){
        for(int p = 0; p < count[i]; p++){
            number.push_back(i);
        } 
    }
    if(count[0] == 0 ){
        for(vector<int>::iterator it = number.begin(); it != number.end(); it++){
            cout << *it;
        }
        return 0;
    }
    else{
        for(int p = 0; p < count[0]; p++){
            number.insert(number.begin() + 1, 0);
        } 
        for(vector<int>::iterator it = number.begin(); it != number.end(); it++){
            cout << *it;
        }

    }

    return 0;
}
