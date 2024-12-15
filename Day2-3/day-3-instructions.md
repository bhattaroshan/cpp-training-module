# Day 3: Overloading Operators, Friend Functions, and Implicit Conversions in C++

## Objective

Build on Day 2 concepts by focusing on:

- **Friend Functions**: Use friend functions to access private members for custom operations, such as addition or stream output.
- **`+` Operator Overloading**: Extend the `Let` class to handle addition of objects with different data types.
- **Overloading `<<` for `std::cout`**: Customize how `Let` objects are printed.
- **Implicit Conversions**: Enable seamless type conversion of `Let` objects to primitive types such as `int` or `double`.
- **Code Organization**: Separate class declarations and definitions into header (`.h`) and implementation (`.cpp`) files to keep the main file clean and modular.

---

## Task

### Enhance the `Let` Class to Support:

1. **Addition with Different Data Types**:
   - Use the `+` operator to add:
     - `int`
     - `double`
     - `const char*`

2. **Implicit Type Conversion**:
   - Enable `Let` objects to be implicitly converted to:
     - `int`
     - `double`

3. **Stream Output**:
   - Overload the `<<` operator using a **friend function** to customize how `Let` objects are displayed.

4. **Length Calculation**:
   - Add a method `length()` that returns:
     - The length of the string if the object holds a `const char*`.
     - The number of digits if the object holds an `int` or `double`.
     - `1` if the object holds a `bool`.

---

## Requirements

The `Let` class should support the following operations:

```cpp
Let a = 42;                     // Implicit constructor
Let b = "Hello";                // Implicit constructor
Let c = a + " world";           // Add int and const char*
Let d = b + 100;                // Add const char* and int
Let e = c + 3.14;               // Add Let and double

std::cout << e << std::endl;    // Overloaded << for output

int n = a;                      // Implicit conversion to int
double x = e;                   // Implicit conversion to double

std::cout << "n: " << n << ", x: " << x << std::endl;

std::cout << e.length() << std::endl; // Length of the stored value
