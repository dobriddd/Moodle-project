#include "teacher.h"
#include "course_manager.h"
#include "assignment_manager.h"
#include <iostream>

Teacher::Teacher(const std::string& firstName, const std::string& lastName, int id, const std::string& password)
    : User(firstName, lastName, id, password) {}

void Teacher::createCourse(const std::string& courseName) {
    CourseManager::createCourse(courseName, getId());
    std::cout << "Course created: " << courseName << std::endl;
}

void Teacher::gradeAssignment(int studentId, int assignmentId, int grade) {
    AssignmentManager::gradeAssignment(assignmentId, studentId, grade);
    std::cout << "Assignment " << assignmentId << " graded for student ID " << studentId << std::endl;
}

void Teacher::enrollStudent(int courseId, int studentId) {
    CourseManager::enrollStudent(courseId, studentId);
    std::cout << "Student " << studentId << " enrolled in course ID " << courseId << std::endl;
}

void Teacher::createAssignment(int courseId, const std::string& description) {
    AssignmentManager::createAssignment(courseId, description);
    std::cout << "Assignment created for course ID " << courseId << ": " << description << std::endl;
}

std::string Teacher::getRole() const {
    return "Teacher";
}
