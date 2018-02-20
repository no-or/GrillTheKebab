// file:        arrayclass.cpp
// author:      Geoff T
// date:        2017-10-13
// description: implementation of a dynamic array class for CPSC 221 PA2

#ifdef _ARRAYCLASS_H_

// default constructor
// Creates an empty ArrayClass with DEFAULTCAPACITY
template <typename T>
ArrayClass<T>::ArrayClass()
{
  // The following is stub code only.
  // Please replace with your own implementation
_capacity = DEFAULTCAPACITY;
_size = 0;
arr = new T[_capacity];
}

// parameterized constructor
// Creates an empty ArrayClass with capacity of n
template <typename T>
ArrayClass<T>::ArrayClass(unsigned int n)
{
  // The following is stub code only.
  // Please replace with your own implementation
_capacity = n;
_size = 0;
arr = new T[_capacity];
}

// copy constructor
// Creates an ArrayClass as a deep copy of the parameter
template <typename T>
ArrayClass<T>::ArrayClass(const ArrayClass& ac)
{
  // The following is stub code only.
  // Please replace with your own implementation

//HELPER FUNCTION
copyArray(ac); 
}

// destructor
template <typename T>
ArrayClass<T>::~ArrayClass()
{

delete [] arr;

}

// overloaded assignment operator
template <typename T>
ArrayClass<T>& ArrayClass<T>::operator=(const ArrayClass& ac)
{
  // The following is stub code only.
  // Please replace with your own implementation
	// if (this == &ac) return *this;
	// copyArray(ac); 
 //        return *this;

	  // Delete original
  delete [] arr;

  // Re-assign values
  _capacity = ac.capacity();
  _size = ac.size();
  
  // Deep copy array
  T* newArray = new T[_capacity]; 
  
  for (int i = 0; i < _size; i++) {
    T item = ac.arr[i];    
    newArray[i] = item;
  }
  arr = newArray;
  return *this; 
}

////////////////////////
// capacity functions //
////////////////////////

// Returns the number of elements stored in the array
template <typename T>
unsigned int ArrayClass<T>::size() const
{
  // The following is stub code only.
  // Please replace with your own implementation
  return _size;
}

// Returns the maximum capacity of the array
template <typename T>
unsigned int ArrayClass<T>::capacity() const
{
  // The following is stub code only.
  // Please replace with your own implementation
  return _capacity;
}

// Resizes the array
// If n is smaller than the size, then only the
//   first n elements are copied to the new array
template <typename T>
void ArrayClass<T>::resize(unsigned int n)
{
  // The following is stub code only.
  // Please replace with your own implementation
	if (n < _size){

	T* new_array = new T[n];
	_capacity = n;


		for(int i = 0; i < n; ++i){
			new_array[i] = arr[i];
		}

		_size = n;
		delete[] arr;
		arr = new_array;
	}
	else{
		T* new_array = new T[n];
		_capacity = n;

		for(int i = 0; i < _size; ++i){
			new_array[i] = arr[i];
		}
	
		delete[] arr;
		arr = new_array;
	}
return;
}

// Check if array is empty
// return true if array is empty
template <typename T>
bool ArrayClass<T>::empty() const
{
  // The following is stub code only.
  // Please replace with your own implementation
	
  return (_size == 0);
}

// Resizes the array to fit exactly as many items
//   as are stored in the array
template <typename T>
void ArrayClass<T>::shrinkToFit()
{
  // The following is stub code only.
  // Please replace with your own implementation
resize (_size);
}

//////////////////////////////
// element access functions //
//////////////////////////////

// Returns a reference to the element at position i
//   in the array.
// Throws an out_of_range exception if i is outside
//   the bounds of valid elements
template <typename T>
T& ArrayClass<T>::operator[](unsigned int i)
{
  // The following is stub code only.
  // Please replace with your own implementation
if(i > (_capacity - 1)) throw std::out_of_range("The given index is out of bounds");

  T& ret = arr[i];   //ref to ith element
  return ret;
}

// Returns a reference to the element at position i
//   in the array.
// Throws an out_of_range exception if i is outside
//   the bounds of valid elements
template <typename T>
T& ArrayClass<T>::at(unsigned int i)
{
  // The following is stub code only.
  // Please replace with your own implementation
	if(i > (_capacity - 1)) throw std::out_of_range("The given index is out of bounds");

  T& ret = arr[i];
  return ret;
}

