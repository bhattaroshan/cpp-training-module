# Day 5: Implementing RAII and Custom Smart Pointers in C++

## Learning Objectives

### RAII (Resource Acquisition Is Initialization):
- Understand the RAII (Resource Acquisition Is Initialization) paradigm and its importance in managing resources.
- Learn how to tie resource management to the lifetime of an object.

### Custom Smart Pointer Implementation:
- Learn how to design and implement custom `shared_ptr` and `unique_ptr` classes.
- Implement features like constructors, destructors, and copy/move semantics.

### Understanding Smart Pointers:
- Differentiate between raw pointers, `shared_ptr`, and `unique_ptr`.
- Learn the concept of reference counting for shared ownership (`shared_ptr`).
- Understand exclusive ownership with `unique_ptr`.

---

## Task

### 1. **Create a Custom Class `SharedPointer`**

Implement the following methods for the `SharedPointer` class:

- **Copy Constructor**: Implement the copy constructor to manage shared ownership of the resource.
- **`MakeShared` Method**: Implement a method that uses an rvalue reference to make the pointer more efficient and avoid unnecessary copy constructor calls.
- **Private `release` Method**: Implement a `release` method to manually release the pointer.
- **Destructor**: Implement a destructor to delete the allocated memory when the `SharedPointer` object goes out of scope.
- **Private Variables**:
  - `ptr`: A pointer variable to hold the resource.
  - `counter`: A counter to track the number of `SharedPointer` objects pointing to the same resource for reference counting.

### Example Usage:

```cpp
SharedPointer<int> sp1 = SharedPointer<int>::MakeShared(10);  // Create SharedPointer using MakeShared
SharedPointer<int> sp2 = sp1;  // Copy constructor is called, sp1 and sp2 share ownership

// Manual resource release
sp1.release();  // Release the ownership of the resource

// Destructor will automatically delete the allocated memory when sp1 and sp2 go out of scope
