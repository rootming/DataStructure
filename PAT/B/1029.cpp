#include <iostream>
using namespace std;

struct Key
{
    char c;
    bool good;
};

int main()
{
    string in;
    string out;
    Key *list;
    cin >> in;
    cin >> out;
    list = new Key[in.length()];
    for(int i = 0; i < in.length(); i++){
        list[i].c = toupper(in[i]);
        list[i].good = false;
    }

    for(int i = 0; i < out.length(); i++)
        out[i] = toupper(out[i]);
    for(int i = 0; i < out.length(); i++){
        for(int p = 0; p < in.length(); p++){
            if(list[p].c == out[i]){
                list[p].good = true;
                //break;

            }
        }
    }

    for(int i = 0; i < in.length(); i++){
        char c = list[i].c;
        for(int p = i + 1; p < in.length(); p++){
            if(c == list[p].c && list[p].good == false)
                list[p].good = true;
        }
    }
    for(int i = 0; i < in.length(); i++){
        if(list[i].good == false){
            cout << (char)list[i].c;
        }
    }
    return 0;


}
