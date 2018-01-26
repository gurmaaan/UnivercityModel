#ifndef LABORATORY_H
#define LABORATORY_H

#include <vector>

#include "men.h"
#include "employee.h"
#include "student.h"

class Laboratory
{
public:
    Laboratory(const std::string& name) : name(name) {}
    std::string getName() const;

    void addStaf(const std::string& name, int type) {
        if(type == 1)
            stafs.push_back(new Employee(name));
        else
            stafs.push_back(new Student(name));
        std::cout << "\nAdded\n";
    }

    void showStafs() const {
        int count = 1;
        for(const Men* staf: stafs)
            std::cout << "          " << count++ << ". " << staf->getDescr() << "\n";
    }

    ~Laboratory() {
        for(size_t i = 0; i < stafs.size(); ++i)
            delete stafs[i];
    }

private:
    std::vector<Men*> stafs;
    std::string name;
};

#endif // LABORATORY_H
