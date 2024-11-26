//
// Created by Raphael Barriet on 25/11/2024.
//

#ifndef GLOBALSTATE_H
#define GLOBALSTATE_H



class GlobalState {
private:
    double clock;
    int weathers[24];

    // Private constructor to prevent direct instantiation
    GlobalState() : clock(0.00), weathers{11, 10, 9, 8, 7, 7, 6, 6, 7, 10, 13, 16, 20, 21, 22, 23, 23, 23, 21, 18, 16, 14, 13, 12} {}

public:
    GlobalState(const GlobalState&) = delete;
    GlobalState& operator=(const GlobalState&) = delete;

    static GlobalState& getInstance() {
        static GlobalState instance;
        return instance;
    }

    [[nodiscard]] double getClock() const { return clock; }

    [[nodiscard]] int getWeather(const int hour) const { return weathers[hour]; }

    void incrementClock(const double hours) {
        clock += hours;
        if (clock >= 24.0) clock -= 24.0; // Wrap around after 24 hours
    }

    [[nodiscard]] std::string getFormattedTime() const {
        int hours = static_cast<int>(clock);              // Extract hours
        int minutes = static_cast<int>((clock - hours) * 60); // Extract minutes
        std::string period = (hours < 12) ? "AM" : "PM";
        hours = (hours == 0) ? 12 : (hours > 12 ? hours - 12 : hours); // Convert to 12-hour format
        return std::to_string(hours) + ":" + (minutes < 10 ? "0" : "") + std::to_string(minutes) + " " + period;
    }
};



#endif //GLOBALSTATE_H
