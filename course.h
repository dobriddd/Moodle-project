#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

class Course {
private:
    int id;
    std::string name;
    int teacherId;
    std::vector<int> enrolledStudents;

public:
    Course(int id, const std::string& name, int teacherId);

    int getId() const;
    std::string getName() const;
    int getTeacherId() const;

    void enrollStudent(int studentId);
};

#endif