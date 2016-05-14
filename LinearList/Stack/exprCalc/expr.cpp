#include <string>
#include "expr.h"

string& trim(string &str, string::size_type pos = 0)
{
	static const string delim = " \t";						//删除空格或者tab字符
	pos = str.find_first_of(delim, pos);
	if (pos == string::npos)
		return str;
	return trim(str.erase(pos, 1));
}

Expr::Expr()
{
	inited = false;
	setLevel();
}

void Expr::initExpr(const string &expr)
{
	inited = true;
	size_t pos = 0;
	exprOrgin = expr;
	string backup = expr;
	trim(backup);									//去除空格 TAB
	while (pos < backup.length()) {
		if (isdigit(backup[pos])) {
			Unit tmp;
			tmp.strraw.push_back(backup[pos]);
			while (isdigit(backup[++pos])) {
				tmp.strraw.push_back(backup[pos]);
			}
			tmp.type = Unit::NUMBER;
			tmp.value = atoi(tmp.strraw.c_str());
			raw.push_back(tmp);
		}
		else {
			Unit tmp;
			tmp.strraw.push_back(backup[pos++]);
			tmp.type = Unit::SYMBOL;
			tmp.weight = markTable[tmp.strraw[0]];
			raw.push_back(tmp);
		}
	}
	inited = true;
}

void Expr::setLevel()
{
	markTable['+'] = 1;
	markTable['-'] = 1;
	markTable['*'] = 2;
	markTable['/'] = 2;
	markTable['%'] = 2;
	markTable['('] = 0;
	//markTable[')'] = 3;
}

void Expr::printMore(void)
{
	if (inited) {
		for (auto i : raw) {
			cout << "Type:";
			i.type == Unit::SYMBOL ? cout << "Symbol" : cout << "Number";
			cout << '\n';
			cout << "Value:" << i.strraw << '\n';
			cout << "Weight:" << i.weight << '\n';
			cout << '\n';
		}
		cout << "\n";

		for (auto i : after) {
			cout << "Type:";
			i.type == Unit::SYMBOL ? cout << "Symbol" : cout << "Number";
			cout << '\n';
			cout << "Value:" << i.strraw << '\n';
			cout << "Weight:" << i.weight << '\n';
			cout << '\n';
		}
		cout << "\n";
	}
}

void Expr::print(void)
{
	if (inited) {
		for (auto i : raw)
			cout << i.strraw << ' ';
		cout << '\n';
		for (auto j : after)
			cout << j.strraw << ' ';
		cout << '\n';
	}
}
void Expr::midToAfter(void)
{
	size_t pos = 0;
	Stack<Unit> stack;
	//while (pos < raw.size()) {
	//	if (raw[pos].type == Unit::NUMBER) {
	//		//如果是数字,存储
	//		after.push_back(raw[pos]);
	//	}
	//	else {
	//		//如果栈为空,则将符号入栈
	//		if (store.isEmpty()) {
	//			store.push(raw[pos]);
	//		}
	//		else {
	//			store.top(temp);
	//			if (raw[pos].strraw[0] == ')') {
	//				store.pop(temp);
	//				while (temp.strraw[0] != '(') {
	//					after.push_back(temp);
	//					store.pop(temp);
	//				}
	//			}
	//			else if (raw[pos].weight < temp.weight) {
	//				store.pop(temp);
	//				do {
	//					after.push_back(temp);
	//					if (!store.pop(temp))
	//						break;
	//				} while (raw[pos].weight < temp.weight);
	//				store.push(raw[pos]);
	//			}
	//			else {
	//				store.push(raw[pos]);
	//			}
	//		}
	//	}
	//	pos++;
	//}
	//while (!store.isEmpty()) {
	//	store.pop(temp);
	//	after.push_back(temp);
	//}
	while (pos < raw.size()) {
		if (raw[pos].type == Unit::NUMBER) {							//如果是数字则存储
			after.push_back(raw[pos]);
		}
		else {
			if (raw[pos].strraw[0] == '(') {							//遇到左括号入栈
				stack.push(raw[pos]);
			}
			else if (raw[pos].strraw[0] == ')') {						//遇到右括号,弹栈至第一个匹配的左括号
				while (stack.top().strraw[0] != '(') {
					after.push_back(stack.pop());
				}
				stack.pop();
			}
			else if (!stack.isEmpty()) {								//如果栈不为空,取栈顶进行判断
				while (raw[pos].weight <= stack.top().weight) {			//弹出栈内所有优先级大于等于当前元素优先级的元素
					after.push_back(stack.top());
					stack.pop();
					if (stack.isEmpty()) {
						break;
					}
				}
				stack.push(raw[pos]);
			}
			else {														//栈为空,则入栈
				stack.push(raw[pos]);
			}
		}
		pos++;
	}
	while (!stack.isEmpty()) {											//弹出栈内剩余元素
		after.push_back(stack.pop());
	}
}

int Expr::calcExpr(void)
{
	if (!transLated)
		return -1;
	int i = 0;
	Stack<int> result;		//操作数栈                                                                                                                                                                          
	for (size_t pos = 0; pos < after.size(); pos++) {
		if (after[pos].type == Unit::NUMBER) {
			result.push(after[pos].value);
		}
		else {
			int op1, op2, op3;
			op1 = result.pop();
			op2 = result.pop();
			switch (after[pos].strraw[0]) {
			case '+':
				op3 = op1 + op2;
				break;
			case '-':
				op3 = op2 - op1;
				break;
			case '*':
				op3 = op1 * op2;
				break;
			case '/':
				op3 = op2 / op1;
				break;
			case '%':
				op3 = op2 % op1;
				break;
			}

			result.push(op3);
		}

	}

	//cout << result.top() << '\n';
	return result.top();//返回最终的计算结果      

}
