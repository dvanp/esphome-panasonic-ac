#pragma once

#include "esphome/components/climate/climate_traits.h"

namespace esphome {
namespace panasonic_ac {

static const uint8_t MIN_TEMPERATURE = 16;     // Minimum temperature as reported by Panasonic app
static const uint8_t MAX_TEMPERATURE = 30;     // Maximum temperature as supported by Panasonic app
static const float TEMPERATURE_STEP = 0.5;     // Steps the temperature can be set in
static const float TEMPERATURE_TOLERANCE = 2;  // The tolerance to allow when checking the climate state
static const uint8_t TEMPERATURE_THRESHOLD = 100;  // Maximum temperature the AC can report before considering the temperature as invalid

// Custom fan modes for Panasonic AC - uses custom modes instead of built-in ESPHome fan modes
// to maintain all 5 speed levels + auto (ESPHome built-in only supports LOW/MEDIUM/HIGH)
static const std::string FAN_SPEED_LEVEL_AUTO = "Dynamisch";
static const std::string FAN_SPEED_LEVEL_1 = "Level 1";
static const std::string FAN_SPEED_LEVEL_2 = "Level 2";
static const std::string FAN_SPEED_LEVEL_3 = "Level 3";
static const std::string FAN_SPEED_LEVEL_4 = "Level 4";
static const std::string FAN_SPEED_LEVEL_5 = "Level 5";



class PanasonicACTraitsBuilder {
    public:
        PanasonicACTraitsBuilder();
        climate::ClimateTraits build_traits() const { return this->traits; };
        void add_horizontal_swing_mode();
        void add_vertical_swing_mode();
    private:
        climate::ClimateTraits traits = climate::ClimateTraits();
};

}
}
