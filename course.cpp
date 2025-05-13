#include "course.h"
#include <iostream>

Course::Course(int id, const std::string& name, int teacherId)
    : id(id), name(name), teacherId(teacherId) {}

void Course::enrollStudent(int studentId) {
    enrolledStudents.push_back(studentId);
    std::cout << "Student " << studentId << " enrolled in course " << name << std::endl;
}

int Course::getId() const {
    return id;
}

std::string Course::getName() const {
    return name;
}

int Course::getTeacherId() const {
    return teacherId;
}