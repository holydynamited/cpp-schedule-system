#pragma once
#include "Student.h"
#include "Teacher.h"
using namespace std;

class Classes : public Student, public Teacher
{
private:
	//���� �����
	string discipline;      // ���������
	string class_type;      // ��� �������
	string class_date;      // ����
	string class_time;      // ���
	string class_location;  // ��������

public:
	//����������� �� �������������
	Classes();

	//����������� � ������� �����������
	Classes(string, string, double*, string, string, string*,
		string, string, string, string, string);

	//����������� ��������� ���������
	Classes(const Classes& obj);

	//³��������� ����������
	virtual ~Classes();

	//������� �� �������
	void setDiscipline(string);
	string getDiscipline();

	void setClassType(string);
	string getClassType();

	void setClassDate(string);
	string getClassDate();

	void setClassTime(string);
	string getClassTime();

	void setClassLocation(string);
	string getClassLocation();

	//³��������� �����
	void printSurname() const override;

	//�������� ��������� ���������
	Classes& operator=(const Classes& other);

	//�������� ()
	void operator()();

	//�������� ���������
	friend ostream& operator<<(ostream& os, const Classes& obj);

	//�������� ��������
	friend istream& operator>>(istream& is, Classes& obj);
};
