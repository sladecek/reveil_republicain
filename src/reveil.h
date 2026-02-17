#pragma once

#include "hardware_interface.h"

#include <concepts>

namespace rr
{

    template <typename T>
        requires std::derived_from<T, hh::Interface>
    class ReveilRepublicain
    {
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


} // namespace rr
