// Add_Func_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "VectorDrawing.h"
#include "Add_Func_Dlg.h"
#include "afxdialogex.h"


// Add_Func_Dlg 对话框

IMPLEMENT_DYNAMIC(Add_Func_Dlg, CDialogEx)

Add_Func_Dlg::Add_Func_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Add_Func_Dlg, pParent)
	, m_strEquation(_T(""))
{

}

Add_Func_Dlg::~Add_Func_Dlg()
{
}

void Add_Func_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EQUATION_EDIT, m_strEquation);
}


BEGIN_MESSAGE_MAP(Add_Func_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_1, &Add_Func_Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &Add_Func_Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &Add_Func_Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &Add_Func_Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &Add_Func_Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &Add_Func_Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &Add_Func_Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &Add_Func_Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &Add_Func_Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_PI, &Add_Func_Dlg::OnBnClickedButtonPi)
	ON_BN_CLICKED(IDC_BUTTON_10, &Add_Func_Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON_E, &Add_Func_Dlg::OnBnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &Add_Func_Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &Add_Func_Dlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_DEC, &Add_Func_Dlg::OnBnClickedButtonDec)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &Add_Func_Dlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &Add_Func_Dlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_SIN, &Add_Func_Dlg::OnBnClickedButtonSin)
	ON_BN_CLICKED(IDC_BUTTON_COS, &Add_Func_Dlg::OnBnClickedButtonCos)
	ON_BN_CLICKED(IDC_BUTTON_TAN, &Add_Func_Dlg::OnBnClickedButtonTan)
	ON_BN_CLICKED(IDC_BUTTON_LOG, &Add_Func_Dlg::OnBnClickedButtonLog)
	ON_BN_CLICKED(IDC_BUTTON_POW, &Add_Func_Dlg::OnBnClickedButtonPow)
	ON_BN_CLICKED(IDC_BUTTON_2POW, &Add_Func_Dlg::OnBnClickedButton2pow)
	ON_BN_CLICKED(IDC_BUTTON_SQRT, &Add_Func_Dlg::OnBnClickedButtonSqrt)
	ON_BN_CLICKED(IDC_BUTTON_LN, &Add_Func_Dlg::OnBnClickedButtonLn)
	ON_BN_CLICKED(IDC_BUTTON_X, &Add_Func_Dlg::OnBnClickedButtonX)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &Add_Func_Dlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &Add_Func_Dlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &Add_Func_Dlg::OnBnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &Add_Func_Dlg::OnBnClickedButtonRight)
	/*ON_BN_CLICKED(IDC_BUTTON_CUBIC, &Add_Func_Dlg::OnBnClickedButtonCubic)*/
	ON_BN_CLICKED(IDOK, &Add_Func_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Add_Func_Dlg 消息处理程序
void Add_Func_Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "1";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "2";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "3";
	UpdateData(false);
}



void Add_Func_Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "4";
	UpdateData(false);
}



void Add_Func_Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "5";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "6";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "7";
	UpdateData(false);
}



void Add_Func_Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "8";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "9";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonPi()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "p";
	UpdateData(false);
}




void Add_Func_Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "0";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonE()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "e";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "+";
	UpdateData(false);
}




void Add_Func_Dlg::OnBnClickedButtonDot()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += ".";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonDec()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "-";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonMul()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "*";
	UpdateData(false);
}





void Add_Func_Dlg::OnBnClickedButtonDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "/";
	UpdateData(false);
}



void Add_Func_Dlg::OnBnClickedButtonSin()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "sin(";
	UpdateData(false);
}



void Add_Func_Dlg::OnBnClickedButtonCos()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "cos(";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonTan()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "tan(";
	UpdateData(false);
}




void Add_Func_Dlg::OnBnClickedButtonLog()  //以10为底
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "lg(";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonPow()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "^";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButton2pow()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "^2";
	UpdateData(false);
}




void Add_Func_Dlg::OnBnClickedButtonSqrt()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "sqrt(";
	UpdateData(false);
}




void Add_Func_Dlg::OnBnClickedButtonLn()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "ln(";
	UpdateData(false);
}



void Add_Func_Dlg::OnBnClickedButtonAbs()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "abs(";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonX()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if (m_cas == 0) m_strEquation += "x";
	else m_strEquation += 't';
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation = "";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	int T = m_strEquation.GetLength();
	if (T > 0)
		m_strEquation = m_strEquation.Left(T - 1);
	UpdateData(false);
}



void Add_Func_Dlg::OnBnClickedButtonLeft()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "(";
	UpdateData(false);
}




void Add_Func_Dlg::OnBnClickedButtonRight()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += ")";
	UpdateData(false);
}



void Add_Func_Dlg::OnBnClickedButtonFloor()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "floor(";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonCeiling()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "ceil(";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonRound()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "round(";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedButtonCubic()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_strEquation += "^3";
	UpdateData(false);
}


void Add_Func_Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}