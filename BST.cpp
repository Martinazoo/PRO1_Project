//--------------------------
// Mètodes privats auxiliars
//--------------------------

template <typename T>
void BST<T>::clear(Item *node) {
	if (node != NULL) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

template <typename T>
typename BST<T>::Item* BST<T>::insert(Item *node, const T& d) {
	if (node == NULL) {
		node = new Item(d, NULL, NULL);
	} else if (d < node->data) {
		node->left = insert(node->left, d);
	} else {
		node->right = insert(node->right, d);
	} 
	return node;
}

template <typename T>
typename BST<T>::Item* BST<T>::remove(Item *node, const T& d) {
	if (node == NULL) {
		return NULL;
	} else if (d > node->data) {
		node->right = remove(node->right, d);
	} else if (d < node->data) {
		node->left = remove(node->left, d);
	} else if (node->left != NULL and node->right != NULL) {
		// Node has two children
		Item *tmp = node->right;
		while (tmp->left != NULL) {
			tmp = tmp->left;
		}
		node->data = tmp->data;
		node->right = remove(node->right, node->data);
	} else {
		// Node has at most one child
		Item *tmp = node;
		if (node->left == NULL) {
			node = node->right;
		} else if (node->right == NULL) {
			node = node->left;
		}
		delete tmp;
	}
	return node;
}

template <typename T>
void BST<T>::setValue(Item *node, const T& d, const T& value) {
	Item *temp = find(node, d);
	if (temp != NULL) {
		temp->data = value;
	} else {
		cerr << "Error: Node not found!" << endl;
	}
}


//-------------
// Constructors
//-------------

template <typename T>
BST<T>::BST() {
	root = NULL;
}


//-------------
// Destructor
//-------------

template <typename T>
BST<T>::~BST() { 
	clear(root); 
}


//-------------
// Modificadors
//-------------

template <typename T>
void BST<T>::insert(const T& d) { 
	root = insert(root, d); 
}

template <typename T>
void BST<T>::remove(const T& d) { 
	root = remove(root, d); 
}

template <typename T>
void BST<T>::setValue(const T& d, const T& value) { 
	setValue(root, d, value); 
}


//-----------
// Consultors
//-----------


template <typename T>
void BST<T>::find_aux(Item *r, T& d, bool& trobat) const{

	if (r != NULL and !trobat){
		if (r->data == d){
			trobat = true;
			d = r->data;
		} else{
			if (r->data < d){
				//HI: alçada del arbre = alçada del arbre - 1
				find_aux(r->right, d, trobat);
			} else{
				//HI: alçada del arbre = alçada del arbre - 1
				find_aux(r->left, d, trobat);
			}
		} 
	} 
}

template <typename T> /* Retorna un boolea i un value */
pair<bool, T> BST<T>::find(const T& d) const { 
	T pac = d;
	bool trobat = false;
	find_aux(root, pac, trobat);
	return pair<bool, T>(trobat, pac);
}