// Draw_Hyperbola_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Draw_Hyperbola_Dlg.h"
#include "afxdialogex.h"


// Draw_Hyperbola_Dlg 对话框

IMPLEMENT_DYNAMIC(Draw_Hyperbola_Dlg, CDialogEx)

Draw_Hyperbola_Dlg::Draw_Hyperbola_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Draw_Hyperbola_Dlg, pParent)
	, m_a(0)
	, m_b(0)
{

}

Draw_Hyperbola_Dlg::~Draw_Hyperbola_Dlg()
{
}

void Draw_Hyperbola_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_a);
	DDX_Text(pDX, IDC_EDIT8, m_b);
}


BEGIN_MESSAGE_MAP(Draw_Hyperbola_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Draw_Hyperbola_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Draw_Hyperbola_Dlg 消息处理程序


void Draw_Hyperbola_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
