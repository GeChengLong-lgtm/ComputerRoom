#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include "orderFile.h"
#include <vector>

//教师类
class Teacher:public Identity {

public:

	//默认构造函数
	Teacher();

	//有参构造函数
	Teacher(int id, string name, string pwd);

	//显示教师操作的菜单界面
	void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void checkOrder();

public:

	int m_EmpId;
};