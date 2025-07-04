#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Student
{
private:
//���� �����
	string stud_group;
	string stud_surname;
	double * stud_grade;



public:
	//������������ �� �������������
	Student();
	//����������� � ������� �����������
	Student(string, string, double*);
  //����������� ��������� ���������
	Student(const Student& obj);

	//������� �� ������� ���� �����
	void setStudGroup(string );
	string getStudGroup()const;

	void setStudSurname(string);
	 string getStudSurname() const;

	 double* getStudGrade();
	 const double* getStudGrade() const;
	 void setStudGrade(double grade);
	 //³��������� ����� 
	 virtual void printSurname() const;

	//³��������� ����������
	virtual ~Student();
	//�������� ()
	void operator()(const string& message) const;
	//�������� ��������� ���������
	Student& operator=(const Student& other);
	//�������� �������� ������
	friend istream& operator>>(istream& in, Student& s);
	//�������� ���������
	friend ostream& operator<<(ostream& out, const Student& s);



};

