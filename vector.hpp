#ifndef VECTOR_HPP
#define VECTOR_HPP

//Constructors and Destructor
atlas3::Vector::Vector() : m_data{0} , m_size{0} , m_capacity{0} {};

atlas3::Vector::Vector(size_type count) {
    m_data = new value_type[count];
    m_size = count;
    m_capacity = count;
}

atlas3::Vector::Vector(size_type count, const_reference value) {
    m_data = new value_type[count];
    for(int i = 0;i < count;++i){
        m_data[i] = value;
    }
    m_capacity = count;
    m_size = count;
}

atlas3::Vector::Vector(std::initializer_list<atlas3::Vector::value_type> init){
    m_size = 0;
    m_capacity = 2 * init.size();
    m_data = new value_type[m_capacity];
    for(value_type x : init){
        m_data[m_size++] = x;
    }
}

atlas3::Vector::Vector(const Vector& other){
    this->copy_from(other);
}

atlas3::Vector::Vector(Vector&& other) noexcept{
    this->move_from(std::move(other));
}

atlas3::Vector::~Vector(){
    this->destroy_elements();
}

// Element Access
atlas3::Vector::reference atlas3::Vector::at(size_type pos){
    if(pos >= m_size){
        throw std::out_of_range("Out of range\n");
    }
    return m_data[pos];
}

atlas3::Vector::const_reference atlas3::Vector::at(size_type pos) const{
    if(pos >= m_size){
        throw std::out_of_range("Out of range\n");
    }
    return m_data[pos];
}



atlas3::Vector::reference atlas3::Vector::operator[](size_type pos){
    if(pos >= m_size){
        throw std::out_of_range("Out of range\n");
    }
    return m_data[pos];
}


atlas3::Vector::const_reference atlas3::Vector::operator[](size_type pos) const{
    if(pos >= m_size){
        throw std::out_of_range("Out of range\n");
    }
    return m_data[pos];
}


atlas3::Vector::reference atlas3::Vector::front(){
    return m_data[0];
}


atlas3::Vector::const_reference atlas3::Vector::front() const{
    return m_data[0];
}


atlas3::Vector::reference atlas3::Vector::back(){
    return m_data[m_size - 1];
}


atlas3::Vector::const_reference atlas3::Vector::back() const{
    return m_data[m_size - 1];
}


atlas3::Vector::pointer atlas3::Vector::data() noexcept{
    return m_data;
}



// Assignment Operators
atlas3::Vector& atlas3::Vector::operator=(const Vector& other){
    if(*this == other){
        return *this;
    }
    this->destroy_elements();
    this->copy_from(other);
    return *this;
}

atlas3::Vector& atlas3::Vector::operator=(Vector&& other) noexcept{
    if(*this == other){
        return *this;
    }
    this->destroy_elements();
    this->move_from(std::move(other));
    return *this;
}

atlas3::Vector& atlas3::Vector::operator=(std::initializer_list<value_type> ilist){
    this->destroy_elements();
    m_capacity = 2 * ilist.size();
    m_data = new value_type[m_capacity];
    for(auto x : ilist){
        m_data[m_size++] = x;
    }
    return *this;
}


// Modifiers

void atlas3::Vector::clear() noexcept{
    if(m_data == nullptr){
        return;
    }
    this->destroy_elements();
}

//use member types
void atlas3::Vector::push_back(const int& value){
    if(m_capacity == m_size){
        this->reallocate(m_capacity);
    }
    m_data[m_size] = value;
    ++m_size;
}

//here too
void atlas3::Vector::push_back(int&& value){
    if(m_capacity == m_size){
        this->reallocate(m_capacity);
    }
    m_data[m_size] = value;
    ++m_size;
}


void atlas3::Vector::pop_back(){
    if(m_size) {
        m_data[m_size - 1] = 0;
        --m_size;
    } else {
        std::cout << "Vector is empty: \n";
    }                 
}


void atlas3::Vector::resize(size_type count){
    this->reallocate(count);
}


void atlas3::Vector::resize(size_type count, const_reference value){
    this->reallocate(count);
    if(m_size < count){
        for(int i=0;i<count;++i){
            m_data[m_size + i] = value; 
        }
        m_size += count;
    }
    return;
}

void atlas3::Vector::swap(Vector& other) noexcept{
    std::swap(m_size,other.m_size);
    std::swap(m_size,other.m_size);
    std::swap(m_data,other.m_data);
}


void atlas3::Vector::insert(size_type pos, const int& value){
    if(m_size == m_capacity){
        this->reallocate(m_capacity);
    }
    if(pos > m_size ){
        throw std::out_of_range("Invalid position\n");
    }
    else if(pos == m_size){
        this->push_back(value);
    }
    else{
        for(int i=0;i<=pos;++i){
            m_data[m_size - i] =  m_data[m_size - i -1];
        }
        m_data[pos] = value;
        ++m_size;
    }
}


