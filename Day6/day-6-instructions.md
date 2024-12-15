# Day 6: Refactoring with Smart Pointers – Implementing `shared_ptr` and `unique_ptr`

## Learning Objectives

### Using `shared_ptr` and `unique_ptr` in C++:
- Understand how to refactor existing code to use `shared_ptr` and `unique_ptr` for better memory management.
- Learn the difference between `shared_ptr` and `unique_ptr`, and when to use each one.
- Explore the benefits of automatic memory management and preventing memory leaks with smart pointers.

### Refactoring Existing Code:
- Refactor the `VariantList` and `Let` classes to use `shared_ptr` and `unique_ptr` instead of raw pointers.
- Understand how `shared_ptr` helps with shared ownership, and how `unique_ptr` ensures exclusive ownership of resources.
- Improve memory safety and efficiency by using smart pointers in your classes.

---

## Task

### 1. **Refactor `VariantList` Class**
- Modify the `VariantList` class to use `std::shared_ptr` for managing the nodes and the `Variant` objects in the linked list.
- Use `std::shared_ptr` for the node pointers in the list, ensuring that the memory is managed automatically when nodes are deleted.
- Implement proper memory management in the class’s destructor, ensuring that no memory leaks occur.

### 2. **Refactor `Let` Class**
- Update the `Let` class to store `std::shared_ptr` (or `std::unique_ptr` depending on ownership requirements) for the `Variant` objects.
- Modify the constructor of the `Let` class to accept and store `shared_ptr<Variant>` objects from the initializer list.
- Ensure that memory is managed properly by using smart pointers, and adjust any operations (such as `+=`) to work with `shared_ptr`.

---

## Key Concepts

- **`shared_ptr`**: A smart pointer that manages shared ownership of an object. The resource will be automatically deleted when the last `shared_ptr` pointing to it is destroyed.
- **`unique_ptr`**: A smart pointer that ensures exclusive ownership of an object. It cannot be copied, and the object is deleted when the `unique_ptr` goes out of scope.
- **Memory Safety**: Smart pointers help in managing memory automatically, thus avoiding memory leaks and dangling pointers.
- **Refactoring with Smart Pointers**: Replacing raw pointers with smart pointers improves memory safety and makes code more efficient by handling memory allocation and deallocation automatically.

---

### Example Usage

```cpp
// Refactored VariantList Class
std::shared_ptr<Variant> var1 = std::make_shared<Variant>(42);  // Using shared_ptr
VariantList list;
list.insert(var1);  // Insert a shared_ptr into the linked list

// Refactored Let Class
Let letObj = {std::make_shared<Variant>(3.14), std::make_shared<Variant>("Hello")};
