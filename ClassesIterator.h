#pragma once
#include "Classes.h"
#pragma once

// �������� ����� �������
class Classes;

// ����-�������� ��� ������ ������
class ClassesIterator {
private:
    Classes* ptr; // �������� �� �������� �������

public:
    explicit ClassesIterator(Classes* p = nullptr);         // �����������
    ClassesIterator(const ClassesIterator& other);          // ����������� ���������

    ClassesIterator& operator=(const ClassesIterator& other); // �������� ���������

    Classes& operator*() const;         // �������� ������������
    Classes* operator->() const;        // �������� ������� �� ����� ����� 

    ClassesIterator& operator++();      // ���������� ���������
    bool operator!=(const ClassesIterator& other) const; // �������� ���������
    bool operator==(const ClassesIterator& other) const; // �������� �� ������
};
