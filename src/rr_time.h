// Time representation with packed fields for the republican alarm clock.
// Uses French Revolutionary (Republican) Calendar:
// - Decimal time: 10 hours/day, 100 minutes/hour, 100 seconds/minute
// - 12 months of 30 days (3 décades of 10 days each)
// - Year starts at autumn equinox

#pragma once

#include "hardware_interface.h"
#include <cstdint>
#include <array>

namespace rr
{

    // Packed time structure for French Republican Calendar:
    struct Time
    {
        uint32_t second : 7 = 0;   // 0-99 (decimal seconds)
        uint32_t minute : 7 = 0;   // 0-99 (decimal minutes)
        uint32_t hour : 4 = 0;     // 0-9 (decimal hours)
        uint32_t day : 4 = 1;      // 0-9 (day of decade)
        uint32_t decade : 2 = 0;   // 0-2 (which decade in month: 0, 1, or 2)
        uint32_t month : 4 = 0;    // 0-11 (month) or 12 (complementary days)
        uint32_t year : 10 = 209;  // years since era start
    
        // Default constructor using default member initializers
        Time() = default;

        // Construct from hardware clock time point (Unix timestamp)
        // Converts from Gregorian calendar with 24h time to Republican calendar with decimal time
        Time(hw::Clock::time_point time_point);

        // Pack the time back into a time_point (Unix timestamp)
        // Converts from Republican calendar with decimal time to Gregorian with 24h time
        hw::Clock::time_point pack() const;

        // Compute the time point when the next decimal minute will start
        // In decimal time, each minute is 86.4 Gregorian seconds
        hw::Clock::time_point compute_next_minute_change() const;

        // Compute day of year (0-364, or 0-365 for leap years with complementary days)
        // Returns: month * 30 + decade * 10 + day
        int day_of_year() const;

