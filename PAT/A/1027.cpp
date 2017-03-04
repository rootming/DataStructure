#include <iostream>
#include <vector>

using namespace std;

const int radix = 13;

const char alpha[] = { 
    '0', '1', '2', '3', '4', '5', '6',
    '7', '8', '9', 'A', 'B', 'C'
};

const string conv(const int &number)
{
    int num = number;
    vector<int> store;
    string result;

    while(num >= radix){
        store.push_back(num / radix);
        num %= radix;
    }

    store.push_back(num);

    for(auto it: store) {
        result.push_back(alpha[it]);
    }

    if(result.length() < 2)
        result = '0' + result;

    return result;
}

int main(void)
{
    string strNumber[3];
    int number;

    for(int i = 0; i < 3; i++){
        cin >> number;
        strNumber[i] = conv(number);;
    }

    cout << '#' << strNumber[0]
        << strNumber[1] 
        << strNumber[2];

    return 0;
}
