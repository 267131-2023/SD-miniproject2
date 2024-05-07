#include <iostream>
#include <chrono>

#include "LinkedPriorityQueue.h"
#include "Node.h"

using namespace std;
using namespace std::chrono;

void displayMainMenu(Heap& heap, PriorityQueue& pq, int& choice, int& number, int& element);

void displayListMenu(PriorityQueue& pq, int& choice, int& number, int& element) {
    cout << "========ListMENU========" << endl;
    cout << "1. Dodaj element" << endl;
    cout << "2. Usun i zwroc element o max priorytecie" << endl;
    cout << "3. Zwrocenie max priorytecie" << endl;
    cout << "4. Zmiana priorytetu elementu" << endl;
    cout << "5. Zwrocenie rozmiaru" << endl;
    cout << "6. Wyjscie" << endl;
    cout << "========================" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        auto start = high_resolution_clock::now();
        int priorityRandom = rand() % 54353 + number;
        pq.insert(element, priorityRandom);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Czas wykonania operacji: " << duration.count() << " nanosekund" << endl;
        break;
    case 2:
        auto start = high_resolution_clock::now();
        pq.extract_max();
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Czas wykonania operacji: " << duration.count() << " nanosekund" << endl;
        break;
    case 3:
        auto start = high_resolution_clock::now();
        pq.peek();
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Czas wykonania operacji: " << duration.count() << " nanosekund" << endl;
        break;
    case 4:
        auto start = high_resolution_clock::now();
        int priorityRandom = rand() % 54353 + number;
        pq.modify_key(10, priorityRandom);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Czas wykonania operacji: " << duration.count() << " nanosekund" << endl;
        break;
    case 5:
        auto start = high_resolution_clock::now();
        pq.return_size();
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Czas wykonania operacji: " << duration.count() << " nanosekund" << endl;
        break;
    case 6:

        break;
    default:
        cout << "Nieprawidlowa opcja. Wybierz ponownie" << endl;
    }
}

void displayHeapMenu(Heap& heap, int& choice, int& number, int& element) {
    cout << "========HeapMENU========" << endl;
    cout << "1. Dodaj element" << endl;
    cout << "2. Usun i zwroc element o max priorytecie" << endl;
    cout << "3. Zwrocenie max priorytecie" << endl;
    cout << "4. Zmiana priorytetu elementu" << endl;
    cout << "5. Zwrocenie rozmiaru" << endl;
    cout << "6. Wyjscie" << endl;
    cout << "========================" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        auto start = high_resolution_clock::now();
        int priorityRandom = rand() % 54353 + number;
        heap.insert(element, priorityRandom);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Czas wykonania operacji: " << duration.count() << " nanosekund" << endl;
        break;
    case 2:
        auto start = high_resolution_clock::now();
        heap.extractMax();
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Czas wykonania operacji: " << duration.count() << " nanosekund" << endl;
        break;
    case 3:
        auto start = high_resolution_clock::now();
        heap.findMax();
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Czas wykonania operacji: " << duration.count() << " nanosekund" << endl;
        break;
    case 4:
        auto start = high_resolution_clock::now();
        int priorityRandom = rand() % 54353 + number;
        heap.modifyKey(10, priorityRandom);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Czas wykonania operacji: " << duration.count() << " nanosekund" << endl;
        break;
    case 5:
        auto start = high_resolution_clock::now();
        heap.returnSize();
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Czas wykonania operacji: " << duration.count() << " nanosekund" << endl;
        break;
    case 6:

        break;
    default:
        cout << "Nieprawidlowa opcja. Wybierz ponownie" << endl;
    }
}

void displayMainMenu(Heap& heap, PriorityQueue& pq, int& choice, int& number, int& element) {

    cout << "==========MENU==========" << endl;
    cout << "1. Kopiec" << endl;
    cout << "2. Lista" << endl;
    cout << "3. Wyjscie" << endl;
    cout << "========================" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        displayHeapMenu(heap, choice, number, element);
        break;
    case 2:
        displayListMenu(pq, choice, number, element);
        break;
    case 3:
        cout << "Koniec programu" << endl;
        break;
    default:
        cout << "Nieprawidlowa opcja. Wybierz ponownie" << endl;
    }
}

int main()
{
    Heap heap(5);
    PriorityQueue pq;
    int choice;
    int number = 10000; //liczba elementów zbioru
    int element = 1; //pojedynczy element

    //ziarna zbiorów

    unsigned int seed = 1670;
    //unsigned int seed = 3007;
    //unsigned int seed = 13;

    srand(seed);


    int priorityRandom;
    int randomNumber;
    for (int i = 0; i < number; i++) {
        randomNumber = rand();
        priorityRandom = rand() % 54353 + number;
        heap.insert(randomNumber, priorityRandom);
        pq.insert(randomNumber, priorityRandom);
    }


    for (int i = 0; i < 3; i++) {
        priorityRandom = rand() % 54353 + number;
        auto start = high_resolution_clock::now();
        pq.modify_key(4124, priorityRandom);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << duration.count() << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        auto start = high_resolution_clock::now();
        pq.peek();
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << duration.count() << endl;
    }



    return 0;
}


