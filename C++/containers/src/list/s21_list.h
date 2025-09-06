#ifndef S21_CONTAINERS_LIST_S21_LIST_H
#define S21_CONTAINERS_LIST_S21_LIST_H

#include <cstdarg>
#include <iostream>
#include <string>
#include <typeinfo>

namespace s21 {

template <typename Type>
struct list_elem {
  Type data;
  list_elem *next = nullptr, *prev = nullptr;
};

template <typename Type>
class list_iterator {
 public:
  list_iterator();
  list_iterator(list_elem<Type> *l);
  list_iterator(s21::list_iterator<Type> *other);

  Type operator*();
  void operator++();
  void operator--();
  void operator=(list_elem<Type> *l) { this->m_ptr = l; };
  friend bool operator==(list_iterator a, list_iterator b) {
    return a.m_ptr == b.m_ptr;
  };
  friend bool operator!=(list_iterator a, list_iterator b) {
    return a.m_ptr != b.m_ptr;
  };
  list_elem<Type> *m_ptr;
};

template <typename Type>
class list {
 public:
  list();
  list(int Size);
  list(int Size, Type value);
  list(std::initializer_list<Type> nameList);
  list(s21::list<Type> &other);
  list(s21::list<Type> *other);
  ~list();

  Type operator[](int i) { return get_element(i); }

  Type get_element(int index);
  list_elem<Type> *get_beginning() { return begin_; };
  list_elem<Type> *get_beginning_next() { return begin_->next; };
  list_elem<Type> *get_end() { return end_; };
  list_elem<Type> *get_end_prev() { return end_->prev; };

  void PushBack(Type end);
  void PushFront(Type val);
  int Size();
  bool Empty();
  void PopBack();
  void PopFront();
  void Erase(int index);
  void Erase(int index_1, int index_2);

  list_iterator<Type> First();
  list_iterator<Type> Last();

  template <typename... Types>
  void Insert_many(s21::list_iterator<Type> pos, Types &&...args);

