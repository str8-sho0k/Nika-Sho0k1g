#pragma once
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

struct ConfigLoader {
    std::unordered_map<std::string, std::string> configValues;

    void loadConfig(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;

        if (!file.is_open()) {
            throw std::runtime_error("Could not open config file");
        }

        while (std::getline(file, line)) {
            util::trim(line);
            if (line.empty() || line[0] == '#') continue;
            auto keyVal = util::split(line);
            if (keyVal.size() != 3 || keyVal[1] != "=") continue;

            configValues[keyVal[0]] = keyVal[2];
        }
        file.close();

        for (const auto& [key, val] : configValues) {
            loadVariables(key, val);
        }
    }

    // Main Features
    bool FEATURE_AIMBOT_ON = false;
    bool FEATURE_SENSE_ON = false;
    bool FEATURE_ITEM_GLOW_ON = false;
    bool FEATURE_NORECOIL_ON = false;
    bool FEATURE_TRIGGERBOT_ON = false;
    bool FEATURE_SPECTATOR_ON = false;
    bool FEATURE_QUICKTURN_ON = false;
    std::string FEATURE_QUICKTURN_BUTTON = "NONE";
    bool FEATURE_SKINCHANGER_ON = false;
    bool FEATURE_PRINT_LEVELS_ON = false;
    std::string FEATURE_PRINT_LEVELS_BUTTON = "NONE";
    bool FEATURE_SUPER_GLIDE_ON = false;
    bool FEATURE_MAP_RADAR_ON = false;
    std::string FEATURE_MAP_RADAR_BUTTON = "NONE";

    // No Recoil
    int NORECOIL_PITCH_REDUCTION = 0;
    int NORECOIL_YAW_REDUCTION = 0;

    // Trigger Bot
    int TRIGGERBOT_ZOOMED_RANGE = 0;
    int TRIGGERBOT_HIPFIRE_RANGE = 0;
    std::string TRIGGERBOT_PAUSE_BUTTON = "NONE";

    // Sense
    int SENSE_MAXRANGE = 300;

    // Aimbot
    bool AIMBOT_ACTIVATED_BY_ATTACK = false;
    bool AIMBOT_ACTIVATED_BY_ADS = false;
    bool AIMBOT_ACTIVATED_BY_KEY = false;
    std::string AIMBOT_ACTIVATION_KEY = "NONE";

    float AIMBOT_SMOOTH = 88.96f;
    float AIMBOT_SPEED = 29.2f;
    float AIMBOT_SMOOTH_EXTRA_BY_DISTANCE = 1887.4f;
    float AIMBOT_FOV = 8.52f;

    bool AIMBOT_PREDICT_BULLETDROP = false;
    bool AIMBOT_PREDICT_MOVEMENT = false;
    bool AIMBOT_ALLOW_TARGET_SWITCH = false;

    float AIMBOT_MAX_DISTANCE = 294;
    float AIMBOT_MIN_DISTANCE = 1;

    // Bunny Hop
    bool FEATURE_BHOP_ON = false;
    std::string BHOP_KEY = "XK_Space";

