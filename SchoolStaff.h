//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_SCHOOLSTAFF_H
#define OOP_SCHOOLSTAFF_H
#pragma once

#pragma once
#include <vector>
#include "Person.h"

class SchoolStaff {
private:
    std::vector<Person*> staffMembers;  // Vector of pointers to Person for polymorphic behavior

public:
    SchoolStaff();
    ~SchoolStaff();
    void addStaffMember(Person* p);  // Add a Person to the collection
    void displayAll() const;  // Display descriptions for all staff members
};


#endif //OOP_SCHOOLSTAFF_H
