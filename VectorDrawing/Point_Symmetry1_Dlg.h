#pragma once

#include "CMyPoint.h"

// Point_Symmetry1_Dlg 对话框

class Point_Symmetry1_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Point_Symmetry1_Dlg)

public:
	Point_Symmetry1_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Point_Symmetry1_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Point_Symmetry1_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
public:
	virtual BOOL OnInitDialog();
	CMyPoint* newpoint;
	vector<CMyPoint*>points;
	double m_A;
	double m_B;
	double m_C;
	CString m_name;
	CListCtrl m_list;
	afx_msg void OnBnClickedOk();
};
