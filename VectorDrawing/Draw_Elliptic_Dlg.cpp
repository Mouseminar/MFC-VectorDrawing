// Draw_Elliptic_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Draw_Elliptic_Dlg.h"
#include "afxdialogex.h"


// Draw_Elliptic_Dlg 对话框

IMPLEMENT_DYNAMIC(Draw_Elliptic_Dlg, CDialogEx)

Draw_Elliptic_Dlg::Draw_Elliptic_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Draw_Elliptic_Dlg, pParent)
	, m_a(0)
	, m_b(0)
{

}

Draw_Elliptic_Dlg::~Draw_Elliptic_Dlg()
{
}

void Draw_Elliptic_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Text(pDX, IDC_EDIT1, m_a);
	DDX_Text(pDX, IDC_EDIT8, m_b);
}


BEGIN_MESSAGE_MAP(Draw_Elliptic_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Draw_Elliptic_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Draw_Elliptic_Dlg 消息处理程序


void Draw_Elliptic_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
