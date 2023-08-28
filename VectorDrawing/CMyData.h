#pragma once

enum MyDataType
{
	DATA_POINT,		//点
	DATA_LINE,		//线
	DATA_CIRCLE,	//圆
	DATA_POLYGON,	//多边形
	DATA_FUNC		//函数
};

class CMyData
{
public:
	int m_type;				//类型
	CString m_name;			//名称
	COLORREF m_Line_Color;	//线条颜色
};

