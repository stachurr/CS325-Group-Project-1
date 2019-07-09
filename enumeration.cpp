#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

const int SIZE = 100;

int main() {

    int arr[SIZE];
    int max_sum = 0;

    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = (rand() % 10) + 1;
    }

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++) {
        for (int j = i; j < SIZE; j++) {
            int temp_sum = 0;
            for (int k = i; k <= j; k++) {
                temp_sum += arr[k];
            }
            if (temp_sum > max_sum) {
                max_sum = temp_sum;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();

    cout << endl;
    cout << "Size of array = " << SIZE << endl;
    cout << "Largest contiguous sum = " << max_sum << endl;
    cout << "Time taken: " << chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "μs" << endl;
    cout << endl;

    return 0;
}
