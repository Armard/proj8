#ifndef __TQUEUE_H__
#define __TQUEUE_H__

#include <cstdlib>
#include <iostream>
using namespace std;

namespace fsu {
	template < typename T >
	class Queue
	{
	public:
	  void  Push(const T& t)
	  {
	  	Link *newLink = new Link(t);

	  	if(lastLink_ == nullptr) 
	  	{
	  		lastLink_ = newLink;
	  		firstLink_ = newLink;
	  	}
	  	else 
	  	{
	  		lastLink_->nextLink_ = newLink;
	  		lastLink_ = newLink;
	  	}
	  	size_++;
	  }

	  T Pop()
	  {
	  	if(firstLink_ == nullptr)
	  	{
	  		throw std::out_of_range("Stack empty");
	  	}

	  	Link *head_val = firstLink_;
	  	firstLink_ = firstLink_->nextLink_;
	  	T ret_value = head_val->element_;
	  	delete head_val;
	  	size_--;
	  	return ret_value;
	  }

	  T& Front()
	  {
	  	if(firstLink_ == nullptr)
	  	{
	  		throw std::out_of_range("Stack empty");
	  	}

	  	return firstLink_->element_;
	  }

	  const T& Front() const
	  {
	  	if(firstLink_ == nullptr)
	  	{
	  		throw std::out_of_range("Stack empty");
	  	}

	  	return firstLink_->element_;
	  }

	  size_t Size() const
	  {
	  	return size_;
	  }

	  bool Empty() const
	  {
	  	return firstLink_ == nullptr;
	  }

	  void Clear()
	  {
	  	Link *working_p = firstLink_;
	  	while(working_p != nullptr)
	  	{
	  		Link *delete_p = working_p;
	  		working_p = working_p->newLink_;
	  		delete delete_p;
	  	}
	  }

	  // extra goodies
	  size_t Capacity() const
	  {
	  	return 0; // not really relevant here
	  }

	  void Append(const Queue& q)
	  {
	  	lastLink_->nextLink_ = q.firstLink_;
	  	lastLink_ = q.lastLink_;
	  }

	  void Release()
	  {
	  	Link *working_p = firstLink_;
	  	while(working_p != nullptr)
	  	{
	  		Link *delete_p = working_p;
	  		working_p = working_p->nextLink_;
	  		delete delete_p;
	  	}	
	  }
	
	public:
	  Queue()              // default constructor
	  {
	  	firstLink_ = nullptr;
	  	lastLink_ = nullptr;
	  	ofc_ = '\0';
	  	size_ = 0;
	  }

	  Queue(char ofc)      // sets output formatting character
	  {
	  	firstLink_ = nullptr;
	  	lastLink_ = nullptr;
	  	ofc_ = ofc;
	  	size_ = 0;	
	  }

	  Queue(const Queue &o)  // copy constructor
	  {
	  	firstLink_ = nullptr;
	  	lastLink_ = nullptr;
	  	ofc_ = o.ofc_;
	  	size_ = o.size_;
	  	Link *working_p = o.firstLink_;
	  	while(working_p != nullptr)
	  	{
	  		Push(working_p->element);
	  		working_p = working_p->newLink_;
	  	}	
	  }

	  ~Queue()              // destructor
	  {
	  	Release();
	  }

	  Queue& operator = (const Queue &o)  // assignment operator
	  {
	  	this->firstLink_ = nullptr;
	  	this->lastLink_ = nullptr;
	  	this->ofc_ = o.ofc_;
	  	this->size_ = o.size_;
	  	Link *working_p = o.firstLink_;
	  	while(working_p != nullptr)
	  	{
	  		this->Push(working_p->element);
	  		working_p = working_p->newLink_;
	  	}

	  	return *this;
	  }
	
	public:
	  void Display(std::ostream& os) const // output queue contents through os - depends on ofc
	  {
	  	Link *working_p = firstLink_;
	  	while(working_p != nullptr)
	  	{
	  		if(ofc_ != '\0')
	  			os << ofc_;
	  		os << working_p->element_;
	  		working_p = working_p->nextLink_;
	  	}
	  }

	  void SetOFC(char ofc)         // sets output formatting character
	  {
	  	ofc_ = ofc;
	  }

	  void Dump(std::ostream& os) const // output all private data (for development use only)
	  {
	  	Display(os);
	  	os << "Size_ " << size_ << "\n";
	  	os << "ofc_ " << ofc_ << "\n";
	  }
	  
	private:
	  char    ofc_;

	private:
	  class Link
	  {
	    Link ( const T& t ) : element_(t), nextLink_(nullptr) {}
	    T      element_;
	    Link * nextLink_;
	    friend class Queue<T>;
	  };
	  
	  Link * firstLink_;
	  Link * lastLink_;
	  int size_;
	};

}

#endif