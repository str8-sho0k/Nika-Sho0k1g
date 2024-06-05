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
            if (keyVal.size() >= 2) {
                std::string key = keyVal[0];
                std::string val = keyVal[1];
                for (size_t i = 2; i < keyVal.size(); ++i) {
                    val += " " + keyVal[i];
                }
                configValues[key] = val;
            }
        }
    }

    void parseLines() {
        for (const auto& [key, val] : configValues) {
            loadVariables(key, val);
        }
    }

    void loadVariables(std::string key, std::string val) {
        using namespace std::string_literals;

        // Enable/Disable Features
        FEATURE_AIMBOT_ON = (key == "FEATURE_AIMBOT_ON") ? util::toBool(val) : FEATURE_AIMBOT_ON;
        FEATURE_SENSE_ON = (key == "FEATURE_SENSE_ON") ? util::toBool(val) : FEATURE_SENSE_ON;
        FEATURE_ITEM_GLOW_ON = (key == "FEATURE_ITEM_GLOW_ON") ? util::toBool(val) : FEATURE_ITEM_GLOW_ON;
        FEATURE_NORECOIL_ON = (key == "FEATURE_NORECOIL_ON") ? util::toBool(val) : FEATURE_NORECOIL_ON;
        FEATURE_TRIGGERBOT_ON = (key == "FEATURE_TRIGGERBOT_ON") ? util::toBool(val) : FEATURE_TRIGGERBOT_ON;
        FEATURE_SPECTATOR_ON = (key == "FEATURE_SPECTATOR_ON") ? util::toBool(val) : FEATURE_SPECTATOR_ON;
        FEATURE_QUICKTURN_ON = (key == "FEATURE_QUICKTURN_ON") ? util::toBool(val) : FEATURE_QUICKTURN_ON;
        FEATURE_SKINCHANGER_ON = (key == "FEATURE_SKINCHANGER_ON") ? util::toBool(val) : FEATURE_SKINCHANGER_ON;
        FEATURE_PRINT_LEVELS_ON = (key == "FEATURE_PRINT_LEVELS_ON") ? util::toBool(val) : FEATURE_PRINT_LEVELS_ON;
        FEATURE_SUPER_GLIDE_ON = (key == "FEATURE_SUPER_GLIDE_ON") ? util::toBool(val) : FEATURE_SUPER_GLIDE_ON;
        FEATURE_MAP_RADAR_ON = (key == "FEATURE_MAP_RADAR_ON") ? util::toBool(val) : FEATURE_MAP_RADAR_ON;
        FEATURE_BHOP_ON = (key == "FEATURE_BHOP_ON") ? util::toBool(val) : FEATURE_BHOP_ON;

        // NORECOIL
        NORECOIL_PITCH_REDUCTION = (key == "NORECOIL_PITCH_REDUCTION") ? std::stof(val) : NORECOIL_PITCH_REDUCTION;
        NORECOIL_YAW_REDUCTION = (key == "NORECOIL_YAW_REDUCTION") ? std::stof(val) : NORECOIL_YAW_REDUCTION;

        // TRIGGERBOT
        TRIGGERBOT_ZOOMED_RANGE = (key == "TRIGGERBOT_ZOOMED_RANGE") ? std::stof(val) : TRIGGERBOT_ZOOMED_RANGE;
        TRIGGERBOT_HIPFIRE_RANGE = (key == "TRIGGERBOT_HIPFIRE_RANGE") ? std::stof(val) : TRIGGERBOT_HIPFIRE_RANGE;

        // SENSE
        SENSE_MAXRANGE = (key == "SENSE_MAXRANGE") ? std::stof(val) : SENSE_MAXRANGE;

        // AIMBOT
        AIMBOT_ACTIVATED_BY_ATTACK = (key == "AIMBOT_ACTIVATED_BY_ATTACK") ? util::toBool(val) : AIMBOT_ACTIVATED_BY_ATTACK;
        AIMBOT_ACTIVATED_BY_ADS = (key == "AIMBOT_ACTIVATED_BY_ADS") ? util::toBool(val) : AIMBOT_ACTIVATED_BY_ADS;
        AIMBOT_ACTIVATED_BY_KEY = (key == "AIMBOT_ACTIVATED_BY_KEY") ? util::toBool(val) : AIMBOT_ACTIVATED_BY_KEY;
        AIMBOT_ACTIVATION_KEY = (key == "AIMBOT_ACTIVATION_KEY" && val != "NONE") ? val : AIMBOT_ACTIVATION_KEY;
        AIMBOT_SMOOTH = (key == "AIMBOT_SMOOTH") ? std::stof(val) : AIMBOT_SMOOTH;
        AIMBOT_SPEED = (key == "AIMBOT_SPEED") ? std::stof(val) : AIMBOT_SPEED;
        AIMBOT_SMOOTH_EXTRA_BY_DISTANCE = (key == "AIMBOT_SMOOTH_EXTRA_BY_DISTANCE") ? std::stof(val) : AIMBOT_SMOOTH_EXTRA_BY_DISTANCE;
        AIMBOT_FOV = (key == "AIMBOT_FOV") ? std::stof(val) : AIMBOT_FOV;
        AIMBOT_PREDICT_BULLETDROP = (key == "AIMBOT_PREDICT_BULLETDROP") ? util::toBool(val) : AIMBOT_PREDICT_BULLETDROP;
        AIMBOT_PREDICT_MOVEMENT = (key == "AIMBOT_PREDICT_MOVEMENT") ? util::toBool(val) : AIMBOT_PREDICT_MOVEMENT;
        AIMBOT_ALLOW_TARGET_SWITCH = (key == "AIMBOT_ALLOW_TARGET_SWITCH") ? util::toBool(val) : AIMBOT_ALLOW_TARGET_SWITCH;
        AIMBOT_MAX_DISTANCE = (key == "AIMBOT_MAX_DISTANCE") ? std::stof(val) : AIMBOT_MAX_DISTANCE;
        AIMBOT_MIN_DISTANCE = (key == "AIMBOT_MIN_DISTANCE") ? std::stof(val) : AIMBOT_MIN_DISTANCE;

        // MISC
        QUICKTURN_BUTTON = (key == "QUICKTURN_BUTTON" && val != "NONE") ? val : QUICKTURN_BUTTON;
        PRINT_LEVELS_BUTTON = (key == "PRINT_LEVELS_BUTTON" && val != "NONE") ? val : PRINT_LEVELS_BUTTON;
        MAP_RADAR_BUTTON = (key == "MAP_RADAR_BUTTON" && val != "NONE") ? val : MAP_RADAR_BUTTON;
        TRIGGERBOT_PAUSE_BUTTON = (key == "TRIGGERBOT_PAUSE_BUTTON" && val != "NONE") ? val : TRIGGERBOT_PAUSE_BUTTON;
        BHOP_KEY = (key == "BHOP_KEY" && val != "NONE") ? val : BHOP_KEY;
    }

    // Feature toggles
    bool FEATURE_AIMBOT_ON = false;
    bool FEATURE_SENSE_ON = false;
    bool FEATURE_ITEM_GLOW_ON = false;
    bool FEATURE_NORECOIL_ON = false;
    bool FEATURE_TRIGGERBOT_ON = false;
    bool FEATURE_SPECTATOR_ON = false;
    bool FEATURE_QUICKTURN_ON = false;
    bool FEATURE_SKINCHANGER_ON = false;
    bool FEATURE_PRINT_LEVELS_ON = false;
    bool FEATURE_SUPER_GLIDE_ON = false;
    bool FEATURE_MAP_RADAR_ON = false;
    bool FEATURE_BHOP_ON = false;

    // NORECOIL
    float NORECOIL_PITCH_REDUCTION = 0;
    float NORECOIL_YAW_REDUCTION = 0;

    // TRIGGERBOT
    float TRIGGERBOT_ZOOMED_RANGE = 0;
    float TRIGGERBOT_HIPFIRE_RANGE = 0;

    // SENSE
    float SENSE_MAXRANGE = 300;

    // AIMBOT
    bool AIMBOT_ACTIVATED_BY_ATTACK = false;
    bool AIMBOT_ACTIVATED_BY_ADS = false;
    bool AIMBOT_ACTIVATED_BY_KEY = false;
    std::string AIMBOT_ACTIVATION_KEY = "";
    float AIMBOT_SMOOTH = 88.96;
    float AIMBOT_SPEED = 29.2;
    float AIMBOT_SMOOTH_EXTRA_BY_DISTANCE = 1887.4;
    float AIMBOT_FOV = 8.52;
    bool AIMBOT_PREDICT_BULLETDROP = false;
    bool AIMBOT_PREDICT_MOVEMENT = false;
    bool AIMBOT_ALLOW_TARGET_SWITCH = false;
    float AIMBOT_MAX_DISTANCE = 294;
    float AIMBOT_MIN_DISTANCE = 1;

    // MISC
    std::string QUICKTURN_BUTTON = "";
    std::string PRINT_LEVELS_BUTTON = "";
    std::string MAP_RADAR_BUTTON = "";
    std::string TRIGGERBOT_PAUSE_BUTTON = "";
    std::string BHOP_KEY = "";
};

namespace util {
    // trim from start (in place)
    static inline void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
    }

    // trim from end (in place)
    static inline void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    // trim from both ends (in place)
    static inline void trim(std::string &s) {
        ltrim(s);
        rtrim(s);
    }

    std::vector<std::string> static inline split(std::string s) {
        std::stringstream ss(s);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> tokens(begin, end);
        return tokens;
    }

    bool toBool(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::istringstream is(str);
        bool b;
        is >> std::boolalpha >> b;
        return b;
    }
}
