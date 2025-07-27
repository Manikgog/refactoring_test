namespace {
    constexpr int kMinYear = 1;
    constexpr int kMaxYear = 9999;
    constexpr int kMonthsInYear = 12;
    constexpr int kMaxHour = 23;
    constexpr int kMaxMinute = 59;
    constexpr int kMaxSecond = 59;

    bool IsLeapYear(int year) {
        return (year % 4 == 0) && !(year % 100 == 0 && year % 400 != 0);
    }
}

std::optional<std::string> CheckDateTimeValidity(const DateTime& dt) {
    if (dt.year < kMinYear) {
        return {"year "s + std::to_string(dt.year) + " is too small"s};
    }
    if (dt.year > kMaxYear) {
        return {"year "s + std::to_string(dt.year) + " is too big"s};
    }

    if (dt.month < 1) {
        return {"month "s + std::to_string(dt.month) + " is too small"s};
    }
    if (dt.month > kMonthsInYear) {
        return {"month "s + std::to_string(dt.month) + " is too big"s};
    }

    const bool is_leap_year = IsLeapYear(dt.year);
    const std::array<int, kMonthsInYear> month_lengths = {31, 28 + is_leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (dt.day < 1) {
        return {"day "s + std::to_string(dt.day) + " is too small"s};
    }
    if (dt.day > month_lengths[dt.month - 1]) {
        return {"day "s + std::to_string(dt.day) + " is too big"s};
    }

    if (dt.hour < 0) {
        return {"hour "s + std::to_string(dt.hour) + " is too small"s};
    }
    if (dt.hour > kMaxHour) {
        return {"hour "s + std::to_string(dt.hour) + " is too big"s};
    }

    if (dt.minute < 0) {
        return {"minute "s + std::to_string(dt.minute) + " is too small"s};
    }
    if (dt.minute > kMaxMinute) {
        return {"minute "s + std::to_string(dt.minute) + " is too big"s};
    }

    if (dt.second < 0) {
        return {"second "s + std::to_string(dt.second) + " is too small"s};
    }
    if (dt.second > kMaxSecond) {
        return {"second "s + std::to_string(dt.second) + " is too big"s};
    }

    return std::nullopt;
}
