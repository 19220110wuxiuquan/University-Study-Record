#include<iostream>
#include<cstdio>
using namespace std;

// 顺序栈的实现
template<class T, int MaxSize>
class SeqStack {
	T data[MaxSize];
	int top;

public:
	SeqStack();
	void Push(T x);
	T Pop();
	T Top();
	bool Empty();
};

// 顺序栈的初始化
template<class T, int MaxSize>
SeqStack<T, MaxSize>::SeqStack() {
	top = -1;
}

// 顺序栈的入栈操作
template<class T, int MaxSize>
void SeqStack<T, MaxSize>::Push(T x) {
	if (top == MaxSize - 1) {
		cerr << "上溢";
		exit(1);
	}
	top++;
	data[top] = x;
}

// 顺序表的出栈操作
template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Pop() {
	if (top == -1) {
		cerr << "下溢" << endl;
		exit(1);
	}
	T x = data[top];
	top--;
	return x;
}

// 取栈顶元素
template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Top() {
	if (top == -1) {
		cerr << "下溢" << endl;
		exit(1);
	}
	return data[top];
}

// 判断顺序栈是否为空
template<class T, int MaxSize>
bool SeqStack<T, MaxSize>::Empty() {
	return top == -1;
}

// 判断运算符优先级
int Precede(char op1, char op2) 
{
	if (op1 == '+' || op1 == '-') {
		if (op2 == '+' || op2 == '-' || op2 == ')' || op2 == '@')
			return '>';
		else
			return '<';
	}
	else if (op1 == '*' || op1 == '/') {
		if (op2 == '(')
			return '<';
		else
			return '>';
	}
	else if (op1 == '(') {
		if (op2 == ')')
			return '=';
		else
			return '<';
	}
	else if (op1 == ')') {
		if (op2 == '(')
			return ' ';
		else
			return '>';
	}
	else if (op1 == '@') {
		if (op2 == '@')
			return '=';
		else
			return '<';
	}
	return -1;
}

// 执行运算
double Operate(double a, char op, double b) 
{
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		return 0.0;
	}
}

// 利用算符优先法计算表达式的值
double Expression_Eval() 
{
	SeqStack<char, 100> OPTR;
	SeqStack<double, 100> OPND;
	OPTR.Push('@');
	char ch = getchar();
	while (ch != '@' || OPTR.Top() != '@') {
		if (ch >= '0' && ch <= '9') {
			OPND.Push(ch - '0');
			ch = getchar();
		}
		else {
			char pre_op = OPTR.Top();
			switch (Precede(pre_op, ch)) {
			case '<':
				OPTR.Push(ch);
				ch = getchar();
				break;
			case '=':
				OPTR.Pop();
				ch = getchar();
				break;
			case '>': {
				double b = OPND.Pop();
				double a = OPND.Pop();
				pre_op = OPTR.Pop();
				OPND.Push(Operate(a, pre_op, b));
				break;
			}
			}
		}
	}
	return OPND.Top();
}

int main() 
{
	cout << "请输入表达式（以@结尾）：" << endl;
	double result = Expression_Eval();
	cout << "计算结果为：" << result << endl;
	return 0;
}