#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>


class Person{
    public:
        Person();
        Person(std::string fName, std::string lName);
        std::string getName();
        
    private:
        std::string firstName;
        std::string lastName;
};

#endif
