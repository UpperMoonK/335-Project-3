#include "MaxHeap.h"
#include "Customer.h"
#include <iostream>
#include <vector>
#include <cstdlib>   // rand()
#include <ctime>     // time()
#include <algorithm> // sort()

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    MaxHeap<Customer> customerHeap;
    std::vector<Customer> history;

    // 7. Create and insert random customers into MaxHeap
    const int NUM_CUSTOMERS = 10;
    for (int i = 1; i <= NUM_CUSTOMERS; ++i) {
        Customer c("Customer" + std::to_string(i));
        customerHeap.insert(c);
    }

    // 8. Service customers and store in history
    while (customerHeap.getSize() > 0) {
        Customer served = customerHeap.deleteMax(); // Remove highest priority customer
        served.setServiceTime();                    // Update their service time
        history.push_back(served);                  // Store in history
    }

    // 9. Sort history based on service time (ascending)
    std::sort(history.begin(), history.end(), [](const Customer& a, const Customer& b) {
        return a.service_time_ < b.service_time_;
    });

    // Print sorted history
    std::cout << "=== Customer Service History (Sorted by Service Time) ===\n";
    for (const Customer& c : history) {
        c.print();
    }

    return 0;
}