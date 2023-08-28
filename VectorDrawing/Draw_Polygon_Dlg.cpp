// Draw_Polygon_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Draw_Polygon_Dlg.h"
#include "afxdialogex.h"


// Draw_Polygon_Dlg 对话框

IMPLEMENT_DYNAMIC(Draw_Polygon_Dlg, CDialogEx)

Draw_Polygon_Dlg::Draw_Polygon_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Draw_Polygon_Dlg, pParent)
	, x(0)
	, y(0)
	, name(_T(""))
	, m_name(_T(""))
{

}

Draw_Polygon_Dlg::~Draw_Polygon_Dlg()
{
}

void Draw_Polygon_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, name);
	DDX_Text(pDX, IDC_EDIT4, m_name);
}


BEGIN_MESSAGE_MAP(Draw_Polygon_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Draw_Polygon_Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &Draw_Polygon_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Draw_Polygon_Dlg 消息处理程序


BOOL Draw_Polygon_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	num = 0;

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_REPORT | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP;
	m_list.SetExtendedStyle(dwStyle);
	CString head[] = { TEXT("序号"),TEXT("坐标"),TEXT("点的名字") };
	//插入列标题
	m_list.InsertColumn(0, head[0], LVCFMT_LEFT, 50);
	m_list.InsertColumn(1, head[1], LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, head[2], LVCFMT_LEFT, 100);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Draw_Polygon_Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_Points.push_back(CMyPoint(name, Line_Color, x, y));
	MessageBox(TEXT("添加成功，请按顺序添加下一个顶点或按确认结束"), TEXT("提示"));
	CString str;
	str.Format(TEXT("%d"), num + 1);
	m_list.InsertItem(num, str);
	str.Format(TEXT("(%.1f,%.1f)"),x,y);
	m_list.SetItemText(num, 1, str);
	m_list.SetItemText(num, 2, name);
	num++;
}


void Draw_Polygon_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
