#pragma once

#include "CMyPoint.h"

// Point_Symmetry2_Dlg 对话框

class Point_Symmetry2_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Point_Symmetry2_Dlg)

public:
	Point_Symmetry2_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Point_Symmetry2_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Point_Symmetry2_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMyPoint* newpoint;
	vector<CMyPoint*>points;
	CListCtrl m_list;
	double m_x;
	double m_y;
	CString m_name;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
