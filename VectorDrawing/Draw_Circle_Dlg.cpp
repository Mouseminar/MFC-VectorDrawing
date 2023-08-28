// Draw_Circle_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Draw_Circle_Dlg.h"
#include "afxdialogex.h"


// Draw_Circle_Dlg 对话框

IMPLEMENT_DYNAMIC(Draw_Circle_Dlg, CDialogEx)

Draw_Circle_Dlg::Draw_Circle_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Draw_Circle_Dlg, pParent)
	, m_x(0)
	, m_y(0)
	, m_r(0)
	, m_name(_T(""))
{

}

Draw_Circle_Dlg::~Draw_Circle_Dlg()
{
}

void Draw_Circle_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	DDX_Text(pDX, IDC_EDIT3, m_r);
	DDX_Text(pDX, IDC_EDIT4, m_name);
}


BEGIN_MESSAGE_MAP(Draw_Circle_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Draw_Circle_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Draw_Circle_Dlg 消息处理程序


void Draw_Circle_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
