#pragma once
#include <iostream>

// I waisted lots of time on this and I don't think i'll use it =)

template <typename T>
class LinkedList
{
private:

	struct node
	{
		T data;
		node* next;
		node* prev;

		//d is a refrence to the value that is stored
		//n is a pointer to the next node in the list
		//p is a pointer to the previous node in the list
		node(const T& d = T{}, node* n = nullptr, node* p = nullptr) : data{ d }, next{ n }, prev{ p } {}
	};

	node* head;//start of list
	node* tail;//end of list
	int size;//size of list




public:


	// this class allows for itteration though the code
	class iterator
	{
	private:
		node* curr;
		friend class LinkedList;

	public:
		iterator() : curr{ nullptr } {}
		iterator(node* n) : curr{ n } {}

		bool operator==(const iterator& other) const
		{
			return curr == other.curr;
		}

		bool operator!=(const iterator& other) const
		{
			return curr != other.curr;
		}

		T& operator*()
		{
			return curr->data;
		}

		iterator& operator++()
		{
			curr = curr->next;
			return *this;
		}

		iterator operator++(int)
		{
			iterator temp{ curr };
			curr = curr->next;
			return temp;
		}

		iterator& operator--()
		{
			curr = curr->prev;
			return *this;
		}

		iterator operator--(int)
		{
			iterator temp{ curr };
			curr = curr->prev;
			return temp;
		}
	};

	//represents the beining of an iterator
	iterator begin()
	{
		return iterator(head);
	}

	//represents teh end of an iterator
	iterator end()
	{
		return iterator(tail);
	}

	LinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}

	~LinkedList() { Clear(); }


	//insert new node
	typename LinkedList<T>::iterator Insert(const T& val, int pos)
	{
		if (pos<0 || pos>size)
		{
			return nullptr;
		}

		if (pos == 0)
		{
			PushFront(val);
		}
		else if (pos == size)
		{
			PushBack(val);
			return nullptr;
		}

		node* curr = nullptr;

		if (pos > size / 2)
		{
			curr = tail;
			for (int i = size - 1; i > pos + 1; --i)
			{
				curr = curr->prev;
			}
			node* newNode = new node{ val, curr, curr->prev };
			curr->prev->next = newNode;
			curr->prev = newNode;

			++size;

			return iterator(newNode);
		}
		else
		{
			curr = head;
			for (int i = 0; i < pos - 1; ++i)
			{
				curr = curr->next;
			}
			node* newNode = new node{ val, curr->next, curr };
			curr->next->prev = newNode;
			curr->next = newNode;

			++size;

			return iterator(newNode);
		}
	}

	void Remove(int pos)
	{
		if (pos < 0 || pos >= size)
		{
			return;
		}

		if (pos == 0)
		{
			PopFront();
		}
		else if (pos == size - 1)
		{
			PopBack();
		}

		node* temp = nullptr;
		if (pos > size / 2)
		{
			temp = tail;
			for (int i = size - 1; i > pos; --i)
			{
				temp = temp->prev;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		else
		{
			temp = head;
			for (int i = 0; i < pos; ++i)
			{
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
			--size;
			delete temp;
	}


	//adds a new node at the end
	void PushBack(const T& val)
	{
		// creates a new node with val and sets the prev node to be tail
		node* newNode = new node{ val, nullptr, tail };

		// if there is a tail then it will set the node after the tain to be the new node
		// else the head will be set to the new node
		if (tail)
		{
			tail->next = newNode;
		}
		else
		{
			head = newNode;
		}

		tail = newNode;
		++size;
	}

	//adds a new node at the front
	void PushFront(const T& val)
	{
		// creates a new node with val, nad sets the next node to be the head
		node* newNode = new node{ val, head, nullptr };

		//if there is a head then set it's next node to be the new node
		//else set the tail to be the new node
		if (head)
		{
			head->prev = newNode;
		}
		else
		{
			tail = newNode;
		}

		head = newNode;
		++size;
	}

	//removes the node at the end
	void PopBack()
	{
		//check if there is a tail to delete
		if (tail)
		{
			node* temp = tail;
			tail = tail->prev;

			//if the new tail exists then sets the point after it to a nullptr
			//else set the head to a nullptr
			if (tail)
			{
				tail->next = nullptr;
			}
			else
			{
				head = nullptr;
			}
			delete temp;
			--size;
		}
	}

	//removes the node at the start
	void PopFront()
	{
		// checks if there is a head to delete
		if (head)
		{
			node* temp = head;
			head = head->next;

			//if the new head exists the set the prev to nullprt
			//else set the tail to nullptr
			if (head)
			{
				head->prev = nullptr;
			}
			else
			{
				tail = nullptr;
			}
			delete temp;
			--size;
		}
	}

	//get the node at the frount
	T& Front()
	{
		return head->data;
	}

	//get a refrence to the node at the frount
	const T& Front() const
	{
		return head->data;
	}

	// get the node at the back
	T& Back()
	{
		return tail->data;
	}

	//get a refrence to the node at the back
	const T& Back() const
	{
		return tail->data;
	}

	// get the size of the list
	int GetSize() const
	{
		return size;
	}

	// check if the list is empty
	bool Empty() const
	{
		return size == 0;
	}

	// this will find a value by its position
	typename LinkedList<T>::iterator Get(int pos)
	{
		if (pos < 0 || pos >= size)
		{
			return nullptr();
		}

		node* curr = nullptr;

		if (pos > size / 2)
		{
			curr = tail;
			for (int i = size - 1; i > pos && curr; --i)
			{
				curr = curr->prev;
			}
		}
		else
		{
			curr = head;
			for (int i = 0; i < pos && curr; ++i)
			{
				curr = curr->next;
			}
		}
		return iterator(curr);
	}

	// this will find a vlaue by it's value
	typename LinkedList<T>::iterator FindValue(const T& val) const
	{
		for (auto it = begin(); it != nullptr; ++it)
		{
			if (*it == val)
			{
				return it;
			}
		}
		return nullptr;
	}

	void Reverse()
	{
		if (!head || !head->next)
		{
			return;
		}

		node* curr = head;
		node* temp = nullptr;

		while (curr)
		{
			temp = curr->prev;
			curr->prev = curr->next;
			curr->next = temp;
			curr = curr->prev;
		}

		temp = head;
		head = tail;
		tail = temp;
	}

	//checks if value exists
	bool Contains(const T& val) const
	{
		node* curr = head;

		while (curr)
		{
			if (curr->data == val)
			{
				return true;
			}
			curr = curr->next;
		}
		return false;
	}

	// empty the list
	void Clear()
	{
		// while there is still a create a new head and delete the old one
		while (head)
		{
			node* temp = head;
			head = temp->next;
			delete temp;
		}
		// set the tail to nullptr and size to zero
		tail = nullptr;
		size = 0;
	}

	// print the data;
	void print() const
	{
		node* curr = head;
		while (curr)
		{
			std::cout << curr->data << " ";
			curr = curr->next;
		}
		std::cout << std::endl;
	}

	//this allows me to search for a value similar to an array with in the []
	T& operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Index out of range");
		}
		node* curr = nullptr;

		if (index > size / 2)
		{
			curr = tail;
			for (int i = size - 1; i > index && curr; --i)
			{
				curr = curr->prev;
			}
		}
		else
		{
			curr = head;
			for (int i = 0; i < index && curr; ++i)
			{
				curr = curr->next;
			}
		}

		if (curr == nullptr)
		{
			throw std::out_of_range("Index out of range");
		}

		return curr->data;
	}

};