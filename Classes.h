#pragma once
#include "Student.h"
#include "Teacher.h"
using namespace std;

class Classes : public Student, public Teacher
{
private:
	//Поля даних
	string discipline;      // Дисципліна
	string class_type;      // Тип заняття
	string class_date;      // Дата
	string class_time;      // Час
	string class_location;  // Аудиторія

public:
	//Конструктор за замовчуванням
	Classes();

	//Конструктор зі списком ініціалізації
	Classes(string, string, double*, string, string, string*,
		string, string, string, string, string);

	//Конструктор глибокого копіювання
	Classes(const Classes& obj);

	//Віртуальний деструктор
	virtual ~Classes();

	//Сеттери та геттери
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

	//Віртуальний метод
	void printSurname() const override;

	//Оператор глибокого копіювання
	Classes& operator=(const Classes& other);

	//Оператор ()
	void operator()();

	//Оператор виведення
	friend ostream& operator<<(ostream& os, const Classes& obj);

	//Оператор введення
	friend istream& operator>>(istream& is, Classes& obj);
};
