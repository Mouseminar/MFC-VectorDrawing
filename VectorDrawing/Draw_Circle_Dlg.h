#pragma once


// Draw_Circle_Dlg 对话框

class Draw_Circle_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Draw_Circle_Dlg)

public:
	Draw_Circle_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Draw_Circle_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Draw_Circle_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_x;
	double m_y;
	double m_r;
	CString m_name;
	afx_msg void OnBnClickedOk();
};
