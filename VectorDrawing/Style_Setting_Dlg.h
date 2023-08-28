#pragma once


// Style_Setting_Dlg 对话框

class Style_Setting_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Style_Setting_Dlg)

public:
	Style_Setting_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Style_Setting_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Style_Setting_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_r;
	afx_msg void OnBnClickedOk();
};
