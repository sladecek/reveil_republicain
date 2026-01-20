#include "reveil.h"

namespace reveil {

int Calculator::add(int a, int b) const {
    return a + b;
}

int Calculator::subtract(int a, int b) const {
    return a - b;
}

int Calculator::multiply(int a, int b) const {
    return a * b;
}

std::string greet(const std::string& name) {
    return "Hello, " + name + "! Welcome to Reveil.";
}

} // namespace reveil
