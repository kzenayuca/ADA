#include <iostream>
#include <vector>
#include <algorithm> 
#include <random>    
#include <cstdlib>   

void randomCase(int n) {
    std::cout << n << std::endl;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(arr.begin(), arr.end(), g);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "missing arr size of: " << argv[0] << std::endl;
        return 1;
    }

    int n = std::atoi(argv[1]);

    for (int i = 1; i <= n; i++) {
        randomCase(i * 10);
    }

    return 0;
}
