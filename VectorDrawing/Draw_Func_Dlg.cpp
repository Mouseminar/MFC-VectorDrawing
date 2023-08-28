// Draw_Func_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Draw_Func_Dlg.h"
#include "afxdialogex.h"
#include "Add_Func_Dlg.h"


// Draw_Func_Dlg 对话框

IMPLEMENT_DYNAMIC(Draw_Func_Dlg, CDialogEx)

Draw_Func_Dlg::Draw_Func_Dlg(int Xmin, int Xmax, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Draw_Func_Dlg, pParent)
	, m_sEquation(_T(""))
	, m_Xmin(Xmin)
	, m_Xmax(Xmax)
	, m_stepX(1000)
	//, m_penWidth(1)
	//, m_penType(0)
	, m_name(_T(""))
{
	//m_color = RGB(0, 0, 0);
	//m_penType = PS_SOLID;
}

Draw_Func_Dlg::~Draw_Func_Dlg()
{
}

void Draw_Func_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FUNC, m_sEquation);
	DDX_Text(pDX, 1011, m_Xmin);
	DDX_Text(pDX, 1012, m_Xmax);
	DDX_Text(pDX, 1013, m_stepX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
}


BEGIN_MESSAGE_MAP(Draw_Func_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SETFUNC, &Draw_Func_Dlg::OnBnClickedButtonSetfunc)
	/*ON_BN_CLICKED(IDC_BUTTON_COLOR, &Draw_Func_Dlg::OnBnClickedButtonColor)*/
	//ON_CBN_SELCHANGE(IDC_COMBO_LINETYPE, &Draw_Func_Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &Draw_Func_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Draw_Func_Dlg 消息处理程序


void Draw_Func_Dlg::OnBnClickedButtonSetfunc()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	Add_Func_Dlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_sEquation = dlg.m_strEquation;
	}
	UpdateData(false);
}


void Draw_Func_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
