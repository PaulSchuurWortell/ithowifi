#pragma once

#define LOG_CONFIG_VERSION "001"

#include <cstdio>
#include <string>

#include <Arduino.h>
#include <ArduinoJson.h>

class LogConfig
{
public:
    uint8_t loglevel;
    uint8_t syslog_active;
    uint8_t esplog_active;
    char logserver[64];
    uint16_t logport;
    char logref[64];
    uint8_t webserial_active;
    uint8_t rfloglevel;
    char config_struct_version[4];

    mutable bool configLoaded;

    LogConfig();
    ~LogConfig();

    bool set(JsonObject);
    void get(JsonObject) const;

protected:
}; // LogConfig

extern LogConfig logConfig;
