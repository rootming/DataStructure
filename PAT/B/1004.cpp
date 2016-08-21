#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct info
{
    string name;
    string number;
    int g;
};


bool cmp(const info &a, const info &b)
{
    return a.g > b.g;
}


ostream & operator <<(ostream & output, const info & arg)
{
    output<<arg.name<<" "<<arg.number<<" "<<arg.g<<endl;
    return output;
}



int main()
{
    int stop;
    cin>>stop;
    vector<info> list(stop);
    for(int i = 0; i < stop; i++){
        cin>>list[i].name>>list[i].number>>list[i].g;
    }
    sort(list.begin(), list.end(), cmp);
    //    for(int i = 0; i < stop; i++){
    //        cout<<list[i];
    //    }
    //sort(list.begin(), list.end() - 1, compare);
    vector<info>::iterator first = list.begin();
    //vector<info>::iterator last = list.end();
    cout<<first->name<<" "<<first->number<<endl;
    first += stop - 1;
    cout<<first->name<<" "<<first->number<<endl;
    //cout<<last->name<<" "<<last->number<<endl;
    return 0;
}
