#include "ClassesIterator.h"


// �����������
ClassesIterator::ClassesIterator(Classes* p) : ptr(p) {}

// ����������� ���������
ClassesIterator::ClassesIterator(const ClassesIterator& other) : ptr(other.ptr) {}

// �������� ���������
ClassesIterator& ClassesIterator::operator=(const ClassesIterator& other) {
    if (this != &other) {
        ptr = other.ptr;
    }
    return *this;
}

// �������� ������������
Classes& ClassesIterator::operator*() const {
    return *ptr;
}

// �������� ������� �� ����� �����
Classes* ClassesIterator::operator->() const {
    return ptr;
}

// ���������� ���������
ClassesIterator& ClassesIterator::operator++() {
    ++ptr;
    return *this;
}

// �������� ��������� "�� ����"
bool ClassesIterator::operator!=(const ClassesIterator& other) const {
    return ptr != other.ptr;
}

// �������� ��������� "����"
bool ClassesIterator::operator==(const ClassesIterator& other) const {
    return ptr == other.ptr;
}
