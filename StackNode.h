/* *~*~*
Stack node template
Written By: Henry Tran
*~**/

#ifndef STACKNODE_H
#define STACKNODE_H

template <class ItemType>
class StackNode
{
private:
    ItemType item;          // Value in the node
    StackNode *next;  // Pointer to next node

public:
    //Constructor
    StackNode() {next = NULL;}
    StackNode(const ItemType &anItem, StackNode *nextPtr = NULL){ item = anItem; }
    
    // setters
    void setItem(ItemType anItem) {item = anItem;}
    void setNext(StackNode* nextPtr) {next = nextPtr;}

    // getters
    ItemType getItem() const {return item;}  // return data object in the stacknode
    StackNode *getNext() const {return next;}

};

#endif
