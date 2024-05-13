#include "SchoolStaff.h"
#include <iostream>

SchoolStaff::SchoolStaff() {}

SchoolStaff::~SchoolStaff() {
    for (auto p : staffMembers) {
        delete p;  // Properly delete all Person instances
    }
}

void SchoolStaff::addStaffMember(Person* p) {
    staffMembers.push_back(p);  // Add a Person to the collection
}

void SchoolStaff::displayAll() const {
    for (const auto& p : staffMembers) {
        std::cout << p->getDescription() << std::endl;  // Polymorphic call
    }
}
