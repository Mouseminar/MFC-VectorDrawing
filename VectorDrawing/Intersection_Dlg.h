#pragma once

#include "CMyLine.h"
#include "CMyPolygon.h"
#include "CMyPoint.h"
#include "CMyCircle.h"

// Intersection_Dlg 对话框

class Intersection_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Intersection_Dlg)

public:
	Intersection_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Intersection_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Intersection_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CMyLine line;
	vector<pair<double, double>> newpoints;
	vector<CMyData*>shapes;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	void GetIntersectionPoint(CMyLine L1, CMyLine L2);
	void LineCircleIntersection(CMyCircle O, CMyLine L);
};