 private:
  list_elem<Type> *begin_, *end_;
};

template <typename Type>
s21::list<Type>::list() {
  begin_ = nullptr;
  end_ = nullptr;
}

template <typename Type>
s21::list<Type>::list(int Size) {
  if (Size < 0) {
    throw std::invalid_argument{"Impossible list length."};
  } else if (Size == 0) {
    begin_ = nullptr;
    end_ = nullptr;
  } else if (Size == 1) {
    begin_ = new list_elem<Type>;
    end_ = new list_elem<Type>;
    begin_->data = (Type)0;
    end_->data = (Type)0;
    begin_->prev = nullptr;
    begin_->next = nullptr;
    end_->prev = nullptr;
    end_->next = nullptr;
  } else {
    begin_ = new list_elem<Type>;
    end_ = new list_elem<Type>;
    begin_->data = (Type)0;
    end_->data = (Type)0;
    begin_->prev = nullptr;
    begin_->next = end_;
    end_->prev = begin_;
    end_->next = nullptr;
    for (int i = 2; i < Size; i++) {
      PushBack(begin_->data);
    }
  }
}

template <typename Type>
s21::list<Type>::list(int Size, Type value) {
  if (Size < 0) {
    throw std::invalid_argument{"Impossible list length."};
  } else if (Size == 0) {
    begin_ = nullptr;
    end_ = nullptr;
  } else if (Size == 1) {
    begin_ = new list_elem<Type>;
    end_ = new list_elem<Type>;
    begin_->prev = nullptr;
    begin_->next = nullptr;
    begin_->data = value;
    end_->prev = nullptr;
    end_->next = nullptr;
    end_->data = value;
  } else {
    begin_ = new list_elem<Type>;
    end_ = new list_elem<Type>;
    begin_->prev = nullptr;
    begin_->next = end_;
    begin_->data = value;
    end_->prev = begin_;
    end_->next = nullptr;
    end_->data = value;
    for (int i = 2; i < Size; i++) {
      PushBack(value);
    }
  }
}

template <typename Type>
s21::list<Type>::list(std::initializer_list<Type> nameList) {
  const Type *temp_p = nullptr;
  if (nameList.size() == 0) {
    begin_ = nullptr;
    end_ = nullptr;
  } else if (nameList.size() == 1) {
    temp_p = nameList.begin();
    begin_ = new list_elem<Type>;
    end_ = new list_elem<Type>;
    begin_->prev = nullptr;
    begin_->next = nullptr;
    begin_->data = *temp_p;
    end_->prev = nullptr;
    end_->next = nullptr;
    end_->data = *temp_p;
  } else {
    s21::list_elem<Type> *temp = new list_elem<Type>;
    temp_p = nameList.begin();
    begin_ = new list_elem<Type>;
    end_ = new list_elem<Type>;
    begin_->prev = nullptr;
    begin_->next = end_;
    end_->prev = begin_;
    end_->next = nullptr;
    for (long unsigned int i = 2; i < nameList.size(); i++) {
      PushBack(begin_->data);
    }
    temp->next = begin_;
    for (long unsigned int i = 0; i < nameList.size(); i++) {
      temp->next->data = *temp_p;
      temp->next = temp->next->next;
      temp_p++;
    }
    delete temp;
  }
}

template <typename Type>
s21::list<Type>::list(s21::list<Type> &other) {
  s21::list_elem<Type> *temp1 = new list_elem<Type>;
  s21::list_elem<Type> *temp2 = new list_elem<Type>;
  if (other.Size() == 0) {
    begin_ = nullptr;
    end_ = nullptr;
  } else if (other.Size() == 1) {
    begin_ = new list_elem<Type>;
    end_ = new list_elem<Type>;
    begin_->data = other.begin_->data;
    begin_->prev = nullptr;
    begin_->next = nullptr;
    end_->prev = nullptr;
    end_->next = nullptr;
  } else {
    begin_ = new list_elem<Type>;
    end_ = new list_elem<Type>;
    begin_->prev = nullptr;
    begin_->next = end_;
    end_->prev = begin_;
    end_->next = nullptr;
    temp1->next = begin_;
    temp2->next = other.begin_;
    for (int i = 2; i < other.Size(); i++) {
      PushBack(begin_->data);
    }
    for (int i = 0; i < other.Size(); i++) {
      temp1->next->data = temp2->next->data;
      temp1->next = temp1->next->next;
      temp2->next = temp2->next->next;
    }
  }
  delete temp1;
  delete temp2;
}

template <typename Type>
s21::list<Type>::list(s21::list<Type> *other) {
  this->begin_ = other->begin_;
  this->end_ = other->end_;
  other->begin_ = nullptr;
  other->end_ = nullptr;
  other->~list();
}

template <typename Type>
s21::list<Type>::~list() {
  if (this->Size() == 0) {
    this->begin_ = nullptr;
    this->end_ = nullptr;
  } else if (this->Size() == 1) {
    delete this->begin_;
    delete this->end_;
    this->begin_ = nullptr;
    this->end_ = nullptr;
  } else {
    /*for (int i = 0; i < this->Size() ; i++) {
        std::cout << "\n Delete list item " << this->get_element(i) << "\n";
    }*/
    s21::list_elem<Type> *temp = this->get_beginning();
    while (temp->next != nullptr) {
      temp = temp->next;
      delete temp->prev;
    }
    delete temp;
    this->begin_ = nullptr;
    this->end_ = nullptr;
  }
}

template <typename Type>
void s21::list<Type>::PushBack(Type val) {
  if (this->begin_ == nullptr) {
    begin_ = new list_elem<Type>;
    end_ = new list_elem<Type>;
    begin_->data = val;
    begin_->prev = nullptr;
    begin_->next = nullptr;
    end_->prev = nullptr;
    end_->next = nullptr;
  } else if (this->begin_->next == nullptr) {
    this->end_->data = val;
    this->end_->prev = this->begin_;
    this->begin_->next = this->end_;
  } else {
    list_elem<Type> *middle = new list_elem<Type>;
    middle->data = val;
    middle->next = nullptr;
    middle->prev = this->end_;
    this->end_->next = middle;
    this->end_ = middle;
  }
}

template <typename Type>
void s21::list<Type>::PushFront(Type val) {
  if (this->begin_ == nullptr) {
    begin_ = new list_elem<Type>;
    end_ = new list_elem<Type>;
    begin_->data = val;
    begin_->prev = nullptr;
    begin_->next = nullptr;
    end_->prev = nullptr;
    end_->next = nullptr;
  } else if (this->begin_->next == nullptr) {
    this->end_->data = this->begin_->data;
    this->begin_->data = val;
    this->end_->prev = this->begin_;
    this->begin_->next = this->end_;
  } else {
    list_elem<Type> *middle = new list_elem<Type>;
    middle->data = val;
    middle->next = this->begin_;
    middle->prev = nullptr;
    this->begin_->prev = middle;
    this->begin_ = middle;
  }
}

template <typename Type>
int s21::list<Type>::Size() {
  s21::list_elem<Type> *temp = new list_elem<Type>;
  int counter = 0;
  temp->next = begin_;
  if (begin_ == nullptr) {
    delete temp;
    return counter;
  } else {
    while (temp->next != nullptr) {
      counter += 1;
      temp->next = temp->next->next;
    }
    delete temp;
    return counter;
  }
}

template <typename Type>
Type s21::list<Type>::get_element(int index) {
  Type result;
  s21::list_elem<Type> *temp = new list_elem<Type>;
  if (this->Size() <= 0) {
    delete temp;
    throw std::invalid_argument{"Impossible list length."};
  } else if (index >= this->Size()) {
    delete temp;
    throw std::invalid_argument{"Range out of bounds."};
  } else if (index < 0) {
    delete temp;
    throw std::invalid_argument{"Impossible index."};
  }
  temp->next = begin_;
  temp->data = temp->next->data;
  for (int i = 0; i < index; i++) {
    temp->next = temp->next->next;
    temp->data = temp->next->data;
  }
  result = temp->data;
  delete temp;
  return result;
}

template <typename Type>
bool s21::list<Type>::Empty() {
  return this->begin_ == nullptr;
}

template <typename Type>
void s21::list<Type>::PopBack() {
  if (this->Empty()) {
    throw std::logic_error{"List is empty."};
  } else if (this->begin_->next == this->end_) {
    this->begin_->next = nullptr;
  } else if (this->begin_->next == nullptr) {
    delete this->begin_;
    delete this->end_;
    this->begin_ = nullptr;
    this->end_ = nullptr;
  } else {
    this->end_ = this->end_->prev;
    delete this->end_->next;
    this->end_->next = nullptr;
  }
}

template <typename Type>
void s21::list<Type>::PopFront() {
  if (this->Empty()) {
    throw std::logic_error{"List is empty."};
  } else if (this->begin_->next == this->end_) {
    this->begin_->next = nullptr;
    this->begin_->data = this->end_->data;
  } else if (this->begin_->next == nullptr) {
    delete this->begin_;
    delete this->end_;
    this->begin_ = nullptr;
    this->end_ = nullptr;
  } else {
    this->begin_ = this->begin_->next;
    delete this->begin_->prev;
    this->begin_->prev = nullptr;
  }
}

template <typename Type>
void s21::list<Type>::Erase(int index) {
  s21::list_elem<Type> *temp = new list_elem<Type>;
  if (this->Size() <= 0) {
    delete temp;
    throw std::invalid_argument{"Impossible list length."};
  } else if (index >= this->Size()) {
    delete temp;
    throw std::invalid_argument{"Range out of bounds."};
  } else if (index == 0) {
    this->PopFront();
  } else if (index == this->Size() - 1) {
    this->PopBack();
  } else {
    temp->next = begin_;
    for (int i = 0; i < index; i++) {
      temp->next = temp->next->next;
    }
    temp->next->prev->next = temp->next->next;
    temp->next->next->prev = temp->next->prev;
    delete temp->next;
  }
  delete temp;
}

template <typename Type>
void s21::list<Type>::Erase(int index_1, int index_2) {
  s21::list_elem<Type> *temp_1 = new list_elem<Type>;
  s21::list_elem<Type> *temp_2 = new list_elem<Type>;
  if (this->Size() <= 0) {
    delete temp_1;
    delete temp_2;
    throw std::invalid_argument{"Impossible list length."};
  } else if (index_1 >= this->Size() || index_2 >= this->Size()) {
    delete temp_1;
    delete temp_2;
    throw std::invalid_argument{"Range out of bounds."};
  } else if (index_2 < index_1) {
    delete temp_1;
    delete temp_2;
    throw std::invalid_argument{"Start index is bigger than end index."};
  } else {
    temp_1->next = begin_;
    temp_2->next = begin_;
    for (int i = 0; i < index_1; i++) {
      temp_1->next = temp_1->next->next;
    }
    for (int i = 0; i < index_2; i++) {
      temp_2->next = temp_2->next->next;
    }
    if (index_1 == 0 && index_2 == this->Size() - 1) {
      s21::list_elem<Type> *temp = this->get_beginning();
      while (temp->next != nullptr) {
        temp = temp->next;
        delete temp->prev;
      }
      delete temp;
      this->begin_ = nullptr;
      this->end_ = nullptr;
    } else if (index_1 == 0) {
      s21::list_elem<Type> *temp = this->get_beginning();
      temp_2->next->next->prev = nullptr;
      this->begin_ = temp_2->next->next;
      while (temp != temp_2->next) {
        temp = temp->next;
        delete temp->prev;
      }
      delete temp;
      if (this->begin_ == this->end_) {
        this->end_ = new list_elem<Type>;
        end_->data = (Type)0;
        begin_->prev = nullptr;
        begin_->next = nullptr;
        end_->prev = nullptr;
        end_->next = nullptr;
      }
    } else if (index_2 == this->Size() - 1) {
      s21::list_elem<Type> *temp = temp_1->next;
      temp_1->next->prev->next = nullptr;
      this->end_ = temp_1->next->prev;
      while (temp->next != nullptr) {
        temp = temp->next;
        delete temp->prev;
      }
      delete temp;
      if (this->begin_ == this->end_) {
        this->begin_ = this->end_;
        this->end_ = new list_elem<Type>;
        end_->data = (Type)0;
        begin_->prev = nullptr;
        begin_->next = nullptr;
        end_->prev = nullptr;
        end_->next = nullptr;
      }
    } else {
      s21::list_elem<Type> *temp = temp_1->next;
      temp_1->next->prev->next = temp_2->next->next;
      temp_2->next->next->prev = temp_1->next->prev;
      while (temp != temp_2->next) {
        temp = temp->next;
        delete temp->prev;
      }
      delete temp;
    }
  }
  delete temp_1;
  delete temp_2;
}

template <typename Type>
list_iterator<Type> s21::list<Type>::First() {
  s21::list_iterator<Type> result(this->begin_);
  return result;
}

template <typename Type>
list_iterator<Type> s21::list<Type>::Last() {
  s21::list_iterator<Type> result(this->end_);
  return result;
}

template <typename Type>
s21::list_iterator<Type>::list_iterator() {
  m_ptr = nullptr;
}

template <typename Type>
s21::list_iterator<Type>::list_iterator(list_elem<Type> *l) {
  m_ptr = l;
}

template <typename Type>
s21::list_iterator<Type>::list_iterator(s21::list_iterator<Type> *other) {
  m_ptr = other->m_ptr;
}

template <typename Type>
Type s21::list_iterator<Type>::operator*() {
  if (m_ptr != nullptr) {
    return m_ptr->data;
  } else {
    return (Type)NULL;
  }
}

template <typename Type>
void s21::list_iterator<Type>::operator++() {
  if (m_ptr == nullptr) {
    m_ptr = nullptr;
  } else if (m_ptr->next == nullptr) {
    while (m_ptr->prev != nullptr) {
      m_ptr = m_ptr->prev;
    }
  } else {
    m_ptr = m_ptr->next;
  }
}

template <typename Type>
void s21::list_iterator<Type>::operator--() {
  if (m_ptr == nullptr) {
    m_ptr = nullptr;
  } else if (m_ptr->prev == nullptr) {
    while (m_ptr->next != nullptr) {
      m_ptr = m_ptr->next;
    }
  } else {
    m_ptr = m_ptr->prev;
  }
}

template <typename Type>
template <typename... Types>
void s21::list<Type>::Insert_many(s21::list_iterator<Type> pos,
                                  Types &&...args) {
  s21::list<Type> new_massive({args...});
  if (pos.m_ptr->prev == nullptr) {
    this->begin_->prev = new_massive.get_end();
    this->begin_->prev->next = this->begin_;
    this->begin_ = new_massive.get_beginning();
    new_massive.begin_ = nullptr;
    new_massive.end_ = nullptr;
  } else {
    s21::list_elem<Type> *temp = this->end_;
    this->end_ = pos.m_ptr->prev;
    this->end_->next = nullptr;
    for (int i = 0; i < new_massive.Size(); i++) {
      this->PushBack(new_massive[i]);
    }
    this->end_->next = pos.m_ptr;
    pos.m_ptr->prev = this->end_;
    this->end_ = temp;
  }
}

}  // namespace s21

#endif  // LIST_H_
