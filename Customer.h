/* Name: Khalid Young
Date: 07/06/2025
This is the documentation and implementation for the MaxHeap class, as well as the Customer struct and its data members. */

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <cstdlib>
#include <iostream>

struct Customer{
    std::string name_;
    int service_time_;
    int priority_level_;
    
    Customer() : name_(""), service_time_(0), priority_level_(0) {
        setPriorityLevel();
    }

    Customer(std::string n) : name_(n) {
        setPriorityLevel();
    }

    void setPriorityLevel() {
        priority_level_ = rand() % 101;  // [0, 100]
    }

    void setServiceTime() {
        service_time_ = rand() % 61;     // [0, 60]
    }

    // For MaxHeap: compare based on priority level
    bool operator>(const Customer& other) const {
        return this->priority_level_ > other.priority_level_;
    }

    bool operator<(const Customer& other) const {
        return this->priority_level_ < other.priority_level_;
    }

    // Optional: display function
    void print() const {
        std::cout << "Name: " << name_
                  << ", Priority: " << priority_level_
                  << ", Service Time: " << service_time_ << "\n";
    }
};
#endif