#ifndef MEN_H
#define MEN_H

#include <iostream>

class Men
{
public:
    Men(const std::string& name) : name(name) {}
    virtual std::string getDescr() const = 0;

    virtual ~Men() {}
protected:
    std::string name;
};

#endif // MEN_H
