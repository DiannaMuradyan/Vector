#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstddef>        // For std::size_t
#include <initializer_list>
#include <stdexcept>      // For std::out_of_range
#include <algorithm>      // For std::swap

namespace atlas3 {

class Vector {
public:
    // Member Types
    using value_type = int;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;

    // Constructors and Destructor

    Vector();
    explicit Vector(size_type count);
    Vector(size_type count, const_reference value);
    Vector(std::initializer_list<value_type> init);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();

    // Assignment Operators
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
    Vector& operator=(std::initializer_list<value_type> ilist);



    // Element Access
    reference at(size_type pos);
    reference operator[](size_type pos);
    reference front();
    reference back();
    pointer data() noexcept;

    const_reference at(size_type pos) const;
    const_reference operator[](size_type pos) const;
    const_reference front() const;
    const_reference back() const;
    const_pointer data() const noexcept;


    // Capacity
    bool empty() const noexcept;
    size_type capacity() const noexcept;
    size_type size() const noexcept;

    void reserve(size_type new_cap);
    void shrink_to_fit();

    // Modifiers

    void clear() noexcept;
    void push_back(const int& value);
    void push_back(int&& value);
    void pop_back();
    void resize(size_type count);
    void resize(size_type count, const value_type& value);
    void swap(Vector& other) noexcept;
    void insert(size_type pos, const int& value);
    void insert(size_type pos, std::initializer_list<int> ilist);

    // Operator Overloading

    // Equality operators
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

   // Relational operators
    bool operator<(const Vector& other) const;
    bool operator>(const Vector& other) const;
    bool operator<=(const Vector& other) const;
    bool operator>=(const Vector& other) const;

    // Addition operator (vector concatenation)
    Vector operator+(const Vector& other) const;

    // Addition assignment operator
    Vector& operator+=(const Vector& other);

   // Operator cast to bool
    explicit operator bool() const noexcept;

    // Friend Functions

    friend void swap(Vector& lhs, Vector& rhs) noexcept {
        lhs.swap(rhs);
    }

private:
    // Private Member Variables

    pointer m_data;        // Pointer to the dynamic array
    size_type m_size;      // Number of elements
    size_type m_capacity;  // Allocated capacity

    // Private Member Functions

    void reallocate(size_type new_capacity);
    void destroy_elements();
    void copy_from(const Vector& other);
    void move_from(Vector&& other) noexcept;
};

} // namespace atlas3

#include "vector.hpp"
#endif // VECTOR_H