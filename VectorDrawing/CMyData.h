#pragma once

enum MyDataType
{
	DATA_POINT,		//��
	DATA_LINE,		//��
	DATA_CIRCLE,	//Բ
	DATA_POLYGON,	//�����
	DATA_FUNC		//����
};

class CMyData
{
public:
	int m_type;				//����
	CString m_name;			//����
	COLORREF m_Line_Color;	//������ɫ
};

