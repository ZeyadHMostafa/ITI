#include "MyList.cpp"

using namespace MyStructure;

template <typename T>
class SortableList: public List<T>{
    protected:

    Node<T>* goToNode(int fromIndex, int toIndex, Node<T>* currNode){
        unsigned int dist = abs(toIndex-fromIndex);
        
        for (unsigned int i=0; i<dist; i++){
            currNode=(toIndex>fromIndex)?currNode->next:currNode->prev;
        }

        return currNode;
    }

    public:
    SortableList():List<T>(){}
    void swapNodes(Node<T>* a, Node<T>* b){
        // data swap
        T tmp = a->data;
        a->data = b->data;
        b->data = tmp;
    }

    void listBubbleSort() {
        bool swapped = true;

        for (Node<T>* endNode = this->tail; endNode!=this->head && swapped; endNode=endNode->prev) {
            swapped = false;
            for (Node<T>* currNode = this->head; currNode!=endNode; currNode=currNode->next) {
                if (currNode->data > currNode->next->data) {
                    swapNodes(currNode, currNode->next);
                    swapped = true;
                }
            }
        }
    }

    void listSelectionSort() {
        bool swapped = true;

        for (Node<T>* endNode = this->tail; endNode!=this->head /*&& swapped*/; endNode=endNode->prev) {
            Node<T>* maxNode = this->head;
            swapped = false;

            for (Node<T>* currNode = this->head; currNode!=endNode; currNode=currNode->next) {
                if (currNode->data > maxNode->data) {
                    maxNode = currNode;
                }
                // etra swap check
                if (currNode->data > currNode->next->data) {
                    swapped = true;
                }
            }
            if (maxNode->data > endNode->data) {
            	swapNodes(maxNode, endNode);
            }
        }
    }

    void listInsertionSort() {
        for (Node<T>* keyNode = this->head; keyNode!=nullptr; keyNode=keyNode->next) {
            Node<T>* currNode = this->head;

            for (currNode = this->head; currNode!=keyNode && currNode->data<=keyNode->data; currNode=currNode->next) {}
            if (currNode!=keyNode){
                T value = this->removeNode(keyNode);
                this->insertBetween(value, currNode->prev, currNode);
            }
        }
    }

    int BinarySearch(T target){
        // only works because this is double linked list
        unsigned int low = 0;
        unsigned int high = this->getCount();
        unsigned int currIndex = 0;

        Node<T>* currNode = this->head; // could be done using slow and fast pointer, but eh
        while (currNode!= nullptr && high>=low){
            unsigned int mid = low + (high-low)/2;
            currNode = goToNode(currIndex,mid,currNode);
            currIndex = mid;
            if (target>currNode->data){low=mid+1;}
            else if (target<currNode->data){high=mid-1;}
            else if(target==currNode->data){return currIndex;}
        }
        throw std::out_of_range("element not found in list");
    }
};
