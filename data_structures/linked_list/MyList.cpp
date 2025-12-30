#include <stdexcept>
#include <iostream>

#include "MyStructure.h"

#ifndef __MY_LIST__
#define __MY_LIST__

namespace MyStructure{


template <typename T>
class Node
{
private:
    // TODO use private, setters and getters, maybe?
public:
    T data;
    Node* next;
    Node* prev;
    
    Node(T data = NULL){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    ~Node(){
        
    }
    
    static void link(Node<T>* a, Node<T>* b){
        if (a != nullptr) a->next = b;
        if (b != nullptr) b->prev = a;
    }
};

template <typename T>
class List: public DataStructure<T>
{
protected:
    Node<T>* head;
    Node<T>* tail;
	unsigned int length;

	Node<T>* getNodeByIndex(int index){
		//TODO: add check for length for efficiency
		Node<T>* node = head;
		if (node == nullptr) 
			throw std::out_of_range("get operation on empty list");

		for (int i=0; i<index; i++){
			node = node->next;
			if (node == nullptr) 
				throw std::out_of_range("index larger than size ");
        }
		return node;
	}

	Node<T>* findMatchingNode(T target,unsigned int& index){
		Node<T>* node = head;
		unsigned int i = 0;
		for (i=0; node != nullptr; i++){
			if (node->data == target){
				index = i;
				return node;
			}
			node = node->next;
		}
		index = (unsigned int)-1;
		return nullptr;
	
	}

	// alias that consumes index
	Node<T>* findMatchingNode(T target){
		unsigned int index;
		return  findMatchingNode(target, index);
	}

	/** 
     * Gets pair of nodes surrounding a specific index
     * return values
     * 0                returns nullptr & head
     * valid            returns index -> node1 & node2
     * Null or Size     returns tail & nullptr
     * invalid index    returns OOB exception
     */
    void getNodePair(Node<T>*& prevNode, Node<T>*& nextNode,unsigned int index=-1){
        switch (index)
		{
		case (unsigned int)-1:
			prevNode = tail;
			nextNode = nullptr;
			break;

		case 0:
			prevNode = nullptr;
			nextNode = head;
			break;
		
		default:
			prevNode = getNodeByIndex(index-1);
			nextNode = prevNode->next;
		}

    }
	
	void fromList(List<T>& other){
		clear();
		Node<T>* original = other.head;
		Node<T>* currNode = nullptr;
		Node<T>* prevNode = nullptr;
		while (original!=nullptr)
		{
			currNode = new Node<T>(original->data);
			if (head==nullptr) head = currNode; 
			Node<T>::link(prevNode,currNode);
			prevNode = currNode;
			original = original->next;
		}
		tail = currNode;
		length=other.length;
	}

	void insertBetween(T data, Node<T>* prevNode, Node<T>* nextNode){
        // try storing new node in memory
		
        Node<T>* newNode;
        
		try {newNode= new Node(data);}
        catch(const std::exception& e)
        {
			std::cerr << e.what() << '\n';
			return;
		}
        
        // revise head and tail if necessary

        if (nextNode == head) head = newNode;
        if (prevNode == tail) tail = newNode;

		// connect nodes
		Node<T>::link(prevNode, newNode);
		Node<T>::link(newNode, nextNode);

		length++;
    }

	T removeNode(Node<T>* node){
		
		// revise head and tail if necessary
		
		if (node==head) head = node->next;
		if (node==tail) tail = node->prev;

		// connect nodes

		Node<T>::link(node->prev,node->next);

		// extract data and delete node

		T data = node->data;
		delete node;

		length--;

		return data;
	}

public:

	virtual DataStructure<T>* createNew(){return new List();}

	void copyFrom(DataStructure<T> *other){
        fromList(*static_cast<List<T>*>(other));
    }

	void clear(){
		// TODO: I'm using head and tail here for efficiency
		// maybe just create new pointers to avoid problems
		while (head != nullptr){
			tail = head; // node to delete
			head = head->next; // next node (save before deleting)
			delete tail;
		}
		head = nullptr;
		tail = nullptr;
		length = 0;
	}
	
    List(){
        this->head = nullptr;
        this->tail = nullptr;
    }

	List(List<T>& other){
        this->head = nullptr;
        this->tail = nullptr;
		fromList(other);
	}

	List<T>& operator= (List<T>& other){
		fromList(other);
		return *this;
	}

    ~List(){
		clear();
    }

    void insert(T data, unsigned int index = -1){
		// try finding insert position

        Node<T>* prevNode;
        Node<T>* nextNode;

        try {getNodePair(prevNode,nextNode,index);}
        catch(const std::exception& e)
        {
			std::cerr << e.what() << '\n';
			return;
		}
		
		insertBetween(data, prevNode, nextNode);

	}

	T remove(unsigned int index = -1){
		Node<T>* node = getNodeByIndex(index);
		return removeNode(node);
	}

	void display(std::ostream& stream){
		Node<T>* node = head;
		stream<<"[";
		while (node != nullptr){
			stream<< node->data <<", ";
			node = node->next;
		}
		stream<<"]";
	}


	unsigned int findMatchingIndex(T target){
		unsigned int index;
		findMatchingNode(target, index);
		return index;
	}

	// requirements
	void insertBefore(T target, T data){
		Node<T>* node = findMatchingNode(target);
		if (node == nullptr) return; // target not found
		insertBetween(data, node->prev, node);
	}
	
	void insertAfter(T target, T data){
		Node<T>* node = findMatchingNode(target);
		if (node == nullptr) return; // target not found
		insertBetween(data, node, node->next);
	}
	
	unsigned int getCount(){
		//TODO: replace with `return length;` for efficiency
		unsigned int count=0;
		for (Node<T>* current = head; current!=nullptr; current=current->next){
			count++;
		}
		return count;
	}

	T getDataByIndex(unsigned int index){
		return getNodeByIndex(index)->data;
	}
	
	void removeAll(T target){
		Node<T>* current = head;
		Node<T>* next = nullptr;
		while (current!=nullptr){
			next=current->next;
			if (current->data == target){
				removeNode(current);
			}
			current=next;
		}
	}
	void addStart(T data){
		insert(data,0);
	}
    void addEnd(T data){
		insert(data);
	}

	T removeStart(){
		return remove(0);
	}

    T removeEnd(){
		return remove();
	}
    
};


}

#endif