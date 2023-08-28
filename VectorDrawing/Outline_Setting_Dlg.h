#pragma once


// Outline_Setting_Dlg 对话框

class Outline_Setting_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Outline_Setting_Dlg)

public:
	Outline_Setting_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Outline_Setting_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Outline_Setting_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combox;
	int m_width;
	CScrollBar m_bar;
	CComboBox m_combo2;
	CComboBox m_combo3;
	COLORREF Line_Color; //线条颜色
	int Line_Type;
	COLORREF Fill_Color;	//填充颜色
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int m_isfill;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};
