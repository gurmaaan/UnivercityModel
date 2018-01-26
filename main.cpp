#include <iostream>

using namespace std;

#include <vector>

#include "faculty.h"
#include "department.h"
#include "laboratory.h"

int main()
{
    std::vector<Faculty> facs;
    while(true){
        std::cout << "\n0. Exit\n1. Add faculty\n2. Add department\n3. Add library\n4. Add staf\n5. Show faculties\n6. Show departments\n7. Show liboratories\n\nChoose your answer -->  ";
        int ans;
        std::cin >> ans;
        std::cout << std::endl;

        std::string tmp1;
        std::string tmp2;
        bool flag;
        int staf;
        int unit;
        int count;
        switch (ans) {
        case 0:
            std::cout << "Bye)";
            facs.clear();
            return 0;
            break;
        case 1:
            std::cout << "Enter faculty name: ";

            std::cin >> tmp1;
            flag = 1;
            for (const Faculty& fac: facs){
                if (fac.getName() == tmp1)
                    flag = 0;
            }
            if (flag){
                facs.push_back(Faculty(tmp1));
                std::cout << "Added\n\n";
            }
            else
                std::cout << "Already exist :(\n";
            break;
        case 2:
            std::cout << "Enter faculty name: ";
            std::cin >> tmp1;
            flag = 1;
            for (Faculty& fac: facs){
                if (fac.getName() == tmp1){
                    flag = 0;
                    std::cout << "Enter department name: ";
                    std::cin >> tmp1;
                    fac.addDep(tmp1);
                    break;
                }
            }
            if (flag)
                std::cout << "No such faculty :(\n\n";
            break;
        case 3:
            std::cout << "Enter faculty name: ";
            std::cin >> tmp1;
            flag = 1;
            for (Faculty& fac: facs){
                if (fac.getName() == tmp1){
                    flag = 0;
                    std::cout << "Enter department name: ";
                    std::cin >> tmp2;
                    fac.addLab(tmp2);
                    break;
                }
            }
            if (flag)
                std::cout << "No such faculty :(\n\n";
            break;
            break;
        case 4:
            std::cout << "1. Add emploee\n2. Add student\n\nChoose staf -->  ";
            std::cin >> staf;
            if (staf < 1 || staf > 2){
                std::cout << "Wrong answer :(\n\n";
                break;
            }
            std::cout << "Enter name: ";
            std::cin >> tmp1;
            std::cout << "\n1. Add to faculty\n2. Add to department\n3. Add to liboratory\n\nChoose unit -->  ";
            std::cin >> unit;
            std::cout << "Enter faculty name: ";
            std::cin >> tmp2;
            flag = 1;
            if(unit == 1){
                for(Faculty& fac: facs)
                    if(fac.getName() == tmp2){
                        flag = 0;
                        fac.addStaf(tmp1, staf);
                    }
                if (flag)
                    std::cout << "Wrong faculty name :(\n\n";
            }
            else if (unit == 2){
                for(Faculty& fac: facs)
                    if(fac.getName() == tmp2){
                        flag = 0;
                        fac.addStafToDep(tmp1, staf);
                    }
                if (flag)
                    std::cout << "Wrong faculty name :(\n\n";
            }
            else if (unit == 3) {
                for(Faculty& fac: facs)
                    if(fac.getName() == tmp2){
                        flag = 0;
                        fac.addStafToLab(tmp1, staf);
                    }
                if (flag)
                    std::cout << "Wrong faculty name :(\n\n";
            }
            else
                std::cout << "Wrong answer :(\n\n";
            break;
        case 5 :
            count = 1;
            for (const Faculty& fac: facs) {
                std::cout << count++ << ". " << fac.getName() << std::endl;
                fac.showStafs();
            }
            break;
        case 6 :
            count = 1;
            for (const Faculty& fac: facs) {
                std::cout << count++ << ". " << fac.getName() << std::endl;
                fac.showDep();
            }
            break;
        case 7 :
            count = 1;
            for (const Faculty& fac: facs) {
                std::cout << count++ << ". " << fac.getName() << std::endl;
                fac.showLabs();
            }
            break;
        default:
            std::cout << "Wrong answer, try again\n";
            break;
        }

    }
    cout << "Hello World!" << endl;
    return 0;
}
