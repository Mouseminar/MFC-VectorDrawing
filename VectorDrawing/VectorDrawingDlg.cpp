
// VectorDrawingDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "VectorDrawing.h"
#include "VectorDrawingDlg.h"
#include "afxdialogex.h"

#include "Pen_Setting_Dlg.h"
#include "Outline_Setting_Dlg.h"
#include "Board_Setting_Dlg.h"
#include "Style_Setting_Dlg.h"
#include "Draw_Point_Dlg.h"
#include "Draw_Line_Dlg.h"
#include "Draw_Circle_Dlg.h"
#include "Draw_Polygon_Dlg.h"
#include "Draw_Func_Dlg.h"
#include "Point_Moving_Dlg.h"
#include "Point_Symmetry1_Dlg.h"
#include "Point_Symmetry2_Dlg.h"
#include "Intersection_Dlg.h"
#include "Draw_Elliptic_Dlg.h"
#include "Draw_Hyperbola_Dlg.h"
#include "Draw_Heartline_Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CVectorDrawingDlg 对话框



CVectorDrawingDlg::CVectorDrawingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VECTORDRAWING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	nTop = 20;  //函数图像不会占据整个视图区
	nBottom = 1020;
	nLeft = 50;
	nRight = 1550;

	m_Xmin = -15;
	m_Xmax = 15;
	m_Ymin = -10;
	m_Ymax = 10;

	Line_Color = RGB(255, 0, 0);
	Line_Type = 0;
	Line_Width = 5;
	isfill = true;
	Fill_Color = RGB(255, 0, 0);
	Point_Style = 0;
	OwnerDrawing = false;
	OwnerDrawing2 = false;

	isclear = false;
}

void CVectorDrawingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_BUTTON1, m_button_del);
	DDX_Control(pDX, IDC_BUTTON2, m_button_jd);
	DDX_Control(pDX, IDC_STATIC1, m_s1);
}

BEGIN_MESSAGE_MAP(CVectorDrawingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_PenSetting, &CVectorDrawingDlg::OnPensetting)
	ON_COMMAND(ID_32782, &CVectorDrawingDlg::OnDrawPoint)
	ON_COMMAND(ID_32783, &CVectorDrawingDlg::OnDrawLine)
	ON_COMMAND(ID_32779, &CVectorDrawingDlg::OnDrawCircle)
	ON_COMMAND(ID_32775, &CVectorDrawingDlg::OnShapesetting)
	ON_COMMAND(ID_32781, &CVectorDrawingDlg::OnDrawPolygon)
	ON_COMMAND(ID_32788, &CVectorDrawingDlg::OnOwnerDraw)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32789, &CVectorDrawingDlg::OnEndOwnerDrawing)
	ON_COMMAND(ID_32791, &CVectorDrawingDlg::OnDrawFunc)
	ON_COMMAND(ID_32790, &CVectorDrawingDlg::OnClearBoard)
	ON_COMMAND(ID_32792, &CVectorDrawingDlg::OnBoardSetting)
	ON_COMMAND(ID_32793, &CVectorDrawingDlg::OnPointMoving)
	ON_COMMAND(ID_32795, &CVectorDrawingDlg::OnPointSymmetry1)
	ON_COMMAND(ID_32796, &CVectorDrawingDlg::OnPointSymmetry2)
	ON_COMMAND(ID_32797, &CVectorDrawingDlg::OnPointStyleSetting)
	ON_BN_CLICKED(IDC_BUTTON1, &CVectorDrawingDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CVectorDrawingDlg::OnBnClickedButton2)
	ON_COMMAND(ID_32786, &CVectorDrawingDlg::OnSavePainting)
	ON_COMMAND(ID_32798, &CVectorDrawingDlg::OnDrawElliptic)
	ON_WM_TIMER()
	ON_COMMAND(ID_32799, &CVectorDrawingDlg::OnDrawHyperbola)
	ON_COMMAND(ID_32800, &CVectorDrawingDlg::OnDrawHeartline)
END_MESSAGE_MAP()


// CVectorDrawingDlg 消息处理程序

