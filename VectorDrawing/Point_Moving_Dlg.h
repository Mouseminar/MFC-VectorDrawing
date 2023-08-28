#pragma once

#include "CMyPoint.h"

// Point_Moving_Dlg 对话框

class Point_Moving_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Point_Moving_Dlg)

public:
	Point_Moving_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Point_Moving_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Point_Moving_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	double m_x;
	double m_y;
	CString m_name;
	CMyPoint* newpoint;
	vector<CMyPoint*>points;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
