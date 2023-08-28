// Outline_Setting_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Outline_Setting_Dlg.h"
#include "afxdialogex.h"


// Outline_Setting_Dlg 对话框

IMPLEMENT_DYNAMIC(Outline_Setting_Dlg, CDialogEx)

Outline_Setting_Dlg::Outline_Setting_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Outline_Setting_Dlg, pParent)
	, m_width(0)
	, m_isfill(0)
{

}

Outline_Setting_Dlg::~Outline_Setting_Dlg()
{
}

void Outline_Setting_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combox);
	DDX_Text(pDX, IDC_EDIT1, m_width);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_bar);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO3, m_combo3);
	DDX_Radio(pDX, IDC_RADIO1, m_isfill);
}


BEGIN_MESSAGE_MAP(Outline_Setting_Dlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_CBN_SELCHANGE(IDC_COMBO1, &Outline_Setting_Dlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Outline_Setting_Dlg::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &Outline_Setting_Dlg::OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_RADIO1, &Outline_Setting_Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Outline_Setting_Dlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// Outline_Setting_Dlg 消息处理程序


BOOL Outline_Setting_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_combox.AddString(TEXT("红色"));
	m_combox.AddString(TEXT("橙色"));
	m_combox.AddString(TEXT("黄色"));
	m_combox.AddString(TEXT("绿色"));
	m_combox.AddString(TEXT("青色"));
	m_combox.AddString(TEXT("蓝色"));
	m_combox.AddString(TEXT("紫色"));
	m_combox.AddString(TEXT("黑色"));
	m_combox.SetCurSel(0);

	m_combo2.AddString(TEXT("实线"));
	m_combo2.AddString(TEXT("虚线"));
	m_combo2.AddString(TEXT("点线"));
	m_combo2.SetCurSel(0);
	Line_Type = 0;

	m_combo3.AddString(TEXT("红色"));
	m_combo3.AddString(TEXT("橙色"));
	m_combo3.AddString(TEXT("黄色"));
	m_combo3.AddString(TEXT("绿色"));
	m_combo3.AddString(TEXT("青色"));
	m_combo3.AddString(TEXT("蓝色"));
	m_combo3.AddString(TEXT("紫色"));
	m_combo3.AddString(TEXT("黑色"));
	m_combo3.SetCurSel(0);

	m_bar.SetScrollRange(1, 10);        // 设置滚动条范围
	m_width = 5;
	m_bar.SetScrollPos(m_width);               // 设置滚动条初始值

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Outline_Setting_Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nSBCode)
	{
		// 如果向左滚动一列，则pos减1  
	case SB_LINELEFT:
		if (m_width > 1)
			m_width -= 1;
		break;
		// 如果向右滚动一列，则pos加1  
	case SB_LINERIGHT:
		if (m_width < 10)
			m_width += 1;
		break;
		// 如果向左滚动一页，则pos减10  
	case SB_PAGELEFT:
		m_width -= 1;
		break;
		// 如果向右滚动一页，则pos加10  
	case SB_PAGERIGHT:
		m_width += 1;
		break;
		// 如果滚动到最左端，则pos为1  
	case SB_LEFT:
		m_width = 0;
		break;
		// 如果滚动到最右端，则pos为100  
	case SB_RIGHT:
		m_width = 150;
		break;
		// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值  
	case SB_THUMBPOSITION:
		m_width = nPos;
		break;
	default:
		;
	}

	(*pScrollBar).SetScrollPos(m_width);
	UpdateData(FALSE);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void Outline_Setting_Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_combox.GetCurSel();
	if (index == 0) Line_Color = RGB(255, 0, 0);
	else if (index == 1) Line_Color = RGB(255, 165, 0);
	else if (index == 2) Line_Color = RGB(255, 255, 0);
	else if (index == 3) Line_Color = RGB(0, 255, 0);
	else if (index == 4) Line_Color = RGB(0, 255, 255);
	else if (index == 5) Line_Color = RGB(0, 0, 255);
	else if (index == 6)  Line_Color = RGB(128, 0, 128);
	else Line_Color = RGB(0, 0, 0);
}


void Outline_Setting_Dlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	Line_Type = m_combo2.GetCurSel();
}


void Outline_Setting_Dlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_combo3.GetCurSel();
	if (index == 0) Fill_Color = RGB(255, 0, 0);
	else if (index == 1) Fill_Color = RGB(255, 165, 0);
	else if (index == 2) Fill_Color = RGB(255, 255, 0);
	else if (index == 3) Fill_Color = RGB(0, 255, 0);
	else if (index == 4) Fill_Color = RGB(0, 255, 255);
	else if (index == 5) Fill_Color = RGB(0, 0, 255);
	else if (index == 6)  Fill_Color = RGB(128, 0, 128);
	else Fill_Color = RGB(0, 0, 0);
}


void Outline_Setting_Dlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_isfill = 0;
	UpdateData(FALSE);
}


void Outline_Setting_Dlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_isfill = 1;
	UpdateData(FALSE);
}
