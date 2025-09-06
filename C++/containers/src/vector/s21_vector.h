#ifndef S21_CONTAINERS_VECTOR_S21_VECTOR_H
#define S21_CONTAINERS_VECTOR_S21_VECTOR_H

#include <cstdarg>
#include <iostream>
#include <tuple>
#include <vector>

namespace s21 {

template <typename Type>
class vector {
 public:
  vector();
  vector(int length);
  vector(int length, Type variable);
  vector(std::initializer_list<Type> nameList);
  vector(s21::vector<Type> &copy);
  vector(s21::vector<Type> *copy);
  ~vector();

  Type operator[](int i);
  Type *At(int i);
  Type *front();
  Type *Back();
  bool Empty();
  int Сapacity();
  int Size();
  void Clear();
  void Erase(int index);
  void Erase(int index_1, int index_2);
  void PushBack(Type value);

  class vector_iterator {
   public:
    vector_iterator();
    vector_iterator(Type *l);
    vector_iterator(s21::vector<Type>::vector_iterator &other);

    Type operator*();
    void operator++();
    void operator--();
    void operator=(Type *a);
    void operator=(s21::vector<Type>::vector_iterator a);
    friend bool operator==(vector_iterator a, vector_iterator b) {
      return a.m_ptr == b.m_ptr;
    };
    friend bool operator!=(vector_iterator a, vector_iterator b) {
      return a.m_ptr != b.m_ptr;
    };
    Type *m_ptr;
  };

  template <typename... Types>
  void insert_many(vector_iterator pos, Types &&...args);

