//--------------------------
// Mètodes privats auxiliars
//--------------------------

template <typename T>	
void Queue<T>::copyItems(const Item *item, Item *(&first), Item *(&last), int &_size) {
	if (item == NULL) {
		first = NULL;
		last = NULL;
		_size = 0;
		return;
	}
	first = new Item();
	first->value = item->value;
	last = first;
	_size = 1;
	while (item->next != NULL) {
		last->next = new Item();
		last = last->next;
		item = item->next;
		last->value = item->value;
		_size++;
	}
	last->next = NULL;
}

template <typename T>
void Queue<T>::deleteItems(Item *item) {
	while (item != NULL) {
		Item *aux = item;
		item = item->next;
		delete aux;
	}
}


//-------------
// Constructors
//-------------

template <typename T>
Queue<T>::Queue() {
	first = last = NULL;
	_size = 0;
}

template <typename T>
Queue<T>::Queue(Queue &q) {
	copyItems(q.first, first, last, _size);
}


//-------------
// Destructor
//-------------

template <typename T>
Queue<T>::~Queue() {
	deleteItems(first);
	_size = 0;
}


//-------------
// Modificadors
//-------------

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue &q) {
	if (this != &q) {
		deleteItems(first);
		copyItems(q.first, first, last, _size);
	}
	return *this;
}

template <typename T>
void Queue<T>::pop() {
	if (first == NULL) {
		cerr << "Error: pop on empty queue" << endl;
		exit(0);
	}
	Item *aux = first;
	first = first-> next;
	delete aux;
	_size--;
	if (first == NULL) last = NULL;
}

template <typename T>
void Queue<T>::push(T value) {
	Item *pitem = new Item();
	pitem->value = value;
	_size++;
	if (first == NULL or value.compare(first->value)) {
		pitem->next = first;
		first = pitem;
		if (last == NULL) last = first;
		return;
	}
	Item *current = first;
	while (current->next != NULL and not (value.compare(current->next->value)))
		current = current->next;
	pitem->next = current->next;
	current->next = pitem;
	if (last == current) last = pitem;
}

template <typename T>
void Queue<T>::remove(T value) {
	
	if (first == NULL) {
		return;
	}
	
	Item* pfirst = first;
	if (pfirst->value == value){
		delete first;
		first = pfirst->next;
	} else {
		Item* pseg = pfirst->next;
		bool trobat = false;
		while (pseg != NULL and !trobat){
			if (pseg->value == value){
				if (pseg->next == NULL) last = pfirst;
				pfirst->next = pseg->next;
				delete pseg;
				trobat = true;
			} else {
				pfirst = pseg;
				pseg = pseg->next;
			}
		}
		
	}
}
/*
template <typename T>
void Queue<T>::remove(T value) {
	
	// PROGRAM THIS METHOD

}
*/
//-----------
// Consultors
//-----------

template <typename T>
T Queue<T>::front() const {
	if (first == NULL) {
	cerr << "Error: front on empty queue" << endl;
	exit(0);
	}
	return first->value;
}	

template <typename T>
T Queue<T>::back() const{
	if (last == NULL) {
	cerr << "Error: front on empty queue" << endl;
	exit(0);
	}
	return last->value;
}

template <typename T>
int Queue<T>::size() const {
	return _size;
}

template <typename T>
bool Queue<T>::empty() const {
	return first == NULL;
}


//-----------
// L/E
//-----------
	
template<typename U>
ostream &operator<<(ostream &os, Queue<U> &q) {
  os << q._size;
  for (typename Queue<U>::Item *item = q.first; item != NULL; item = item->next)
    os << " " << item->value;
  return os;
}

template<typename U>
istream &operator>>(istream &is, Queue<U> &q) {
  int size;
  is >> size;
  if (size == 0) {
    q = Queue<U> ();
    return is;
  }
  for (int i = 0; i < size; ++i) {
    U x;
    cin >> x;
    q.push(x);
  }
  return is;
}
