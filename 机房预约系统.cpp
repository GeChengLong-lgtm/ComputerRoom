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

void studentMenu(Identity*& student) {

	while (1) {
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;
		if (select == 1) {
			stu->applyOrder();
		}
		else if (select == 2) {
			stu->showMyOrder();
		}
		else if (select == 3) {
			stu->showAllOrder();
		}
		else if (select == 4) {
			stu->cancelOrder();
		}
		else {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void teacherMenu(Identity*& tea) {

	while (1) {
		tea->operMenu();
		Teacher* t = (Teacher*)tea;
		int select = 0;

		cin >> select;
		if (select == 1) {
			t->showAllOrder();
		}
		else if (select == 2) {
			t->checkOrder();
		}
		else {
			delete tea;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void managerMenu(Identity*& manager) {

	while (1) {
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
		if (select == 1) {
			cout << "添加账号" << endl;
			man->addAccount();
		}
		else if (select == 2) {
			cout << "查看账号" << endl;
			man->checkAccount();
		}
		else if (select == 3) {
			cout << "查看机房" << endl;
			man->checkComputer();
		}
		else if (select == 4) {
			cout << "清空预约" << endl;
			man->clearOrder();
		}
		else {
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LogIn(string fileName, int type) {

	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	
	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;
	
	if (type == 1) {

		//学生登录验证
		int sid;
		string sname;
		string spwd;
		while (ifs >> sid && ifs >> sname && ifs >> spwd) {
			cout << "id:" << id << "name:" << name << "pwd:" << pwd;
			cout << "sid:" << sid << "name:" << sname << "pwd:" << spwd;
			if (sid == id && sname == name && spwd == pwd) {
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
		
	}
	else if (type == 2) {

		//教师登录验证
		int tid;
		string tname;
		string tpwd;
		while (ifs >> tid && ifs >> tname && ifs >> tpwd) {
			if (tid == id && tname == name && tpwd == pwd) {
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				
				return;
			}
		}
	}
	else if (type == 3) {

		//管理员登录验证
		int mid;
		string mname;
		string mpwd;
		while (ifs >> mname && ifs >> mpwd) {
			if (mname == name && mpwd == pwd) {
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
		
	}

	cout << "验证登录失败！" << endl;

	system("pause");
	system("cls");
	return;
}

int main() {

	int choice;	

	while (1) {
		cout << "==================  欢迎来到南京邮电大学机房预约系统  ================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> choice;

		switch (choice) {
		case 1:
			LogIn(STUDENT_FILE, choice);
			break;
		case 2:
			LogIn(TEACHER_FILE, choice);
			break;
		case 3:
			LogIn(ADMIN_FILE, choice);
			break;
		case 0:
			cout << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误！请重新输入：" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}