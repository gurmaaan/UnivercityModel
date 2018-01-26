#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "men.h"

class Employee : public Men
{
public:
    Employee(const std::string& name) : Men(name) {}
    virtual std::string getDescr() const {
        return "Emploee " + name;
    }

   virtual ~Employee(){}
};

#endif // EMPLOYEE_H
