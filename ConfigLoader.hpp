#pragma once
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

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

    std::vector<std::string> static inline split(const std::string& s) {
        std::stringstream ss(s);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> tokens(begin, end);
        return tokens;
    }

    bool toBool(const std::string& str) {
        std::string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        std::istringstream is(lowerStr);
        bool b;
        is >> std::boolalpha >> b;
        return b;
    }
}

struct ConfigLoader {
    bool FEATURE_AIMBOT_ON;
    bool FEATURE_SENSE_ON;
    bool FEATURE_ITEM_GLOW_ON;
    bool FEATURE_NORECOIL_ON;
    bool FEATURE_TRIGGERBOT_ON;
    bool FEATURE_SPECTATOR_ON;
    bool FEATURE_QUICKTURN_ON;
    std::string FEATURE_QUICKTURN_BUTTON;
    bool FEATURE_SKINCHANGER_ON;
    bool FEATURE_PRINT_LEVELS_ON;
    std::string FEATURE_PRINT_LEVELS_BUTTON;
    bool FEATURE_SUPER_GLIDE_ON;
    bool FEATURE_MAP_RADAR_ON;
    std::string FEATURE_MAP_RADAR_BUTTON;
    int NORECOIL_PITCH_REDUCTION;
    int NORECOIL_YAW_REDUCTION;
    int TRIGGERBOT_ZOOMED_RANGE;
    int TRIGGERBOT_HIPFIRE_RANGE;
    std::string TRIGGERBOT_PAUSE_BUTTON;
    int SENSE_MAXRANGE;
    bool AIMBOT_ACTIVATED_BY_ATTACK;
    bool AIMBOT_ACTIVATED_BY_ADS;
    bool AIMBOT_ACTIVATED_BY_KEY;
    std::string AIMBOT_ACTIVATION_KEY;
    float AIMBOT_SMOOTH;
    float AIMBOT_SPEED;
    float AIMBOT_SMOOTH_EXTRA_BY_DISTANCE;
    float AIMBOT_FOV;
    bool AIMBOT_PREDICT_BULLETDROP;
    bool AIMBOT_PREDICT_MOVEMENT;
    bool AIMBOT_ALLOW_TARGET_SWITCH;
    float AIMBOT_MAX_DISTANCE;
    float AIMBOT_MIN_DISTANCE;

    bool FEATURE_BHOP_ON;
    std::string BHOP_KEY;

    void loadConfig(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open config file");
        }

        std::string line;
        while (std::getline(file, line)) {
            util::trim(line);
            if (line.empty() || line[0] == '#') {
                continue;
            }

            auto keyVal = util::split(line);
            if (keyVal.size() == 2) {
                loadVariables(keyVal[0], keyVal[1]);
            }
        }
    }

    void loadVariables(const std::string& key, const std::string& val) {
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

    void reloadFile() {
        loadConfig("nika.ini");
    }
};
