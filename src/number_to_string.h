/// Number to string conversion for fixed-width digit display
#pragma once

#include "font.h"
#include "renderer.h"
#include "generated/drawing_objects.h"

#include <array>
#include <cstdint>

namespace rr::ui
{

    template <Font F, int NumDigits>
    class NumberToString
    {
        static_assert(NumDigits <= 4, "NumDigits must be <= 4");
        
    public:
        using string_t = String;

        // Convert an integer to a fixed-width string of digits
        // Right-aligned, padded with spaces, unused positions filled with NULL_CHAR
        string_t convert(int number) const
        {
            string_t result;
            
            // Initialize all positions with NULL_CHAR
            for (int i = 0; i < 4; ++i)
            {
                result[i] = NULL_CHAR;
            }
            
            // Calculate starting position (right-aligned within NumDigits)
            int start_pos = 4 - NumDigits;
            
            // Extract digits from right to left
            int temp = number;
            int pos = 3; // Start from rightmost position
            
            // Fill in digits from right to left
            while (pos >= start_pos && temp > 0)
            {
                int digit = temp % 10;
                // nr fragment starts at index 0, so digit N is at fragment_index 0 + N
                result[pos] = static_cast<uint16_t>(fragment_index::nr) + digit;
                temp /= 10;
                --pos;
            }
            
            // Handle zero case
            if (number == 0)
            {
                result[3] = static_cast<uint16_t>(fragment_index::nr);
                --pos;
            }
            
            // Pad remaining positions (within NumDigits range) with space (character index 0)
            for (int i = start_pos; i <= pos; ++i)
            {
                result[i] = 0; // space character
            }
            
            return result;
        }
    };

} // namespace rr::ui
