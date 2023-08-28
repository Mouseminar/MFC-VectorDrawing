#pragma once
#include "CMyData.h"

class CMyFunc :
    public CMyData
{
public:
	CString m_Equation;		//�������ʽ
	double m_minX, m_maxX;		//x��ֵ
	double m_maxY, m_minY;		//y��ֵ
	int m_stepX;				//�������Ϊ�����������
	int m_Line_Width;

	vector<pair<double, double> > vetPoint;			 //��������������
	double GetY(double xVal, bool& succ);//�õ�δ֪��ΪxValʱ����ֵ��succ��ʾ�����Ƿ�ɹ�
	bool CalcList();					 //����vetPoint
	bool GetNearest(pair<double, double> NowPoint, pair<double, double>& CmpPoint);//��ȡ��������NowPoint����ĵ�

	CMyFunc(CString name, COLORREF Line_Color, int Line_Width, CString Equation, double minX, double maxX, int stepX);
};

