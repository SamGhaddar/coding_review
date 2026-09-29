// C++ REFRESHER - everything in one file. Do the steps IN ANY ORDER.
// Each step has an EXAMPLE, then a TODO for you. A failing step never blocks the others.
//
// Run:  g++ -std=c++17 -Wall refresher.cpp -o refresher && ./refresher
// You will see PASS / FAIL for every step. Goal: all PASS. Type the code yourself.
#include <iostream>
#include <memory>
#include <string>
using namespace std;

// ============ STEP 1: functions ============
// EXAMPLE
int doubleIt(int n) { return n * 2; }

// TODO: return a + b
int add(int a, int b) {
    return 0;
}

// ============ STEP 2: pointers ============
// int* p = &x;  -> p holds the ADDRESS of x.   *p  -> the value stored there.
// EXAMPLE
void setTo100(int* p) { *p = 100; }

// TODO: add 1 to the value p points at
void addOne(int* p) {
}

// ============ STEP 3: references ============
// int& r = x;  -> r is another NAME for x. Use r like a normal variable.
// EXAMPLE
void setTo100Ref(int& r) { r = 100; }

// TODO: add 1 to r
void addOneRef(int& r) {
}

// ============ STEP 4: swap ============
// EXAMPLE: swap using a temp variable (references, so the caller's variables change)
void swapRef(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// TODO: do the same with POINTERS (remember * to reach the values)
void swapPtr(int* a, int* b) {
}

// ============ STEP 5: const ============
// const = "I promise not to change this". const& = pass without copying.
// EXAMPLE
int lengthOf(const string& s) { return s.size(); }

// TODO: return true if s has no characters (hint: s.empty())
bool isEmpty(const string& s) {
    return false;
}

// ============ STEP 6: const with pointers ============
// const int* p1 -> can't change the VALUE through p1
// int* const p2 -> can't re-aim p2, but CAN change the value through it
// TODO: fill in the 3 lines, then return x
int constDemo() {
    int x = 1;
    // const int* p1 = &x;        <- type this line
    // int* const p2 = &x;        <- type this line
    // *p2 = 99;                  <- type this line
    return x;   // should be 99
}

// ============ STEP 7: static ============
// A static local keeps its value between calls.
// EXAMPLE: 1, 2, 3, ...
int counter() {
    static int n = 0;
    n = n + 1;
    return n;
}

// TODO: 10, 20, 30, ...
int tens() {
    return 0;
}

// ============ STEP 8: heap (new / delete) ============
// EXAMPLE: caller must delete the result
int* makeFive() { return new int(5); }

// TODO: create an int holding v on the heap and return its pointer
int* makeInt(int v) {
    return nullptr;
}

// ============ STEP 9: unique_ptr (auto-delete) ============
// EXAMPLE: no delete needed, it cleans itself up
unique_ptr<int> makeUniqueFive() { return make_unique<int>(5); }

// TODO: return a unique_ptr holding v
unique_ptr<int> makeUnique(int v) {
    return nullptr;
}

// ============ STEP 10: shared_ptr (shared ownership) ============
// TODO: make sharedA = make_shared<int>(7); then sharedB = sharedA; return sharedA.use_count()
int sharedCount() {
    return 0;   // should be 2
}

// ---------------- test runner (don't edit below) ----------------
int passed = 0, total = 0;
void check(const string& name, bool ok) {
    total++;
    if (ok) passed++;
    cout << (ok ? "PASS  " : "FAIL  ") << name << "\n";
}

int main() {
    check("1 add", add(2, 3) == 5);

    int a = 1; addOne(&a);
    check("2 pointers: addOne", a == 2);

    int b = 1; addOneRef(b);
    check("3 references: addOneRef", b == 2);

    int x = 1, y = 2; swapPtr(&x, &y);
    check("4 swapPtr", x == 2 && y == 1);

    check("5 const&: isEmpty", isEmpty("") && !isEmpty("hi"));

    check("6 const pointers", constDemo() == 99);

    tens(); tens();
    check("7 static: tens", tens() == 30);

    int* p = makeInt(42);
    check("8 heap: makeInt", p != nullptr && *p == 42);
    delete p;

    auto u = makeUnique(5);
    check("9 unique_ptr", u != nullptr && *u == 5);

    check("10 shared_ptr", sharedCount() == 2);

    cout << "\n" << passed << "/" << total << " passed\n";
}
