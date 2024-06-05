#pragma once
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

namespace util {
    // trim from start (in place)
    static inline void ltrim(std::string &s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                        { return !std::isspace(ch); }));
    }

    // trim from end (in place)
    static inline void rtrim(std::string &s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                             { return !std::isspace(ch); })
                    .base(),
                s.end());
    }

    // trim from both ends (in place)
    static inline void trim(std::string &s)
    {
        ltrim(s);
        rtrim(s);
    }

    std::vector<std::string> static inline split(std::string s)
    {
        std::stringstream ss(s);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> tokens(begin, end);
        return tokens;
    }
}

std::string trimConstructive(const std::string& str) {
    std::string trimmedStr = str;
    util::trim(trimmedStr);
    return trimmedStr;
}

struct ConfigLoader {
    std::unordered_map<std::string, std::string> configMap;

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
    int NORECOIL_PITCH_REDUCTION = 0;
    int NORECOIL_YAW_REDUCTION = 0;
    int TRIGGERBOT_ZOOMED_RANGE = 0;
    int TRIGGERBOT_HIPFIRE_RANGE = 0;
    std::string TRIGGERBOT_PAUSE_BUTTON = "NONE";
    int SENSE_MAXRANGE = 300;
    bool AIMBOT_ACTIVATED_BY_ATTACK = false;
    bool AIMBOT_ACTIVATED_BY_ADS = false;
    bool AIMBOT_ACTIVATED_BY_KEY = false;
    std::string AIMBOT_ACTIVATION_KEY = "NONE";
    float AIMBOT_SMOOTH = 88.96;
    float AIMBOT_SPEED = 29.2;
    float AIMBOT_SMOOTH_EXTRA_BY_DISTANCE = 1887.4;
    float AIMBOT_FOV = 8.52;
    bool AIMBOT_PREDICT_BULLETDROP = false;
    bool AIMBOT_PREDICT_MOVEMENT = false;
    bool AIMBOT_ALLOW_TARGET_SWITCH = false;
    int AIMBOT_MAX_DISTANCE = 294;
    int AIMBOT_MIN_DISTANCE = 1;

    // Bunny Hop
    bool FEATURE_BHOP_ON = false;
    std::string BHOP_KEY = "XK_Space";

