#pragma once

struct LocalPlayer {
    uint64_t base;
    int teamNumber;
    int squadNumber;
    Vector3D localOrigin;
    Vector3D viewAngles;
    int currentHealth;
    int currentShields;
    int maxHealth;
    int maxShields;
    int weaponIndex;
    float traversalStartTime;
    float traversalProgress;
    float traversalReleaseTime;
    float worldtime;
    int frameCount;
    bool onGround; // Add this line

    bool isValid() {
        return base != 0;
    }

    void setYaw(float yaw) {
        viewAngles.y = yaw;
        mem::Write<Vector3D>(base + OFF_VIEWANGLES, viewAngles);
    }

    void readFromMemory() {
        base = mem::Read<uint64_t>(OFF_REGION + OFF_LOCAL_PLAYER, "LocalPlayer base");
        if (base == 0) return;
        teamNumber = mem::Read<int>(base + OFF_TEAM_NUMBER, "LocalPlayer teamNumber");
        squadNumber = mem::Read<int>(base + OFF_SQUAD_NUMBER, "LocalPlayer squadNumber");
        localOrigin = mem::Read<Vector3D>(base + OFF_LOCAL_ORIGIN, "LocalPlayer localOrigin");
        viewAngles = mem::Read<Vector3D>(base + OFF_VIEWANGLES, "LocalPlayer viewAngles");
        currentHealth = mem::Read<int>(base + OFF_CURRENT_HEALTH, "LocalPlayer currentHealth");
        currentShields = mem::Read<int>(base + OFF_CURRENT_SHIELDS, "LocalPlayer currentShields");
        maxHealth = mem::Read<int>(base + OFF_MAX_HEALTH, "LocalPlayer maxHealth");
        maxShields = mem::Read<int>(base + OFF_MAX_SHIELDS, "LocalPlayer maxShields");
        weaponIndex = mem::Read<int>(base + OFF_WEAPON_INDEX, "LocalPlayer weaponIndex");
        traversalStartTime = mem::Read<float>(base + OFF_TRAVERSAL_START_TIME, "LocalPlayer traversalStartTime");
        traversalProgress = mem::Read<float>(base + OFF_TRAVERSAL_PROGRESS, "LocalPlayer traversalProgress");
        traversalReleaseTime = mem::Read<float>(base + OFF_TRAVERSAL_RELEASE_TIME, "LocalPlayer traversalReleaseTime");
        worldtime = mem::Read<float>(base + OFF_WORLD_TIME, "LocalPlayer worldtime");
        frameCount = mem::Read<int>(base + OFF_FRAME_COUNT, "LocalPlayer frameCount");
        onGround = mem::Read<bool>(base + OFF_ON_GROUND, "LocalPlayer onGround"); // Add this line
    }
};
