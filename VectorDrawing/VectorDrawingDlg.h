
// VectorDrawingDlg.h: 头文件
//

#pragma once
#include "CMyPoint.h"
#include "CMyLine.h"
#include "CMyCircle.h"
#include "CMyPolygon.h"
#include "CMyFunc.h"

// CVectorDrawingDlg 对话框
class CVectorDrawingDlg : public CDialogEx
{
// 构造
public:
	CVectorDrawingDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VECTORDRAWING_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	//画板基本参数
	double m_Xmin, m_Xmax, m_Ymin, m_Ymax;
	int nTop, nBottom, nLeft, nRight;
	//坐标转换函数
	double LPxtoFPx(int x);
	int FPxtoLPx(double x);
	double LPytoFPy(int y);
	int FPytoLPy(double y);
	//画板初始化函数
	void InitBoard(CPaintDC& dc); 
	//图形参数
	bool isfill;      //填充 true：填充 false：不填充
	int Line_Type;    //线型 0：实线 1：虚线 2：点线
	int Line_Width;   //线宽
	COLORREF Line_Color; //线条颜色
	COLORREF Fill_Color;	//填充颜色
	int Point_Style;	//点的样式 0:实心圆形  1：空心圆形  2：正方形  3：三角形  4：十字型

	//所有需要绘制的数据存储在vector中
	vector<CMyData*> data;
	void Draw_All(CPaintDC& dc);	//绘制所有的数据
	void Draw_Point(CMyPoint* mypoint, CPaintDC& dc);	//绘制点
	void Draw_Line(CMyLine* myline, CPaintDC& dc);		//绘制线
	void Draw_Circle(CMyCircle* mycirlce, CPaintDC& dc);//绘制圆
	void Draw_Polygon(CMyPolygon* mypolygon, CPaintDC& dc);//绘制多边形
	void Draw_Func(CMyFunc* myfunc, CPaintDC& dc);		//绘制函数

	//自由绘制
	bool OwnerDrawing, OwnerDrawing2; //自由绘制标志位
	CPoint P_Start, P_End; //起点与终点

	bool isclear;	//清空画板标志位
	CString saveFilePath;	//保存路径

	CListCtrl m_list;
	void UpdateList(); //更新列表

	//椭圆,双曲线,心形线动点
	int type;
	double a;
	double b;
	double r;
	int angle;
	double dynamicPointX;
	double dynamicPointY;

	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnPensetting();
	afx_msg void OnDrawPoint();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawCircle();
	afx_msg void OnShapesetting();
	afx_msg void OnDrawPolygon();
	afx_msg void OnOwnerDraw();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnEndOwnerDrawing();
	afx_msg void OnDrawFunc();
	afx_msg void OnClearBoard();
	afx_msg void OnBoardSetting();
	afx_msg void OnPointMoving();
	afx_msg void OnPointSymmetry1();
	afx_msg void OnPointSymmetry2();
	afx_msg void OnPointStyleSetting();
	CButton m_button_del;
	CButton m_button_jd;
	CStatic m_s1;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnSavePainting();
	afx_msg void OnDrawElliptic();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDrawHyperbola();
	afx_msg void OnDrawHeartline();
};
