#include "pch.h"
#include "CalculatorFunc.h"

#define MAXNUM 30
#define MAXOPT 30

const double pi = 3.1415926535898;
const double e = 2.718281828459;

bool IsOpt(char c) {
	return  c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool IsNum(char c) {
	return c >= '0' && c <= '9' || c == 'e'  || c == 'p';
}

double GetNum(CString& Eq, int& i, char xKey, double xVal)
{
	int flag = 1;
	if (i < Eq.GetLength() && Eq[i] == '-') {
		flag = -1;
		i++;
	}
	
	if (i < Eq.GetLength() && Eq[i] == 'p') {
		i++;
		return flag * pi;
	 }
   
	if (i < Eq.GetLength() && Eq[i] == 'e') {
		i++;
		return flag * e;
	}
	//cout<<Eq[i]<<" ";	
	if (i < Eq.GetLength() && Eq[i] == xKey) {
		i++;
		return flag * xVal;
	}

	double x = 0;
	while (i < Eq.GetLength() && IsNum(Eq[i]))
	{
		x = x * 10 + Eq[i] - '0';
		i++;
	}
	double rad = 0.1;
	if (i < Eq.GetLength() && Eq[i] == '.')
	{
		i++;
		while (i < Eq.GetLength() && IsNum(Eq[i]))
		{
			x = x + (Eq[i] - '0') * rad;
			rad = rad * 0.1;
			i++;
		}
	}
	return flag * x;
}

double Get_Equation_Num(CString& Eq, int& i, bool& succ, char xKey, double xVal) {
	if (IsNum(Eq[i]) || Eq[i] == '-' || Eq[i] == xKey)
		return GetNum(Eq, i, xKey, xVal);//�������ֱ�Ӷ�
	CString single_func;//��¼��Ŀ�����
	succ = false;
	double tmp_ans = 0;//��¼��ʽ��ֵ
	int Lcnt = 0;//�ж����������ţ���sqrt(1+(1-1))
	while (i < Eq.GetLength()) {
		if (Eq[i] == '(') {//�����ţ���Ŀ������Ѿ���¼�꣬����������ʽ
			i++;
			CString tmpEq;//��¼��ʽ
			while (i < Eq.GetLength()) {
				if (Eq[i] == '(') Lcnt++;
				if (Eq[i] == ')') {
					if (Lcnt)
						Lcnt--;
					else {//�ҵ����һ��������ƥ�����������
						succ = true;//�ݹ������������ʽ��ֵ
						tmp_ans = CalcEquation(tmpEq, succ, xKey, xVal);
						i++;
						break;
					}
				}
				tmpEq += Eq[i];
				i++;
			}
			break;
		}
		single_func += Eq[i];
		i++;
	}

	if (succ) {
		if (single_func == _T(""))
			return tmp_ans;
		if (single_func == _T("sin")) 
			return sin(tmp_ans);
		if (single_func == _T("cos"))
			return cos(tmp_ans);
		if (single_func == _T("tan"))
			return tan(tmp_ans);
		if (single_func == _T("abs"))
			return abs(tmp_ans);
		if (single_func == _T("floor"))
			return floor(tmp_ans);
		if (single_func == _T("ceil"))
			return ceil(tmp_ans);
		if (single_func == _T("round"))
			return round(tmp_ans);
		if (single_func == _T("sqrt"))
			return sqrt(tmp_ans);
		if (single_func == _T("ln"))
			return log(tmp_ans);
		if (single_func == _T("lg"))
			return log10(tmp_ans);
		succ = false;
		return 0;
	}
}



double Calc(double num1, char opt, double num2)
{

	//cout << "calc " << num1 << opt << num2 << "\n"; 
	switch (opt)
	{
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	case '^': return pow(num1, num2);
	}
}

int cPriority(char c) {
	if (c == '^') return 3;
	if (c == '*' || c == '/') return 2;
	return 1;
}

double CalcEquation(CString m_sEquation, bool& succ, char xKey, double xVal) {
	//m_sEquation���ʽ succ�����Ƿ�ɹ� xKeyδ֪����"x"����"t"  xValδ֪����ֵ
	if (m_sEquation.GetLength() == 0) {
		succ = false;
		return 0;
	}
	double num[MAXNUM];//����ջ
	int ntop = -1;
	char opt[MAXOPT];//���ʽջ
	int otop = -1;
	int Len = m_sEquation.GetLength();

	for (int i = 0; i < Len; ) {
		num[++ntop] = Get_Equation_Num(m_sEquation, i, succ, xKey, xVal);
		// Get_Equation_Num���ڵõ�һ�����ֻ���һ����Ŀ�����+��ʽ��ֵ
		if (i == Len) break;
		if (!IsOpt(m_sEquation[i])) {//�ж��Ƿ���˫Ŀ�����
			succ = false;
			return 0;
		}

		while (otop >= 0 && cPriority(opt[otop]) >= cPriority(m_sEquation[i])) {//�����ȼ���ջ
			num[ntop - 1] = Calc(num[ntop - 1], opt[otop], num[ntop]);
			ntop--;
			otop--;
		}
		opt[++otop] = m_sEquation[i];
		i++;
	}

	while (otop >= 0 && ntop >= 1) {//û��ջ�ĳ�ջ
		num[ntop - 1] = Calc(num[ntop - 1], opt[otop], num[ntop]);
		ntop--;
		otop--;
	}
	if (otop != -1 && ntop != 0)
		succ = false;
	return num[0];
}