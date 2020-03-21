#ifndef DLINK_SEQ_H_
#define DLINK_SEQ_H_

#include <cassert>
#include <cstddef>
#include <memory>
#include <utility>

//sequences are wrapped in a unique ptr
template <typename E> class DLinkSeqConstIter;

/** Seq ADT */
template <typename E>
class DLinkSeq : public Seq<E> {

public:
    
    DLinkSeq(int size){
        head = new Node(); //might need to change to raw pointer
        this->size = size;
    }

    static SeqPtr<E> make(int size = 8) {
        return std::make_unique<DLinkSeq<E>>(size);
    }

  /** base destructor */
  ~DLinkSeq() {clear();}
  
  /** clear contents from this seq, making it empty. */
  void clear(){         //Possible memory leak???
      
      if(head->next != nullptr){
          head->next->clear();
      }
      if(head->prev != nullptr){
          head->prev->clear();
      }

    delete head;
      
  }
  
  /** add item to the start of this seq. */
  void unshift(const E& item){
      assert(size < maxSize && "dlink seq overflow"); 
      if(head == nullptr){
        head = new Node();
        head->next = nullptr;
        head->prev = nullptr;
        head->element = item;
        size = 1;
        return;
      }
      auto dlink = new Node();
      dlink->element = item;
      dlink->next = head;
      dlink->prev = nullptr;
      head->prev = dlink;
      head = dlink;
      size++;
      return;
  };
  
  /** remove and return first item from this seq. 
   *  fails if this seq is empty.
   */
  E shift(){
    assert(size > 0 && "shift on empty dlink seq"); 
    int x = head->element;
    auto tmp = head;
    head = head->next;
    delete tmp; 
    size--;
    return element;
  };
  
  /** add item at the end of this seq. */
  void push(const E& item){

    assert(size < maxSize && "dlink seq overflow");

      if(head == nullptr){
        head = new Node();
        head->next = nullptr;
        head->prev = nullptr;
        head->element = item;
        size = 1;
        return;
      }
      
    auto tmp = new Node({item, nullptr, nullptr});

    auto ptr = head;

    while(ptr->next != nullptr){
        ptr = ptr->next();
    }

    ptr->next = tmp;
    tmp->prev = ptr;

    size++;

  };
  
  /** remove and return last item from this seq.
   *  fails if this seq is empty.
   */
    E pop(){
        assert(size > 0 && "empty dlink seq");

        auto tmp = new Node({item, nullptr, nullptr});

        auto ptr = head;

        while(ptr->next != nullptr){
            ptr = ptr->next();
        }

        int x = ptr->element;

        delete ptr;

        size--;

        return x;
    }
  
  /** return number of elements in this seq. */
  int size(){
      return size;
  }

  /** return an iterator initialized to start of this seq */
  ConstIterPtr<E> cbegin(){
      
  }

  /** return an iterator initialized to end of this seq */
  virtual ConstIterPtr<E> cend() const = 0;

private: 

    typedef struct Node{
        E element;
        DLinkSeq* next;
        DLinkSeq* prev;
    } Node;

    int maxSize;
    int size = 0; 

    Node *head;

};

/** const iterator: not possible to change underlying element E */

template <typename E>
class DLinkSeqConstIter : public ConstIter<E> {
public:

  DLinkSeqConstIter(const DLinkSeq<E>* const seq, bool isHead=true){
      ptr = seq->head;
      if(!isHead){
          while(ptr != NULL && ptr->next != NULL){
              ptr = ptr->next;
          }
      }
  }

  /** pre-increment */
  DLinkSeqConstIter& operator++() {
    ptr = ptr->next;
    return *this;
  }

  /** pre-decrement */
  DLinkSeqConstIter& operator--() {
    ptr = ptr->prev;
    return *this;
  }

  // /** post-increment */
  // ArraySeqConstIter& operator++(int) { }

  // /** post-decrement */
  // ArraySeqConstIter& operator--(int) { }

  /** return true iff this pointer is not "NULL" */
  virtual operator bool() {
    return ptr != NULL;
  }

  /** Return element this is pointing to */
  const E& operator*() {
    return ptr->element;
  }

  /** Return pointer to element this is pointing to */
  const E* operator->() {
    return &ptr->element;
  }

private:
  Node *ptr;
};




#endif //ifndef SEQ_H_
