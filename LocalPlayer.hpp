#pragma once

#include "Vectors.hpp"
#include "Offsets.hpp"

struct LocalPlayer {
    uint64_t base;
    int teamNumber;
    int squadNumber;
    Vector3D viewAngles;
    Vector3D localOrigin;
    int maxHealth;
    int maxShields;
    float traversalStartTime;
    float traversalProgress;
    float traversalReleaseTime;
    float worldtime;
    int frameCount;
    bool onGround; // This should be defined
    int highlightSettingsPtr;
    int weaponEntity;

    void setYaw(float yaw) {
        viewAngles.y = yaw;
        mem::Write<Vector3D>(base + OFF_VIEW_ANGLES, viewAngles);
    }

    void readFromMemory() {
        base = mem::Read<uint64_t>(OFF_REGION + OFF_LOCAL_PLAYER, "LocalPlayer base");
        squadNumber = mem::Read<int>(base + OFF_SQUAD_NUMBER, "LocalPlayer squadNumber");
        viewAngles = mem::Read<Vector3D>(base + OFF_VIEW_ANGLES, "LocalPlayer viewAngles");
        maxHealth = mem::Read<int>(base + OFF_MAX_HEALTH, "LocalPlayer maxHealth");
        maxShields = mem::Read<int>(base + OFF_MAX_SHIELDS, "LocalPlayer maxShields");
        traversalStartTime = mem::Read<float>(base + OFF_TRAVERSAL_START_TIME, "LocalPlayer traversalStartTime");
        traversalProgress = mem::Read<float>(base + OFF_TRAVERSAL_PROGRESS, "LocalPlayer traversalProgress");
        traversalReleaseTime = mem::Read<float>(base + OFF_TRAVERSAL_RELEASE_TIME, "LocalPlayer traversalReleaseTime");
        worldtime = mem::Read<float>(base + OFF_WORLD_TIME, "LocalPlayer worldtime");
        frameCount = mem::Read<int>(base + OFF_FRAME_COUNT, "LocalPlayer frameCount");
        onGround = mem::Read<bool>(base + OFF_ON_GROUND, "LocalPlayer onGround"); // Add this line
        localOrigin = mem::Read<Vector3D>(base + OFF_LOCAL_ORIGIN, "LocalPlayer localOrigin");
    }

    bool isValid() {
        return base != 0;
    }
};
