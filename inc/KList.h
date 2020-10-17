
#ifndef __KLIST_H__
#define __KLIST_H__

// #include "IIterable.h"
// #include "IIterator.h"
#include "KList.h"

template<typename T>
class KList;

template<typename T>
class KListNode
{
  friend class KList<T>;

  T element;
  KListNode* next;

public:
  KListNode(T element)
    : element(element)
    , next(nullptr)
  {}

  bool operator!=(KListNode const& other) { return element == other.element; }
};

template<typename T>
class KList
{
  KListNode<T>* beginNode;
  KListNode<T>* endNode;

public:
  KList();

  void Append(T element);

  class Iterator
  {
    KListNode<T>* node;

  public:
    Iterator()
      : node(nullptr)
    {}

    Iterator(KListNode<T>* node)
      : node(node)
    {}

    bool operator!=(Iterator const& other) const { return node != other.node; }
    Iterator const& operator++()
    {
      node = node->next;
      return *this;
    }
    T& operator*() { return node->element; }
  };

  Iterator begin() { return Iterator(beginNode); }
  Iterator end() { return Iterator(nullptr); }
};

template<typename T>
KList<T>::KList()
{
  beginNode = nullptr;
  endNode = nullptr;
}

template<typename T>
void
KList<T>::Append(T element)
{
  KListNode<T>* newNode = new KListNode<T>(element);
  if (!beginNode)
    beginNode = endNode = newNode;
  else
    endNode->next = newNode;
  endNode = newNode;
}

#endif // __KLIST_H__