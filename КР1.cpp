#include <iostream>
#include <fstream>
#include "Teacher.h"
#include "ClassSchedule.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ClassSchedule schedule;

    int choice;
    while (true) {
        cout << "1. Додати заняття" << endl;
        cout << "2. Показати розклад" << endl;
        cout << "3. Зберегти у файл" << endl;
        cout << "4. Поліморфний виклик printSurname()" << endl;
        cout << "5. Копіювати заняття" << endl;
        cout << "6. Надіслати повідомлення   (operator())" << endl;
        cout << "7. Ввести заняття через оператор >> та вивести через << " << endl;
        cout << "8. Вихід" << endl;

        cin >> choice;

        if (choice == 1) {
            if (schedule.getCount() >= 2) {
                cout << "Розклад переповнено! Можна лише 2 заняття." << endl;
                continue;
            }
            string group, studSurname, teachSurname, initials, discipline, type, date, time, location, pos;
            double grade;
            cout << "Група студента: "; cin >> group;
            cout << "Прізвище студента: "; cin >> studSurname;
            cout << "Оцінка: "; cin >> grade;
            cout << "Прізвище викладача: "; cin >> teachSurname;
            cout << "Ініціали викладача: "; cin >> initials;
            cin.ignore();
            cout << "Посада викладача: "; getline(cin, pos);
            cout << "Дисципліна: "; getline(cin, discipline);
            cout << "Тип заняття: "; getline(cin, type);
            cout << "Дата: "; getline(cin, date);
            cout << "Час: "; getline(cin, time);
            cout << "Місце проведення: "; getline(cin, location);

            Classes lesson(
                group, studSurname, new double(grade),
                teachSurname, initials, new string(pos),
                discipline, type, date, time, location
            );
            schedule.addLesson(lesson);
            cout << "Заняття додано." << endl;
        }
        else if (choice == 2) {
            if (schedule.begin() == schedule.end()) {
                cout << "Розклад порожній, додайте хоча б одне заняття!" << endl;
                continue;
            }
            cout << "Вивід розкладу:" << endl;
            int idx = 1;
            for (ClassesIterator it = schedule.begin(); it != schedule.end(); ++it) {
                cout << "Заняття " << idx++ << ":" << endl;
                cout << "Дисципліна: " << it->getDiscipline() << endl;
                cout << "Тип заняття: " << it->getClassType() << endl;
                cout << "Дата: " << it->getClassDate() << endl;
                cout << "Час: " << it->getClassTime() << endl;
                cout << "Місце проведення: " << it->getClassLocation() << endl;
                cout << "Студент: група " << it->getStudGroup()
                    << ", прізвище " << it->getStudSurname()
                    << ", оцінка ";
                if (it->getStudGrade()) cout << *it->getStudGrade() << endl;
                else cout << "відсутня" << endl;
                cout << "Викладач: прізвище " << it->getTeacherSurname()
                    << ", ініціали " << it->getTeacherInitials()
                    << ", посада ";
                if (it->getTeacherPosition()) cout << *it->getTeacherPosition() << endl;
                else cout << "відсутня" << endl;
                cout << "-----------------------------------" << endl;
            }
        }
        else if (choice == 3) {
            ofstream fout("schedule.txt");
            int idx = 1;
            for (ClassesIterator it = schedule.begin(); it != schedule.end(); ++it) {
                fout << "Заняття " << idx++ << ":" << endl;
                fout << "Дисципліна: " << it->getDiscipline() << endl;
                fout << "Тип заняття: " << it->getClassType() << endl;
                fout << "Дата: " << it->getClassDate() << endl;
                fout << "Час: " << it->getClassTime() << endl;
                fout << "Місце проведення: " << it->getClassLocation() << endl;
                fout << "Студент: група " << it->getStudGroup()
                    << ", прізвище " << it->getStudSurname()
                    << ", оцінка ";
                if (it->getStudGrade()) fout << *it->getStudGrade() << endl;
                else fout << "відсутня" << endl;
                fout << "Викладач: прізвище " << it->getTeacherSurname()
                    << ", ініціали " << it->getTeacherInitials()
                    << ", посада ";
                if (it->getTeacherPosition()) fout << *it->getTeacherPosition() << endl;
                else fout << "відсутня" << endl;
                fout << "-----------------------------------" << endl;
            }
            fout.close();
            cout << "Розклад збережено у файл schedule.txt" << endl;
        }
        else if (choice == 4) {
            if (schedule.begin() == schedule.end()) {
                cout << "Розклад порожній, додайте хоча б одне заняття!" << endl;
                return 0;
            }

            cout << "Тест поліморфного виклику printSurname() для введених даних:" << endl;

            
            Classes demo = *schedule.begin();

            
            Student* stud_ptr = new Student(demo.getStudGroup(), demo.getStudSurname(), demo.getStudGrade());
            Teacher* teach_ptr = new Teacher(demo.getTeacherSurname(), demo.getTeacherInitials(), demo.getTeacherPosition());
            Classes* classes_ptr = new Classes(demo); 

            cout << "Student*: "; stud_ptr->printSurname();
            cout << "Teacher*: "; teach_ptr->printSurname();
            cout << "Classes*: "; classes_ptr->printSurname();

            cout << "-----------------------------------" << endl;

            delete stud_ptr;
            delete teach_ptr;
            delete classes_ptr;
        }

        else if (choice == 5) {
            if (schedule.getCount() < 1) {
                cout << "Додайте хоча б одне заняття!" << endl;
                continue;
            }
            if (schedule.getCount() >= 2) {
                cout << "Неможливо скопіювати: розклад уже містить 2 заняття." << endl;
                continue;
            }

            Classes demo = *schedule.begin();
            Classes copy = demo; 
            schedule.addLesson(copy); 

            cout << "Заняття скопійовано у другий слот!" << endl;
            cout << "Оригінал: " << demo << endl;
            cout << "Копія: " << copy << endl;
}

        else if (choice == 6) {
            if (schedule.getCount() < 1) {
                cout << "Додайте хоча б одне заняття!" << endl;
                continue;
            }
            Classes demo = *schedule.begin();

            Student* stud_ptr = new Classes(demo);
            Teacher* teach_ptr = new Classes(demo);
            Classes* classes_ptr = new Classes(demo);

            string msg;
            cout << "Введіть повідомлення для студента: ";
            cin.ignore();
            getline(cin, msg);
            stud_ptr->operator()(msg);

            cout << "Введіть повідомлення для викладача: ";
            getline(cin, msg);
            teach_ptr->operator()(msg);


            cout << "Classes* operator(): ";
            classes_ptr->operator()();

            delete stud_ptr;
            delete teach_ptr;
            delete classes_ptr;
        }
        else if (choice == 7) {
            if (schedule.getCount() >= 2) {
                cout << "Розклад переповнено! Можна лише 2 заняття." << endl;
                continue;
            }
            Classes temp;
            cout << "Введіть дані заняття через оператор >>" << endl;
            cin.ignore();
            cin >> temp;
            cout << "Введене заняття через оператор << :" << endl;
            cout << temp << endl;
            schedule.addLesson(temp);
        }



        else if (choice == 8) {
            cout << "Вихід." << endl;
            break;
        }
        else {
            cout << "Некоректний вибір. Повторіть спробу." << endl;
        }
    }
    return 0;
}