BOOL CVectorDrawingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// 将对话框的矩形区域设置为所需的大小
	CRect m_DialogRect; // 用于存储对话框的矩形区域
	// 获取对话框的当前矩形区域
	GetWindowRect(&m_DialogRect);
	m_DialogRect.right = m_DialogRect.left + 2000;
	m_DialogRect.bottom = m_DialogRect.top + 1150;
	MoveWindow(&m_DialogRect);

	// 设置List Control控件的大小
	CRect rect;
	//m_list.GetClientRect(&rect);
	rect.right = 350;
	rect.bottom = 800;
	m_list.MoveWindow(rect);
	// 调整List Control控件在对话框中的位置
	CRect dlgRect;
	GetClientRect(&dlgRect);
	m_list.SetWindowPos(nullptr, dlgRect.right - 360, dlgRect.top + 20, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	m_s1.SetWindowPos(nullptr, dlgRect.right - 360, dlgRect.top + 850, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_button_del.SetWindowPos(nullptr, dlgRect.right - 360, dlgRect.top + 900, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_button_jd.SetWindowPos(nullptr, dlgRect.right - 160, dlgRect.top + 900, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_REPORT | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP;
	m_list.SetExtendedStyle(dwStyle);
	CString head[] = { TEXT("序号"),TEXT("类型"),TEXT("名称") };
	//插入列标题
	m_list.InsertColumn(0, head[0], LVCFMT_LEFT, 80);
	m_list.InsertColumn(1, head[1], LVCFMT_LEFT, 120);
	m_list.InsertColumn(2, head[2], LVCFMT_LEFT, 120);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CVectorDrawingDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CVectorDrawingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		InitBoard(dc);
		if(!isclear) Draw_All(dc);
		isclear = false;
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CVectorDrawingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

double CVectorDrawingDlg::LPxtoFPx(int x)
{
	return m_Xmin + (1.0 * x - nLeft) * (m_Xmax - m_Xmin) / (1.0 * nRight - nLeft);
}

int CVectorDrawingDlg::FPxtoLPx(double x)
{
	return nLeft + (int)round((x - m_Xmin) * (1.0 * nRight - nLeft) / (m_Xmax - m_Xmin));
}

double CVectorDrawingDlg::LPytoFPy(int y)
{
	return m_Ymin + (1.0 * nBottom - y) * (m_Ymax - m_Ymin) / (1.0 * nBottom - nTop);
}

int CVectorDrawingDlg::FPytoLPy(double y)
{
	return nBottom - (int)round((y - m_Ymin) * (1.0 * nBottom - nTop) / (m_Ymax - m_Ymin));
}

void CVectorDrawingDlg::InitBoard(CPaintDC& dc)
{
	dc.MoveTo(nLeft, nTop);
	dc.LineTo(nLeft, nBottom);
	dc.LineTo(nRight, nBottom);
	dc.LineTo(nRight, nTop);
	dc.LineTo(nLeft, nTop);

	//画x坐标信息
	int nX, nY;
	bool BIGX = abs(m_Xmin) > 100 || abs(m_Xmax) > 100;//x坐标值比较大时，标注更稀
	for (nX = nLeft; nX < nRight; nX += (BIGX ? 100 : 50)) { //每隔100/50像素一个标注
		CRect textRect(nX - (BIGX ? 50 : 25), nBottom + 1, nX + (BIGX ? 50 : 25), nBottom + 20);//显示区域
		CString xInfo;
		xInfo.Format(_T("%.2f"), LPxtoFPx(nX));
		dc.DrawText(xInfo, &textRect, DT_SINGLELINE | DT_CENTER);
		//单行,上下左右居中显示
	}
	if (nX - nRight <= (BIGX ? 50 : 25)) {//最后一个x坐标，与前一个标注距离太近则不显示
		CRect textRect(nRight, nBottom + 1, nRight + 50, nBottom + 20);
		CString xInfo;
		xInfo.Format(_T("%.2f"), m_Xmax);
		dc.DrawText(xInfo, &textRect, DT_SINGLELINE | DT_LEFT | DT_TOP);
	}

	//y坐标
	for (nY = nBottom - 50; nY > nTop; nY -= 50) {
		CRect textRect(nLeft - 200, nY - 10, nLeft - 3, nY + 10);
		CString yInfo;
		yInfo.Format(_T("%.2f"), LPytoFPy(nY));
		dc.DrawText(yInfo, &textRect, DT_SINGLELINE | DT_RIGHT);
	}
	if (nTop - nY <= 25) {
		CRect textRect(nLeft - 200, nTop - 10, nLeft - 3, nTop + 10);
		CString yInfo;
		yInfo.Format(_T("%.2f"), m_Ymax);
		dc.DrawText(yInfo, &textRect, DT_SINGLELINE | DT_BOTTOM | DT_RIGHT);
	}

	//  显示网格
	CPen pen(PS_SOLID, 1, RGB(150, 150, 150));           //创建笔，虚线，并调整坐标颜色灰色
	CPen* pOldPen = (CPen*)dc.SelectObject(&pen);
	for (nX = nLeft; nX < nRight; nX += 50) {
		dc.MoveTo(nX, nTop);
		dc.LineTo(nX, nBottom);
	}
	for (nY = nBottom; nY > nTop; nY -= 50) {
		dc.MoveTo(nLeft, nY);
		dc.LineTo(nRight, nY);
	}
	dc.SelectObject(pOldPen);

	// 显示坐标轴
	CPen pen2(PS_SOLID, 3, RGB(0, 0, 0));
	CPen* pOldPen2 = (CPen*)dc.SelectObject(&pen2);
	int oX = FPxtoLPx(0);
	int oY = FPytoLPy(0);
	bool showY = oX >= nLeft && oX <= nRight;
	bool showX = oY >= nTop && oY <= nBottom;//判断x,y轴是否在范围内
	if (showX) {
		dc.MoveTo(nLeft - 10, oY);
		dc.LineTo(nRight + 10, oY);
	}
	if (showY) {
		dc.MoveTo(oX, nBottom + 10);
		dc.LineTo(oX, nTop - 10);
	}
	if (showX && showY) {
		dc.TextOutW(oX + 1, oY + 1, _T("0"));
	}
	if (showX) {
		dc.MoveTo(nRight + 10, oY);
		dc.LineTo(nRight + 5, oY + 5);
		dc.MoveTo(nRight + 10, oY);
		dc.LineTo(nRight + 5, oY - 5);
		dc.TextOutW(nRight + 10, oY, _T("X轴"));
	}
	if (showY) {
		dc.MoveTo(oX, nTop - 10);
		dc.LineTo(oX - 5, nTop - 5);
		dc.MoveTo(oX, nTop - 10);
		dc.LineTo(oX + 5, nTop - 5);
		dc.TextOutW(oX + 5, nTop - 10, _T("Y轴"));
	}
	dc.SelectObject(pOldPen2);
}



void CVectorDrawingDlg::Draw_All(CPaintDC& dc)
{
	for (int i = 0; i < data.size(); i++)
	{
		switch (data[i]->m_type)
		{
			case DATA_POINT:	//点
			{
				CMyPoint* mypoint = (CMyPoint*)data[i];
				Draw_Point(mypoint, dc);
				break;
			}
			case DATA_LINE:		//线
			{
				CMyLine* myline = (CMyLine*)data[i];
				Draw_Line(myline, dc);
				break;
			}
			case DATA_CIRCLE:	//圆
			{
				CMyCircle* mycircle = (CMyCircle*)data[i];
				Draw_Circle(mycircle, dc);
				break;
			}
			case DATA_POLYGON:	//多边形
			{
				CMyPolygon* mypolygon = (CMyPolygon*)data[i];
				Draw_Polygon(mypolygon, dc);
				break;
			}
			case DATA_FUNC:	//函数
			{
				CMyFunc* myfunc = (CMyFunc*)data[i];
				Draw_Func(myfunc, dc);
				break;
			}
			default:
				break;
		}

	}
}

void CVectorDrawingDlg::Draw_Point(CMyPoint* mypoint, CPaintDC& dc)
{
	CBrush* pNewBrush;
	CBrush* pOldBrush;
	CPen* pNewPen;
	CPen* pOldPen;
	//绘制圆
	double x = mypoint->m_x;
	double y = mypoint->m_y;
	if (Point_Style == 0)	//实心圆
	{
		pNewBrush = new CBrush;
		pNewBrush->CreateSolidBrush(mypoint->m_Line_Color);
		//选择新画刷 
		pOldBrush = dc.SelectObject(pNewBrush);
		dc.Ellipse(FPxtoLPx(x - 0.2), FPytoLPy(y - 0.2), FPxtoLPx(x + 0.2), FPytoLPy(y + 0.2));
		//恢复原有画刷 
		dc.SelectObject(pOldBrush);
		delete pNewBrush;
	}
	else if (Point_Style == 1)
	{
		pNewPen = new CPen;
		pNewPen->CreatePen(0, 2, mypoint->m_Line_Color);
		pOldPen = dc.SelectObject(pNewPen); //选择新笔，并保存旧笔 
		//画圆 
		dc.SelectStockObject(NULL_BRUSH);
		dc.Ellipse(FPxtoLPx(x - 0.2), FPytoLPy(y - 0.2), FPxtoLPx(x + 0.2), FPytoLPy(y + 0.2));
		//恢复原有的笔 
		dc.SelectObject(pOldPen);
		delete pNewPen;
	}
	else if (Point_Style == 2)
	{
		pNewBrush = new CBrush;
		pNewBrush->CreateSolidBrush(mypoint->m_Line_Color);
		//选择新画刷 
		pOldBrush = dc.SelectObject(pNewBrush);
		dc.Rectangle(FPxtoLPx(x - 0.2), FPytoLPy(y - 0.2), FPxtoLPx(x + 0.2), FPytoLPy(y + 0.2));
		//恢复原有画刷 
		dc.SelectObject(pOldBrush);
		delete pNewBrush;
	}
	else if (Point_Style == 3)
	{
		pNewBrush = new CBrush;
		pNewBrush->CreateSolidBrush(mypoint->m_Line_Color);
		//选择新画刷 
		pOldBrush = dc.SelectObject(pNewBrush);
		//绘制多边形
		CPoint p[3];
		p[0] = CPoint(FPxtoLPx(x), FPytoLPy(y + 0.3));
		p[1] = CPoint(FPxtoLPx(x - 0.2), FPytoLPy(y - 0.2));
		p[2] = CPoint(FPxtoLPx(x + 0.2), FPytoLPy(y - 0.2));
		dc.Polygon(p, 3);//p为点集
		//恢复原有画刷 
		dc.SelectObject(pOldBrush);
		delete pNewBrush;
	}
	else if (Point_Style == 4)
	{
		pNewBrush = new CBrush;
		pNewBrush->CreateSolidBrush(mypoint->m_Line_Color);
		//选择新画刷 
		pOldBrush = dc.SelectObject(pNewBrush);
		dc.Rectangle(FPxtoLPx(x - 0.1), FPytoLPy(y + 0.3), FPxtoLPx(x + 0.1), FPytoLPy(y - 0.3));
		dc.Rectangle(FPxtoLPx(x - 0.3), FPytoLPy(y + 0.1), FPxtoLPx(x + 0.3), FPytoLPy(y - 0.1));
		//恢复原有画刷 
		dc.SelectObject(pOldBrush);
		delete pNewBrush;
	}

	CFont new_font;
	//创建字体宋体格式  100为字高
	VERIFY(new_font.CreatePointFont(150, _T("宋体"), &dc));
	//选择该字体进入PDC
	CFont* default_font = dc.SelectObject(&new_font);
	//设置字体颜色
	dc.SetTextColor(mypoint->m_Line_Color);
	dc.TextOut(FPxtoLPx(x - 0.1), FPytoLPy(y + 0.9), mypoint->m_name);
}

void CVectorDrawingDlg::Draw_Line(CMyLine* myline, CPaintDC& dc)
{
	Draw_Point(&myline->m_p1, dc);
	Draw_Point(&myline->m_p2, dc);
	if (myline->m_Line_Type == 0) //实线
	{
		CPen* pNewPen;
		CPen* pOldPen;
		pNewPen = new CPen;
		pNewPen->CreatePen(myline->m_Line_Type, myline->m_Line_Width, myline->m_Line_Color);
		pOldPen = dc.SelectObject(pNewPen); //选择新笔，并保存旧笔 
		//画直线 
		dc.MoveTo(FPxtoLPx(myline->m_p1.m_x), FPytoLPy(myline->m_p1.m_y));
		dc.LineTo(FPxtoLPx(myline->m_p2.m_x), FPytoLPy(myline->m_p2.m_y));
		//恢复原有的笔 
		dc.SelectObject(pOldPen);
		delete pNewPen;
	}
	else //虚线, 点线
	{
		LOGBRUSH logBrush;
		logBrush.lbStyle = BS_SOLID;
		logBrush.lbColor = myline->m_Line_Color;
		CPen pen2(myline->m_Line_Type | PS_GEOMETRIC | PS_ENDCAP_ROUND, myline->m_Line_Width, &logBrush);
		CPen* pOldPen = dc.SelectObject(&pen2);
		dc.MoveTo(FPxtoLPx(myline->m_p1.m_x), FPytoLPy(myline->m_p1.m_y));
		dc.LineTo(FPxtoLPx(myline->m_p2.m_x), FPytoLPy(myline->m_p2.m_y));
		pen2.DeleteObject();
		dc.SelectObject(pOldPen);
	}
	CFont new_font;
	//创建字体宋体格式  100为字高
	VERIFY(new_font.CreatePointFont(150, _T("宋体"), &dc));
	//选择该字体进入PDC
	CFont* default_font = dc.SelectObject(&new_font);
	//设置字体颜色
	dc.SetTextColor(myline->m_Line_Color);
	dc.TextOut(FPxtoLPx((myline->m_p1.m_x + myline->m_p2.m_x) / 2),
		FPytoLPy((myline->m_p1.m_y + myline->m_p2.m_y) / 2), myline->m_name);
}

void CVectorDrawingDlg::Draw_Circle(CMyCircle* mycirlce, CPaintDC& dc)
{
	CRect rect(CPoint(FPxtoLPx(mycirlce->m_O.m_x - mycirlce->m_R), FPytoLPy(mycirlce->m_O.m_y - mycirlce->m_R)), 
		CPoint(FPxtoLPx(mycirlce->m_O.m_x + mycirlce->m_R), FPytoLPy(mycirlce->m_O.m_y + mycirlce->m_R)));
	if (mycirlce->m_Line_Type == 0) //实线
	{
		CPen* pNewPen;
		CPen* pOldPen;
		pNewPen = new CPen;
		pNewPen->CreatePen(mycirlce->m_Line_Type, mycirlce->m_Line_Width, mycirlce->m_Line_Color);
		pOldPen = dc.SelectObject(pNewPen); //选择新笔，并保存旧笔 
		//画圆 
		dc.SelectStockObject(NULL_BRUSH);
		dc.Ellipse(rect);
		//恢复原有的笔 
		dc.SelectObject(pOldPen);
		delete pNewPen;
	}
	else //虚线, 点线
	{
		LOGBRUSH logBrush;
		logBrush.lbStyle = BS_SOLID;
		logBrush.lbColor = mycirlce->m_Line_Color;
		CPen pen2(mycirlce->m_Line_Type | PS_GEOMETRIC | PS_ENDCAP_ROUND, mycirlce->m_Line_Width, &logBrush);
		CPen* pOldPen = dc.SelectObject(&pen2);
		//画圆 
		dc.SelectStockObject(NULL_BRUSH);
		dc.Ellipse(rect);
		pen2.DeleteObject();
		dc.SelectObject(pOldPen);
	}

	if (mycirlce->m_isfill)
	{
		CBrush* pNewBrush;
		CBrush* pOldBrush;
		pNewBrush = new CBrush;
		pNewBrush->CreateSolidBrush(mycirlce->m_Fill_Color);
		//选择新画刷 
		pOldBrush = dc.SelectObject(pNewBrush);
		//绘制圆 
		dc.Ellipse(rect);
		//恢复原有画刷 
		dc.SelectObject(pOldBrush);
		delete pNewBrush;
	}
	CFont new_font;
	//创建字体宋体格式  100为字高
	VERIFY(new_font.CreatePointFont(150, _T("宋体"), &dc));
	//选择该字体进入PDC
	CFont* default_font = dc.SelectObject(&new_font);
	//设置字体颜色
	dc.SetTextColor(mycirlce->m_Line_Color);
	dc.TextOut(FPxtoLPx(mycirlce->m_O.m_x), FPytoLPy(mycirlce->m_O.m_y), mycirlce->m_name);
}

void CVectorDrawingDlg::Draw_Polygon(CMyPolygon* mypolygon, CPaintDC& dc)
{
	for (int i = 0; i < mypolygon->m_Points.size() - 1; i++)
	{
		Draw_Line(&CMyLine(TEXT(""), mypolygon->m_Line_Color, mypolygon->m_Points[i],
			mypolygon->m_Points[i + 1], mypolygon->m_Line_Type, mypolygon->m_Line_Width), dc);
	}
	if(mypolygon->m_Points.size() > 2)
		Draw_Line(&CMyLine(TEXT(""), mypolygon->m_Line_Color, mypolygon->m_Points[0],
		mypolygon->m_Points[mypolygon->m_Points.size() - 1], mypolygon->m_Line_Type, mypolygon->m_Line_Width), dc);
	if (mypolygon->m_isfill)
	{
		CBrush* pNewBrush;
		CBrush* pOldBrush;
		pNewBrush = new CBrush;
		pNewBrush->CreateSolidBrush(mypolygon->m_Fill_Color);
		//选择新画刷 
		pOldBrush = dc.SelectObject(pNewBrush);
		//绘制多边形
		CPoint p[128];
		for (int i = 0; i < mypolygon->m_Points.size(); i++)
		{
			p[i] = CPoint(FPxtoLPx(mypolygon->m_Points[i].m_x), FPytoLPy(mypolygon->m_Points[i].m_y));
		}
		dc.Polygon(p, mypolygon->m_Points.size());//p为点集
		//恢复原有画刷 
		dc.SelectObject(pOldBrush);
		delete pNewBrush;
	}
	CFont new_font;
	//创建字体宋体格式  100为字高
	VERIFY(new_font.CreatePointFont(150, _T("宋体"), &dc));
	//选择该字体进入PDC
	CFont* default_font = dc.SelectObject(&new_font);
	//设置字体颜色
	dc.SetTextColor(mypolygon->m_Line_Color);
	dc.TextOut(FPxtoLPx((mypolygon->m_Points[0].m_x + mypolygon->m_Points[1].m_x) / 2),
		FPytoLPy((mypolygon->m_Points[0].m_y + mypolygon->m_Points[1].m_y) / 2), 
		mypolygon->m_name);
}

void CVectorDrawingDlg::Draw_Func(CMyFunc* myfunc, CPaintDC& dc)
{
	bool shouldMov = true;//一段曲线第一个点MoveTo，其他都是LineTo
	CPen pen(Line_Type, myfunc->m_Line_Width, myfunc->m_Line_Color);
	CPen* pOldPen = (CPen*)dc.SelectObject(&pen);

	myfunc->m_minX = m_Xmin;
	myfunc->m_maxX = m_Xmax;
	myfunc->CalcList();

	for (auto dot : myfunc->vetPoint) {
		if (dot.first < m_Xmin || dot.first > m_Xmax || dot.second < m_Ymin || dot.second > m_Ymax || dot.second != dot.second) {
			shouldMov = true;
			continue;
		}
		if (shouldMov) {
			dc.MoveTo(FPxtoLPx(dot.first), FPytoLPy(dot.second));
			shouldMov = false;
		}
		else
			dc.LineTo(FPxtoLPx(dot.first), FPytoLPy(dot.second));
	}
}

void CVectorDrawingDlg::UpdateList()
{
	m_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < data.size(); i++)
	{
		str.Format(TEXT("%d"), i+1);
		m_list.InsertItem(i, str);
		if (data[i]->m_type == DATA_POINT) str = TEXT("点");
		else if (data[i]->m_type == DATA_LINE) str = TEXT("线段");
		else if (data[i]->m_type == DATA_CIRCLE) str = TEXT("圆");
		else if (data[i]->m_type == DATA_POLYGON) str = TEXT("多边形");
		else if (data[i]->m_type == DATA_FUNC) str = TEXT("函数");
		m_list.SetItemText(i, 1, str);
		if (data[i]->m_name == TEXT("")) m_list.SetItemText(i, 2, TEXT("未设置"));
		else m_list.SetItemText(i, 2, data[i]->m_name);
	}
}

void CVectorDrawingDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString msg;
	msg.Format(_T("(%.4f,%.4f)"), LPxtoFPx(point.x), LPytoFPy(point.y));
	MessageBox(msg, TEXT("点的坐标"));

	CDialogEx::OnLButtonDblClk(nFlags, point);
}


void CVectorDrawingDlg::OnPensetting()
{
	// TODO: 在此添加命令处理程序代码
	Pen_Setting_Dlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		Line_Width = dlg.m_width;
		Line_Color = dlg.Line_Color;
		Line_Type = dlg.Line_Type;
	}
}


void CVectorDrawingDlg::OnDrawPoint()
{
	// TODO: 在此添加命令处理程序代码
	Draw_Point_Dlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		// 创建一个CMyPoint对象并初始化
		CMyPoint* myPoint = new CMyPoint(dlg.m_name, Line_Color, dlg.m_x, dlg.m_y);
		// 将CMyPoint指针添加到vector中
		data.push_back(myPoint);
		UpdateList();
		Invalidate();
	}
}


