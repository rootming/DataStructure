#include "expr.h"



int main(void)
{
	string testExpr = "12 -11*20/(20-10)+100+(1000+22)+(1+1+2/2*((2*20)))";
	//string testExpr = "(1-1)-1+1*4/4";
	Expr test;
	test.initExpr(testExpr);
	test.midToAfter();
	test.print();
	cout << "Result:" << test.calcExpr() << '\n';
	getchar();
}