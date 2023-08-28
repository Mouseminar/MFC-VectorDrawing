#pragma once


// Pen_Setting_Dlg 对话框

class Pen_Setting_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Pen_Setting_Dlg)

public:
	Pen_Setting_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Pen_Setting_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Pen_Setting_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	int m_width;
	COLORREF Line_Color; //线条颜色
	int Line_Type;
	CScrollBar m_bar;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_combo2;
	afx_msg void OnCbnSelchangeCombo2();
};
