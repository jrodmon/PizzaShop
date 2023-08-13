
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTree.h"

template<class ItemType>
class BinarySearchTree : public BinaryTree<ItemType>
{
public:
    // insert a node at the correct location
    bool insert(const ItemType &item);
    // remove a node if found
    bool remove(const ItemType &item);

    bool deleteNode(const ItemType &item);

    bool search(const ItemType &target, ItemType &returnedItem) const;
    // find the smallest node
    bool findSmallest(ItemType &returnedItem) const;
    // find the largest node
    bool findLargest(ItemType &returnedItem) const;

    bool minimumKey(ItemType &returnedItem)const;

    void removeRoot() const;

private:
	// internal insert node: insert newNode in nodePtr subtree
	BinaryNode<ItemType>* _insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNode);

	// search for target node
	BinaryNode<ItemType>* _search(BinaryNode<ItemType>* treePtr, const ItemType &target) const;

   // find the smallest node
   BinaryNode<ItemType>* _findSmallest(BinaryNode<ItemType>* nodePtr, ItemType &smallest) const;

   // find the largest node
   BinaryNode<ItemType>* _findLargest(BinaryNode<ItemType>* nodePtr, ItemType &smallest) const;

    // internal remove node: locate and delete target node under nodePtr subtree
    // BinaryNode<ItemType>* _remove(BinaryNode<ItemType>* nodePtr, const ItemType target, bool &success);

     // delete target node from tree, called by internal remove node
     BinaryNode<ItemType>* _deleteNode(BinaryNode<ItemType>*rootPtr, BinaryNode<ItemType>* targetNodePtr);

         // delete target node from tree, called by internal remove node
     //BinaryNode<ItemType>* _removeNode(BinaryNode<ItemType>* targetNodePtr);

     // remove the leftmost node in the left subtree of nodePtr
     //BinaryNode<ItemType>* _removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType &successor);


};

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType & newEntry)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
	this->rootPtr = _remove(this->rootPtr, newNodePtr);
	return true;
}
///////////////////////// public function definitions ///////////////////////////
//Wrapper for _insert - Inserting items within a tree
template<class ItemType>
bool BinarySearchTree<ItemType>::insert(const ItemType & newEntry)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
	this->rootPtr = _insert(this->rootPtr, newNodePtr);
	return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::deleteNode(const ItemType & item)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(item);
	this->rootPtr = _deleteNode(this->rootPtr, newNodePtr);
	return true;
}
//Wrapper for _search
// - it calls the private _search function that returns a Node pointer or NULL
// - if found, it copies data from that node and sends it back to the caller
//   via the output parameter, and returns true, otherwise it returns false.
template<class ItemType>
bool BinarySearchTree<ItemType>::search(const ItemType& anEntry, ItemType & returnedItem) const
{
    BinaryNode<ItemType>* temp = nullptr;
   /* Write your code here */


   temp = _search(BinaryTree<ItemType>::rootPtr, anEntry);
//_search(BinaryNode<ItemType>* nodePtr,const ItemType &target) const


   if(temp)//got something
   {
       returnedItem = temp->getItem(); //output/return parameter gets data

       return true;//flag to true, found
   }
    else //got nothing
        return false;//not found
}



//////////////////////////// private functions ////////////////////////////////////////////


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_deleteNode(BinaryNode<ItemType>* rootPtr ,BinaryNode<ItemType>* targetNodePtr)
{
    if(rootPtr != nullptr)
    {
         BinaryNode<ItemType>* node = rootPtr;
        //int key = rootPtr->key;

        if(rootPtr->getLeftPtr() == NULL && rootPtr->getRightPtr() == NULL)
        {
            rootPtr = nullptr;
            delete node;

        }
        else if(rootPtr->getLeftPtr() ==NULL && rootPtr->getRightPtr()  != NULL)
        {

            rootPtr = rootPtr->getRightPtr() ;
            node->setRightPtr(nullptr);
        }
        else if(rootPtr->getLeftPtr() !=NULL && rootPtr->getRightPtr() == NULL)
        {

            rootPtr= rootPtr->getLeftPtr();
            node->setLeftPtr(nullptr);
            delete node;
            //key = rootPtr->key;
        }
    }


}



//Implementation of the insert operation
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr,
                                                          BinaryNode<ItemType>* newNodePtr)
{
    BinaryNode<ItemType>* pWalk = nodePtr, *parent = nullptr;

    if( !nodePtr) // == NULL
    {
        nodePtr = newNodePtr;
        return nodePtr;

    }
    else
    {
        while(pWalk) // != NULL
        {
            parent = pWalk;
            if (pWalk->getItem() > newNodePtr->getItem())
                pWalk = pWalk->getLeftPtr();
            else
                pWalk = pWalk->getRightPtr();
        }
        if (parent->getItem() > newNodePtr->getItem())
            parent->setLeftPtr(newNodePtr);
        else
            parent->setRightPtr(newNodePtr);
    }

    return nodePtr;
}

//Implementation for the search operation
// - return NULL if target not found, otherwise
// - returns a pointer to the node that matched the target
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_search(BinaryNode<ItemType>* nodePtr,const ItemType &target) const
{
    BinaryNode<ItemType>* found = nullptr;

    /* Write your code here */

    if(nodePtr == found) //==nullptr
        return found;

    else if(nodePtr->getItem()>target)
        { found =  _search(nodePtr->getLeftPtr(), target);}
            //when target is smaller

    else if(nodePtr->getItem()<target)
        {found = _search(nodePtr->getRightPtr(), target);}


    else//==target
        {return nodePtr;}

        return found;

}




#endif


