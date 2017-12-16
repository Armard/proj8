#ifndef __TSTACK_H__
#define __TSTACK_H__

#include <cstdlib>
#include <iostream>
using namespace std;

namespace fsu {

  template < typename T , size_t N = 100>
  class Stack
  {
  public:
    void Push(const T& t)  // push t onto stack; error if full
    {
      if(size_ >= capacity_)
      {
        throw std::out_of_range("Stack full");
      }

      data_[size_++] = t;
    }

    T Pop()           // pop stack and return removed element; error if stack is empty
    {
      if(size_ <= 0) 
      {
        throw std::out_of_range("Stack empty");
      }

      T ret_value = data_[size_-1];
      size_--;
      return ret_value;
    }

    T& Top()           // return top element of stack; error if stack is empty
    {
      if(size_ <= 0) 
      {
        throw std::out_of_range("Stack empty");
      }

      return data_[size_-1];
    }

    const T& Top() const     // const version
    {
      if(size_ <= 0) 
      {
        throw std::out_of_range("Stack empty");
      }

      return data_[size_-1];  
    }

    size_t Size() const     // return number of elements in stack
    {
      return size_;
    }

    size_t Capacity() const     // return storage capacity [maximum size] of stack
    {
      return capacity_;
    }

    bool Empty() const     // return 1/true if stack is empty, 0/false if not empty
    {
      return size_ == 0;
    }

    void Clear()           // make the stack empty
    {
      size_ = 0;
    }

  public:
    Stack() : capacity_(N)             // default constructor
    {
      ofc_ = '\0';
      dir_ = 1;
      size_ = 0;
    }

    Stack(char ofc, int dir) : capacity_(N) // sets ofc_ and dir_
    {
      this->ofc_ = ofc;
      this->dir_ = dir;
      size_ = 0;
    }

    Stack(const Stack &o) : capacity_(o.capacity_) // copy constructor
    {
      this->ofc_ = o.ofc_;
      this->dir_ = o.dir_;
      this->size_ = o.size_;
      for(size_t i=0; i < this->size_; i++) {
        this->data_[i] = o.data_[i];
      }
    }

    ~Stack()              // destructor
    {

    }

    Stack& operator = (const Stack &o) // assignment operator
    {
      this->ofc_ = o.ofc_;
      this->dir_ = o.dir_;
      this->size_ = o.size_;
      for(int i=0; i < this.size_; i++) {
        this->data_[i] = o.data_[i];
      }
      return *this; 
    }

  private:
    const size_t capacity_;  // = N = size of array   - fixed during life of stack
    T            data_[N];   // statically declared array of T objects    - where T objects are stored
    size_t       size_;      // current size of stack - dynamic during life of stack

  public:
    void  Display(std::ostream& os) const // output stack contents through os - depends on ofc_ and dir_
    {
      if(dir_ >= 0) 
      {
        for(size_t i = 0; i < size_; i++)
        {
          if(ofc_ != '\0') 
            os << ofc_;
          os << data_[i];
        }
      }
      else 
      {
        for(int i = size_-1; i >= 0; i--)
        {
          if(ofc_ != '\0') 
            os << ofc_;
          os << data_[i];
        }
      }
    }
    
    void SetOFC(char ofc)
    {
      this->ofc_ = ofc;
    }

    void  SetDIR(int dir)
    {
      this->dir_ = dir;
    }

    void  Dump(std::ostream& os) const // output all private data (for development use only)
    {
      Display(os);
      os << "\ncapacity_ " << capacity_ <<  "\n";
      os << "size_ " << size_ << "\n";
      os << "ofc " << ofc_ << "\n";
      os << "dir " << dir_ << "\n";
    }
    
  private:
    char    ofc_;
    int     dir_;
  };

}
#endif
