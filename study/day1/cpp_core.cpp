// Day 1 - C++ core. Fill in every TODO, then run:
//   g++ -std=c++17 -Wall cpp_core.cpp -o cpp_core && ./cpp_core
// Every assert must pass. Type the code yourself, don't paste.
#include <cassert>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

// 1. Swap two ints using REFERENCES.
void swapRef(int& a, int& b) {
    // TODO
}

// 2. Swap two ints using POINTERS.
void swapPtr(int* a, int* b) {
    // TODO
}

// 3. Return the length of a string WITHOUT copying it and WITHOUT allowing modification.
//    (Fix the parameter type.)
size_t len(string s) {
    return s.size();
}

// 4. Return how many times this function has been called (use a static local).
int callCount() {
    // TODO
    return 0;
}

// 5. Allocate an int on the HEAP with value v and return the raw pointer.
//    (The caller will delete it.)
int* makeOnHeap(int v) {
    // TODO
    return nullptr;
}

// 6. Same as 5, but return a unique_ptr so nobody has to call delete.
unique_ptr<int> makeUnique(int v) {
    // TODO
    return nullptr;
}

// 7. Make sharedA and sharedB own the same int, then check use_count() == 2.
void sharedDemo() {
    // TODO: create sharedA with make_shared<int>(7), copy it into sharedB
    // then: assert(sharedA.use_count() == 2);
}

// 8. Declare a "pointer to const int" p1 and a "const pointer to int" p2 (both point at x).
//    Then make p2 change x to 99. (p1 must NOT be able to change x - don't write that line.)
void constDemo() {
    int x = 1;
    // TODO: const int* p1 = ...
    // TODO: int* const p2 = ...
    // TODO: *p2 = 99;
    assert(x == 99);
}

int main() {
    int a = 1, b = 2;
    swapRef(a, b);
    assert(a == 2 && b == 1);
    swapPtr(&a, &b);
    assert(a == 1 && b == 2);

    assert(len("hello") == 5);

    callCount(); callCount();
    assert(callCount() == 3);

    int* h = makeOnHeap(42);
    assert(h != nullptr && *h == 42);
    delete h;

    auto u = makeUnique(5);
    assert(u && *u == 5);

    sharedDemo();
    constDemo();

    cout << "All Day 1 C++ exercises passed!\n";
}
