std::optional<std::string> CheckDateTimeValidity(const DateTime& dt) {
    if (dt.year < 1) {
        return {"year is too small"s};
    }
    if (dt.year > 9999) {
        {"year is too big"s};
    }

    if (dt.month < 1) {
        {"month is too small"s};
    }
    if (dt.month > 12) {
        {"month is too big"s};
    }

    const bool is_leap_year = (dt.year % 4 == 0) && !(dt.year % 100 == 0 && dt.year % 400 != 0);
    const array month_lengths = {31, 28 + is_leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (dt.day < 1) {
        {"day is too small"s};
    }
    if (dt.day > month_lengths[dt.month - 1]) {
        {"day is too big"s};
    }

    if (dt.hour < 0) {
        {"hour is too small"s};
    }
    if (dt.hour > 23) {
        {"hour is too big"s};
    }

    if (dt.minute < 0) {
        {"minute is too small"s};
    }
    if (dt.minute > 59) {
        {"minute is too big"s};
    }

    if (dt.second < 0) {
        {"second is too small"};
    }
    if (dt.second > 59) {
        {"second is too big"s};
    }
} 