// Returns a reference to the first element in the array
// Calling this on an empty array throws out_of_range exception
template <typename T>
T& ArrayClass<T>::front()
{
  // The following is stub code only.
  // Please replace with your own implementation
  if(_size == 0) throw std::out_of_range("The array is empty");

  T& ret = arr[0];
  return ret;
}

// Returns a reference to the last element in the array
// Calling this on an empty array throws out_of_range exception
template <typename T>
T& ArrayClass<T>::back()
{
  // The following is stub code only.
  // Please replace with your own implementation
  if(_size == 0) throw std::out_of_range("The array is empty");

  T& ret = arr[_size-1];
  return ret;
}
//////////////////////
// modify functions //
//////////////////////

// Add an element at the end
// If array is at capacity before adding, then
//   expand the array to double its capacity and
//   then add.
template <typename T>
void ArrayClass<T>::pushBack(const T& item)
{
  // The following is stub code only.
  // Please replace with your own implementation
	if(_size < _capacity) arr[_size] = item;
	else{
		resize(2*_capacity);
		arr[_size] = item;
	}
	_size++;
}

// Removes the last stored element in the array,
//   reducing container size by 1.
// No effect if called on an empty container
template <typename T>
void ArrayClass<T>::popBack()
{
  // The following is stub code only.
  // Please replace with your own implementation
	if(_size == 0) return;
	_size--;
}

// Inserts an element before the element at specified position
// Expands the array if necessary
// Elements to the right of position (inclusive) must be shifted
// Throws out_of_range if position is > _size
// POST: item is at position, all elements formerly at position and beyond are shifted
template <typename T>
void ArrayClass<T>::insert(unsigned int position, const T& item)
{
   if (position > _size) throw std::out_of_range("out of bounds");
// else if (position == _size) pushBack(item);
// else{
// 	if (_capacity == _size) expandArray(); 
// 	 T& temp = arr[position-1];
// 	 T& temp1 = arr[position];
// 	arr[position-1] = item;
// 	_size++;
	
// 	//now do the shift
// 	for (int i = position; i < _size; ++i) //CHECK BOUNDS IF DOES NOT WORK
// 	{
// 		temp1 = arr[i];
// 		arr[i] = temp;
// 		temp = temp1;
// 	}
// 	}

  
  else if (_size + 1 <= _capacity){
    for(int i = _size; i > position; i--){
        arr[i] = arr[i - 1];
    }
    arr[position] = item;
    _size++;
  }
  else{
    resize(_capacity + 1); 
    for(int i = _size; i > position; i--){
      arr[i] = arr[i - 1];
    }
    
    arr[position] = item;
    _size++;
  }

}

// Removes an element from the array at specified position.
// Elements to the right of position will be shifted over to fill the gap
// Throws out_of_range if position is >= _size
template <typename T>
void ArrayClass<T>::erase(unsigned int position)
{
if (position >= _size) throw std::out_of_range("out of bounds");
else{
	 T& temp = arr[position+1];

	//now do the shift
	for (int i = position; i < _size; ++i)
	{
		arr[i] = temp;
		temp = arr[i+1];
	}
	--_size;
	}
}

// Reallocates stored items into a new array of the same size,
//   starting from specified position
// No effect if position is 0 or >= _size
// e.g. startFrom(3) on {1, 2, 3, 4, 5, 6, 7}
//   produces {4, 5, 6, 7, 1, 2, 3}
template <typename T>
void ArrayClass<T>::startFrom(unsigned int position)
{
	if(position >= _size || position == 0) return;

	T* new_array = new T[_capacity];
	int j = 0;
	for (int i = position; i < _size; ++i){
		new_array[j] = arr[i];
		//new_array._size++;
		j++;
	}

	int i = 0;
	while (j < _size && i < position)
	{
		new_array[j] = arr[i];
		//new_array._size++;
		++i;
		++j;
	}
	delete [] arr;
	arr = new_array;
}

//////////////////////
// helper functions //
//////////////////////

// helper method for deep copy
template <typename T>
void ArrayClass<T>::copyArray(const ArrayClass& ac)
{
	T* copy_array = new T[ac._capacity];
	for(int i = 0; i < ac._capacity; ++i){
		copy_array[i] = ac.arr[i];
		//copy_array._size++;
	}
delete [] arr;
arr = copy_array;
}



// helper method for expanding array
template <typename T>
void ArrayClass<T>::expandArray()
{
resize(_capacity * EXPANSIONFACTOR);
}

#endif
