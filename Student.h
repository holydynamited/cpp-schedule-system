#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Student
{
private:
//поля даних
	string stud_group;
	string stud_surname;
	double * stud_grade;



public:
	//Конструктори за замовчуванням
	Student();
	//Конструктор зі списком ініціалізації
	Student(string, string, double*);
  //Конструктор глибокого копіювання
	Student(const Student& obj);

	//Сеттери та геттери полів даних
	void setStudGroup(string );
	string getStudGroup()const;

	void setStudSurname(string);
	 string getStudSurname() const;

	 double* getStudGrade();
	 const double* getStudGrade() const;
	 void setStudGrade(double grade);
	 //Віртуальний метод 
	 virtual void printSurname() const;

	//Віртуальний деструктор
	virtual ~Student();
	//Оператор ()
	void operator()(const string& message) const;
	//Оператор глибокого копіювання
	Student& operator=(const Student& other);
	//Оператор введення данних
	friend istream& operator>>(istream& in, Student& s);
	//Оператор виведення
	friend ostream& operator<<(ostream& out, const Student& s);



};

