#include "course_manager.h"
#include <fstream>
#include <iostream>

int CourseManager::getNextCourseId() {
    int maxId = 0;
    std::ifstream file("../courses.txt");

    if (file.is_open()) {
        int id;
        std::string name;
        int teacherId;
        while (file >> id >> name >> teacherId) {
            if (id > maxId) {
                maxId = id;
            }
        }
        file.close();
    }

    return maxId + 1;
}

void CourseManager::createCourse(const std::string& name, int teacherId) {
    int courseId = getNextCourseId();
    std::ofstream file("../courses.txt", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open courses.txt for writing!" << std::endl;
        return;
    }

    file << courseId << " " << name << " " << teacherId << std::endl;
    file.close();
    std::cout << "Course created with ID " << courseId << ": " << name << std::endl;
}

void CourseManager::enrollStudent(int courseId, int studentId) {
    std::ofstream file("../enrollments.txt", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open enrollments.txt for writing!" << std::endl;
        return;
    }

    file << courseId << " " << studentId << std::endl;
    file.close();
    std::cout << "Student " << studentId << " enrolled in course ID " << courseId << std::endl;
}