#ifndef __HASH_H
#define __HASH_H
#include <vector>
#include <algorithm>

using namespace std;

#define LIMIT 100

//template <typename T>
class Hash
{

    public:
        Hash()
        {
            count = 0;
            dataTable = vector<Node>(LIMIT);  
            //dataTable = tmp;

        }

        void insert(const int &key)
        {
            //if(count >= LIMIT){
            //    cout << "Table full.\n";
            //}
            int index = getHash(key);
            //            if(dataTable[index].init == false){
            //                dataTable[index].data.push_back(key);
            //                dataTable.init = true;
            //                count++;
            //            }
            //            else{
            //                cout << "Key aready exist.\n"
            //            }
            auto it = find(dataTable[index].data.begin(), dataTable[index].data.end(), key);
            if(it == dataTable[index].data.end()){
                dataTable[index].data.push_back(key);
                count++;
            }
            else{
                //cout << "Key aready exist.\n";
            }

        }

        void erase(const int &key)
        {
            int index = getHash(key);
            //            if(dataTable[index].init == true){
            //                dataTable[index].data.clear();
            //                dataTable.init = false;
            //                count--;
            //            }
            auto it = find(dataTable[index].data.begin(), dataTable[index].data.end(), key);
            if(it != dataTable[index].data.end()){
                dataTable[index].data.erase(it);
            }
            else{
                cout << "Key not exist!\n";
            }

        }

        bool findKey(const int &key)
        {
            int index = getHash(key);
            auto it = find(dataTable[index].data.begin(), dataTable[index].data.end(), key);
            if(it != dataTable[index].data.end())
                return true;
            else
                return false;

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
            vector<int> data;
        };
        vector<Node> dataTable;
        int count;
        //get index
        virtual int getHash(const int &key)
        {
            return key % LIMIT;
        }

};

#endif
