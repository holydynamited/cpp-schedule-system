#include "Teacher.h"

//����������� �� �������������
Teacher::Teacher() {
   
    teacher_surname = "����";
    teacher_initials = "����";
    teacher_position = new string("����");
}

//����������� � ������� �����������
Teacher::Teacher(string surname, string initials, string* position) :
    teacher_surname{ surname }, teacher_initials{ initials }, teacher_position(new string(*position)) {
 
}

//����������� ��������� ���������
Teacher::Teacher(const Teacher& obj) {
    teacher_surname = obj.teacher_surname;
    teacher_initials = obj.teacher_initials;
    teacher_position = new string;
    *teacher_position = *obj.teacher_position;
 
}

//³��������� ����������
Teacher::~Teacher() {
    //��������� ���'��
    delete teacher_position;
}

//������� �� �������

string Teacher::getTeacherSurname() const {
    return teacher_surname;
}

void Teacher::setTeacherSurname(const string& surname) {
    teacher_surname = surname;
}

string* Teacher::getTeacherPosition() {
    return teacher_position;
}

const string* Teacher::getTeacherPosition() const {
    return teacher_position;
}

void Teacher::setTeacherPosition(const string& position) {
    if (teacher_position) {
        delete teacher_position;
    }
    teacher_position = new string(position);
}

string Teacher::getTeacherInitials() const {
    return teacher_initials;
}

void Teacher::setTeacherInitials(const string& initials) {
    teacher_initials = initials;
}
void Teacher::printSurname() const {
    cout << "Teacher Surname: " << teacher_surname << endl;

}
//�������� ()
void Teacher::operator()(const string& message) const {
    cout << "�������� " << teacher_surname << " (" << teacher_initials
        << ", " << *teacher_position << ") ���������: " << message << endl;
}

//�������� ��������� ��������� ����� �������/�������
Teacher& Teacher::operator=(const Teacher& other) {
    if (this != &other) {
        setTeacherSurname(other.getTeacherSurname());
        setTeacherInitials(other.getTeacherInitials());

        if (teacher_position) {
            delete teacher_position;
            teacher_position = nullptr;
        }

        if (other.getTeacherPosition()) {
            teacher_position = new string(*other.getTeacherPosition());
        }
        else {
            teacher_position = nullptr;
        }
    }
    return *this;
}

//�������� �������� (����� �������)
istream& operator>>(istream& is, Teacher& t) {
    string surname, initials, pos;
    cout << "������ ������� ���������: ";
    is >> surname;
    cout << "������ ������� ���������: ";
    is >> initials;
    is.ignore();
    cout << "������ ������ ���������: ";
    getline(is, pos);

    t.setTeacherSurname(surname);
    t.setTeacherInitials(initials);
    t.setTeacherPosition(pos);

    return is;
}

//�������� ��������� (����� �������)
ostream& operator<<(ostream& os, const Teacher& t) {
    os << "�������: " << t.getTeacherSurname()
        << ", �������: " << t.getTeacherInitials()
        //�������� ��������� ���������� �� � ��������
        << ", ������: " << (t.getTeacherPosition() ? *t.getTeacherPosition() : "����");
    return os;
}
