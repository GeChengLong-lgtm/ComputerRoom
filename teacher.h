#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include "orderFile.h"
#include <vector>

//��ʦ��
class Teacher:public Identity {

public:

	//Ĭ�Ϲ��캯��
	Teacher();

	//�вι��캯��
	Teacher(int id, string name, string pwd);

	//��ʾ��ʦ�����Ĳ˵�����
	void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void checkOrder();

public:

	int m_EmpId;
};