void CVectorDrawingDlg::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	Draw_Line_Dlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		// 创建一个CMyPoint对象并初始化
		CMyLine* myLine = new CMyLine(dlg.m_name, Line_Color, CMyPoint(dlg.m_name1, Line_Color, dlg.m_x1, dlg.m_y1),
			CMyPoint(dlg.m_name2, Line_Color, dlg.m_x2, dlg.m_y2), Line_Type, Line_Width);
		// 将CMyPoint指针添加到vector中
		data.push_back(myLine);
		UpdateList();
		Invalidate();
	}
}


void CVectorDrawingDlg::OnDrawCircle()
{
	// TODO: 在此添加命令处理程序代码
	Draw_Circle_Dlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		// 创建一个CMyPoint对象并初始化
		CMyCircle* mycircle = new CMyCircle(dlg.m_name, Line_Color, CMyPoint(dlg.m_name, Line_Color, dlg.m_x, dlg.m_y),
			dlg.m_r, Line_Type, Line_Width, isfill, Fill_Color);
		// 将CMyPoint指针添加到vector中
		data.push_back(mycircle);
		UpdateList();
		Invalidate();
	}
}


void CVectorDrawingDlg::OnShapesetting()
{
	// TODO: 在此添加命令处理程序代码
	Outline_Setting_Dlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		Line_Width = dlg.m_width;
		Line_Color = dlg.Line_Color;
		Line_Type = dlg.Line_Type;
		isfill = !dlg.m_isfill;
		Fill_Color = dlg.Fill_Color;
	}
}


