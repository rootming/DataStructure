#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
    map<int, int> score, sorted;
    map<int, int>::iterator it;
    int count;
    int number, level;
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> number;
        cin >> level;
        score[number] += level;
    }

    for(it = score.begin(); it != score.end(); ++it)
        sorted[it->second] = it->first;
    it = sorted.end();
    --it;
    cout << it->second << " " << it->first;




    return 0;
}
