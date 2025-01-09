# Vector Class Implementation

This repository contains an implementation of a custom Vector class in C++ designed to mimic the functionality of std::vector. The Vector class provides dynamic resizing, element access, and a variety of utility functions for working with sequences of elements. It is built using templates and supports modern C++ features.

Features
Dynamic Array: The vector grows and shrinks dynamically to hold elements.
Support for Copy and Move Semantics: Efficient handling of copies and moves using copy constructors, move constructors, and assignment operators.
Element Access: Provides element access with at(), operator[], front(), back(), and data().
Capacity Management: Functions for checking capacity (capacity()), resizing (resize()), and shrinking the vector to fit its size (shrink_to_fit()).
Modifiers: Functions for modifying the vector, such as push_back(), pop_back(), clear(), and inserting elements.
Operator Overloading: Overloads for comparison (==, !=, <, >, <=, >=) and arithmetic (+, +=) operators.
Initializer List Support: Support for initialization using initializer lists.
Memory Management: Efficient memory allocation, reallocation, and deallocation.
Classes
Vector Class
The Vector class contains the following functionalities:

Constructors:

Default constructor (Vector()).
Constructor that creates a vector of a specified size (Vector(size_type count)).
Constructor with a specific value for each element (Vector(size_type count, const_reference value)).
Constructor that initializes the vector with an initializer list (Vector(std::initializer_list<value_type> init)).
Copy constructor (Vector(const Vector& other)).
Move constructor (Vector(Vector&& other) noexcept).
Destructor (~Vector()).
Assignment Operators:

Copy assignment operator (operator=(const Vector& other)).
Move assignment operator (operator=(Vector&& other) noexcept).
Assignment from initializer list (operator=(std::initializer_list<value_type> ilist)).
Element Access:

at() (throws an exception if out of bounds).
operator[] (does not check bounds).
front() and back() for first and last elements.
data() to access the underlying array.
Capacity Functions:

empty() returns true if the vector is empty.
size() returns the number of elements in the vector.
capacity() returns the allocated capacity.
reserve() increases the capacity if necessary.
shrink_to_fit() reduces the allocated memory to fit the size.
Modifiers:

clear() clears all elements.
push_back() adds an element to the end.
pop_back() removes the last element.
resize() changes the size of the vector.
swap() swaps two vectors.
insert() inserts elements at a specified position.
Operator Overloading:

Comparison operators (==, !=, <, >, <=, >=).
Addition operator for vector concatenation (+).
Addition assignment operator (+=).
Cast to bool to check if the vector is not empty.
