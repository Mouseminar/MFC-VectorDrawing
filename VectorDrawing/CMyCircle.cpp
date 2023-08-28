#include "pch.h"
#include "CMyCircle.h"

CMyCircle::CMyCircle(CString name, COLORREF Line_Color, CMyPoint O, double R, int Line_Type, int Line_Width, bool isfill, COLORREF Fill_Color)
{
	m_type = DATA_CIRCLE;
	m_name = name;
	m_Line_Color = Line_Color;
	m_Line_Type = Line_Type;
	m_Line_Width = Line_Width;
	m_O = O;
	m_R = R;
	m_isfill = isfill;
	m_Fill_Color = Fill_Color;
}
