// =====================================================================
//  C++ REFRESHER  -  explanations + exercises in one file
// =====================================================================
// How to use it:
//   1. Read the explanation box of a step.
//   2. Read the EXAMPLE (it already works).
//   3. Type your answer in the TODO. Don't paste, type.
//   4. Run:  g++ -std=c++17 -Wall refresher.cpp -o refresher && ./refresher
// You get PASS / FAIL for each step. Steps are independent: do them in any
// order, and a FAIL in one never blocks the others. Goal: 10/10 PASS.
// =====================================================================
#include <iostream>
#include <memory>
#include <string>
using namespace std;

// ---------------------------------------------------------------------
// STEP 1: FUNCTIONS
// A function takes inputs (parameters) and gives back one output (return).
// The type before the name is what it returns: int, bool, string, void (nothing).
// ---------------------------------------------------------------------
// EXAMPLE
int doubleIt(int n) { return n * 2; }

// TODO: return a + b
int add(int a, int b) {
    return 0;
}

// ---------------------------------------------------------------------
// STEP 2: POINTERS
// Every variable lives at an address in memory. A pointer is a variable
// that stores an ADDRESS instead of a normal value.
//     int x = 5;
//     int* p = &x;   // &x = "address of x". p now points at x.
//     *p             // "the value at that address" (this is called dereferencing)
//     *p = 9;        // changes x itself, because p leads to x
//
// Why functions use them: C++ passes copies by default. If you want a
// function to change the caller's variable, give it the address.
// Careful: *p + 1 is "value plus 1". p + 1 (no star) moves the ADDRESS.
// Interview question: "What's a null pointer / dangling pointer?"
//   null = points at nothing (nullptr). dangling = points at memory that was freed.
// ---------------------------------------------------------------------
// EXAMPLE
void setTo100(int* p) { *p = 100; }

// TODO: add 1 to the value p points at (hint: look at the example, use *p on both sides)
void addOne(int* p) {
}

// ---------------------------------------------------------------------
// STEP 3: REFERENCES
// A reference is a second NAME for an existing variable. No address, no star:
//     int x = 5;
//     int& r = x;   // r and x are the same variable
//     r = 9;        // x is now 9
// Pointer vs reference (top interview question):
//   - reference can't be null and can't be re-aimed at another variable
//   - pointer can be null and can be re-aimed (p = &other)
//   - use a reference when you always have a real variable, a pointer when it might be missing
// The & after the type (int&) means "reference". Inside the function just write r.
// ---------------------------------------------------------------------
// EXAMPLE
void setTo100Ref(int& r) { r = 100; }

// TODO: add 1 to r
void addOneRef(int& r) {
}

// ---------------------------------------------------------------------
// STEP 4: SWAP  (pointer version vs reference version)
// Swapping needs a temp so you don't overwrite a value before saving it:
//     temp = a;   a = b;   b = temp;
// ---------------------------------------------------------------------
// EXAMPLE: reference version. The parameters ARE the caller's variables.
void swapRef(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// TODO: same thing with pointers. Now a and b are addresses, so use *a and *b.
void swapPtr(int* a, int* b) {
}

// ---------------------------------------------------------------------
// STEP 5: const
// const means "this can't be changed" and the compiler enforces it.
// const string& s = pass by reference (no copy, fast) + read-only (safe).
// It's the standard way to pass big objects (strings, vectors) you only read.
// Interview line: "I pass by const reference to avoid copies."
// ---------------------------------------------------------------------
// EXAMPLE
int lengthOf(const string& s) { return s.size(); }

// TODO: return true if s has no characters (hint: s.empty())
bool isEmpty(const string& s) {
    return false;
}

// ---------------------------------------------------------------------
// STEP 6: const WITH POINTERS  (read it right-to-left)
//     const int* p1   "p1 is a pointer to a const int"  -> can't change the value via p1
//     int* const p2   "p2 is a const pointer to an int"  -> can't re-aim p2, CAN change the value
// A quick trick: whatever is to the LEFT of the const is what's frozen.
// ---------------------------------------------------------------------
// TODO: uncomment and type these 3 lines (remove the // at the start), then run
int constDemo() {
    int x = 1;
    // const int* p1 = &x;
    // int* const p2 = &x;
    // *p2 = 99;
    return x;   // should be 99
}

// ---------------------------------------------------------------------
// STEP 7: static
// Normal local variables are recreated on every call. A static local is
// created ONCE and remembers its value between calls.
// (Also: static at file level = private to that file; static in a class =
//  shared by all objects. Those are common interview questions.)
// ---------------------------------------------------------------------
// EXAMPLE: returns 1, then 2, then 3, ...
int counter() {
    static int n = 0;   // this line only runs the first time
    n = n + 1;
    return n;
}

// TODO: return 10, then 20, then 30, ...
int tens() {
    return 0;
}

// ---------------------------------------------------------------------
// STEP 8: STACK vs HEAP  (new / delete)
//   Stack: normal variables. Automatic, fast, freed when the function ends. Small.
//   Heap : memory you request with new. It lives until YOU delete it. Big.
//     int* p = new int(5);   // allocate on heap, p holds its address
//     delete p;              // give it back (forget this = memory leak)
// Use the heap when something must outlive the function that made it.
// Embedded systems (your Thales role!) often avoid the heap: it can be slow,
// fragment memory, and it isn't predictable in timing.
// ---------------------------------------------------------------------
// EXAMPLE: the caller must delete what this returns
int* makeFive() { return new int(5); }

// TODO: create an int holding v on the heap and return its pointer
int* makeInt(int v) {
    return nullptr;
}

// ---------------------------------------------------------------------
// STEP 9: unique_ptr  (RAII: cleanup is automatic)
// Manual new/delete is easy to get wrong. A smart pointer deletes for you
// when it goes out of scope. This idea is called RAII.
//   unique_ptr = exactly ONE owner. Can't be copied, only moved.
// Prefer make_unique<Type>(args) over writing new yourself.
// ---------------------------------------------------------------------
// EXAMPLE: no delete needed anywhere
unique_ptr<int> makeUniqueFive() { return make_unique<int>(5); }

// TODO: return a unique_ptr holding v
unique_ptr<int> makeUnique(int v) {
    return nullptr;
}

// ---------------------------------------------------------------------
// STEP 10: shared_ptr  (several owners)
// shared_ptr keeps a counter of how many owners exist. Memory is freed when
// the last owner goes away. use_count() tells you the number of owners.
//   auto a = make_shared<int>(7);   // count = 1
//   auto b = a;                     // count = 2 (copy = another owner)
// Rule of thumb: unique_ptr by default, shared_ptr only when ownership is truly shared.
// weak_ptr = a non-owning view; it prevents two objects keeping each other alive forever.
// ---------------------------------------------------------------------
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
