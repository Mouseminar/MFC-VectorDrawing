// Intersection_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Intersection_Dlg.h"
#include "afxdialogex.h"


// Intersection_Dlg 对话框

IMPLEMENT_DYNAMIC(Intersection_Dlg, CDialogEx)

Intersection_Dlg::Intersection_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Intersection_Dlg, pParent)
{

}

Intersection_Dlg::~Intersection_Dlg()
{
}

void Intersection_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(Intersection_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Intersection_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Intersection_Dlg 消息处理程序


void Intersection_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	int nIndex = m_list.GetSelectionMark();

	if (nIndex > -1)
	{
		if(shapes[nIndex]->m_type == DATA_LINE)
			GetIntersectionPoint(line, *(CMyLine*)shapes[nIndex]);
		else if (shapes[nIndex]->m_type == DATA_POLYGON)
		{
			CMyPolygon p = *(CMyPolygon*)shapes[nIndex];
			for (int i = 0; i < p.m_Points.size() - 1; i++)
			{
				CMyLine L1 = CMyLine(TEXT(""), RGB(0, 0, 0), p.m_Points[i], p.m_Points[i + 1], 0, 0);
				GetIntersectionPoint(line, L1);
			}
			GetIntersectionPoint(line, CMyLine(TEXT(""), RGB(0, 0, 0), p.m_Points[0], p.m_Points[p.m_Points.size() - 1], 0, 0));
		}
		else
		{
			LineCircleIntersection(*(CMyCircle*)shapes[nIndex], line);
		}
	}
	else
	{
		MessageBox(TEXT("点击列表选择计算的数据！"), TEXT("提示"));
		return;
	}

	CDialogEx::OnOK();
}


BOOL Intersection_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_REPORT | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP;
	m_list.SetExtendedStyle(dwStyle);
	CString head[] = { TEXT("序号"),TEXT("类型"),TEXT("名字") };
	//插入列标题
	m_list.InsertColumn(0, head[0], LVCFMT_LEFT, 120);
	m_list.InsertColumn(1, head[1], LVCFMT_LEFT, 120);
	m_list.InsertColumn(2, head[2], LVCFMT_LEFT, 120);

	CString str;

	for (int i = 0; i < shapes.size(); i++)
	{
		str.Format(TEXT("%d"), i + 1);
		m_list.InsertItem(i, str);
		if (shapes[i]->m_type == DATA_LINE) str = TEXT("线段");
		if (shapes[i]->m_type == DATA_POLYGON) str = TEXT("多边形");
		else str = TEXT("圆");
		m_list.SetItemText(i, 1, str);
		m_list.SetItemText(i, 2, shapes[i]->m_name);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


//在这个函数中，我们首先计算两条线段的方向向量，然后使用向量的叉乘判断它们是否相交。
//如果两个叉乘的乘积都小于零，表示线段相交。然后，我们计算交点的坐标
void Intersection_Dlg::GetIntersectionPoint(CMyLine L1, CMyLine L2)
{
	double x1 = L1.m_p1.m_x;
	double y1 = L1.m_p1.m_y;
	double x2 = L1.m_p2.m_x;
	double y2 = L1.m_p2.m_y;
	double x3 = L2.m_p1.m_x;
	double y3 = L2.m_p1.m_y;
	double x4 = L2.m_p2.m_x;
	double y4 = L2.m_p2.m_y;

	// 计算线段1的方向向量
	double dx1 = x2 - x1;
	double dy1 = y2 - y1;

	// 计算线段2的方向向量
	double dx2 = x4 - x3;
	double dy2 = y4 - y3;

	// 计算向量的叉乘
	double crossProduct1 = dx1 * (y3 - y1) - dy1 * (x3 - x1);
	double crossProduct2 = dx1 * (y4 - y1) - dy1 * (x4 - x1);
	double crossProduct3 = dx2 * (y1 - y3) - dy2 * (x1 - x3);
	double crossProduct4 = dx2 * (y2 - y3) - dy2 * (x2 - x3);

	// 检查是否相交
	if (crossProduct1 * crossProduct2 < 0 && crossProduct3 * crossProduct4 < 0)
	{
		// 计算交点的坐标
		double t = crossProduct3 / (crossProduct3 - crossProduct4);
		double intersectionX = x1 + dx1 * t;
		double intersectionY = y1 + dy1 * t;

		newpoints.push_back(make_pair(intersectionX, intersectionY));

		return;
	}

	return;
}

//在这个函数中，我们首先计算线段的方向向量，并将其归一化。
//然后，我们计算线段起点到圆心的投影长度，并检查投影点是否在线段上。
//如果投影点不在线段上，表示圆心在线段的延长线上，因此没有交点。
//如果投影点在线段上，我们计算投影点到圆心的距离。如果距离小于等于圆的半径，表示相交，计算交点的坐标。
void Intersection_Dlg::LineCircleIntersection(CMyCircle O, CMyLine L)
{
	double x1 = L.m_p1.m_x;
	double y1 = L.m_p1.m_y;
	double x2 = L.m_p2.m_x;
	double y2 = L.m_p2.m_y;

	double x0 = O.m_O.m_x;
	double y0 = O.m_O.m_y;
	double R = O.m_R;

	// 计算线段的方向向量
	double dx = x2 - x1;
	double dy = y2 - y1;

	// 计算线段的长度
	double segmentLength = sqrt(dx * dx + dy * dy);

	// 将线段的方向向量归一化
	dx /= segmentLength;
	dy /= segmentLength;

	// 计算线段起点到圆心的向量
	double vx = x0 - x1;
	double vy = y0 - y1;

	// 计算线段起点到圆心的投影长度
	double projection = vx * dx + vy * dy;

	// 如果投影长度小于零或大于线段长度，表示圆心在线段的延长线上，无交点
	if (projection < 0 || projection > segmentLength)
	{
		return;
	}

	// 计算投影点的坐标
	double projectionX = x1 + projection * dx;
	double projectionY = y1 + projection * dy;

	// 计算投影点到圆心的距离
	double distance = sqrt((projectionX - x0) * (projectionX - x0) + (projectionY - y0) * (projectionY - y0));

	// 如果距离小于等于圆的半径，表示相交
	if (distance <= R)
	{
		// 计算交点到线段起点的距离
		double d = sqrt(R * R - distance * distance);

		// 计算交点的坐标
		double intersectionX1 = projectionX + d * dx;
		double intersectionY1 = projectionY + d * dy;
		newpoints.push_back(make_pair(intersectionX1, intersectionY1));

		// 如果圆心不在线段上，计算第二个交点
		if (distance > 0)
		{
			double intersectionX2 = projectionX - d * dx;
			double intersectionY2 = projectionY - d * dy;
			newpoints.push_back(make_pair(intersectionX2, intersectionY2));
		}

		return;
	}

	return;
}
