#pragma once
#include "CMyPoint.h"
class CMyPolygon :
    public CMyData
{
public:
    int m_Line_Type;
    int m_Line_Width;
    bool m_isfill;
    COLORREF m_Fill_Color;

    vector<CMyPoint> m_Points;

    CMyPolygon(CString name, COLORREF Line_Color, vector<CMyPoint> Points, int Line_Type,
        int Line_Width, bool isfill, COLORREF Fill_Color);
};

