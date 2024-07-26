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

//����Ա��
class Manager:public Identity{

public:

	//Ĭ�Ϲ��캯��
	Manager();

	//�вι��캯��
	Manager(string name, string pwd);

	//��ʾѧ�������Ĳ˵�����
	void operMenu();

	//����˺�
	void addAccount();

	//�鿴�˺�
	void checkAccount();

	//�鿴������Ϣ
	void checkComputer();

	//���ԤԼ��¼
	void clearOrder();

	//��ʼ������
	void initVector();

	//����ظ� 
	bool checkRepeat(int id, int type);

public:

	int m_MgrId;

	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

	//������Ϣ����
	vector<ComputerRoom>vCom;

};
