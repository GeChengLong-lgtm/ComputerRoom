#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <vector>
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"

//学生类
class Student:public Identity {

public:

	//默认构造
	Student();

	//有参构造	
	Student(int id, string name, string pwd);

	//显示学生操作的菜单界面
	void operMenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

public:

	int m_Id;

	vector<ComputerRoom> vCom;
};