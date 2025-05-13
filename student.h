#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include <string>

class Student : public User {
public:
    Student(const std::string& firstName, const std::string& lastName, int id, const std::string& password);
    void submitAssignment(int courseId, const std::string& answer);
    void viewGrades() const;
    std::string getRole() const override;
};

#endif