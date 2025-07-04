#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class Teacher
{
private:
	//Поля даних
	string teacher_surname;
	string teacher_initials;
	string* teacher_position;


public:
	//Конструктор за замовчуванням
	Teacher();
	//Конструктор зі списком ініціалізіції
	Teacher(string, string, string*);
	//Конструктор глибокого копіювання
	Teacher(const Teacher& obj);
	//Віртуальний деструктор
	virtual ~Teacher();
	//Віртуальний деструктор
	string getTeacherSurname() const;

	//Сеттери та геттери
	void setTeacherSurname(const string& surname);
	string* getTeacherPosition();           
	const string* getTeacherPosition() const; 
	void setTeacherPosition(const string& position);  
	string getTeacherInitials() const;
	void setTeacherInitials(const string& initials);

	//Віртуальний метод 
	virtual void printSurname() const;

	//Оператор ()
	void operator()(const string& message) const;
	//Оператор глибокого копіювання
	Teacher& operator=(const Teacher& other);
	//Оператор введення
	friend istream& operator>>(istream& is, Teacher& t);
	//Оператор виведення
	friend ostream& operator<<(ostream& os, const Teacher& t);





	
};

                                                                                    