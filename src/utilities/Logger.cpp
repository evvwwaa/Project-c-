#include "Logger.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

Logger::Logger(const std::string& filename) : _currentLevel(INFO) {
    _file.open(filename, std::ios::app);
    if (!_file.is_open()) {
        std::cerr << "Error" << std::endl;
    }
}

std::string Logger::_time() {
    std::time_t time = std::time(nullptr);
    std::string time_str = std::ctime(&time);
    time_str.pop_back();
    return time_str;
}

std::string Logger::_format(Level level) {
    switch(level) {
        case ERROR:
            return "ERROR";
        case WARNING:
            return "WARNING";
        case INFO:
            return "INFO";
        case DEBUG:
            return "DEBUG";
        default:
            return "UNKNOWN";
    }
}

Logger & Logger::getInstance(const std::string &filename) {
    static Logger instance(filename);
    return instance;
}

void Logger::log(const std::string &message, Level level) {
    if (level > _currentLevel) {
        return;
    }
    std::string time = _time();
    std::string format = _format(level);

    std::string res = "[" + time + "] [" + format + "] " + message;

    if (_file.is_open()) {
        _file << res << std::endl;
        _file.flush();
    }
}

void Logger::setLevel(Level level) {
    _currentLevel = level;
}

Logger::~Logger() {
    _file.close();
}

Logger::Logger() {
};
