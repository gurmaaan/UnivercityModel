#ifndef STUDENT_H
#define STUDENT_H

#include "men.h"

class Student : public Men
{
public:
    Student(const std::string& name) : Men(name) {}
    virtual std::string getDescr() const {
        return "Student " + name;
    }

    virtual ~Student(){}
};

#endif // STUDENT_H
