#pragma once
#include "CMyPoint.h"
class CMyLine :
    public CMyData
{
public:
    CMyPoint m_p1, m_p2;
    int m_Line_Type;
    int m_Line_Width;

    CMyLine();
    CMyLine(CString name, COLORREF Line_Color, CMyPoint p1, CMyPoint p2, int Line_Type, int Line_Width);
};

