#pragma once
#include "CMyData.h"

class CMyFunc :
    public CMyData
{
public:
	CString m_Equation;		//函数表达式
	double m_minX, m_maxX;		//x极值
	double m_maxY, m_minY;		//y极值
	int m_stepX;				//可以理解为样本点的数量
	int m_Line_Width;

	vector<pair<double, double> > vetPoint;			 //储存所有样本点
	double GetY(double xVal, bool& succ);//得到未知数为xVal时函数值，succ表示计算是否成功
	bool CalcList();					 //计算vetPoint
	bool GetNearest(pair<double, double> NowPoint, pair<double, double>& CmpPoint);//获取本函数与NowPoint最近的点

	CMyFunc(CString name, COLORREF Line_Color, int Line_Width, CString Equation, double minX, double maxX, int stepX);
};

