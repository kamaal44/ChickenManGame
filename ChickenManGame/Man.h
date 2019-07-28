#ifndef MAN_H
#define MAN_H

// ========== Includes ========== //

#include <Arduino.h>           // String Class
#include <ESP8266WiFi.h>       // Scan WiFi
#include <ESP8266HTTPClient.h> // HTTPClient

#include "eeprom.h"
#include "types.h"             // TEAM, LEVEL enums
#include "hardware.h"          // EEPROM_STATS_ADDR

// From config.h
extern const unsigned int NUM_PASSWORDS;
extern const char* SUPER_SECRET PROGMEM;
extern const char* DIFFICULTY[] PROGMEM;
extern const char* SSID_PREFIX PROGMEM;
extern const char* SSID_SUFFIX[] PROGMEM;
extern const char* EASY_PSWD[] PROGMEM;
extern const char* MEDIUM_PSWD[] PROGMEM;
extern const char* HARD_PSWD[];

// ========== Man Class ========== //

class Man {
    private:
        game_stats stats;

        HTTPClient http;

        void saveStats();
        bool recoverStats();

        bool isAChicken(uint8_t* bssid) const;
        bool isAChicken(String ssid, uint8_t* bssid) const;
        String getSSID(uint8_t* bssid) const;
        String getPassword(uint8_t* bssid) const;

        void addScore(String payload);

    public:
        Man();

        void begin();
        void update();

        int getPoints(TEAM team) const;
        String getPointsString() const;

        TEAM getFlag() const;

        bool resetGame(String password);
};


#endif /* ifndef MAN_H */