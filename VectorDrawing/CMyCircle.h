#pragma once
#include "CMyPoint.h"
class CMyCircle :
    public CMyData
{
public:
    CMyPoint m_O; //Բ��
    double m_R;   //�뾶
    int m_Line_Type;
    int m_Line_Width;
    bool m_isfill;
    COLORREF m_Fill_Color;

    CMyCircle(CString name, COLORREF Line_Color, CMyPoint O, double R, int Line_Type, 
        int Line_Width, bool isfill, COLORREF Fill_Color);
};

