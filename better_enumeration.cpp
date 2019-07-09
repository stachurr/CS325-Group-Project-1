#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

const int SIZE = 9000;

int main() {

    int arr[SIZE];
    int sum = 0;

    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = (rand() % 10) + 1;
    }

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++) {
        int temp_sum = 0;
        int max_temp_sum = 0;

        for (int j = i; j < SIZE; j++) {
            temp_sum += arr[j];
            if (temp_sum > max_temp_sum) {
                max_temp_sum = temp_sum;
            }
        }

        if (max_temp_sum > sum) {
            sum = max_temp_sum;
        }
    }

    auto end = chrono::high_resolution_clock::now();

    cout << endl;
    cout << "Size of array = " << SIZE << endl;
    cout << "Largest contiguous sum = " << sum << endl;
    cout << "Time taken: " << chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "μs" << endl;
    cout << endl;

    return 0;
}
