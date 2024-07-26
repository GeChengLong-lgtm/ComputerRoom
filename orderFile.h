#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "globalFile.h"

//预约记录类
class OrderFile {

public:

	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

public:

	map<int, map<string, string>> m_orderData;

	int m_Size;
};
