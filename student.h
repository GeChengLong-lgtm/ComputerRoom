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

//ѧ����
class Student:public Identity {

public:

	//Ĭ�Ϲ���
	Student();

	//�вι���	
	Student(int id, string name, string pwd);

	//��ʾѧ�������Ĳ˵�����
	void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

public:

	int m_Id;

	vector<ComputerRoom> vCom;
};