#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include"Classes.h"
#include "ClassesIterator.h"
using namespace std; 
class ClassSchedule {
private:
    Classes lessons[2]; // ����� ������
    int count;            // ������� ������

public:
    ClassSchedule(); // �����������

    void addLesson(const Classes& lesson); // ������ �������
    void print();            
    int getCount() const;
   

    ClassesIterator begin() { return ClassesIterator(lessons); }
    ClassesIterator end() { return ClassesIterator(lessons + count); }

};