void CVectorDrawingDlg::OnDrawPolygon()
{
	// TODO: 在此添加命令处理程序代码
	Draw_Polygon_Dlg dlg;
	dlg.Line_Color = Line_Color;
	if (dlg.DoModal() == IDOK)
	{
		// 创建一个CMyPolygon对象并初始化
		CMyPolygon* mypolygon = new CMyPolygon(dlg.m_name, Line_Color, dlg.m_Points, Line_Type, Line_Width, isfill, Fill_Color);
		// 将CMyPoint指针添加到vector中
		data.push_back(mypolygon);
		UpdateList();
		Invalidate();
	}
}


void CVectorDrawingDlg::OnOwnerDraw()
{
	// TODO: 在此添加命令处理程序代码
	OnPensetting();
	OwnerDrawing = true;
}


void CVectorDrawingDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	P_Start = point;
	OwnerDrawing2 = true;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CVectorDrawingDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//OwnerDrawing = false;
	OwnerDrawing2 = false;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CVectorDrawingDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (OwnerDrawing && OwnerDrawing2)
	{
		CPen* pNewPen;
		CDC* pdc = GetDC();
		pNewPen = new CPen;
		pNewPen->CreatePen(0, Line_Width, Line_Color);
		pdc->SelectObject(pNewPen); //选择新笔，并保存旧笔 
		pdc->MoveTo(P_Start);
		pdc->LineTo(point);
		P_Start = point;
		delete pNewPen;
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CVectorDrawingDlg::OnEndOwnerDrawing()
{
	// TODO: 在此添加命令处理程序代码
	OwnerDrawing = false;
	OwnerDrawing2 = false;
}


void CVectorDrawingDlg::OnDrawFunc()
{
	// TODO: 在此添加命令处理程序代码
	Draw_Func_Dlg dlg(m_Xmin, m_Xmax, nullptr);
	//	
	if (dlg.DoModal() == IDOK)
	{
		// 创建一个CMyPolygon对象并初始化
		CMyFunc* myfunc = new CMyFunc(dlg.m_name, Line_Color, Line_Width, dlg.m_sEquation, dlg.m_Xmin, dlg.m_Xmax, dlg.m_stepX);

		if (myfunc->CalcList() == false)
		{
			AfxMessageBox(_T("请检查方程是否完整！"));
		}
		else
		{
			//将CMyPoint指针添加到vector中
			data.push_back(myfunc);
			UpdateList();
			Invalidate();
		}
	}
}


void CVectorDrawingDlg::OnClearBoard()
{
	// TODO: 在此添加命令处理程序代码
	data.clear();
	m_list.DeleteAllItems();
	isclear = true;
	Invalidate();
}


void CVectorDrawingDlg::OnBoardSetting()
{
	// TODO: 在此添加命令处理程序代码
	Board_Setting_Dlg dlg;
	dlg.m_Xmax = m_Xmax;
	dlg.m_Ymax = m_Ymax;
	dlg.m_Xmin = m_Xmin;
	dlg.m_Ymin = m_Ymin;
	if (dlg.DoModal() == IDOK)
	{
		m_Xmax = dlg.m_Xmax;
		m_Ymax = dlg.m_Ymax;
		m_Xmin = dlg.m_Xmin;
		m_Ymin = dlg.m_Ymin;
		Invalidate();
	}
}


void CVectorDrawingDlg::OnPointMoving()
{
	// TODO: 在此添加命令处理程序代码
	vector<CMyPoint*>temp;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i]->m_type == DATA_POINT)
			temp.push_back((CMyPoint*)data[i]);
	}
	if (temp.size() == 0)
	{
		MessageBox(TEXT("请先添加点！"), TEXT("提示"));
		return;
	}
	Point_Moving_Dlg dlg;
	dlg.points = temp;
	if (dlg.DoModal() == IDOK)
	{
		data.push_back(dlg.newpoint);
		UpdateList();
		Invalidate();
	}
}


