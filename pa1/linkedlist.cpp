#include "linkedlist.h"
#include "kebab.h"

//default constructor
  LinkedList::LinkedList() {
	length = 0;
  	front = NULL; 
  	back = NULL;
  }

  // helper function for deep copy
  // Used by copy constructor and operator=
  // should create new Kebab objects
  void LinkedList::copyList(const LinkedList& ll){
	//removing the existing list first what leads the front and back to be pointed to NULL
	this->deleteList();		
	//getting the front of the given list
	Node* curr = ll.front;
	
	while(curr->next != NULL){
		this->insertBack(curr->data);
		curr = curr->next;	
        }
  }

  void LinkedList::deleteList(){
	Node* curr = LinkedList::front;

	//if there is only one member in the list
	if(curr->next == NULL){
		delete curr;
	}	
	//when there are more than one member in the list
	else{
		while(curr->next != NULL){
			delete curr->data;
			curr->data = NULL;
			curr = curr->next;
		}
	 }
	length = 0;
	front = NULL;
	back = NULL;
	return;
  }

  // copy constructor, performs deep copy of list elements
  LinkedList::LinkedList(const LinkedList& ll){
	copyList(ll);
  }

  // destructor
  LinkedList::~LinkedList(){
	deleteList();
  }

  // MUTATORS

  // Inserts an item at the front of the list
  // POST:  List contains item at position 0
  // PARAM: item = item to be inserted
  void LinkedList::insertFront(Kebab* item){
	Node* curr = new Node(item);

	if(LinkedList::length != 0){
		curr->data = item;
		curr->next = LinkedList::front;
		LinkedList::front = curr;
		LinkedList::length++;
		return;
	}
		curr->data = item;
		curr->next = LinkedList::front;
		LinkedList::front = curr;
		LinkedList::back = curr;
		LinkedList::length++;
		return;
  }

  // Inserts an item at the back of the list
  // POST:  List contains item at back
  // PARAM: item = item to be inserted
  void LinkedList::insertBack(Kebab* item){
	Node* node = LinkedList::back;
	Node* curr = new Node(item);
	curr->data = item;
	curr->next = NULL;
		
	//if the list has more than one member
	if(LinkedList::length != 0){
		node->next = curr;
		LinkedList::back = curr;
		LinkedList::length++;
		return;
	}
	//if the list is empty
		LinkedList::front = curr;
		LinkedList::back = curr;	
		LinkedList::length++;
		return; 
  }

  // Inserts an item in position p (0-indexed)
  // Returns false for invalid index
  // PRE:   0 <= p <= size
  // POST:  List contains item at position p
  // PARAM: item = item to be inserted, p = position where item will be inserted
  bool LinkedList::insertAt(Kebab* item, unsigned int p){
	Node* insert = new Node(item);
	Node* curr = front;
	Node* next;
	unsigned int i = 0;
	
	//invalid index
	if(p > length) return false;
	//inserting at the back
	if(p == (length-1)){
		insertBack(item);
		return true;
	}
	//inserting at the front
	if(p == 0){
		insertFront(item);
		return true;
	}
	//for the other cases
	while(p > i){
		curr = curr->next;
		i++;
	}
	next = curr->next;
	curr->next = insert;
	insert->next = next;
	length++;
	return true;
  }

  // Removes and returns an item from position p (0-indexed)
  // Return NULL if index is invalid
  // PRE:   0 <= p < size
  // POST:  Item is removed from list.
  //        Node is deallocated but Kebab should in memory
  //        Thus set data to NULL before deleting
  // PARAM: p = position from where item will be removed
  Kebab* LinkedList::removeAt(unsigned int p){
	Node* curr = front;
	Node* prev = front;
	Node* next = front->next;
	Node* temp;
	unsigned int index = 0;
	
	if (LinkedList::length <= p) return NULL;
	
	if (p == 0){
		curr->data = NULL;
		delete curr;
		front = next;
		--length;
		return prev->data;
		}

	while(next != NULL && index != p){
		prev = curr;
		curr = next;
		next = next->next;
		++index;
	}

 	if (index != p) return NULL;
	else if (next == NULL){
		temp = curr;
		curr->data = NULL;
		delete curr;
		--length;
		prev->next = NULL;
		return temp -> data;
	}
	else {	temp = curr;
		curr->data = NULL;
		delete curr;
		--length;
		prev->next = next;
		return temp->data;
	}
  }

  // ACCESSORS
  // Returns size of list
  unsigned int LinkedList::size() const {
	return length;
  }

  // Returns whether the list is empty
  bool LinkedList::isEmpty() const {
	if (length != 0) return false;
	return true;
  }

  // Returns existence of a Kebab that has at least
  //   all the same ingredients as k, in any order
  //   i.e. the list has a Kebab whose ingredients
  //   are a super-multiset of k's ingredients
  bool LinkedList::contains(Kebab& k) const {
	Node* curr = LinkedList::front;
	bool sameIngredients = false;

	while(curr->next != NULL){
		sameIngredients = (curr->data)->hasSameIngredients(k);
		if (sameIngredients == true) break;
		curr = curr->next;
	}	
	return sameIngredients;
  }

  // Returns item at index (0-indexed)
  // Returns NULL if index is invalid
  Kebab* LinkedList::elementAt(unsigned int p) const{
	Node* curr = front;
	unsigned int i = 0;

	if(p >=length) return NULL;
	
	while (i != p){
		curr = curr->next;
		++i;
	}
	return curr->data;
  }

  // OVERLOADED OPERATORS

  // overloaded assignment operator
  // must work in the following cases:
  // list2 = list1 -> general case
  // list2 = list2 -> should do nothing
  LinkedList& LinkedList::operator=(const LinkedList& ll){
	if (this != &ll){
		delete this;
		LinkedList(ll);
	}
	return *this;
 }
