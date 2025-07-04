#include "ClassSchedule.h"
#include "ClassesIterator.h"

using namespace std;

//����������� �� �������������
ClassSchedule::ClassSchedule() {
    count = 0;
}

//������ �������
void ClassSchedule::addLesson(const Classes& lesson) {
    if (count < 2) {
        lessons[count] = lesson;
        count++;
    }
    else {
        cout << "������� �����������!" << endl;
    }
}

//���� �������� ����� ��������
void ClassSchedule::print() {
    int idx = 1;
    for (ClassesIterator it = begin(); it != end(); ++it) {
        cout << "������� " << (idx++) << ":" << endl;
        cout << *it << endl;
    }
}
int ClassSchedule::getCount() const {
    return count;
}
