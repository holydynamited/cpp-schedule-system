#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class Teacher
{
private:
	//���� �����
	string teacher_surname;
	string teacher_initials;
	string* teacher_position;


public:
	//����������� �� �������������
	Teacher();
	//����������� � ������� ����������
	Teacher(string, string, string*);
	//����������� ��������� ���������
	Teacher(const Teacher& obj);
	//³��������� ����������
	virtual ~Teacher();
	//³��������� ����������
	string getTeacherSurname() const;

	//������� �� �������
	void setTeacherSurname(const string& surname);
	string* getTeacherPosition();           
	const string* getTeacherPosition() const; 
	void setTeacherPosition(const string& position);  
	string getTeacherInitials() const;
	void setTeacherInitials(const string& initials);

	//³��������� ����� 
	virtual void printSurname() const;

	//�������� ()
	void operator()(const string& message) const;
	//�������� ��������� ���������
	Teacher& operator=(const Teacher& other);
	//�������� ��������
	friend istream& operator>>(istream& is, Teacher& t);
	//�������� ���������
	friend ostream& operator<<(ostream& os, const Teacher& t);





	
};

                                                                                    