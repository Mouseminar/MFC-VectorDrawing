#include "pch.h"
#include "CMyLine.h"

CMyLine::CMyLine()
{
}

CMyLine::CMyLine(CString name, COLORREF Line_Color, CMyPoint p1, CMyPoint p2, int Line_Type, int Line_Width)
{
	m_type = DATA_LINE;
	m_p1 = p1;
	m_p2 = p2;
	m_name = name;
	m_Line_Color = Line_Color;
	m_Line_Type = Line_Type;
	m_Line_Width = Line_Width;
}
