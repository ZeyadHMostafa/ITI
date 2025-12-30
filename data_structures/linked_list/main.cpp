#include <iostream>

#include "MyList.cpp"
#include "MyCirArray.cpp"
#include "MyQueue.cpp"
#include "MyDEQueue.cpp"
#include "listSort.cpp"

using namespace MyStructure;

void basicListTest(){
    List<int> list;
    list.insert(2);
    list.insert(4);
    list.insert(3,1);
    list.insert(5);
    list.insert(1,0);
    std::cout<<"list after insert = " <<list<<std::endl;
    list.remove();
    list.remove(2);
    list.remove(0);
    std::cout<<"list after remove = " <<list<<std::endl;
    List<int> list2;
    list2 = list;
    std::cout<<"list2 after copy and assign = " <<list<<std::endl;
    std::cout << "------------------------\n";
}

void requirementsTest(){
    List<int> list;
    list.insert(3);
    list.insertBefore(3,1);
    list.insertAfter(3,5);
    list.insertBefore(3,2);
    list.insertAfter(3,4);
    for (int i=1; i<5; i++){
        list.insertAfter(i,0);
    }
    std::cout<<"list after insert = " <<list<<std::endl;
    std::cout<<"list size = " <<list.getCount()<<std::endl;
    std::cout<<"list[4] = " <<list.getDataByIndex(4)<<std::endl;
    list.removeAll(0);
    std::cout<<"list after remove 0 = " <<list<<std::endl;
    std::cout << "------------------------\n";
}

void queueTest(Queue<int>& queue){
    for (int i = 0; i < 5; i++)
    {
        queue.add(i);
        std::cout<<i<<" added: ";
        std::cout<<queue<<"\n";
    }

    for (int i = 0; i < 3; i++)
    {
        std::cout<<queue.remove()<<" removed: ";
        std::cout<<queue<<"\n";
    }

    for (int i = 5; i < 7; i++)
    {
        queue.add(i);
        std::cout<<i<<" added: ";
        std::cout<<queue<<"\n";
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout<<queue.remove()<<" removed: ";
        std::cout<<queue<<"\n";
    }
    
    std::cout << "------------------------\n";
}

void basicQueueTest(){
    Queue<int> queue(new CirArray<int>(5));
    queueTest(queue);
}


void listQueueTest(){
    Queue<int> queue(new List<int>());
    queueTest(queue);
    List<int> list;
}

void dEQueueTest(){
    DEQueue<int> queue(new List<int>());
    queueTest(queue);
    for (int i = 7; i < 10; i++)
    {
        queue.addStart(i);
        std::cout<<i<<" added: ";
        std::cout<<queue<<"\n";
    }

    for (int i = 0; i < 3; i++)
    {
        std::cout<<queue.removeEnd()<<" removed: ";
        std::cout<<queue<<"\n";
    }
    std::cout << "------------------------\n";
}

void initList(List<int>& list){
    list.clear();
    for (int i=0; i<11*2; i++){
        list.addEnd(i*7%11);
    }
}

void sortTest1(){
    std::cout << "Bubble sort: " <<std::endl;
    SortableList<int> list;
    initList(list);
    std::cout << "before sort: " << list << std::endl;
    list.listBubbleSort();
    std::cout << "after  sort: " << list << std::endl;
    std::cout << "------------------------\n";
}

void sortTest2(){
    std::cout << "Selection sort: " <<std::endl;
    SortableList<int> list;
    initList(list);
    std::cout << "before sort: " << list << std::endl;
    list.listSelectionSort();
    std::cout << "after  sort: " << list << std::endl;
    std::cout << "------------------------\n";
}

void sortTest3(){
    std::cout << "Insertion sort: " <<std::endl;
    SortableList<int> list;
    initList(list);
    std::cout << "before sort: " << list << std::endl;
    list.listInsertionSort();
    std::cout << "after  sort: " << list << std::endl;
    std::cout << "------------------------\n";
}

void binarySearchTest(int x){
    SortableList<int> list;
    initList(list);
    std::cout << "before sort: " << list << std::endl;
    list.listSelectionSort();
    std::cout << "after  sort: " << list << std::endl;
    std::cout << "------------------------\n";
    std::cout << "index of ("<<x<<") is " << list.BinarySearch(x)<< std::endl;
}

int main(int argc, char const *argv[])
{
    basicListTest();
    requirementsTest();
    basicQueueTest();
    listQueueTest();
    dEQueueTest();
    sortTest1();
    sortTest2();
    sortTest3();
    binarySearchTest(7);
    return 0;
}