    private:
        static constexpr int longitude_of_paris_observatory_s = 561;
        // Julian Day Number for the first day (1 Vendémiaire) of each Republican year
        // Covers years 209-308 (Gregorian 2000-2099)
        // JD at noon UTC
        static constexpr int FIRST_YEAR = 209;
        static constexpr int YEAR_COUNT = 100;
        static constexpr int JD_ZERO = 2451810; // pack 100 years to 16 bits
        static constexpr std::array<uint16_t, YEAR_COUNT> first_day_jd = {{
            2451810 - JD_ZERO,  // Year 209 (1 Vendémiaire = 2000-09-22)
            2452175 - JD_ZERO,  // Year 210 (1 Vendémiaire = 2001-09-22)
            2452541 - JD_ZERO,  // Year 211 (1 Vendémiaire = 2002-09-23)
            2452906 - JD_ZERO,  // Year 212 (1 Vendémiaire = 2003-09-23)
            2453271 - JD_ZERO,  // Year 213 (1 Vendémiaire = 2004-09-22)
            2453636 - JD_ZERO,  // Year 214 (1 Vendémiaire = 2005-09-22)
            2454002 - JD_ZERO,  // Year 215 (1 Vendémiaire = 2006-09-23)
            2454367 - JD_ZERO,  // Year 216 (1 Vendémiaire = 2007-09-23)
            2454732 - JD_ZERO,  // Year 217 (1 Vendémiaire = 2008-09-22)
            2455097 - JD_ZERO,  // Year 218 (1 Vendémiaire = 2009-09-22)
            2455463 - JD_ZERO,  // Year 219 (1 Vendémiaire = 2010-09-23)
            2455828 - JD_ZERO,  // Year 220 (1 Vendémiaire = 2011-09-23)
            2456193 - JD_ZERO,  // Year 221 (1 Vendémiaire = 2012-09-22)
            2456558 - JD_ZERO,  // Year 222 (1 Vendémiaire = 2013-09-22)
            2456924 - JD_ZERO,  // Year 223 (1 Vendémiaire = 2014-09-23)
            2457289 - JD_ZERO,  // Year 224 (1 Vendémiaire = 2015-09-23)
            2457654 - JD_ZERO,  // Year 225 (1 Vendémiaire = 2016-09-22)
            2458019 - JD_ZERO,  // Year 226 (1 Vendémiaire = 2017-09-22)
            2458385 - JD_ZERO,  // Year 227 (1 Vendémiaire = 2018-09-23)
            2458750 - JD_ZERO,  // Year 228 (1 Vendémiaire = 2019-09-23)
            2459115 - JD_ZERO,  // Year 229 (1 Vendémiaire = 2020-09-22)
            2459480 - JD_ZERO,  // Year 230 (1 Vendémiaire = 2021-09-22)
            2459846 - JD_ZERO,  // Year 231 (1 Vendémiaire = 2022-09-23)
            2460211 - JD_ZERO,  // Year 232 (1 Vendémiaire = 2023-09-23)
            2460576 - JD_ZERO,  // Year 233 (1 Vendémiaire = 2024-09-22)
            2460941 - JD_ZERO,  // Year 234 (1 Vendémiaire = 2025-09-22)
            2461307 - JD_ZERO,  // Year 235 (1 Vendémiaire = 2026-09-23)
            2461672 - JD_ZERO,  // Year 236 (1 Vendémiaire = 2027-09-23)
            2462037 - JD_ZERO,  // Year 237 (1 Vendémiaire = 2028-09-22)
            2462402 - JD_ZERO,  // Year 238 (1 Vendémiaire = 2029-09-22)
            2462768 - JD_ZERO,  // Year 239 (1 Vendémiaire = 2030-09-23)
            2463133 - JD_ZERO,  // Year 240 (1 Vendémiaire = 2031-09-23)
            2463498 - JD_ZERO,  // Year 241 (1 Vendémiaire = 2032-09-22)
            2463863 - JD_ZERO,  // Year 242 (1 Vendémiaire = 2033-09-22)
            2464228 - JD_ZERO,  // Year 243 (1 Vendémiaire = 2034-09-22)
            2464594 - JD_ZERO,  // Year 244 (1 Vendémiaire = 2035-09-23)
            2464959 - JD_ZERO,  // Year 245 (1 Vendémiaire = 2036-09-22)
            2465324 - JD_ZERO,  // Year 246 (1 Vendémiaire = 2037-09-22)
            2465689 - JD_ZERO,  // Year 247 (1 Vendémiaire = 2038-09-22)
            2466055 - JD_ZERO,  // Year 248 (1 Vendémiaire = 2039-09-23)
            2466420 - JD_ZERO,  // Year 249 (1 Vendémiaire = 2040-09-22)
            2466785 - JD_ZERO,  // Year 250 (1 Vendémiaire = 2041-09-22)
            2467150 - JD_ZERO,  // Year 251 (1 Vendémiaire = 2042-09-22)
            2467516 - JD_ZERO,  // Year 252 (1 Vendémiaire = 2043-09-23)
            2467881 - JD_ZERO,  // Year 253 (1 Vendémiaire = 2044-09-22)
            2468246 - JD_ZERO,  // Year 254 (1 Vendémiaire = 2045-09-22)
            2468611 - JD_ZERO,  // Year 255 (1 Vendémiaire = 2046-09-22)
            2468977 - JD_ZERO,  // Year 256 (1 Vendémiaire = 2047-09-23)
            2469342 - JD_ZERO,  // Year 257 (1 Vendémiaire = 2048-09-22)
            2469707 - JD_ZERO,  // Year 258 (1 Vendémiaire = 2049-09-22)
            2470072 - JD_ZERO,  // Year 259 (1 Vendémiaire = 2050-09-22)
            2470438 - JD_ZERO,  // Year 260 (1 Vendémiaire = 2051-09-23)
            2470803 - JD_ZERO,  // Year 261 (1 Vendémiaire = 2052-09-22)
            2471168 - JD_ZERO,  // Year 262 (1 Vendémiaire = 2053-09-22)
            2471533 - JD_ZERO,  // Year 263 (1 Vendémiaire = 2054-09-22)
            2471899 - JD_ZERO,  // Year 264 (1 Vendémiaire = 2055-09-23)
            2472264 - JD_ZERO,  // Year 265 (1 Vendémiaire = 2056-09-22)
            2472629 - JD_ZERO,  // Year 266 (1 Vendémiaire = 2057-09-22)
            2472994 - JD_ZERO,  // Year 267 (1 Vendémiaire = 2058-09-22)
            2473360 - JD_ZERO,  // Year 268 (1 Vendémiaire = 2059-09-23)
            2473725 - JD_ZERO,  // Year 269 (1 Vendémiaire = 2060-09-22)
            2474090 - JD_ZERO,  // Year 270 (1 Vendémiaire = 2061-09-22)
            2474455 - JD_ZERO,  // Year 271 (1 Vendémiaire = 2062-09-22)
            2474820 - JD_ZERO,  // Year 272 (1 Vendémiaire = 2063-09-22)
            2475186 - JD_ZERO,  // Year 273 (1 Vendémiaire = 2064-09-22)
            2475551 - JD_ZERO,  // Year 274 (1 Vendémiaire = 2065-09-22)
            2475916 - JD_ZERO,  // Year 275 (1 Vendémiaire = 2066-09-22)
            2476281 - JD_ZERO,  // Year 276 (1 Vendémiaire = 2067-09-22)
            2476647 - JD_ZERO,  // Year 277 (1 Vendémiaire = 2068-09-22)
            2477012 - JD_ZERO,  // Year 278 (1 Vendémiaire = 2069-09-22)
            2477377 - JD_ZERO,  // Year 279 (1 Vendémiaire = 2070-09-22)
            2477742 - JD_ZERO,  // Year 280 (1 Vendémiaire = 2071-09-22)
            2478108 - JD_ZERO,  // Year 281 (1 Vendémiaire = 2072-09-22)
            2478473 - JD_ZERO,  // Year 282 (1 Vendémiaire = 2073-09-22)
            2478838 - JD_ZERO,  // Year 283 (1 Vendémiaire = 2074-09-22)
            2479203 - JD_ZERO,  // Year 284 (1 Vendémiaire = 2075-09-22)
            2479569 - JD_ZERO,  // Year 285 (1 Vendémiaire = 2076-09-22)
            2479934 - JD_ZERO,  // Year 286 (1 Vendémiaire = 2077-09-22)
            2480299 - JD_ZERO,  // Year 287 (1 Vendémiaire = 2078-09-22)
            2480664 - JD_ZERO,  // Year 288 (1 Vendémiaire = 2079-09-22)
            2481030 - JD_ZERO,  // Year 289 (1 Vendémiaire = 2080-09-22)
            2481395 - JD_ZERO,  // Year 290 (1 Vendémiaire = 2081-09-22)
            2481760 - JD_ZERO,  // Year 291 (1 Vendémiaire = 2082-09-22)
            2482125 - JD_ZERO,  // Year 292 (1 Vendémiaire = 2083-09-22)
            2482491 - JD_ZERO,  // Year 293 (1 Vendémiaire = 2084-09-22)
            2482856 - JD_ZERO,  // Year 294 (1 Vendémiaire = 2085-09-22)
            2483221 - JD_ZERO,  // Year 295 (1 Vendémiaire = 2086-09-22)
            2483586 - JD_ZERO,  // Year 296 (1 Vendémiaire = 2087-09-22)
            2483952 - JD_ZERO,  // Year 297 (1 Vendémiaire = 2088-09-22)
            2484317 - JD_ZERO,  // Year 298 (1 Vendémiaire = 2089-09-22)
            2484682 - JD_ZERO,  // Year 299 (1 Vendémiaire = 2090-09-22)
            2485047 - JD_ZERO,  // Year 300 (1 Vendémiaire = 2091-09-22)
            2485412 - JD_ZERO,  // Year 301 (1 Vendémiaire = 2092-09-21)
            2485778 - JD_ZERO,  // Year 302 (1 Vendémiaire = 2093-09-22)
            2486143 - JD_ZERO,  // Year 303 (1 Vendémiaire = 2094-09-22)
            2486508 - JD_ZERO,  // Year 304 (1 Vendémiaire = 2095-09-22)
            2486873 - JD_ZERO,  // Year 305 (1 Vendémiaire = 2096-09-21)
            2487239 - JD_ZERO,  // Year 306 (1 Vendémiaire = 2097-09-22)
            2487604 - JD_ZERO,  // Year 307 (1 Vendémiaire = 2098-09-22)
            2487969 - JD_ZERO,  // Year 308 (1 Vendémiaire = 2099-09-22)
        }};
    };

} // namespace rr
