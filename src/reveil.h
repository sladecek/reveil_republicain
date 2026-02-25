#pragma once

#include "hardware_interface.h"

#include <concepts>

namespace rr
{

    class ReveilRepublicain
    {
    public:
        template <hw::Display D, hw::Timer T>
        hw::output_flags_t compute_update(D &display, T &timer, const hw::Event &event)
        {
            return static_cast<hw::output_flags_t>(hw::OutputFlags::None);
        }
    };

} // namespace rr
