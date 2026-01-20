#ifndef REVEIL_H
#define REVEIL_H

#include <string>

namespace reveil {

/**
 * @brief A simple calculator class for demonstration
 */
class Calculator {
public:
    /**
     * @brief Add two integers
     * @param a First operand
     * @param b Second operand
     * @return Sum of a and b
     */
    int add(int a, int b) const;

    /**
     * @brief Subtract two integers
     * @param a First operand
     * @param b Second operand
     * @return Difference of a and b
     */
    int subtract(int a, int b) const;

    /**
     * @brief Multiply two integers
     * @param a First operand
     * @param b Second operand
     * @return Product of a and b
     */
    int multiply(int a, int b) const;
};

/**
 * @brief Get a greeting message
 * @param name Name to greet
 * @return Greeting string
 */
std::string greet(const std::string& name);

} // namespace reveil

#endif // REVEIL_H
