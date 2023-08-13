/* *~*~*
Stack template
Written By: Henry Tran
*~**/

#ifndef STACK_H
#define STACK_H
#include "StackNode.h"

template <class ItemType>
class Stack
{
private:
    StackNode<ItemType> *top;     // Pointer to the stack top
    int length;

public:
    // Constructor
    Stack() { top = NULL; length = 0; }
    
    // Destructor
    ~Stack();

    // Stack operations:
    // push()
    bool push(ItemType);
    
    // pop()
    ItemType pop();
    
    // peek()
    ItemType peek() { return top->getItem(); }
    
    // isEmpty()
    bool isEmpty() { return length == 0; }
    
    // getLength()
    int getLength() { return length; }
};

/**~*~*~*~*
  Member function push inserts the argument onto
  the stack.
*~**/
template <class ItemType>
bool Stack<ItemType>::push(ItemType item)
{
   StackNode<ItemType> *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode<ItemType>;
   if (!newNode)
       return false;
   newNode->setItem(item);

   // Update links and counter
   newNode->setNext(top);
   top = newNode;
   length++;

   return true;
}

template <class ItemType>
ItemType Stack<ItemType>::pop()
{
   StackNode<ItemType> *temp; // Temporary pointer

   ItemType item = top->getItem();
   temp = top->getNext();
   delete top;
   top = temp;
   length--;

   return item;
}

/**~*~*~*~*
  Destructor:
  Traverses the list deleting each node (without calling pop)
*~**/
template <class ItemType>
Stack<ItemType>::~Stack()
{
   StackNode<ItemType> *currNode;

   // Position nodePtr at the top of the stack.
   currNode = top;

   // Traverse the list deleting each node.
   while (currNode)
   {
      // Set top to the next node of the stack.
      top->setNext(currNode->getNext());
      
      // Release the memory.
      delete currNode;
      
      // Position currNode at the next node.
      currNode = top;
   }
}

#endif