    void loadVariables(std::string key, std::string val) {
        FEATURE_AIMBOT_ON = (key == "FEATURE_AIMBOT_ON") ? util::toBool(val) : FEATURE_AIMBOT_ON;
        FEATURE_SENSE_ON = (key == "FEATURE_SENSE_ON") ? util::toBool(val) : FEATURE_SENSE_ON;
        FEATURE_ITEM_GLOW_ON = (key == "FEATURE_ITEM_GLOW_ON") ? util::toBool(val) : FEATURE_ITEM_GLOW_ON;
        FEATURE_NORECOIL_ON = (key == "FEATURE_NORECOIL_ON") ? util::toBool(val) : FEATURE_NORECOIL_ON;
        FEATURE_TRIGGERBOT_ON = (key == "FEATURE_TRIGGERBOT_ON") ? util::toBool(val) : FEATURE_TRIGGERBOT_ON;
        FEATURE_SPECTATOR_ON = (key == "FEATURE_SPECTATOR_ON") ? util::toBool(val) : FEATURE_SPECTATOR_ON;
        FEATURE_QUICKTURN_ON = (key == "FEATURE_QUICKTURN_ON") ? util::toBool(val) : FEATURE_QUICKTURN_ON;
        FEATURE_QUICKTURN_BUTTON = (key == "FEATURE_QUICKTURN_BUTTON") ? val : FEATURE_QUICKTURN_BUTTON;
        FEATURE_SKINCHANGER_ON = (key == "FEATURE_SKINCHANGER_ON") ? util::toBool(val) : FEATURE_SKINCHANGER_ON;
        FEATURE_PRINT_LEVELS_ON = (key == "FEATURE_PRINT_LEVELS_ON") ? util::toBool(val) : FEATURE_PRINT_LEVELS_ON;
        FEATURE_PRINT_LEVELS_BUTTON = (key == "FEATURE_PRINT_LEVELS_BUTTON") ? val : FEATURE_PRINT_LEVELS_BUTTON;
        FEATURE_SUPER_GLIDE_ON = (key == "FEATURE_SUPER_GLIDE_ON") ? util::toBool(val) : FEATURE_SUPER_GLIDE_ON;
        FEATURE_MAP_RADAR_ON = (key == "FEATURE_MAP_RADAR_ON") ? util::toBool(val) : FEATURE_MAP_RADAR_ON;
        FEATURE_MAP_RADAR_BUTTON = (key == "FEATURE_MAP_RADAR_BUTTON") ? val : FEATURE_MAP_RADAR_BUTTON;

        NORECOIL_PITCH_REDUCTION = (key == "NORECOIL_PITCH_REDUCTION") ? std::stoi(val) : NORECOIL_PITCH_REDUCTION;
        NORECOIL_YAW_REDUCTION = (key == "NORECOIL_YAW_REDUCTION") ? std::stoi(val) : NORECOIL_YAW_REDUCTION;

        TRIGGERBOT_ZOOMED_RANGE = (key == "TRIGGERBOT_ZOOMED_RANGE") ? std::stoi(val) : TRIGGERBOT_ZOOMED_RANGE;
        TRIGGERBOT_HIPFIRE_RANGE = (key == "TRIGGERBOT_HIPFIRE_RANGE") ? std::stoi(val) : TRIGGERBOT_HIPFIRE_RANGE;
        TRIGGERBOT_PAUSE_BUTTON = (key == "TRIGGERBOT_PAUSE_BUTTON") ? val : TRIGGERBOT_PAUSE_BUTTON;

        SENSE_MAXRANGE = (key == "SENSE_MAXRANGE") ? std::stoi(val) : SENSE_MAXRANGE;

        AIMBOT_ACTIVATED_BY_ATTACK = (key == "AIMBOT_ACTIVATED_BY_ATTACK") ? util::toBool(val) : AIMBOT_ACTIVATED_BY_ATTACK;
        AIMBOT_ACTIVATED_BY_ADS = (key == "AIMBOT_ACTIVATED_BY_ADS") ? util::toBool(val) : AIMBOT_ACTIVATED_BY_ADS;
        AIMBOT_ACTIVATED_BY_KEY = (key == "AIMBOT_ACTIVATED_BY_KEY") ? util::toBool(val) : AIMBOT_ACTIVATED_BY_KEY;
        AIMBOT_ACTIVATION_KEY = (key == "AIMBOT_ACTIVATION_KEY") ? val : AIMBOT_ACTIVATION_KEY;

        AIMBOT_SMOOTH = (key == "AIMBOT_SMOOTH") ? std::stof(val) : AIMBOT_SMOOTH;
        AIMBOT_SPEED = (key == "AIMBOT_SPEED") ? std::stof(val) : AIMBOT_SPEED;
        AIMBOT_SMOOTH_EXTRA_BY_DISTANCE = (key == "AIMBOT_SMOOTH_EXTRA_BY_DISTANCE") ? std::stof(val) : AIMBOT_SMOOTH_EXTRA_BY_DISTANCE;
        AIMBOT_FOV = (key == "AIMBOT_FOV") ? std::stof(val) : AIMBOT_FOV;

        AIMBOT_PREDICT_BULLETDROP = (key == "AIMBOT_PREDICT_BULLETDROP") ? util::toBool(val) : AIMBOT_PREDICT_BULLETDROP;
        AIMBOT_PREDICT_MOVEMENT = (key == "AIMBOT_PREDICT_MOVEMENT") ? util::toBool(val) : AIMBOT_PREDICT_MOVEMENT;
        AIMBOT_ALLOW_TARGET_SWITCH = (key == "AIMBOT_ALLOW_TARGET_SWITCH") ? util::toBool(val) : AIMBOT_ALLOW_TARGET_SWITCH;

        AIMBOT_MAX_DISTANCE = (key == "AIMBOT_MAX_DISTANCE") ? std::stof(val) : AIMBOT_MAX_DISTANCE;
        AIMBOT_MIN_DISTANCE = (key == "AIMBOT_MIN_DISTANCE") ? std::stof(val) : AIMBOT_MIN_DISTANCE;

        FEATURE_BHOP_ON = (key == "FEATURE_BHOP_ON") ? util::toBool(val) : FEATURE_BHOP_ON;
        BHOP_KEY = (key == "BHOP_KEY") ? val : BHOP_KEY;
    }
};
