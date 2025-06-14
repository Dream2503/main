#include "08-CircularLinkedList.h" // Assuming this is the file name you gave
using namespace std;

int main() {
    // Test constructor (initializer list)
    SortedDoublyLinkedList<int> ascList{3, 1, 4, 2, 5};
    cout << "Ascending List:\n";
    ascList.display();

    SortedDoublyLinkedList<int> descList({3, 1, 4, 2, 5}, "dsc");
    cout << "\nDescending List:\n";
    descList.display();

    // Test insert maintains order
    ascList.insert(0);
    ascList.insert(6);
    cout << "\nAfter inserting 0 and 6 (Ascending):\n";
    ascList.display();

    descList.insert(0);
    descList.insert(6);
    cout << "\nAfter inserting 0 and 6 (Descending):\n";
    descList.display();

    // Test count
    cout << "\nCount of 2 in ascending list: " << ascList.count(2) << "\n";

    // Test copy constructor
    auto copyAsc = ascList.copy();
    cout << "\nCopied Ascending List:\n";
    copyAsc.display();

    // Test extend and operator+=
    SortedDoublyLinkedList<int> extList{7, 8};
    ascList += extList;
    cout << "\nAscending List after += {7, 8}:\n";
    ascList.display();

    // Test operator+
    auto merged = descList + SortedDoublyLinkedList<int>{{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30}, "dsc"};
    cout << "\nMerged Descending List:\n";
    merged.display();

    // Test operator*
    auto repeated = SortedDoublyLinkedList<int>({1, 2, 3}) * 3;
    cout << "\nRepeated (3x) Sorted List:\n";
    repeated.display();

    // Test *=
    SortedDoublyLinkedList<int> timesList{4, 5};
    timesList *= 2;
    cout << "\nTimes *= 2:\n";
    timesList.display();

    // Test min/max
    cout << "\nMin of ascList: " << ascList.min() << "\n";
    cout << "Max of ascList: " << ascList.max() << "\n";

    cout << "Min of descList: " << descList.min() << "\n";
    cout << "Max of descList: " << descList.max() << "\n";

    // Test reverse (which also flips mode)
    ascList.reverse();
    cout << "\nascList after reverse (should be descending):\n";
    ascList.display();

    descList.reverse();
    cout << "\ndescList after reverse (should be ascending):\n";
    descList.display();

    return 0;
}