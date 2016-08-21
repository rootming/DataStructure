#include <iostream>
#include <map>

using namespace std;

int main()
{
        map<char, int> table;
        string input;
        cin >> input;
        for(int i = 0 ; i < input.length(); i++){
                table[input[i]]++;
        }
        for(auto it : table){
        cout << it.first << ":" << it.second << "\n";
        }
}