void CVectorDrawingDlg::OnPointSymmetry1()
{
	// TODO: 在此添加命令处理程序代码
	vector<CMyPoint*>temp;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i]->m_type == DATA_POINT)
			temp.push_back((CMyPoint*)data[i]);
	}
	if (temp.size() == 0)
	{
		MessageBox(TEXT("请先添加点！"), TEXT("提示"));
		return;
	}
	Point_Symmetry1_Dlg dlg;
	dlg.points = temp;
	if (dlg.DoModal() == IDOK)
	{
		data.push_back(dlg.newpoint);
		UpdateList();
		Invalidate();
	}
}


void CVectorDrawingDlg::OnPointSymmetry2()
{
	// TODO: 在此添加命令处理程序代码
	vector<CMyPoint*>temp;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i]->m_type == DATA_POINT)
			temp.push_back((CMyPoint*)data[i]);
	}
	if (temp.size() == 0)
	{
		MessageBox(TEXT("请先添加点！"), TEXT("提示"));
		return;
	}
	Point_Symmetry2_Dlg dlg;
	dlg.points = temp;
	if (dlg.DoModal() == IDOK)
	{
		data.push_back(dlg.newpoint);
		UpdateList();
		Invalidate();
	}
}


void CVectorDrawingDlg::OnPointStyleSetting()
{
	// TODO: 在此添加命令处理程序代码
	Style_Setting_Dlg dlg;
	dlg.m_r = Point_Style;
	if (dlg.DoModal() == IDOK)
	{
		Point_Style = dlg.m_r;
		Invalidate();
	}
}


void CVectorDrawingDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_list.GetSelectionMark();
	if (nIndex > -1)
	{
		UINT i;
		i = MessageBox(_T("确定要删除该图形吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			data.erase(data.begin() + nIndex);
			MessageBox(TEXT("删除成功！"));
			UpdateList();
			Invalidate();
		}
	}
	else
	{
		MessageBox(TEXT("点击列表选择要删除的数据！"), TEXT("提示"));
	}
}


void CVectorDrawingDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_list.GetSelectionMark();
	if (nIndex > -1)
	{
		if (data[nIndex]->m_type == DATA_LINE)
		{
			vector<CMyData*>temp;
			for (int i = 0; i < data.size(); i++)
			{
				if (i == nIndex) continue;
				if (data[i]->m_type == DATA_LINE || data[i]->m_type == DATA_POLYGON || data[i]->m_type == DATA_CIRCLE)
					temp.push_back(data[i]);
			}
			if (temp.size() == 0)
			{
				MessageBox(TEXT("请先添加其他的点或图形！"), TEXT("提示"));
				return;
			}
			Intersection_Dlg dlg;
			dlg.shapes = temp;
			dlg.line = *(CMyLine*)data[nIndex];
			if (dlg.DoModal() == IDOK)
			{
				if (!dlg.newpoints.empty())
				{
					for (int i = 0; i < dlg.newpoints.size(); i++)
					{
						CMyPoint* P = new CMyPoint(TEXT(""), Line_Color, 
							dlg.newpoints[i].first, dlg.newpoints[i].second);
						data.push_back(P);
					}
					MessageBox(TEXT("这两个对象存在交点！"), TEXT("提示"));
					Invalidate();
				}
				else
				{
					MessageBox(TEXT("这两个对象无交点！"), TEXT("提示"));
				}
			}
		}
		else
		{
			MessageBox(TEXT("请选择线段！"), TEXT("提示"));
		}
	}
	else
	{
		MessageBox(TEXT("点击列表选择数据！"), TEXT("提示"));
	}
}


