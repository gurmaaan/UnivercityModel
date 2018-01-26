#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <department.h>

class Person
{
public:
    Person();
private:
    int _id;
    QString _name;

    Department _depMembership;
};

#endif // PERSON_H
