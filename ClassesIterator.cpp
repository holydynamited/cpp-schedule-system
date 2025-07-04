#include "ClassesIterator.h"


// Конструктор
ClassesIterator::ClassesIterator(Classes* p) : ptr(p) {}

// Конструктор копіювання
ClassesIterator::ClassesIterator(const ClassesIterator& other) : ptr(other.ptr) {}

// Оператор присвоєння
ClassesIterator& ClassesIterator::operator=(const ClassesIterator& other) {
    if (this != &other) {
        ptr = other.ptr;
    }
    return *this;
}

// Оператор розіменування
Classes& ClassesIterator::operator*() const {
    return *ptr;
}

// Оператор доступу до членів класу
Classes* ClassesIterator::operator->() const {
    return ptr;
}

// Префіксний інкремент
ClassesIterator& ClassesIterator::operator++() {
    ++ptr;
    return *this;
}

// Оператор порівняння "не рівно"
bool ClassesIterator::operator!=(const ClassesIterator& other) const {
    return ptr != other.ptr;
}

// Оператор порівняння "рівно"
bool ClassesIterator::operator==(const ClassesIterator& other) const {
    return ptr == other.ptr;
}