 private:
  long unsigned int massive_size_;
  long unsigned int elements_size_;
  Type *massive_;
};

template <typename Type>
s21::vector<Type>::vector() {
  massive_size_ = 100;
  elements_size_ = 0;
  try {
    massive_ = new Type[100];
  } catch (...) {
    std::cout << "Memory allocation error." << std::endl;
    massive_size_ = 0;
    massive_ = nullptr;
  }
}

template <typename Type>
s21::vector<Type>::vector(int length) {
  if (length < 0) {
    throw std::invalid_argument{"Impossible list length."};
  }
  this->massive_size_ = length;
  this->elements_size_ = 0;
  try {
    massive_ = new Type[length];
  } catch (...) {
    std::cout << "Memory allocation error." << std::endl;
    massive_size_ = 0;
    massive_ = nullptr;
  }
}

template <typename Type>
s21::vector<Type>::vector(int length, Type variable) {
  if (length < 0) {
    throw std::invalid_argument{"Impossible list length."};
  }
  this->massive_size_ = length;
  this->elements_size_ = length;
  try {
    massive_ = new Type[length];
    for (int i = 0; i < length; i++) {
      massive_[i] = variable;
    }
  } catch (...) {
    std::cout << "Memory allocation error." << std::endl;
    massive_size_ = 0;
    elements_size_ = 0;
    massive_ = nullptr;
  }
}

template <typename Type>
s21::vector<Type>::vector(std::initializer_list<Type> nameList) {
  const Type *pointer = nameList.begin();
  this->massive_size_ = nameList.size();
  this->elements_size_ = nameList.size();
  try {
    massive_ = new Type[nameList.size()];
    for (long unsigned int i = 0; i < nameList.size(); i++) {
      massive_[i] = *pointer;
      ++pointer;
    }
  } catch (...) {
    std::cout << "Memory allocation error." << std::endl;
    massive_size_ = 0;
    elements_size_ = 0;
    massive_ = nullptr;
  }
}

template <typename Type>
s21::vector<Type>::vector(s21::vector<Type> &copy) {
  this->massive_size_ = copy.massive_size_;
  this->elements_size_ = copy.elements_size_;
  try {
    this->massive_ = new Type[copy.massive_size_];
    for (long unsigned int i = 0; i < copy.massive_size_; i++) {
      massive_[i] = copy.massive_[i];
    }
  } catch (...) {
    std::cout << "Memory allocation error." << std::endl;
    massive_size_ = 0;
    elements_size_ = 0;
    massive_ = nullptr;
  }
}

template <typename Type>
s21::vector<Type>::vector(s21::vector<Type> *copy) {
  this->massive_size_ = copy->massive_size_;
  this->elements_size_ = copy->elements_size_;
  this->massive_ = copy->massive_;
  copy->massive_size_ = 0;
  copy->elements_size_ = 0;
  copy->massive_ = nullptr;
}

template <typename Type>
s21::vector<Type>::~vector() {
  this->massive_size_ = 0;
  this->elements_size_ = 0;
  delete[] this->massive_;
  this->massive_ = nullptr;
}

template <typename Type>
Type s21::vector<Type>::operator[](int i) {
  if ((long unsigned int)i >= elements_size_) {
    throw std::out_of_range{"Incorrect index."};
  }
  return massive_[i];
}

template <typename Type>
Type *s21::vector<Type>::At(int i) {
  if ((long unsigned int)i >= elements_size_) {
    throw std::out_of_range{"Incorrect index."};
  }
  return &massive_[i];
}

template <typename Type>
Type *s21::vector<Type>::front() {
  if (massive_size_ == 0) {
    return nullptr;
  } else {
    return &massive_[0];
  }
}

template <typename Type>
Type *s21::vector<Type>::Back() {
  if (massive_size_ == 0) {
    return nullptr;
  } else {
    return &massive_[elements_size_ - 1];
  }
}

template <typename Type>
bool s21::vector<Type>::Empty() {
  if (elements_size_ == 0) {
    return true;
  } else {
    return false;
  }
}

template <typename Type>
int s21::vector<Type>::Сapacity() {
  return massive_size_;
}

template <typename Type>
int s21::vector<Type>::Size() {
  return elements_size_;
}

template <typename Type>
void s21::vector<Type>::Clear() {
  this->elements_size_ = 0;
}

template <typename Type>
void s21::vector<Type>::Erase(int index) {
  if (this->Size() <= 0) {
    throw std::invalid_argument{"Impossible list length."};
  } else if (index >= this->Size()) {
    throw std::invalid_argument{"Range out of bounds."};
  } else if (index < 0) {
    throw std::invalid_argument{"Impossible index."};
  }
  for (long unsigned int i = index; i < elements_size_ - 1; i++) {
    massive_[i] = massive_[i + 1];
  }
  this->elements_size_ -= 1;
}

template <typename Type>
void s21::vector<Type>::Erase(int index_1, int index_2) {
  if (this->Size() <= 0) {
    throw std::invalid_argument{"Impossible list length."};
  } else if (index_1 >= this->Size() || index_2 >= this->Size()) {
    throw std::invalid_argument{"Range out of bounds."};
  } else if (index_2 < index_1) {
    throw std::invalid_argument{"Start index is bigger than end index."};
  } else if (index_1 < 0 || index_2 < 0) {
    throw std::invalid_argument{"Impossible index."};
  }
  for (long unsigned int i = index_1;
       i + (index_2 - index_1) + 1 < elements_size_; i++) {
    massive_[i] = massive_[i + (index_2 - index_1) + 1];
  }
  this->elements_size_ -= index_2 - index_1 + 1;
}

template <typename Type>
void s21::vector<Type>::PushBack(Type value) {
  if (massive_size_ == elements_size_) {
    try {
      Type *temp = massive_;
      massive_ = new Type[massive_size_ + 50];
      for (long unsigned int i = 0; i < massive_size_; i++) {
        massive_[i] = temp[i];
      }
      massive_[elements_size_] = value;
      massive_size_ += 50;
      elements_size_ += 1;
      delete[] temp;
    } catch (...) {
      std::cout << "Memory allocation error." << std::endl;
    }
  } else {
    massive_[elements_size_] = value;
    elements_size_ += 1;
  }
}

template <typename Type>
s21::vector<Type>::vector_iterator::vector_iterator() {
  m_ptr = nullptr;
}

template <typename Type>
s21::vector<Type>::vector_iterator::vector_iterator(Type *l) {
  m_ptr = l;
}

template <typename Type>
s21::vector<Type>::vector_iterator::vector_iterator(
    s21::vector<Type>::vector_iterator &other) {
  m_ptr = other.m_ptr;
}

template <typename Type>
Type s21::vector<Type>::vector_iterator::operator*() {
  if (m_ptr != nullptr) {
    return *m_ptr;
  } else {
    return (Type)NULL;
  }
}

template <typename Type>
void s21::vector<Type>::vector_iterator::operator++() {
  ++m_ptr;
}

template <typename Type>
void s21::vector<Type>::vector_iterator::operator--() {
  --m_ptr;
}

template <typename Type>
void s21::vector<Type>::vector_iterator::operator=(Type *a) {
  this->m_ptr = a;
}

template <typename Type>
void s21::vector<Type>::vector_iterator::operator=(
    s21::vector<Type>::vector_iterator a) {
  this->m_ptr = a.m_ptr;
}

template <typename Type>
template <typename... Types>
void s21::vector<Type>::insert_many(vector_iterator pos, Types &&...args) {
  long unsigned int counter = 0;
  s21::vector<Type> first;
  s21::vector<Type> second({args...});
  s21::vector<Type> third;
  s21::vector<Type>::vector_iterator pointer(this->front());
  s21::vector<Type>::vector_iterator position_copy(pos);
  while (pointer != pos) {
    if ((int)counter >= this->Size()) {
      throw std::out_of_range{"Iterator is out of bounds."};
    }
    ++pointer;
    counter += 1;
  }
  while (this->Size() + second.Size() > this->Сapacity()) {
    Type *temp = massive_;
    massive_ = new Type[this->massive_size_ + 50];
    for (long unsigned int i = 0; i < massive_size_; i++) {
      massive_[i] = temp[i];
    }
    massive_size_ += 50;
    delete[] temp;
  }
  pos = this->At(counter);
  for (long unsigned int i = 0; i < counter; i++) {
    first.PushBack(this->massive_[i]);
  }
  for (; counter < this->elements_size_; counter++) {
    third.PushBack(this->massive_[counter]);
  }
  this->Clear();
  for (int i = 0; i < first.Size(); i++) {
    this->PushBack(first[i]);
  }
  for (int i = 0; i < second.Size(); i++) {
    this->PushBack(second[i]);
  }
  for (int i = 0; i < third.Size(); i++) {
    this->PushBack(third[i]);
  }
}

}  // namespace s21

#endif  // VECTOR_H_
