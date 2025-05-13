#include "student.h"
#include "assignment_manager.h"
#include <iostream>
#include <fstream>

Student::Student(const std::string& firstName, const std::string& lastName, int id, const std::string& password)
    : User(firstName, lastName, id, password) {}

void Student::submitAssignment(int assignmentId, const std::string& answer) {
    AssignmentManager::submitAssignment(assignmentId, getId(), answer);
    std::cout << "Assignment " << assignmentId << " submitted for student ID " << getId() << std::endl;
}

void Student::viewGrades() const {
    std::ifstream file("../grades.txt");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open grades.txt for reading!" << std::endl;
        return;
    }

    int assignmentId, studentId, grade;
    bool found = false;

    while (file >> assignmentId >> studentId >> grade) {
        if (studentId == getId()) {
            std::cout << "Assignment " << assignmentId << ": Grade " << grade << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No grades found for student ID " << getId() << std::endl;
    }

    file.close();
}

std::string Student::getRole() const {
    return "Student";
}