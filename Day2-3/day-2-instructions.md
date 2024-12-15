# Day 2: Introduction to Constructors, Assignment Operator, Destructors, and Rule of Three

## Objective

Gain hands-on experience with the following concepts:

- **Constructors**: Parameterized and Copy Constructor.
- **Implicit Constructor Behavior**: Understand how constructors are implicitly invoked during object initialization.
- **Assignment Operator Overloading**: Overload assignment operator for safe object assignment.
- **Destructors**: Ensure proper cleanup of resources.
- **The Rule of Three**: Learn how to manage resource ownership and implement safe copying, assignment, and cleanup in C++.

---

## Task

### Create a class `Let` with the following functionality:

1. **Implicit Assignments**:
   - The class should support implicit assignments of the following types:
     - `int`
     - `double`
     - `bool`
     - `const char*`

2. **Implicit Constructor Behavior**:
   - Explore and demonstrate how constructors are implicitly invoked during object initialization.

3. **Implement the Rule of Three**:
   - **Destructor**: Ensures proper cleanup of dynamically allocated memory.
   - **Copy Constructor**: Handles deep copying of objects to avoid shallow copy issues.
   - **Assignment Operator Overloading**: Ensures safe assignment between objects.

4. **Operator Overloading**:
   - Overload the `+` operator to support the following:
     - Adding an `int` or `const char*` to a `Let` object.

---

## Requirements

The `Let` class should support the following operations:

```cpp
Let var1 = 42;               // Implicit constructor for int
Let var2 = 3.14;             // Implicit constructor for double
Let var3 = "Hello";          // Implicit constructor for const char*
Let var4 = false;            // Implicit constructor for bool
Let var5 = var3;             // Copy Constructor
var2 = var1;                 // Assignment operator overload
Let result = var3 + var1;    // + Operator Overload
Let result2 = result + " World!";  // + Operator Overload with const char*
