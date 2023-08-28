#pragma once
#include "CMyPolygon.h"

// Draw_Polygon_Dlg 对话框

class Draw_Polygon_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Draw_Polygon_Dlg)

public:
	Draw_Polygon_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Draw_Polygon_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Draw_Polygon_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	double x;
	double y;
	CString name;
	CString m_name;
	int num;
	COLORREF Line_Color; //线条颜色
	vector<CMyPoint> m_Points;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
