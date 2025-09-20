#include <iostream>
using namespace std;

int main() {
    int arr[5]; // static array of size 5
    int size = 0; // current number of elements

    // Insert elements
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    size = 3;

    cout << "Initial array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Update element
    arr[1] = 25;
    cout << "After updating second element: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Delete last element
    size--;
    cout << "After deleting last element: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
