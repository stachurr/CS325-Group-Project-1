#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>
using namespace std;

const int SIZE = 9000;

int maxSum(int arr[], int size) {
    int * temp_arr;
    temp_arr = new int [size + 1];
    temp_arr[0] = 0;

    for (int i = 1; i < size + 1; i++) {
        temp_arr[i] = max(temp_arr[i-1] + arr[i-1], arr[i-1]);
    }

    int answer = temp_arr[0];
    for (int i = 1; i < size + 1; i++) {
        if (answer < temp_arr[i]) {
            answer = temp_arr[i];
        }
    }

    return answer;
}

int main() {
    int arr[SIZE];

    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = (rand() % 10) + 1;
    }


    cout << endl;
    cout << "Size of array = " << SIZE << endl;

    auto start = chrono::high_resolution_clock::now();

    cout << "Largest contiguous sum = " << maxSum(arr, SIZE) << endl;

    auto end = chrono::high_resolution_clock::now();

    cout << "Time taken: " << chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "μs" << endl;
    cout << endl;

    return 0;
}
