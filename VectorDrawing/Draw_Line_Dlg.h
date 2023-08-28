#pragma once


// Draw_Line_Dlg 对话框

class Draw_Line_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Draw_Line_Dlg)

public:
	Draw_Line_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Draw_Line_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Draw_Line_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_x1;
	double m_y1;
	CString m_name1;
	CString m_name2;
	double m_y2;
	double m_x2;
	afx_msg void OnBnClickedOk();
	CString m_name;
};
