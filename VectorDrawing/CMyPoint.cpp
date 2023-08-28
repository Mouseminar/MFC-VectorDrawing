#include "pch.h"
#include "CMyPoint.h"

CMyPoint::CMyPoint()
{
	m_type = DATA_POINT;
	m_name = TEXT("");
	m_x = 0;
	m_y = 0;
	COLORREF m_Line_Color = RGB(0, 0, 0);
}

CMyPoint::CMyPoint(CString name, COLORREF Line_Color, double x, double y)
{
	m_type = DATA_POINT;
	m_name = name;
	m_x = x;
	m_y = y;
	m_Line_Color = Line_Color;
}
