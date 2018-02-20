# ifdef _QUEUE_H_
#include <iostream>


// default constructor
template <typename T>
Queue<T>::Queue()
{
	ArrayClass<T> ac;
	front = 0;
	_size = ac.size();
}

// copy constructor
template<typename T>
Queue<T>::Queue(const Queue& qq)
{
	ac = qq.ac;
}

// assignment operator
template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& qq)
{	
	ac = qq.ac;
	_size = qq.size();
	front = 0;
	return *this;
}

    ///////////////
    // accessors //
    ///////////////

// Return true if the queue contains no items
template<typename T>
bool Queue<T>::isEmpty() const
{
	return ac.empty();
}

// Returns the number of items stored in the queue
template<typename T>
unsigned int Queue<T>::size() const
{
	return ac.size();
}

// Return a reference to the front item of the queue
// Throws an out_of_range exception if the queue is empty
template<typename T>
T& Queue<T>::peek()
{
	return ac.at(front);	
}

    //////////////
    // mutators //
    //////////////

// Inserts an item to the back of the queue
template<typename T>
void Queue<T>::enqueue(const T item)
{
	//TODO not sure if it's the right func to use
	//using circular array
	 ac.insert((front + ac.size() % ac.capacity()), item);
     	_size++;

     
}

// Removes and returns (a copy of) the front item of the queue
// Throws an out_of_range exception if the queue is empty
template<typename T>
T Queue<T>::dequeue()
{
	if (isEmpty()) throw std::out_of_range("Out of range : the array is empty");

	T retFront = ac.at(front);
	ac.erase(front);
	_size--;
	//front = (front + 1) % ac.capacity();
	front = 0;
	return retFront;
}

#endif
