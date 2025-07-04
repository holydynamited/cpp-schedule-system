#include "Student.h"

// ����������� �� �������������
Student::Student() {
    stud_group = "���� �����";
    stud_surname = "����";
    stud_grade = new double(0);
   
}

// ����������� � ������� �����������
Student::Student(string stud_group, string stud_surname, double* stud_grade)
    : stud_group{ stud_group }, stud_surname{ stud_surname }, stud_grade{ new double(*stud_grade) } {
    
}

// ����������� ��������� ���������
Student::Student(const Student& obj) {
    stud_group = obj.stud_group;
    stud_surname = obj.stud_surname;
    // ������� ���������
    stud_grade = new double; *stud_grade = *obj.stud_grade;
    
}

// ������� �� �������
void Student::setStudGroup(string group) {
    stud_group = group;
}

string Student::getStudGroup() const {
    return stud_group;
}

void Student::setStudSurname(string surname) {
    stud_surname = surname;
}

string Student::getStudSurname() const {
    return stud_surname;
}

void Student::setStudGrade(double grade) {
    if (stud_grade) delete stud_grade;
    stud_grade = new double(grade);
}

double* Student::getStudGrade() {
    return stud_grade;
}

const double* Student::getStudGrade() const {
    return stud_grade;
}

// ³��������� �����
void Student::printSurname() const {
    cout << "����� ��������: " << stud_surname << endl;
}

// ³��������� ����������
Student::~Student() {
    // ��������� ���'��
    delete stud_grade;
 
}

// �������� ()
void Student::operator()(const string& message) const {
    if (stud_grade && *stud_grade >= 60)
        cout << message << ", " << stud_surname << "! ����! ���� ������: " << *stud_grade << endl;
    else
        cout << message << ", " << stud_surname << "! ������. ����� ����� ���������! ������: " << *stud_grade << endl;
}

// �������� ��������� ��������� 
Student& Student::operator=(const Student& other) {
    if (this == &other)
        return *this;

    setStudGroup(other.getStudGroup());
    setStudSurname(other.getStudSurname());

    if (stud_grade) {
        delete stud_grade;
        stud_grade = nullptr;
    }

    if (other.getStudGrade()) {
        stud_grade = new double(*other.getStudGrade());
    }
    else {
        stud_grade = nullptr;
    }

    return *this;
}

// �������� �������� ������
istream& operator>>(istream& is, Student& s) {
    string group, surname;
    double grade;
    is >> group >> surname >> grade;
    s.setStudGroup(group);
    s.setStudSurname(surname);
    s.setStudGrade(grade);
    return is;
}

// �������� ���������
ostream& operator<<(ostream& os, const Student& s) {
    os << "�����: " << s.getStudGroup() << ", �������: " << s.getStudSurname();
    if (s.getStudGrade())
        os << ", ������: " << *s.getStudGrade();
    else
        os << ", ������: �������";
    return os;
}
