#pragma once
#include "Classes.h"
#pragma once

// Прототип класу заняття
class Classes;

// Клас-ітератор для масиву занять
class ClassesIterator {
private:
    Classes* ptr; // Вказівник на поточний елемент

public:
    explicit ClassesIterator(Classes* p = nullptr);         // Конструктор
    ClassesIterator(const ClassesIterator& other);          // Конструктор копіювання

    ClassesIterator& operator=(const ClassesIterator& other); // Оператор присвоєння

    Classes& operator*() const;         // Оператор розіменування
    Classes* operator->() const;        // Оператор доступу до членів класу 

    ClassesIterator& operator++();      // Префіксний інкремент
    bool operator!=(const ClassesIterator& other) const; // Оператор порівняння
    bool operator==(const ClassesIterator& other) const; // Оператор на рівність
};
