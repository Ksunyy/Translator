#include <iostream>
#include "string"
#include "Stack.h"


class Translator {
	public:
		bool IsDigit(char symb) {
			return ('0' <= symb && symb <= '9');
		};
		bool IsOperator(char symb) {
			return ((symb == '+') || (symb == '-') || (symb == '*') || (symb == '/'));
		}
		double Calculate(double val1, double val2, char op) {
			switch (op)
			{
			case('+'): return val2 + val1;
			case('-'): return val2 - val1;
			case('*'): return val2 * val1;
			case('/'): if (val1 == 0) throw "division by zero";
				return val2 / val1;

			default: "wrong value";
			}
		}
		int Priority(char op) {
			if (op == '+' || op == '-') return 1;
			if (op == '*' || op == '/') return 2;
			return 0;
		};
		std::string ToPostFix(std::string& str) {
			Stack<char> operators;
			std::string res = "";
			int chekBrackets = 0;
			int flagOper = 0;
			if (!IsDigit(str[0])) throw "first symbol should be digit";
			for (int i = 0; i < str.length(); ++i) {
				char val = str[i];
				if (IsDigit(val)) {
					res += val;
					flagOper = 0;
				}
				else if (val == '(') {
					chekBrackets++;
					flagOper = 0;
					operators.push(str[i]);
				}
				else if (str[i] == ')') {
					if (chekBrackets == 0) throw "Not expected bracket";
					while (operators.top() != '(') {
						res += operators.top();
						operators.pop();
					}
					flagOper = 0;
					chekBrackets--;
					operators.pop();

				}

				else if (IsOperator(val)) {
					while (!(operators.empty()) && (Priority(val) <= Priority(operators.top()))) {
						if (flagOper == 1) throw "too many operators";
						res += operators.top();
						operators.pop();
						

					}
					flagOper = 1;
					operators.push(val);
				}
				else throw "uncorrect values in string";
				

			}
			while (!operators.empty()) {
				res += operators.top();
				operators.pop();
			}
			if (chekBrackets != 0) throw "Bracket withoout couple";
			return res;
		};

		double CalcPostfix(std::string& postfix) {
			Stack<double> values;
			for (int i = 0; i < postfix.length(); ++i) {
				double res = 0;
				double tmp = 0;
				char cur = postfix[i];
				if (IsDigit(cur)) {
					tmp = (cur - '0');
					values.push(tmp);
				}
				if (IsOperator(cur)) {
					double v1 = values.top();
					values.pop();
					double v2 = values.top();
					values.pop();
					res = Calculate(v1, v2, cur);
					values.push(res);

				}
			}
			return values.top();
		}


};