void CVectorDrawingDlg::OnSavePainting()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CRect rect;
	//BOOL  showMsgTag;                  //是否要弹出”图像保存成功对话框" 
	GetClientRect(&rect);                  //获取画布大小
	HBITMAP hbitmap = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);

	//创建兼容位图
	HDC hdc = CreateCompatibleDC(dc);      //创建兼容DC，以便将图像保存为不同的格式
	HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap);
	//将位图选入DC，并保存返回值 
	BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0, SRCCOPY);
	//将屏幕DC的图像复制到内存DC中

	CImage image;
	image.Attach(hbitmap);                //将位图转化为一般图像

	CString  strFilter = _T("位图文件(*.bmp)|*.bmp|JPEG 图像文件|*.jpg|GIF图像文件 | *.gif | PNG图像文件 | *.png |其他格式(*.*) | *.* || ");
	CFileDialog dlg(FALSE, _T("bmp"), _T("iPaint1.bmp"), NULL, strFilter);
	if (dlg.DoModal() != IDOK) return;

	CString strFileName;          //如果用户没有指定文件扩展名，则为其添加一个
	CString strExtension;
	strFileName = dlg.m_ofn.lpstrFile;

	if (dlg.m_ofn.nFileExtension == 0)               //扩展名项目为0
	{
		switch (dlg.m_ofn.nFilterIndex)
		{
		case 1:
			strExtension = "bmp"; break;
		case 2:
			strExtension = "jpg"; break;
		case 3:
			strExtension = "gif"; break;
		case 4:
			strExtension = "png"; break;
		default:
			break;
		}
		strFileName = strFileName + "." + strExtension;
	}

	saveFilePath = strFileName;     //saveFilePath为视类中的全局变量,类型为CString

	HRESULT hResult = image.Save(saveFilePath);     //保存图像
	if (FAILED(hResult))
	{
		MessageBox(_T("保存图像文件失败！"));
	}
	else
	{
		MessageBox(_T("文件保存成功！"));
	}
	image.Detach();
	SelectObject(hdc, hOldMap);
}


