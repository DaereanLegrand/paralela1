#include <bits/stdc++.h>
#include <chrono>

#define MAX 1500

int
main()
{
    double A[MAX][MAX], x[MAX], y[MAX];

    for (int i = 0; i < MAX; i++) {
        x[i] = rand();
        y[i] = 0;
        for (int j = 0; j < MAX; j++) {
            A[i][j] = rand();
        }
    }

    std::ios_base::sync_with_stdio(false);
    auto start1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i] += A[i][j] * x[j];

    auto end1 = std::chrono::high_resolution_clock::now();


    for (int i = 0; i < MAX; i++)
        y[i] = rand();

    auto start2 = std::chrono::high_resolution_clock::now();

    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++)
            y[i] += A[i][j] * x[j];

    auto end2 = std::chrono::high_resolution_clock::now();

    double time_taken1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();
    double time_taken2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();

    std::cout << "Time taken in first: " << time_taken1 << std::endl;
    std::cout << "Time taken in second: " << time_taken2 << std::endl;
}
