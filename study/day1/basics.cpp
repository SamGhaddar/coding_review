// Day 1 REFRESHER - start here. Each step: read the EXAMPLE, then do the TODO right below it.
// Run:  g++ -std=c++17 -Wall basics.cpp -o basics && ./basics
// The program stops at the first step you haven't finished. Do them in order.
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

// ---------- STEP 1: functions ----------
// EXAMPLE: a function that returns double a number.
int doubleIt(int n) { return n * 2; }

// TODO: write a function that returns a + b.
int add(int a, int b) {
    return 0;  // change this line
}

// ---------- STEP 2: pointers ----------
// A pointer holds the ADDRESS of a variable. &x = "address of x", *p = "the value at p".
// EXAMPLE: set the value at a pointer to 100.
void setTo100(int* p) { *p = 100; }

// TODO: use the pointer to add 1 to the value it points at.
void addOne(int* p) {
    // your code here
}

// ---------- STEP 3: references ----------
// A reference is another NAME for the same variable. No & or * needed when you use it.
// EXAMPLE: set the variable to 100.
void setTo100Ref(int& r) { r = 100; }

// TODO: use the reference to add 1 to the variable.
void addOneRef(int& r) {
    // your code here
}

// ---------- STEP 4: const ----------
// const = "promise not to change it". Pass big things as const& to avoid a copy.
// EXAMPLE:
int lengthOf(const string& s) { return s.size(); }

// TODO: return true if the string is empty. (Use const string&, and s.empty() or s.size()).
bool isEmpty(/* fix the parameter */) {
    return false;  // change this line
}

// ---------- STEP 5: static ----------
// A static local keeps its value between calls.
// EXAMPLE: returns 1, then 2, then 3, ...
int counter() {
    static int n = 0;
    n = n + 1;
    return n;
}

// TODO: same idea, but return 10, then 20, then 30, ... (add 10 each call).
int tens() {
    return 0;  // change this
}

// ---------- STEP 6: heap (new / delete) ----------
// EXAMPLE: make an int on the heap. The caller must delete it.
int* makeFive() { return new int(5); }

// TODO: make an int on the heap holding the value v and return it.
int* makeInt(int v) {
    return nullptr;  // change this
}

int main() {
    assert(add(2, 3) == 5);                        cout << "Step 1 ok\n";

    int a = 1; addOne(&a);
    assert(a == 2);                                cout << "Step 2 ok\n";

    int b = 1; addOneRef(b);
    assert(b == 2);                                cout << "Step 3 ok\n";

    assert(isEmpty("") && !isEmpty("hi"));         cout << "Step 4 ok\n";

    tens(); tens();
    assert(tens() == 30);                          cout << "Step 5 ok\n";

    int* p = makeInt(42);
    assert(p != nullptr && *p == 42);
    delete p;                                      cout << "Step 6 ok\n";

    cout << "Refresher done! Now try cpp_core.cpp\n";
}
