#ifndef COURSE_MANAGER_H
#define COURSE_MANAGER_H

#include <string>
#include <vector>
#include "course.h"

class CourseManager {
public:
    static int getNextCourseId();
    static void createCourse(const std::string& name, int teacherId);
    static void enrollStudent(int courseId, int studentId);
    static std::vector<Course> loadCourses();
};

#endif