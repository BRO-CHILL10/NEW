#include <iostream>
using namespace std;

class body {
public:
    int age;
    int id;

    body(int a = 0, int i = 0) : age(a), id(i) {}

    // Prefix -- (Decrement)
    body& operator--() {
        --age;
        --id;
        return *this;  // Modify directly and return reference
    }

    // Postfix -- (Decrement)
    body operator--(int) {
        body temp = *this;  // Save the original object
        age--;
        id--;
        return temp;  // Return the original object (before change)
    }

    // Prefix ++ (Increment)
    body& operator++() {
        ++age;
        ++id;
        return *this;  // Modify directly and return reference
    }

    // Postfix ++ (Increment)
    body operator++(int) {
        body temp = *this;  // Save the original object
        age++;
        id++;
        return temp;  // Return the original object (before change)
    }

    void display() {
        cout << "Age: " << age << ", ID: " << id << endl;
    }
};

int main() {
    body b1(25, 1001),b2;
    b1.display();  // Age: 25, ID: 1001

    --b1;
    b1.display();  // Age: 24, ID: 1000

    b1++;
    b1.display();  // Age: 25, ID: 1001

     b2 = b1--;
    b2.display();  // Age: 25, ID: 1001 (original)
    b1.display();  // Age: 24, ID: 1000 (after decrement)

    return 0;
}

