#ifndef ASSIGNMENT_MANAGER_H
#define ASSIGNMENT_MANAGER_H

#include <string>

class AssignmentManager {
public:
    static int getNextAssignmentId();
    static void createAssignment(int courseId, const std::string& description);
    static void submitAssignment(int assignmentId, int studentId, const std::string& answer);
    static void gradeAssignment(int assignmentId, int studentId, int grade);
    static void viewGrades(int studentId);
};

#endif