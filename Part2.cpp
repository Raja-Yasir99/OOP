#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to resize array (increase size by 1)
int* ResizeArray(int* arr, int size, int newValue) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = newValue; // new number at last
    delete[] arr;
    return newArr;
}

// Function to delete number (decrease size by 1)
int* DeleteNumber(int* arr, int& size, int value) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Number not found!" << endl;
        return arr; // return same array
    }

    int* newArr = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newArr[j++] = arr[i];
        }
    }
    delete[] arr;
    size--;
    return newArr;
}

// Print array
void PrintArray(int* arr, int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Print sum
void PrintSum(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "Sum of array = " << sum << endl;
}

int main() {
    srand(time(0));

    int size = 5;
    int* arr = new int[size];

    // Random values 0–10
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 11;
    }

    int choice, num;

    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Add new number\n";
        cout << "2. Delete a number\n";
        cout << "3. Print array\n";
        cout << "4. Print sum of array\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number to add: ";
                cin >> num;
                arr = ResizeArray(arr, size, num);
                size++;
                break;
            case 2:
                cout << "Enter number to delete: ";
                cin >> num;
                arr = DeleteNumber(arr, size, num);
                break;
            case 3:
                PrintArray(arr, size);
                break;
            case 4:
                PrintSum(arr, size);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    delete[] arr;
    return 0;
}
