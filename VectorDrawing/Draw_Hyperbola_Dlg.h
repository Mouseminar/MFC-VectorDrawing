#pragma once


// Draw_Hyperbola_Dlg 对话框

class Draw_Hyperbola_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Draw_Hyperbola_Dlg)

public:
	Draw_Hyperbola_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Draw_Hyperbola_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Draw_Hyperbola_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_a;
	double m_b;
	afx_msg void OnBnClickedOk();
};
