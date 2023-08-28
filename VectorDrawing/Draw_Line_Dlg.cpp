// Draw_Line_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Draw_Line_Dlg.h"
#include "afxdialogex.h"


// Draw_Line_Dlg 对话框

IMPLEMENT_DYNAMIC(Draw_Line_Dlg, CDialogEx)

Draw_Line_Dlg::Draw_Line_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Draw_Line_Dlg, pParent)
	, m_x1(0)
	, m_y1(0)
	, m_name1(_T(""))
	, m_name2(_T(""))
	, m_y2(0)
	, m_x2(0)
	, m_name(_T(""))
{

}

Draw_Line_Dlg::~Draw_Line_Dlg()
{
}

void Draw_Line_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_x1);
	DDX_Text(pDX, IDC_EDIT2, m_y1);
	DDX_Text(pDX, IDC_EDIT3, m_name1);
	DDX_Text(pDX, IDC_EDIT6, m_name2);
	DDX_Text(pDX, IDC_EDIT5, m_y2);
	DDX_Text(pDX, IDC_EDIT4, m_x2);
	DDX_Text(pDX, IDC_EDIT7, m_name);
}


BEGIN_MESSAGE_MAP(Draw_Line_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Draw_Line_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Draw_Line_Dlg 消息处理程序


void Draw_Line_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
