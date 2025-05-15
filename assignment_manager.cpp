#include "assignment_manager.h"
#include <fstream>
#include <iostream>

int AssignmentManager::getNextAssignmentId() {
    int maxId = 0;
    std::ifstream file("../assignments.txt");

    if (file.is_open()) {
        int id, courseId;
        std::string description;
        while (file >> id >> courseId) {
            std::getline(file, description);
            if (id > maxId) {
                maxId = id;
            }
        }
        file.close();
    }

    return maxId + 1;
}

void AssignmentManager::createAssignment(int courseId, const std::string& description) {
    int assignmentId = getNextAssignmentId();
    std::ofstream file("../assignments.txt", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open assignments.txt for writing!" << std::endl;
        return;
    }

    file << assignmentId << " " << courseId << " " << description << std::endl;
    file.close();
    std::cout << "Assignment created with ID " << assignmentId << " for course " << courseId << std::endl;
}

void AssignmentManager::submitAssignment(int assignmentId, int studentId, const std::string& answer) {
    std::ofstream file("../submissions.txt", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open submissions.txt for writing!" << std::endl;
        return;
    }

    file << assignmentId << " " << studentId << " " << answer << std::endl;
    file.close();
    std::cout << "Assignment " << assignmentId << " submitted by student ID " << studentId << std::endl;
}

void AssignmentManager::gradeAssignment(int assignmentId, int studentId, int grade) {
    std::ofstream file("../grades.txt", std::ios::app);
    file << assignmentId << " " << studentId << " " << grade << std::endl;
    file.close();
    std::cout << "Assignment " << assignmentId << " graded for student ID " << studentId << std::endl;
}
