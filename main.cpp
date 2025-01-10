#include "vector.h"

int main() {
    // Create a vector using the default constructor
    atlas3::Vector vec1;
    std::cout << "vec1 size: " << vec1.size() << ", capacity: " << vec1.capacity() << std::endl;

    // Create a vector with initial size 5
    atlas3::Vector vec2(5);
    std::cout << "vec2 size: " << vec2.size() << ", capacity: " << vec2.capacity() << std::endl;

    // Create a vector with 5 elements initialized to 10
    atlas3::Vector vec3(5, 10);
    std::cout << "vec3 size: " << vec3.size() << ", capacity: " << vec3.capacity() << std::endl;
    for (size_t i = 0; i < vec3.size(); ++i) {
        std::cout << "vec3[" << i << "] = " << vec3[i] << std::endl;
    }

    // Create a vector using an initializer list
    atlas3::Vector vec4 = {1, 2, 3, 4, 5};
    std::cout << "vec4 size: " << vec4.size() << ", capacity: " << vec4.capacity() << std::endl;

    // Push back some values
    vec1.push_back(100);
    vec1.push_back(200);
    vec1.push_back(300);
    std::cout << "vec1 size after push_back: " << vec1.size() << ", capacity: " << vec1.capacity() << std::endl;
    
    // Access elements using the at method and operator[]
    std::cout << "vec1[0]: " << vec1[0] << std::endl;
    std::cout << "vec1.at(1): " << vec1.at(1) << std::endl;

    // Resize the vector
    vec1.resize(10, 999);
    std::cout << "vec1 size after resize: " << vec1.size() << ", capacity: " << vec1.capacity() << std::endl;
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << "vec1[" << i << "] = " << vec1[i] << std::endl;
    }

    // Pop back an element
    vec1.pop_back();
    std::cout << "vec1 size after pop_back: " << vec1.size() << std::endl;

    // Insert element at a position
    vec1.insert(2, 500);
    std::cout << "vec1 size after insert: " << vec1.size() << std::endl;
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << "vec1[" << i << "] = " << vec1[i] << std::endl;
    }

    // Concatenate vectors
    atlas3::Vector vec5 = vec1 + vec3;
    std::cout << "vec5 size after concatenation: " << vec5.size() << ", capacity: " << vec5.capacity() << std::endl;
    for (size_t i = 0; i < vec5.size(); ++i) {
        std::cout << "vec5[" << i << "] = " << vec5[i] << std::endl;
    }

    // Test equality operators
    std::cout << "vec1 == vec2? " << (vec1 == vec2 ? "Yes" : "No") << std::endl;
    std::cout << "vec1 != vec2? " << (vec1 != vec2 ? "Yes" : "No") << std::endl;

    // Test relational operators
    std::cout << "vec1 < vec2? " << (vec1 < vec2 ? "Yes" : "No") << std::endl;
    std::cout << "vec1 > vec2? " << (vec1 > vec2 ? "Yes" : "No") << std::endl;

    // Swap two vectors
    vec1.swap(vec2);
    std::cout << "vec1 size after swap: " << vec1.size() << ", vec2 size after swap: " << vec2.size() << std::endl;

    // Check if the vector is empty
    std::cout << "Is vec1 empty? " << (vec1.empty() ? "Yes" : "No") << std::endl;

    // Shrink the vector to fit the size
    vec1.shrink_to_fit();
    std::cout << "vec1 size after shrink_to_fit: " << vec1.size() << ", capacity: " << vec1.capacity() << std::endl;

    return 0;
}

