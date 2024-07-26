#include <iostream>
#include <fstream>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include <string>
#include "globalFile.h"
#include "orderFile.h"
#include "computerRoom.h"
using namespace std;

//默认构造
Student::Student() {

}

//有参构造	
Student::Student(int id, string name, string pwd) {

	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	if (!ifs.is_open()) {
		cout << "打开文件失败！" << endl;
		ifs.close();
		return;
	}

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}

	ifs.close();
}

//显示学生操作的菜单界面
void Student::operMenu() {
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//申请预约
void Student::applyOrder() {

	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int date = 0;
	int interval = 0;
	int room = 0;

	while (1) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "日期输入有误！" << endl;
	}

	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (1) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "时间段输入有误！" << endl;
	}

	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << vCom[0].m_MaxNum << endl;
	cout << "2号机房容量：" << vCom[1].m_MaxNum << endl;
	cout << "3号机房容量：" << vCom[2].m_MaxNum << endl;

	while (1) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "机房编号输入有误!" << endl;
	}

	cout << "预约成功！审核中" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

//查看自身预约
void Student::showMyOrder() {

	OrderFile of;
	cout << "of.size()=" << of.m_Size << endl;
	if (of.m_Size == 0) {
		cout << "当前无记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	/*for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << "预约日期：周" << of.m_orderData[i]["date"];
			cout << "时段：" << (of.m_orderData[i]["interval"]
				== "1" ? "上午" : "下午");
			cout << "机房编号：" << of.m_orderData[i]["roomId"];
			string status = "状态：";
			if (of.m_orderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "3") {
				status += "审核未通过，预约失败";
			}
			else {
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}*/

	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << "预约日期：周" << of.m_orderData[i]["date"];
			cout << "时段：" << (of.m_orderData[i]["interval"]
				== "1" ? "上午" : "下午");
			cout << "机房编号：" << of.m_orderData[i]["roomId"];
			string status = "状态：";
			if (of.m_orderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "3") {
				status += "审核未通过，预约失败";
			}
			else {
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder() {

	OrderFile of;
	if (of.m_Size == 0) {
		cout << "当前无记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {

		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["date"];
		cout << "时段：" << (of.m_orderData[i]["interval"]
			== "1" ? "上午" : "下午");
		cout << "机房编号：" << of.m_orderData[i]["roomId"];
		string status = "状态：";
		if (of.m_orderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "3") {
			status += "审核未通过，预约失败";
		}
		else {
			status += "预约已取消";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

//取消预约
void Student::cancelOrder() {

	OrderFile of;
	if (of.m_Size == 0) {
		cout << "当前无记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "已在审核的或预约成功的可以被取消，请输入要取消的记录" << endl;
	vector<int> v;
	int index = 1;

	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << endl;
				cout << "预约日期：周" << of.m_orderData[i]["date"];
				cout << "时段：" << (of.m_orderData[i]["interval"]
					== "1" ? "上午" : "下午");
				cout << "机房编号：" << of.m_orderData[i]["roomId"];
				string status = "状态：";
				if (of.m_orderData[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "预约成功";
				}
				else if (of.m_orderData[i]["status"] == "3") {
					status += "审核未通过，预约失败";
				}
				else {
					status += "预约已取消";
				}
				cout << status << endl;
			}
		}
	}

	cout << "请输入需要取消的记录(0代表操作完毕)：" << endl;
	int select = 0;
	while (1) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.m_orderData[select - 1]["status"] = "0";
				of.updateOrder();
				cout << "已成功取消预约！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入!" << endl;
	}

	system("pause");
	system("cls");
}