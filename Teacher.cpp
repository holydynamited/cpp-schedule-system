#include "Teacher.h"

//Конструктор за замовчуванням
Teacher::Teacher() {
   
    teacher_surname = "Немає";
    teacher_initials = "Немає";
    teacher_position = new string("Немає");
}

//Конструктор зі списком ініціалізації
Teacher::Teacher(string surname, string initials, string* position) :
    teacher_surname{ surname }, teacher_initials{ initials }, teacher_position(new string(*position)) {
 
}

//Конструктор глибокого копіювання
Teacher::Teacher(const Teacher& obj) {
    teacher_surname = obj.teacher_surname;
    teacher_initials = obj.teacher_initials;
    teacher_position = new string;
    *teacher_position = *obj.teacher_position;
 
}

//Віртуальний деструктор
Teacher::~Teacher() {
    //Звільнення пам'яті
    delete teacher_position;
}

//Сеттери та геттери

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
//Оператор ()
void Teacher::operator()(const string& message) const {
    cout << "Викладач " << teacher_surname << " (" << teacher_initials
        << ", " << *teacher_position << ") повідомляє: " << message << endl;
}

//Оператор глибокого копіювання через сеттери/геттери
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

//Оператор введення (через сеттери)
istream& operator>>(istream& is, Teacher& t) {
    string surname, initials, pos;
    cout << "Введіть прізвище викладача: ";
    is >> surname;
    cout << "Введіть ініціали викладача: ";
    is >> initials;
    is.ignore();
    cout << "Введіть посаду викладача: ";
    getline(is, pos);

    t.setTeacherSurname(surname);
    t.setTeacherInitials(initials);
    t.setTeacherPosition(pos);

    return is;
}

//Оператор виведення (через геттери)
ostream& operator<<(ostream& os, const Teacher& t) {
    os << "Прізвище: " << t.getTeacherSurname()
        << ", Ініціали: " << t.getTeacherInitials()
        //Перевірка тернарним оператором чи є вказівник
        << ", Посада: " << (t.getTeacherPosition() ? *t.getTeacherPosition() : "Немає");
    return os;
}
