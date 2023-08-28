// Point_Symmetry1_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Point_Symmetry1_Dlg.h"
#include "afxdialogex.h"


// Point_Symmetry1_Dlg 对话框

IMPLEMENT_DYNAMIC(Point_Symmetry1_Dlg, CDialogEx)

Point_Symmetry1_Dlg::Point_Symmetry1_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Point_Symmetry1_Dlg, pParent)
	, m_A(0)
	, m_B(0)
	, m_C(0)
	, m_name(_T(""))
{

}

Point_Symmetry1_Dlg::~Point_Symmetry1_Dlg()
{
}

void Point_Symmetry1_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_A);
	DDX_Text(pDX, IDC_EDIT2, m_B);
	DDX_Text(pDX, IDC_EDIT4, m_C);
	DDX_Text(pDX, IDC_EDIT3, m_name);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(Point_Symmetry1_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Point_Symmetry1_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Point_Symmetry1_Dlg 消息处理程序


BOOL Point_Symmetry1_Dlg::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialogEx::OnNotify(wParam, lParam, pResult);
}


BOOL Point_Symmetry1_Dlg::OnInitDialog()
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


void Point_Symmetry1_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	//if (m_B == 0)
	//{
	//	MessageBox(TEXT("B不能为0！"), TEXT("提示"));
	//	return;
	//}

	int nIndex = m_list.GetSelectionMark();

	if (nIndex > -1)
	{
		// 计算对称点的坐标
		double x = points[nIndex]->m_x;
		double y = points[nIndex]->m_y;
		double A = m_A;
		double B = m_B;
		double C = m_C;

		double t = (A*x + B*y + C) / (A*A + B*B);

		double xp = x - 2 * A * t;
		double yp = y - 2 * B * t;

		newpoint = new CMyPoint;
		newpoint->m_name = m_name;
		newpoint->m_type = DATA_POINT;
		newpoint->m_Line_Color = points[nIndex]->m_Line_Color;
		newpoint->m_x = xp;
		newpoint->m_y = yp;
	}
	else
	{
		MessageBox(TEXT("请点击列表选择对称的点！"), TEXT("提示"));
		return;
	}

	CDialogEx::OnOK();
}
