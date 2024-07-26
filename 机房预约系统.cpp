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
			cout << "ע���ɹ�" << endl;
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
			cout << "ע���ɹ���" << endl;
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
			cout << "����˺�" << endl;
			man->addAccount();
		}
		else if (select == 2) {
			cout << "�鿴�˺�" << endl;
			man->checkAccount();
		}
		else if (select == 3) {
			cout << "�鿴����" << endl;
			man->checkComputer();
		}
		else if (select == 4) {
			cout << "���ԤԼ" << endl;
			man->clearOrder();
		}
		else {
			delete manager;
			cout << "ע���ɹ�" << endl;
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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;
	
	if (type == 1) {

		//ѧ����¼��֤
		int sid;
		string sname;
		string spwd;
		while (ifs >> sid && ifs >> sname && ifs >> spwd) {
			cout << "id:" << id << "name:" << name << "pwd:" << pwd;
			cout << "sid:" << sid << "name:" << sname << "pwd:" << spwd;
			if (sid == id && sname == name && spwd == pwd) {
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
		
	}
	else if (type == 2) {

		//��ʦ��¼��֤
		int tid;
		string tname;
		string tpwd;
		while (ifs >> tid && ifs >> tname && ifs >> tpwd) {
			if (tid == id && tname == name && tpwd == pwd) {
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				
				return;
			}
		}
	}
	else if (type == 3) {

		//����Ա��¼��֤
		int mid;
		string mname;
		string mpwd;
		while (ifs >> mname && ifs >> mpwd) {
			if (mname == name && mpwd == pwd) {
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
		
	}

	cout << "��֤��¼ʧ�ܣ�" << endl;

	system("pause");
	system("cls");
	return;
}

int main() {

	int choice;	

	while (1) {
		cout << "==================  ��ӭ�����Ͼ��ʵ��ѧ����ԤԼϵͳ  ================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

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
			cout << "��ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�����������������룺" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}