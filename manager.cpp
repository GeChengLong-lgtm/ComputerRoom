#include "manager.h"
#include "globalFile.h"
#include <fstream>
using namespace std;

//Ĭ�Ϲ��캯��
Manager::Manager() {

}

//�вι��캯��
Manager::Manager(string name, string pwd) {

	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��!" << endl;
		ifs.close();
		return;
	}

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
	ifs.close();
}

//��ʾѧ�������Ĳ˵�����
void Manager::operMenu() {

	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�
void Manager::addAccount() {

	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2����ӽ�ʦ" << endl;

	string filename;
	string tip;
	ofstream ofs;

	string errorTip;
	int select = 0;
	cin >> select;

	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룺";
	}
	else {
		filename = TEACHER_FILE;
		tip = "������ְ���ţ�" ;
		errorTip = "ְ�����ظ������������룺";
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (1) {
		cin >> id;
		bool ret = this->checkRepeat(id, select);

		if (ret) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ���" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//���ó�ʼ�������ӿڣ����»�ȡ�ļ��е�����
	this->initVector();
}

//�鿴�˺�
void Manager::checkAccount() {

	cout << "��������鿴����Ա���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;

	int select = 0;

	cin >> select;

	if (select == 1) {
		cout << "����ѧ����Ϣ���£�" << endl;
		for (vector<Student>::iterator it = vStu.begin();
			it != vStu.end(); it++) {
			cout << "ѧ�ţ�" << it->m_Id
				<< " ������" << it->m_Name
				<< " ���룺" << it->m_Pwd << endl;
		}
	}
	else if (select == 2) {
		cout << "���н�ְ����Ϣ���£�" << endl;
		for (vector<Teacher>::iterator it = vTea.begin();
			it != vTea.end(); it++) {
			cout << "ѧ�ţ�" << it->m_EmpId
				<< " ������" << it->m_Name
				<< " ���룺" << it->m_Pwd << endl;
		}
	}
}

//�鿴������Ϣ
void Manager::checkComputer() {

	cout << "��ǰ������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin();
		it != vCom.end(); it++) {
		cout << "�������Ϊ��" << it->m_ComId
			<< "�����������Ϊ��" << it->m_MaxNum << endl;
	}

	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::clearOrder() {

	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector() {

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		ifs.close();
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}

//����ظ� 
bool Manager::checkRepeat(int id, int type) {

	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin();
			it != vStu.end(); it++) {
			if (it->m_Id == id) {
				return true;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin();
			it != vTea.end(); it++) {
			if (it->m_EmpId == id) {
				return true;
			}
		}
	}
	return false;
}