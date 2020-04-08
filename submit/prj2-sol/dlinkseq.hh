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

  friend class DLinkSeqConstIter<E>;

public:
    
    DLinkSeq(int size){
        head = nullptr;//new Node(); //might need to change to raw pointer
        this->maxSize = size;
    }

    static SeqPtr<E> make(int size = 8) {
        return std::make_unique<DLinkSeq<E>>(size);
    }

  /** base destructor */
  ~DLinkSeq() {clear();}
  
  /** clear contents from this seq, making it empty. */
  void clear(){         //Possible memory leak???
      
    for(int i = 0; i < currSize; i++)
    {
      pop();
    }

    currSize = 0;

  };
  
  /** add item to the start of this seq. */
  void unshift(const E& item){
      assert(currSize < maxSize && "dlink seq overflow"); 
      if(head == nullptr){
        head = new Node();
        head->next = nullptr;
        head->prev = nullptr;
        head->element = item;
        currSize++;
        return;
      }
      auto *dlink = new Node();
      dlink->element = item;
      dlink->next = head;
      dlink->prev = nullptr;
      head->prev = dlink;
      head = dlink;
      currSize++;
      return;
  };
  
  /** remove and return first item from this seq. 
   *  fails if this seq is empty.
   */
  E shift(){
    assert(currSize > 0 && "shift on empty dlink seq"); 
    int x = head->element;
    auto tmp = head;
    head = head->next;
    head->prev = nullptr;
    delete tmp; 
    currSize--;
    return x;
  };
  
  /** add item at the end of this seq. */
  void push(const E& item){

    assert(currSize < maxSize && "dlink seq overflow");

      if(head == nullptr){
        head = new Node();
        head->next = nullptr;
        head->prev = nullptr;
        head->element = item;
        //std::cout << "head elem : " << head->element << "\n item: " << item << std::endl;
        currSize++;
        return;
      }
      
    auto tmp = new Node({item, nullptr, nullptr});

    auto ptr = head;

    while(ptr->next != nullptr){
        ptr = ptr->next;
    }

    

    ptr->next = tmp;
    tmp->prev = ptr;

    currSize++;

  };
  
  /** remove and return last item from this seq.
   *  fails if this seq is empty.
   */
    E pop(){
        assert(currSize > 0 && "empty dlink seq");

        //auto tmp = new Node({0, nullptr, nullptr});

        auto ptr = head;

        while(ptr->next != nullptr){
            ptr = ptr->next;
        }

        int x = ptr->element;

          if(ptr->prev == nullptr){
            head = nullptr;
          }else{
            ptr->prev->next = nullptr;
            //ptr->next->prev = nullptr;
            delete ptr;
          }

        currSize--;

        return x;
    }

  /** return number of elements in this seq. */
  int size() const{
      return currSize;
  }

  /** return an iterator initialized to start of this seq */
  ConstIterPtr<E> cbegin() const {
    const DLinkSeq* constThis = static_cast<const DLinkSeq*>(this);
    return std::make_unique<DLinkSeqConstIter<E>>(constThis);
  }

  /** return an iterator initialized to end of this seq */
  ConstIterPtr<E> cend() const {
    const DLinkSeq* constThis = static_cast<const DLinkSeq*>(this);
    return std::make_unique<DLinkSeqConstIter<E>>(constThis, false);
  }

private: 

    typedef struct Node{
        E element;
        Node* next;
        Node* prev;
    } Node;

    int maxSize;
    int currSize = 0; 

    Node *head = nullptr;

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

  typename DLinkSeq<E>::Node *ptr;
};




#endif //ifndef SEQ_H_
