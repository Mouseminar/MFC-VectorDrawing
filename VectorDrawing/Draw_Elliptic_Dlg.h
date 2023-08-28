#pragma once

#include "CMyPoint.h"

// Draw_Elliptic_Dlg 对话框

class Draw_Elliptic_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Draw_Elliptic_Dlg)

public:
	Draw_Elliptic_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Draw_Elliptic_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Draw_Elliptic_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CMyPoint p1, p2;
//	double m_x1;
//	double m_x2;
//	double m_y1;
//	double m_y2;
//	CString m_name1;
//	CString m_name2;
	afx_msg void OnBnClickedOk();
//	double m_d;
	double m_a;
	double m_b;
};
