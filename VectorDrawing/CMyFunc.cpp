#include "pch.h"
#include "CMyFunc.h"
#include "CalculatorFunc.h"

const double inf = 1e14;
// FuncData
inline double Pow2(double x) { return x * x; }

double CMyFunc::GetY(double xVal, bool& succ)
{
    return  CalcEquation(m_Equation, succ, 'x', xVal);
}

bool CMyFunc::CalcList()
{
	vetPoint.clear();
	double detx = (m_maxX - m_minX) / m_stepX;
	bool succ = true;
	m_minY = inf; m_maxY = -inf;
	for (double tmp_x = m_minX; tmp_x <= m_maxX; tmp_x += detx) {
		double tmp_y = this->GetY(tmp_x, succ);
		if (tmp_y > m_maxY) m_maxY = tmp_y;
		if (tmp_y < m_minY) m_minY = tmp_y;
		vetPoint.emplace_back(std::make_pair(tmp_x, tmp_y));
		if (!succ) return false;
	}
	return true;
}

bool CMyFunc::GetNearest(pair<double, double> NowPoint, pair<double, double>& CmpPoint)
{
	if (NowPoint.first < m_minX || NowPoint.second > m_maxX) return false;
	bool succ;
	double nY = GetY(NowPoint.first, succ);
	if (Pow2(nY - NowPoint.second) < Pow2(NowPoint.first - CmpPoint.first) + Pow2(NowPoint.second - CmpPoint.second)) {
		CmpPoint = std::make_pair(NowPoint.first, nY);
		return true;
	}
	return false;
}

CMyFunc::CMyFunc(CString name, COLORREF Line_Color, int Line_Width, CString Equation, double minX, double maxX, int stepX)
{
	m_type = DATA_FUNC;
	m_name = name;
	m_Line_Color = Line_Color;
	m_Line_Width = Line_Width;
	m_Equation = Equation;
	m_minX = minX;
	m_maxX = maxX;
	m_stepX = stepX;
}