void CVectorDrawingDlg::OnDrawElliptic()
{
	// TODO: 在此添加命令处理程序代码
	Draw_Elliptic_Dlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CDC* pDC = GetDC();

		a = dlg.m_a;
		b = dlg.m_b;

		// 绘制动点
		dynamicPointX = a * cos(0);  // 动点初始 x 坐标
		dynamicPointY = b * sin(0);  // 动点初始 y 坐标

		angle = 0;
		type = 0;

		SetTimer(1,50,NULL);
	}
}


void CVectorDrawingDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDC* pDC = GetDC();

	// 创建画笔和画刷
	CPen pen(PS_SOLID, 3, Line_Color);
	CBrush brush(RGB(255, 0, 0));

	// 选择画笔和画刷
	pDC->SelectObject(&pen);
	pDC->SelectObject(&brush);

	angle++;
	double angleRad = angle * 3.14159 / 180.0;

	double dynamicPointNewX;
	double dynamicPointNewY;

	if (type == 0)
	{
		// 根据几何方法计算动点的坐标
		dynamicPointNewX = a * cos(angleRad);
		dynamicPointNewY = b * sin(angleRad);
	}
	else if (type == 1)
	{
		dynamicPointNewX = a * 1 / cos(angleRad);
		dynamicPointNewY = b * tan(angleRad);
	}
	else
	{
		dynamicPointNewX = 2 * r * (sin(angle) - sin(2 * angle) / 2);  // 动点初始 x 坐标
		dynamicPointNewY = 2 * r * (cos(angle) - cos(2 * angle) / 2);  // 动点初始 y 坐标
	}

	// 绘制轨迹
	if (dynamicPointX > m_Xmin && dynamicPointX < m_Xmax
		&& dynamicPointY > m_Ymin && dynamicPointY < m_Ymax)
	{
		pDC->MoveTo(FPxtoLPx(dynamicPointX), FPytoLPy(dynamicPointY));
		pDC->LineTo(FPxtoLPx(dynamicPointNewX), FPytoLPy(dynamicPointNewY));
	}

	// 更新动点的坐标
	dynamicPointX = dynamicPointNewX;
	dynamicPointY = dynamicPointNewY;

	CFont new_font;
	//创建字体宋体格式  100为字高
	VERIFY(new_font.CreatePointFont(150, _T("宋体"), pDC));
	//选择该字体进入PDC
	CFont* default_font = pDC->SelectObject(&new_font);
	//设置字体颜色
	pDC->SetTextColor(RGB(0,0,0));
	CString str;
	str.Format(TEXT("θ = %d°"), angle);
	pDC->TextOut(FPxtoLPx(a + 1), FPytoLPy(0), str);

	if (angle > 360) KillTimer(1);

	CDialogEx::OnTimer(nIDEvent);
}


void CVectorDrawingDlg::OnDrawHyperbola()
{
	// TODO: 在此添加命令处理程序代码
	Draw_Hyperbola_Dlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CDC* pDC = GetDC();

		a = dlg.m_a;
		b = dlg.m_b;

		// 绘制动点
		dynamicPointX = a * 1/(cos(0));  // 动点初始 x 坐标
		dynamicPointY = b * tan(0);  // 动点初始 y 坐标

		angle = 0;
		type = 1;

		SetTimer(1, 50, NULL);
	}
}


void CVectorDrawingDlg::OnDrawHeartline()
{
	// TODO: 在此添加命令处理程序代码
	Draw_Heartline_Dlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CDC* pDC = GetDC();

		r = dlg.m_r;
		angle = 0;

		// 绘制动点
		dynamicPointX = 2 * r * (sin(angle) - sin(2 * angle) / 2);  // 动点初始 x 坐标
		dynamicPointY = 2 * r * (cos(angle) - cos(2 * angle) / 2);  // 动点初始 y 坐标

		type = 2;

		SetTimer(1, 50, NULL);
	}
}
