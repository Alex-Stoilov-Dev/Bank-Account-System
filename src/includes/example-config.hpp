// config.h.example - Commit this!
#pragma once
#include <string_view>

namespace Config {
    inline constexpr std::string_view DB_host = "YOUR_SERVER_HERE";
    inline constexpr std::string_view DB_name = "YOUR_DB_NAME_HERE";
    inline constexpr std::string_view DB_user = "YOUR_DB_USER_HERE";
    inline constexpr std::string_view DB_pass = "YOUR_DB_USER_PASS_HERE";
}