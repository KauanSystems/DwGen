#include <exception>
#include <iostream>

#include <registry.h>

int main(int argc, char* argv[]) {
    try {
        return Program::Dispatch(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Fatal Error Unknown.\n";
        return 1;
    }
}
