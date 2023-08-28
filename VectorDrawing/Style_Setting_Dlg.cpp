// Style_Setting_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Style_Setting_Dlg.h"
#include "afxdialogex.h"


// Style_Setting_Dlg 对话框

IMPLEMENT_DYNAMIC(Style_Setting_Dlg, CDialogEx)

Style_Setting_Dlg::Style_Setting_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Style_Setting_Dlg, pParent)
	, m_r(0)
{

}

Style_Setting_Dlg::~Style_Setting_Dlg()
{
}

void Style_Setting_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_r);
}


BEGIN_MESSAGE_MAP(Style_Setting_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Style_Setting_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Style_Setting_Dlg 消息处理程序


void Style_Setting_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
