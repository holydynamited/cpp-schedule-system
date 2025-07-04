#include "Classes.h"

// Конструктор за замовчуванням
Classes::Classes() : Student(), Teacher() {
    discipline = "Немає";
    class_type = "Немає";
    class_date = "Немає";
    class_time = "Немає";
    class_location = "Немає";
  
}

// Конструктор зі списком ініціалізації
Classes::Classes(string group, string surname, double* grade,
    string teachersurname, string initials, string* position,
    string discp, string classtype,
    string date, string time, string location)
    : Student(group, surname, grade),
    Teacher(teachersurname, initials, position),
    discipline{ discp },
    class_type{ classtype },
    class_date{ date },
    class_time{ time },
    class_location{ location }
{
  
}

// Конструктор глибокого копіювання
Classes::Classes(const Classes& obj)
    : Student(obj), Teacher(obj),
    discipline{ obj.discipline },
    class_type{ obj.class_type },
    class_date{ obj.class_date },
    class_time{ obj.class_time },
    class_location{ obj.class_location }
{
  
}

// Віртуальний деструктор
Classes::~Classes() {
    
}



void Classes::setDiscipline(string d) {
    discipline = d;
}

string Classes::getDiscipline() {
    return discipline;
}

void Classes::setClassType(string t) {
    class_type = t;
}

string Classes::getClassType() {
    return class_type;
}

void Classes::setClassDate(string d) {
    class_date = d;
}

string Classes::getClassDate() {
    return class_date;
}

void Classes::setClassTime(string t) {
    class_time = t;
}

string Classes::getClassTime() {
    return class_time;
}

void Classes::setClassLocation(string l) {
    class_location = l;
}

string Classes::getClassLocation() {
    return class_location;
}
void Classes::printSurname() const {
    cout << "Студент: " << getStudSurname()
        << ", Викладач: " << getTeacherSurname() << endl;
}

Classes& Classes::operator=(const Classes& other) {
    if (this != &other) {
        Student::operator=(other);
        Teacher::operator=(other);
        discipline = other.discipline;
        class_type = other.class_type;
        class_date = other.class_date;
        class_time = other.class_time;
        class_location = other.class_location;
    }
    return *this;
}

// Оператор ()
void Classes::operator()() {
    cout << "Заняття з дисципліни "<< discipline << " проводить(ться):" << endl;
    cout << "Тип: " << class_type << endl;
    cout << "Дата: " << class_date << endl;
    cout << "Час: " << class_time << endl;
    cout << "Місце проведення: " << class_location << endl;
}

// Оператор виводу
ostream& operator<<(ostream& os, const Classes& obj) {
    os << "Дисципліна: " << obj.discipline << endl;
    os << "Тип заняття: " << obj.class_type << endl;
    os << "Дата: " << obj.class_date << endl;
    os << "Час: " << obj.class_time << endl;
    os << "Місце проведення: " << obj.class_location << endl;
    return os;
}

// Оператор вводу
istream& operator>>(istream& is, Classes& obj) {
    cout << "Введіть назву дисципліни: ";
    is >> obj.discipline;
    cout << "Введіть тип заняття: ";
    is >> obj.class_type;
    cout << "Введіть дату заняття: ";
    is >> obj.class_date;
    cout << "Введіть час заняття: ";
    is >> obj.class_time;
    cout << "Введіть місце проведення заняття: ";
    is >> obj.class_location;
    return is;
}