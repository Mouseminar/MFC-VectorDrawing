// Board_Setting_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Board_Setting_Dlg.h"
#include "afxdialogex.h"


// Board_Setting_Dlg 对话框

IMPLEMENT_DYNAMIC(Board_Setting_Dlg, CDialogEx)

Board_Setting_Dlg::Board_Setting_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Board_Setting_Dlg, pParent)
	, m_Xmin(0)
	, m_Ymin(0)
	, m_Xmax(0)
	, m_Ymax(0)
{

}

Board_Setting_Dlg::~Board_Setting_Dlg()
{
}

void Board_Setting_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Xmin);
	DDX_Text(pDX, IDC_EDIT2, m_Ymin);
	DDX_Text(pDX, IDC_EDIT3, m_Xmax);
	DDX_Text(pDX, IDC_EDIT4, m_Ymax);
}


BEGIN_MESSAGE_MAP(Board_Setting_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Board_Setting_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Board_Setting_Dlg 消息处理程序


void Board_Setting_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_Xmax <= m_Xmin || m_Ymax <= m_Ymin)
	{
		MessageBox(TEXT("您的设置有误，请检查！"));
		return;
	}
	CDialogEx::OnOK();
}
