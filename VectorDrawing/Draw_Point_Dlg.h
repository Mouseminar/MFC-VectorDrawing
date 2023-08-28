#pragma once


// Draw_Point_Dlg 对话框

class Draw_Point_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Draw_Point_Dlg)

public:
	Draw_Point_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Draw_Point_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Draw_Point_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_x;
	double m_y;
	afx_msg void OnBnClickedOk();
	CString m_name;
};
