#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstdlib>

using namespace std;

#define LIMIT 37

class MyHash
{
    public:
    MyHash()
    {
        count = 0;
        dataTable = vector<Node>(LIMIT);  
    }

    void insert(const string &key)
    {
        uint32_t index = getHash(key.c_str());
        auto it = find(dataTable[index].data.begin(), dataTable[index].data.end(), key);
        if(it == dataTable[index].data.end()){
            dataTable[index].data.push_back(key);
            count++;
        }
        else{
            //cout << "Key aready exist.\n";
        }

    }

    void erase(const string &key)
    {
        uint32_t index = getHash(key.c_str());
        auto it = find(dataTable[index].data.begin(), dataTable[index].data.end(), key);
        if(it != dataTable[index].data.end()){
            dataTable[index].data.erase(it);
        }
        else{
            cout << "Key not exist!\n";
        }

    }

    void showCount(void)
    {
        cout << "Count number :" << count << endl;
    }

    private:
    struct Node
    {
        Node(): init(false) {}
        bool init;
        vector<string> data;
    };
    vector<Node> dataTable;
    uint32_t count;

    uint32_t getHash(const char *str)   //BKDRHash
    {
        unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
        unsigned int hash = 0;
        while (*str)
        {
            hash = hash * seed + (*str++);
        }   
        return (hash & 0x7FFFFFFF) % LIMIT;
    }

    

    bool findKey(const string &key)
    {
            uint32_t index = getHash(key.c_str());
            auto it = find(dataTable[index].data.begin(), dataTable[index].data.end(), key);
            if(it != dataTable[index].data.end())
                return true;
            else
                return false;

    }
};

int main(void)
{
    string name1 = "张三";
    string name2 = "张三";
    string name3 = "赵一";
    MyHash test;
    test.insert(name1);
    test.insert(name2);
    test.insert(name3);
    test.showCount();
    return 0;
}

