#pragma once
#include "CMyData.h"
class CMyPoint :
    public CMyData
{
public:
    double m_x;
    double m_y;
    CMyPoint();
    CMyPoint(CString name, COLORREF Line_Color, double x, double y);
};

