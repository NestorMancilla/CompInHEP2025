#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) return 1;
    std::cout << "Hello world " << std::atoi(argv[1]) << std::endl;
    return 0;
}