    void loadVariables(std::string key, std::string val) {
        FEATURE_AIMBOT_ON = (key.compare("FEATURE_AIMBOT_ON") != 0) ? FEATURE_AIMBOT_ON : (val == "YES");
        FEATURE_SENSE_ON = (key.compare("FEATURE_SENSE_ON") != 0) ? FEATURE_SENSE_ON : (val == "YES");
        FEATURE_ITEM_GLOW_ON = (key.compare("FEATURE_ITEM_GLOW_ON") != 0) ? FEATURE_ITEM_GLOW_ON : (val == "YES");
        FEATURE_NORECOIL_ON = (key.compare("FEATURE_NORECOIL_ON") != 0) ? FEATURE_NORECOIL_ON : (val == "YES");
        FEATURE_TRIGGERBOT_ON = (key.compare("FEATURE_TRIGGERBOT_ON") != 0) ? FEATURE_TRIGGERBOT_ON : (val == "YES");
        FEATURE_SPECTATOR_ON = (key.compare("FEATURE_SPECTATOR_ON") != 0) ? FEATURE_SPECTATOR_ON : (val == "YES");
        FEATURE_QUICKTURN_ON = (key.compare("FEATURE_QUICKTURN_ON") != 0) ? FEATURE_QUICKTURN_ON : (val == "YES");
        FEATURE_QUICKTURN_BUTTON = (key.compare("FEATURE_QUICKTURN_BUTTON") != 0) ? FEATURE_QUICKTURN_BUTTON : trimConstructive(val);
        FEATURE_SKINCHANGER_ON = (key.compare("FEATURE_SKINCHANGER_ON") != 0) ? FEATURE_SKINCHANGER_ON : (val == "YES");
        FEATURE_PRINT_LEVELS_ON = (key.compare("FEATURE_PRINT_LEVELS_ON") != 0) ? FEATURE_PRINT_LEVELS_ON : (val == "YES");
        FEATURE_PRINT_LEVELS_BUTTON = (key.compare("FEATURE_PRINT_LEVELS_BUTTON") != 0) ? FEATURE_PRINT_LEVELS_BUTTON : trimConstructive(val);
        FEATURE_SUPER_GLIDE_ON = (key.compare("FEATURE_SUPER_GLIDE_ON") != 0) ? FEATURE_SUPER_GLIDE_ON : (val == "YES");
        FEATURE_MAP_RADAR_ON = (key.compare("FEATURE_MAP_RADAR_ON") != 0) ? FEATURE_MAP_RADAR_ON : (val == "YES");
        FEATURE_MAP_RADAR_BUTTON = (key.compare("FEATURE_MAP_RADAR_BUTTON") != 0) ? FEATURE_MAP_RADAR_BUTTON : trimConstructive(val);
        NORECOIL_PITCH_REDUCTION = (key.compare("NORECOIL_PITCH_REDUCTION") != 0) ? NORECOIL_PITCH_REDUCTION : std::stoi(val);
        NORECOIL_YAW_REDUCTION = (key.compare("NORECOIL_YAW_REDUCTION") != 0) ? NORECOIL_YAW_REDUCTION : std::stoi(val);
        TRIGGERBOT_ZOOMED_RANGE = (key.compare("TRIGGERBOT_ZOOMED_RANGE") != 0) ? TRIGGERBOT_ZOOMED_RANGE : std::stoi(val);
        TRIGGERBOT_HIPFIRE_RANGE = (key.compare("TRIGGERBOT_HIPFIRE_RANGE") != 0) ? TRIGGERBOT_HIPFIRE_RANGE : std::stoi(val);
        TRIGGERBOT_PAUSE_BUTTON = (key.compare("TRIGGERBOT_PAUSE_BUTTON") != 0) ? TRIGGERBOT_PAUSE_BUTTON : trimConstructive(val);
        SENSE_MAXRANGE = (key.compare("SENSE_MAXRANGE") != 0) ? SENSE_MAXRANGE : std::stoi(val);
        AIMBOT_ACTIVATED_BY_ATTACK = (key.compare("AIMBOT_ACTIVATED_BY_ATTACK") != 0) ? AIMBOT_ACTIVATED_BY_ATTACK : (val == "YES");
        AIMBOT_ACTIVATED_BY_ADS = (key.compare("AIMBOT_ACTIVATED_BY_ADS") != 0) ? AIMBOT_ACTIVATED_BY_ADS : (val == "YES");
        AIMBOT_ACTIVATED_BY_KEY = (key.compare("AIMBOT_ACTIVATED_BY_KEY") != 0) ? AIMBOT_ACTIVATED_BY_KEY : (val == "YES");
        AIMBOT_ACTIVATION_KEY = (key.compare("AIMBOT_ACTIVATION_KEY") != 0) ? AIMBOT_ACTIVATION_KEY : trimConstructive(val);
        AIMBOT_SMOOTH = (key.compare("AIMBOT_SMOOTH") != 0) ? AIMBOT_SMOOTH : std::stof(val);
        AIMBOT_SPEED = (key.compare("AIMBOT_SPEED") != 0) ? AIMBOT_SPEED : std::stof(val);
        AIMBOT_SMOOTH_EXTRA_BY_DISTANCE = (key.compare("AIMBOT_SMOOTH_EXTRA_BY_DISTANCE") != 0) ? AIMBOT_SMOOTH_EXTRA_BY_DISTANCE : std::stof(val);
        AIMBOT_FOV = (key.compare("AIMBOT_FOV") != 0) ? AIMBOT_FOV : std::stof(val);
        AIMBOT_PREDICT_BULLETDROP = (key.compare("AIMBOT_PREDICT_BULLETDROP") != 0) ? AIMBOT_PREDICT_BULLETDROP : (val == "YES");
        AIMBOT_PREDICT_MOVEMENT = (key.compare("AIMBOT_PREDICT_MOVEMENT") != 0) ? AIMBOT_PREDICT_MOVEMENT : (val == "YES");
        AIMBOT_ALLOW_TARGET_SWITCH = (key.compare("AIMBOT_ALLOW_TARGET_SWITCH") != 0) ? AIMBOT_ALLOW_TARGET_SWITCH : (val == "YES");
        AIMBOT_MAX_DISTANCE = (key.compare("AIMBOT_MAX_DISTANCE") != 0) ? AIMBOT_MAX_DISTANCE : std::stoi(val);
        AIMBOT_MIN_DISTANCE = (key.compare("AIMBOT_MIN_DISTANCE") != 0) ? AIMBOT_MIN_DISTANCE : std::stoi(val);

        // Bunny Hop
        FEATURE_BHOP_ON = (key.compare("FEATURE_BHOP_ON") != 0) ? FEATURE_BHOP_ON : (val == "YES");
        BHOP_KEY = (key.compare("BHOP_KEY") != 0) ? BHOP_KEY : trimConstructive(val);
    }

    void parseLines() {
        std::ifstream file("nika.ini");
        std::string line;
        while (std::getline(file, line)) {
            util::trim(line);
            if (line.empty() || line[0] == '#') continue;
            std::vector<std::string> keyVal = util::split(line);
            if (keyVal.size() == 2) {
                loadVariables(keyVal[0], keyVal[1]);
            }
        }
    }

    void reloadFile() {
        parseLines();
    }
};
