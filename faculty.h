#ifndef FACULTY_H
#define FACULTY_H

#include <vector>

#include "department.h"
#include "men.h"

class Faculty
{
public:
    Faculty(const std::string& name) : name(name) { }

    std::string getName() const;

    void addDep (const std::string& name) {
        bool flag = 1;
        for (const Department& dep: deps)
            if (dep.getName() == name) {
                flag = 0;
                break;
            }
        if (flag){
            deps.push_back(Department(name));
            std::cout << "Added\n\n";
        }
        else
            std::cout << "Already exist :(\n";
    }

    void addLab (const std::string& name) {
        bool flag = 1;
        for (Department& dep: deps)
            if (dep.getName() == name) {
                flag = 0;
                std::cout << "Enter laboratory name: ";
                std::string labName;
                std::cin >> labName;
                dep.addLab(labName);
                break;
            }
        if (flag){
            std::cout << "\nNo such department on this faculty\n";
        }
    }

    void addStaf(const std::string& name, int type) {
        if(type == 1)
            stafs.push_back(new Employee(name));
        else
            stafs.push_back(new Student(name));
        std::cout << "\nAdded\n";
    }

    void addStafToDep(const std::string &name, int type) {
        std::cout << "Enter department name: ";
        std::string depName;
        std::cin >> depName;
        int flag = 1;
        for(Department& dep: deps)
            if (dep.getName() == depName){
                flag = 0;
                dep.addStaf(name, type);
            }
        if (flag){
            std::cout << "\nNo such department on this faculty\n";
        }
    }

    void addStafToLab(const std::string &name, int type) {
        std::cout << "Enter department name: ";
        std::string depName;
        std::cin >> depName;
        int flag = 1;
        for(Department& dep: deps)
            if (dep.getName() == depName){
                flag = 0;
                dep.addStafToLab(name, type);
            }
        if (flag){
            std::cout << "\nNo such department on this faculty\n";
        }
    }

    std::vector<Department> getDeps() const;



    void showStafs() const {
        int count = 1;
        for(size_t i = 0; i < stafs.size(); ++i){
            std::string name = stafs[i]->getDescr();
            std::cout << "  " << count++ << ". " << name << "\n";
        }
    }

    void showDep() const {
        int count = 1;
        for(const Department& dep: deps) {
            std::cout << "  " << count++ << ". " << dep.getName() << "\n";
            dep.showStafs();
        }
    }

    void showLabs() const {
        int count = 1;
        for(const Department& dep: deps) {
            std::cout << "  " << count++ << ". " << dep.getName() << "\n";
            dep.showLabs();
        }
    }

    ~Faculty() {
        for(size_t i = 0; i < stafs.size(); ++i)
                delete stafs[i];
    }

private:
    std::vector<Department> deps;
    std::vector<Men*> stafs;
    std::string name;
};

#endif // FACULTY_H
