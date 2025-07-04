#include "ClassSchedule.h"
#include "ClassesIterator.h"

using namespace std;

//Конструктор за замовчуванням
ClassSchedule::ClassSchedule() {
    count = 0;
}

//Додаємо заняття
void ClassSchedule::addLesson(const Classes& lesson) {
    if (count < 2) {
        lessons[count] = lesson;
        count++;
    }
    else {
        cout << "Розклад переповнено!" << endl;
    }
}

//Вивід розкладу через ітератор
void ClassSchedule::print() {
    int idx = 1;
    for (ClassesIterator it = begin(); it != end(); ++it) {
        cout << "Заняття " << (idx++) << ":" << endl;
        cout << *it << endl;
    }
}
int ClassSchedule::getCount() const {
    return count;
}
