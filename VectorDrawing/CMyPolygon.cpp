#include "pch.h"
#include "CMyPolygon.h"

CMyPolygon::CMyPolygon(CString name, COLORREF Line_Color, vector<CMyPoint> Points, int Line_Type, int Line_Width, bool isfill, COLORREF Fill_Color)
{
	m_type = DATA_POLYGON;
	m_name = name;
	m_Points = Points;
	m_Line_Color = Line_Color;
	m_Line_Type = Line_Type;
	m_Line_Width = Line_Width;
	m_isfill = isfill;
	m_Fill_Color = Fill_Color;
}
