#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<string> words;

void strDiv(char *text)
{
  const char delimit[] = { ' '};      // 分割单词的字符集
  char* word = NULL;                              // 提取到的单词的指针
  char* nextWord = NULL;                          // 指示下次操作的入口指针，实际上是strok()在分割单词之后
  // 置入的'\0'字符处，这就是源串不能是常量的原因

  word = strtok(text, delimit);
  while (word != NULL)
  {
    words.push_back(string(word));
    word = strtok(NULL, delimit);
  }
}

int main()
{
  char tmp[80];
    cin.getline(tmp, 90);
    strDiv(tmp);
    for(int i = words.size() - 1; i >= 0; i--)
    {
      cout << words[i];
      i == 0 ? cout << "" : cout << " ";
    }


}