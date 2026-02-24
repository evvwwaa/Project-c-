#pragma once

#include <string>
#include <fstream>
class Logger {
public:
    Logger(const Logger&) = delete;
    Logger& operator = (const Logger&) = delete;

    enum Level {
        ERROR,
        WARNING,
        INFO,
        DEBUG,
    };

    static Logger& getInstance(const std::string& filename = "file.txt");

    void log(const std::string& message, Level level);
    void setLevel(Level level);

    ~Logger();

private:
    Logger();
    explicit Logger(const std::string& filename);

    std::ofstream _file;
    Level _currentLevel;

    std::string _time();
    std::string _format(Level level);
};
