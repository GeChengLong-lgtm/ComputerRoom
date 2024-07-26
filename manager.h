#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"

//管理员类
class Manager:public Identity{

public:

	//默认构造函数
	Manager();

	//有参构造函数
	Manager(string name, string pwd);

	//显示学生操作的菜单界面
	void operMenu();

	//添加账号
	void addAccount();

	//查看账号
	void checkAccount();

	//查看机房信息
	void checkComputer();

	//清空预约记录
	void clearOrder();

	//初始化容器
	void initVector();

	//检测重复 
	bool checkRepeat(int id, int type);

public:

	int m_MgrId;

	//学生容器
	vector<Student>vStu;

	//教师容器
	vector<Teacher>vTea;

	//机房信息容器
	vector<ComputerRoom>vCom;

};
