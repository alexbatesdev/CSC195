#pragma once

#include <initializer_list>
#include <limits>
#include <iostream>
namespace nc {
	template<typename T>
	class list {
		struct node_t {
			node_t(const T& value) : _value{ value } {}
			T _value;
			node_t* _next{ nullptr };
			node_t* _prev{ nullptr };
		};

	public:
		list() {}
		list(const std::initializer_list<T>& ilist);
		list(const list& other);
		~list();

		list& operator = (const list& other);

		T& front();
		//const T& front() const;

		T& back();
		//const T& back() const;

		void push_front(const T& value);
		void pop_front();

		void push_back(const T& value);
		void pop_back();

		void remove(const T& value);
		void reverse(); // see references for implementation
		//void resize(size_t count, const T& value = T{});
		void clear(); // search online for implementation

		bool empty() { return (size() == 0); }
		size_t size(); // see references for implementation
		size_t max_size() { return std::numeric_limits<size_t>::max(); }
		std::ostream& write(std::ostream& stream);
	private:
		node_t* tail();
	private:
		node_t* _head{ nullptr }; //_head is just a title, you point at the first node and it is granted the status of head
	};

	// ////////////////////////////////////////////////////////////////////////////////////////// ASK WHAT THESE DO
	template<typename T>
	list<T>::list(const std::initializer_list<T>& ilist) {
		for (auto iter = ilist.begin(); iter != ilist.end(); iter++) {
			push_back(*iter);
		}
	}
	//                                         ASK WHAT THESE DO!!!!!!!!!!!!!!!!!!!
	template<typename T>
	list<T>::list(const list& other) {
		node_t* node = other._head;
		while (node) {
			push_back(node->_value);
			node = node->_next;
		}
	}

	template<typename T>
	list<T>::~list() {
		clear();
	}

	// ------------------------------------------------ ASK WHAT THOSE DO


	template<typename T>
	void list<T>::remove(const T& value) {
		node_t* node = _head;
		while (node) {
			if (node->_value == value) {
				node_t* next_node = node->_next;
				node_t* prev_node = node->_prev;
				if (prev_node) prev_node->_next = next_node;
				if (next_node) next_node->_prev = prev_node;


				if (_head == node) {
					_head = next_node;
				}
				delete node; //QUESTION, we delete the node,     is this deleting the data on the heap but the varianle remains so we change it to the next node?
				node = next_node; // then keep working with it?
			}
			else
			{
				node = node->_next;
			}
		}
	}

	// ===================================================================

	template<typename T>
	void list<T>::push_front(const T& value) {
		node_t* new_node = new node_t{ value };
		if (!_head) {
			_head->_prev = new_node;
		}
		new_node->_next = _head;
		_head = new_node; 
	}

	template<typename T>
	void list<T>::push_back(const T& value)	{
		node_t* new_node = new node_t{ value };
		if (!_head) {
			_head = new_node;
		}
		else {
			node_t* node = tail();
			new_node->_prev = node;
			node->_next = new_node;
		}
	}

	template<typename T>
	void list<T>::pop_back() {
		node_t* node = tail();
		node_t* node_prev = node->_prev;
		node_prev->_next = nullptr;
		delete node;
	}

	template<typename T>
	void list<T>::pop_front() {
		node_t* node = _head;
		node_t* next_node = node->_next;

		if (next_node) {
			_head = next_node;
			next_node->_prev = nullptr;
			delete node;
		}
	}

	// +++++++++++++++++++++++++++++++++++++++++++++++

	template<typename T>
	typename list<T>::node_t* list<T>::tail() {
		node_t* node = _head;

		while (node && node->_next) {
			node = node->_next;
		}
		return node;
	}

	template<typename T>
	list<T>& list<T>::operator = (const list& other) { //Copy
		node_t* nodeR = other._head; //Start
		while (nodeR) {
			push_back(nodeR->_value);
			nodeR = nodeR->_next;
		}
		return *this; //Finish
	}

	template<typename T>
	void list<T>::reverse() {
		node_t* node = _head;
		node_t* node_prev = nullptr;
		node_t* node_next = nullptr;
		while (node) {
			node_next = node->_next;
			node_prev = node->_prev;
			node->_next = node_prev;
			node->_prev = node_next;
			node_prev = node;
			node = node_next; 
		}
		_head = node_prev;
	}

	template<typename T>
	T& list<T>::front() {
		return _head->_value;
	}

	template<typename T>
	T& list<T>::back() {
		return tail()->_value;
	}

	template<typename T>
	void list<T>::clear() {
		node_t* node = tail();
		while (node) {
			node_t* node_prev = node->_prev;
			//node_prev->_next = nullptr;
			delete node;
			node = node_prev;
		}
		_head = nullptr;
	}

	template<typename T>
	size_t list<T>::size() {
		node_t* node = _head;
		size_t count = 0;
		while (node && _head) {
			node = node->_next;
			count++;
		}
		return count;
	}

	//WRITE (I do not know how to do this one or what it wants)
	template<typename T>
	std::ostream& list<T>::write(std::ostream& stream) {
		node_t* node = _head;
		while (node) {
			stream << node->_value << " ";
			node = node->_next;
		}
		return stream << '\n';
	}
}