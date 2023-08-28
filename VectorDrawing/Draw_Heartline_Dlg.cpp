// Draw_Heartline_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Draw_Heartline_Dlg.h"
#include "afxdialogex.h"


// Draw_Heartline_Dlg 对话框

IMPLEMENT_DYNAMIC(Draw_Heartline_Dlg, CDialogEx)

Draw_Heartline_Dlg::Draw_Heartline_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Draw_Heartline_Dlg, pParent)
	, m_r(0)
{

}

Draw_Heartline_Dlg::~Draw_Heartline_Dlg()
{
}

void Draw_Heartline_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_r);
}


BEGIN_MESSAGE_MAP(Draw_Heartline_Dlg, CDialogEx)
END_MESSAGE_MAP()


// Draw_Heartline_Dlg 消息处理程序
