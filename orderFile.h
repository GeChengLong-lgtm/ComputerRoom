#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "globalFile.h"

//ԤԼ��¼��
class OrderFile {

public:

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

public:

	map<int, map<string, string>> m_orderData;

	int m_Size;
};
