#ifndef TEACHER_H
#define TEACHER_H

#include "user.h"
#include <string>

class Teacher : public User {
public:
    Teacher(const std::string& firstName, const std::string& lastName, int id, const std::string& password);
    void createCourse(const std::string& courseName);
    void gradeAssignment(int studentId, int assignmentId, int grade);
    void enrollStudent(int courseId, int studentId);
    void createAssignment(int courseId, const std::string& description);
    std::string getRole() const override;
};

#endif