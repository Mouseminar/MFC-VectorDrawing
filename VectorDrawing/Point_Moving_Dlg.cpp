// Point_Moving_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Point_Moving_Dlg.h"
#include "afxdialogex.h"


// Point_Moving_Dlg 对话框

IMPLEMENT_DYNAMIC(Point_Moving_Dlg, CDialogEx)

Point_Moving_Dlg::Point_Moving_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Point_Moving_Dlg, pParent)
	, m_x(0)
	, m_y(0)
	, m_name(_T(""))
{

}

Point_Moving_Dlg::~Point_Moving_Dlg()
{
}

void Point_Moving_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	DDX_Text(pDX, IDC_EDIT3, m_name);
}


BEGIN_MESSAGE_MAP(Point_Moving_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Point_Moving_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Point_Moving_Dlg 消息处理程序


BOOL Point_Moving_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_REPORT | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP;
	m_list.SetExtendedStyle(dwStyle);
	CString head[] = { TEXT("序号"),TEXT("坐标"),TEXT("点的名字") };
	//插入列标题
	m_list.InsertColumn(0, head[0], LVCFMT_LEFT, 50);
	m_list.InsertColumn(1, head[1], LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, head[2], LVCFMT_LEFT, 100);

	CString str;
	
	for (int i = 0; i < points.size(); i++)
	{
		str.Format(TEXT("%d"), i + 1);
		m_list.InsertItem(i, str);
		str.Format(TEXT("(%.1f,%.1f)"), points[i]->m_x, points[i]->m_y);
		m_list.SetItemText(i, 1, str);
		m_list.SetItemText(i, 2, points[i]->m_name);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Point_Moving_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int nIndex = m_list.GetSelectionMark();

	if (nIndex > -1)
	{
		newpoint = new CMyPoint;
		newpoint->m_name = m_name;
		newpoint->m_type = DATA_POINT;
		newpoint->m_Line_Color = points[nIndex]->m_Line_Color;
		newpoint->m_x = points[nIndex]->m_x + m_x;
		newpoint->m_y = points[nIndex]->m_y + m_y;
	}
	else
	{
		MessageBox(TEXT("请点击列表选择平移的点！"), TEXT("提示"));
		return;
	}

	CDialogEx::OnOK();
}
