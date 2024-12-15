# Day 4: Mastering Linked Lists and Memory Management with LinkedList

## Learning Objectives

### Working with Linked Lists:
- Understand how to use linked lists to dynamically store `Variant` objects.
- Learn how to create a `Node` structure to hold `Variant` objects.
- Implement an `insert` method to insert `Variant` objects into the linked list.

### Using Initializer Lists:
- Learn how to use initializer lists in C++ to pass multiple `Variant` objects to a class constructor.
- Understand how to manage different types of data passed through the initializer list.

### Memory Management:
- Understand how to manage dynamic memory safely (e.g., using `new` and `delete`).
- Learn how to use destructors to properly clean up memory when objects go out of scope for linked lists.

---

## Task

### 1. **Implement a Variant Class**

Create a class `Variant` that can hold one of the following types:

- `int`
- `double`
- `const char*` (string)

Use an **enum** `DataType` to track which type is currently held in the `Variant`.

- Provide appropriate constructors for each data type.
- Include a destructor to handle dynamic memory for strings (`const char*`).
- Add a method `getType()` that returns the current type of the value.

### 2. **Build a Linked List to Store Variant Objects**

Define a `Node` structure that contains:

- A `Variant` object.
- A pointer to the next node (`Node* next`).

Create a `VariantList` class that will manage a linked list of `Variant` objects. Implement the following methods:

- **`insert()`**: Adds new `Variant` objects to the list.
- **`~VariantList()`**: Destructor that deletes all nodes in the linked list to avoid memory leaks.

### 3. **Use Initializer List in Constructor (For Let Class)**

Create a class `Let` that accepts a list of `Variant` objects using an **initializer list**.

- The constructor should store all the passed `Variant` objects.
- Print out the values stored in the `Let` object.

---

## Example Usage:

```cpp
Variant v1 = 42;              // Variant holding int
Variant v2 = 3.14;            // Variant holding double
Variant v3 = "Hello";         // Variant holding const char*

VariantList list;
list.insert(v1);
list.insert(v2);
list.insert(v3);

Let let = {v1, v2, v3};       // Initializer list for Let class
let.printValues();             // Print values stored in Let object