void atlas3::Vector::insert(size_type pos, std::initializer_list<int> ilist){
    if(m_size == m_capacity){
        this->reallocate(m_capacity);
    }
    if(pos > m_size){
        throw std::out_of_range("Invalid position\n");
    }
    else if(pos == m_size){
        for(int i=0;i<ilist.size();++i){
            this->push_back(*(ilist.begin() + i));
        }
    }
    else{
        for(int i=0;i<=pos;++i){
            m_data[m_size + ilist.size() - i - 1] = m_data[m_size - i - 1];
        }
        for(int i=0;i<ilist.size();++i){
            m_data[pos + i] = *(ilist.begin() + i);
        }
        m_size += ilist.size();
    }
}


//Operator Overloading

// Equality operators
bool atlas3::Vector::operator==(const Vector& other) const{
    if(m_size != other.m_size){
        return false;
    }
    for(int i=0;i<m_size;++i){
        if(m_data[i] != other.m_data[i]){
            return false;
        }
    }
    return true;
}

bool atlas3::Vector::operator!=(const Vector& other) const{
    return !(*this == other);
}


// Relational operators
bool atlas3::Vector::operator<(const Vector& other) const{
    for(int i=0;i<m_size;++i){
        if(m_data[i] < other.m_data[i]){
            return true;
        }
    }
    if(m_size < other.m_size){
        return true;
    }
    return false;
}

bool atlas3::Vector::operator>(const Vector& other) const{
    return !(*this < other && *this != other) ;
}

bool atlas3::Vector::operator<=(const Vector& other) const{
    return !(*this > other) ;
}

bool atlas3::Vector::operator>=(const Vector& other) const{
    return !(*this < other) ;
}

//Addition operator (vector concatenation)
atlas3::Vector atlas3::Vector::operator+(const Vector& other) const{
    atlas3::Vector vec;
    int size = m_size + other.m_size;
    vec.m_data = new int[2*size];
    for(int i = 0;i < m_size; ++i){
        vec.m_data[i] = m_data[i]; 
    }
    for(int i = 0;i < other.m_size;++i){
        vec.m_data[m_size + i] = other.m_data[i]; 
    }
    vec.m_size = size;
    vec.m_capacity = 2 * size;
    return vec;
}

// Operator cast to bool
atlas3::Vector::operator bool() const noexcept{
    return !empty();
}


// Addition assignment operator
atlas3::Vector& atlas3::Vector::operator+=(const Vector& other){
    *this = std::move(*this + other);
    return *this;
}


//Capacity
atlas3::Vector::size_type  atlas3::Vector::size() const noexcept{
    return m_size;
}

atlas3::Vector::size_type atlas3::Vector::capacity() const noexcept{
    return m_capacity;
}

bool atlas3::Vector::empty() const noexcept{
    return !m_size;
}

void atlas3::Vector::reserve(size_type new_cap){
    if(new_cap > m_capacity){
        this->reallocate(new_cap);
    }
    return;
}

void atlas3::Vector::shrink_to_fit(){
    m_capacity = m_size;
    atlas3::Vector vec;
    vec.m_data = new int[m_size];
    for(int i=0;i<m_size;++i){
        vec.m_data[i] = m_data[i];
    }
    delete[] m_data;
    m_data = vec.m_data;
    vec.m_data = nullptr;
}

// Private Member Functions
void atlas3::Vector::destroy_elements(){
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

void atlas3::Vector::copy_from(const Vector& other){
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = new value_type[m_capacity];
    for(int i=0;i<other.m_size;++i){
        m_data[i] = other.m_data[i];
    }
}

void atlas3::Vector::move_from(Vector&& other) noexcept{
    this->destroy_elements();
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = other.m_data;
    other.m_data = nullptr;
}

void atlas3::Vector::reallocate(size_type new_capacity){
    atlas3::Vector vec;
    if(m_size == new_capacity){
        vec.m_data = new int[2*new_capacity];
        for(int i=0;i<m_size;++i){
            vec.m_data[i] = m_data[i];
        }
        m_capacity = 2*new_capacity;
    }
    else if(m_size > new_capacity){
        vec.m_data = new int[2*new_capacity];
        for(int i=0;i<new_capacity;++i){
            vec.m_data[i] = m_data[i];
        }
         m_size = new_capacity;
         m_capacity = 2*new_capacity;
    }else{
        vec.m_data = new int[new_capacity];
        for(int i=0;i<m_size;++i){
            vec.m_data[i] = m_data[i];
        }
         m_capacity = new_capacity;
    }
    delete[] m_data;
    m_data = vec.m_data;
    vec.m_data = nullptr;
}

#endif //VECTOR_HPP
