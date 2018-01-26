#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <vector>

#include "laboratory.h"
#include "men.h"
#include "employee.h"
#include "student.h"

class Department
{
public:
    Department(const std::string& name) : name(name) {}
    std::string getName() const;

    void addLab (const std::string& name) {
        bool flag = 1;
        for (Laboratory lab: labs) {
            if(lab.getName() == name) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            labs.push_back(Laboratory(name));
            std::cout << "Added\n\n";
        }
        else
            std::cout << "Already exist :(\n";

    }

    void addStaf(const std::string& name, int type) {
        if(type == 1)
            stafs.push_back(new Employee(name));
        else
            stafs.push_back(new Student(name));
        std::cout << "\nAdded\n";
    }

    void addStafToLab(const std::string &name, int type) {
        std::cout << "Enter laboratory name: ";
        std::string labName;
        std::cin >> labName;
        int flag = 1;
        for(Laboratory& lab: labs)
            if (lab.getName() == labName){
                flag = 0;
                lab.addStaf(name, type);
            }
        if (flag){
            std::cout << "No such department on this faculty\n";
        }
    }

    void showStafs() const {
        int count = 1;
        for(const Men* staf: stafs)
            std::cout << "      " << count++ << ". " << staf->getDescr() << "\n";
    }

    void showLabs() const {
        int count = 1;
        for(const Laboratory& lab: labs) {
            std::cout << "      " << count++ << ". " << lab.getName() << "\n";
            lab.showStafs();
        }
    }


    ~Department() {
        for(size_t i = 0; i < stafs.size(); ++i)
            delete stafs[i];
    }

private:
    std::vector <Laboratory> labs;
    std::vector <Men*> stafs;
    std::string name;
};

#endif // DEPARTMENT_H
