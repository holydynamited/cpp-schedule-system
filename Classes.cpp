#include "Classes.h"

// ����������� �� �������������
Classes::Classes() : Student(), Teacher() {
    discipline = "����";
    class_type = "����";
    class_date = "����";
    class_time = "����";
    class_location = "����";
  
}

// ����������� � ������� �����������
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

// ����������� ��������� ���������
Classes::Classes(const Classes& obj)
    : Student(obj), Teacher(obj),
    discipline{ obj.discipline },
    class_type{ obj.class_type },
    class_date{ obj.class_date },
    class_time{ obj.class_time },
    class_location{ obj.class_location }
{
  
}

// ³��������� ����������
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
    cout << "�������: " << getStudSurname()
        << ", ��������: " << getTeacherSurname() << endl;
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

// �������� ()
void Classes::operator()() {
    cout << "������� � ��������� "<< discipline << " ���������(����):" << endl;
    cout << "���: " << class_type << endl;
    cout << "����: " << class_date << endl;
    cout << "���: " << class_time << endl;
    cout << "̳��� ����������: " << class_location << endl;
}

// �������� ������
ostream& operator<<(ostream& os, const Classes& obj) {
    os << "���������: " << obj.discipline << endl;
    os << "��� �������: " << obj.class_type << endl;
    os << "����: " << obj.class_date << endl;
    os << "���: " << obj.class_time << endl;
    os << "̳��� ����������: " << obj.class_location << endl;
    return os;
}

// �������� �����
istream& operator>>(istream& is, Classes& obj) {
    cout << "������ ����� ���������: ";
    is >> obj.discipline;
    cout << "������ ��� �������: ";
    is >> obj.class_type;
    cout << "������ ���� �������: ";
    is >> obj.class_date;
    cout << "������ ��� �������: ";
    is >> obj.class_time;
    cout << "������ ���� ���������� �������: ";
    is >> obj.class_location;
    return is;
}