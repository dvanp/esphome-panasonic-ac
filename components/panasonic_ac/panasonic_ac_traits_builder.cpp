#include "panasonic_ac_traits_builder.h"

namespace esphome {
namespace panasonic_ac {

PanasonicACTraitsBuilder::PanasonicACTraitsBuilder() {
    // ESPHome 2026.7 replaced the individual supports_* setters with feature flags.
    // Two-point target temperature support remains disabled by default.
    this->traits.add_feature_flags(climate::CLIMATE_SUPPORTS_ACTION |
                                   climate::CLIMATE_SUPPORTS_CURRENT_TEMPERATURE);
    // Set visual temperature parameters
    this->traits.set_visual_min_temperature(MIN_TEMPERATURE);
    this->traits.set_visual_max_temperature(MAX_TEMPERATURE);
    this->traits.set_visual_temperature_step(TEMPERATURE_STEP);
    // Set default supported modes
    this->traits.set_supported_modes({
        climate::CLIMATE_MODE_OFF,
        climate::CLIMATE_MODE_HEAT,
        climate::CLIMATE_MODE_COOL,
        climate::CLIMATE_MODE_DRY,
        climate::CLIMATE_MODE_HEAT_COOL,
        climate::CLIMATE_MODE_FAN_ONLY
    });
    // Set default OFF swing mode
    this->traits.add_supported_swing_mode(climate::CLIMATE_SWING_OFF);
    // Set default presets
    this->traits.set_supported_presets({
        climate::CLIMATE_PRESET_NONE,
        climate::CLIMATE_PRESET_ECO,
        climate::CLIMATE_PRESET_BOOST
    });
}

void PanasonicACTraitsBuilder::add_horizontal_swing_mode() {
    this->traits.add_supported_swing_mode(climate::CLIMATE_SWING_HORIZONTAL);
    if (this->traits.supports_swing_mode(climate::CLIMATE_SWING_VERTICAL)) {
        this->traits.add_supported_swing_mode(climate::CLIMATE_SWING_BOTH);
    }
}

void PanasonicACTraitsBuilder::add_vertical_swing_mode() {
    this->traits.add_supported_swing_mode(climate::CLIMATE_SWING_VERTICAL);
    if (this->traits.supports_swing_mode(climate::CLIMATE_SWING_HORIZONTAL)) {
        this->traits.add_supported_swing_mode(climate::CLIMATE_SWING_BOTH);
    }
}

}
}
