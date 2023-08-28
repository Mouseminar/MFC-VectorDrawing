#pragma once


// Draw_Heartline_Dlg 对话框

class Draw_Heartline_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Draw_Heartline_Dlg)

public:
	Draw_Heartline_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Draw_Heartline_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Draw_Heartline_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_r;
};
