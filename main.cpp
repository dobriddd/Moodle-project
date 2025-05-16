#include <iostream>
#include "auth.h"
#include "user_manager.h"
#include "message_manager.h"
#include "course_manager.h"
#include "assignment_manager.h"

void showAdminMenu() {
    std::cout << "1. Create User\n";
    std::cout << "2. View Inbox\n";
    std::cout << "3. Send Message\n";
}

void showTeacherMenu() {
    std::cout << "1. Create Course\n";
    std::cout << "2. Grade Assignment\n";
    std::cout << "3. Enroll Student\n";
    std::cout << "4. Create Assignment\n";
    std::cout << "5. Send Message\n";
    std::cout << "6. View inbox\n";
}

void showStudentMenu() {
    std::cout << "1. Submit Assignment\n";
    std::cout << "2. View Grades\n";
    std::cout << "3. Send Message\n";
    std::cout << "4. View inbox\n";
}

int main() {
    std::string id, password;
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    std::cin >> password;

    User* user = Auth::login(id, password);
    if (user == nullptr) {
        std::cout << "Login failed!" << std::endl;
        return 1;
    }

    std::cout << "Logged in as: " << user->getRole() << std::endl;

    if (user->getRole() == "Administrator") {
        showAdminMenu();
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::string fname, lname, pwd, role;
            int uid;
            std::cout << "First name: ";
            std::cin >> fname;
            std::cout << "Last name: ";
            std::cin >> lname;
            std::cout << "ID: ";
            std::cin >> uid;
            std::cout << "Password: ";
            std::cin >> pwd;
            std::cout << "Role (Teacher/Student): ";
            std::cin >> role;
            UserManager::addUser(fname, lname, uid, pwd, role);
        } else if (choice == 2) {
            user->viewInbox();
        } else if (choice == 3) {
            size_t senderId = user->getId();
            size_t recipientId;
            std::string content;
            std::cout << "Enter recipient ID: ";
            std::cin >> recipientId;
            std::cin.ignore();
            std::cout << "Enter message content: ";
            std::getline(std::cin, content);
            user->sendMessage(recipientId, content);
        }
    } else if (user->getRole() == "Teacher") {
        showTeacherMenu();
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::string courseName;
            std::cout << "Course name: ";
            std::cin >> courseName;
            dynamic_cast<Teacher*>(user)->createCourse(courseName);
        } else if (choice == 2) {
            int assignmentId, studentId, grade;
            std::cout << "Assignment ID: ";
            std::cin >> assignmentId;
            std::cout << "Student ID: ";
            std::cin >> studentId;
            std::cout << "Grade: ";
            std::cin >> grade;
            dynamic_cast<Teacher*>(user)->gradeAssignment(studentId, assignmentId, grade);
        } else if (choice == 3) {
            int courseId, studentId;
            std::cout << "Course ID: ";
            std::cin >> courseId;
            std::cout << "Student ID: ";
            std::cin >> studentId;
            dynamic_cast<Teacher*>(user)->enrollStudent(courseId, studentId);
        } else if (choice == 4) {
            int courseId;
            std::string description;
            std::cout << "Course ID: ";
            std::cin >> courseId;
            std::cout << "Assignment Description: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            dynamic_cast<Teacher*>(user)->createAssignment(courseId, description);
        } else if (choice == 5) {
            size_t senderId = user->getId();
            size_t recipientId;
            std::string content;
            std::cout << "Enter recipient ID: ";
            std::cin >> recipientId;
            std::cin.ignore();
            std::cout << "Enter message content: ";
            std::getline(std::cin, content);
            user->sendMessage(recipientId, content);
        } else if (choice == 6) {
            user->viewInbox();
        }
    } else if (user->getRole() == "Student") {
        showStudentMenu();
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            int assignmentId;
            std::string answer;
            std::cout << "Assignment ID: ";
            std::cin >> assignmentId;
            std::cout << "Answer: ";
            std::cin.ignore();
            std::getline(std::cin, answer);
            dynamic_cast<Student*>(user)->submitAssignment(assignmentId, answer);
        } else if (choice == 2) {
            dynamic_cast<Student*>(user)->viewGrades();
        } else if (choice == 3) {
            size_t senderId = user->getId();
            size_t recipientId;
            std::string content;
            std::cout << "Enter recipient ID: ";
            std::cin >> recipientId;
            std::cin.ignore();
            std::cout << "Enter message content: ";
            std::getline(std::cin, content);
            user->sendMessage(recipientId, content);
        } else if (choice == 4) {
            user->viewInbox();
        }
    }

    delete user;
    return 0;
}