#pragma once


// Board_Setting_Dlg 对话框

class Board_Setting_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Board_Setting_Dlg)

public:
	Board_Setting_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Board_Setting_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Board_Setting_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_Xmin;
	double m_Ymin;
	double m_Xmax;
	double m_Ymax;
	afx_msg void OnBnClickedOk();
};
