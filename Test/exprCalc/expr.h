#ifndef __EXPR_H__
#define __EXPR_H__
#include <string>
#include <map>
#include "unit.h"
#include "stack.h"



class Expr
{
    public:
        Expr();
        void initExpr(const string &expr);
        //void clearExpr(void);
        void midToAfter(void);
        void print(void);
        void printMore(void);
        int calcExpr(void);
    private:
        bool inited;
        bool transLated;
        vector<Unit> raw;
        vector<Unit> after;
        map<char, int>markTable;
        string exprOrgin;
        string exprAfter;
        //int markTable[255];
        void setLevel();

};


#endif
