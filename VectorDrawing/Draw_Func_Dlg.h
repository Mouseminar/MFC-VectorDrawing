#pragma once


// Draw_Func_Dlg 对话框

class Draw_Func_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Draw_Func_Dlg)

public:
	Draw_Func_Dlg(int Xmin, int Xmax, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Draw_Func_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Draw_Func_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CString m_sEquation;
	double m_Xmin;
	double m_Xmax;
	int m_stepX;
	afx_msg void OnBnClickedButtonSetfunc();
	afx_msg void OnBnClickedOk();
	CString m_name;
};
