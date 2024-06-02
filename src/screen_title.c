#include "raylib.h"
#include "rlgl.h"
#include "screens.h"
#include <stdio.h> 
#include <math.h>
#include "gauges.h"

static int framesCounter = 0;
static int finishScreen = 0;
static float heightOffset = 30.0f;
int rpm = 3000;
const int rpmMax = 5000;
int speed = 15;
const int speedMax = 50;
float temp = 0;
float voltage = 6;
float angle = 225;
bool maxAngle = false;

// Title Screen Initialization logic
void InitTitleScreen(void) {
    // TODO: Initialize TITLE screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// Title Screen Update logic
void UpdateTitleScreen(void) {
    // TODO: Update TITLE screen variables here!
}

// Title Screen Draw logic
void DrawTitleScreen(void) {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

    // LEFT HAND SIDE ( RPM )
    Vector2 speedCenter = { (GetScreenWidth() / 4.0f), (GetScreenHeight() / 2.0f) + heightOffset };
    Vector2 rpmCenter = { (GetScreenWidth() / 1.35f), (GetScreenHeight() / 2.0f) + heightOffset };

    DrawRectangle(speedCenter.x, speedCenter.y-160, rpmCenter.x-speedCenter.x, 320, (Color){102, 191, 255, 155});

    DrawCircle(speedCenter.x, speedCenter.y, 210, BLACK);
    DrawNeedle(speedCenter, speed, speedMax);
    DrawCircularGauge(speedCenter);
    DrawSemiCircularGauge(speedCenter, true);

    DrawTextEx(
        font,
        "KM/H",
        (Vector2){ ((GetScreenWidth())/4.0f)-(MeasureTextEx(font, "KM/H", 24, 2).x)/2.0f, (((GetScreenHeight())/2.0f)+30.0f)+heightOffset },
        24,
        2,
        RAYWHITE
    );
    DrawTextEx(
        font,
        TextFormat("%i", speed),
        (Vector2){ ((GetScreenWidth())/4.0f)-(MeasureTextEx(font, TextFormat("%i", speed), 64, 2).x)/2.0f, (((GetScreenHeight())/2.0f)-35.0f)+heightOffset },
        64,
        2,
        RAYWHITE
    );
    calculateSpeedLocations(speedCenter.x, speedCenter.y-10, 160, -225.0f, 45.0f, &font);
    // calculateSemiCircle(rpmCenter.x, rpmCenter.y-10, 150, 360, 0, 10);

    DrawCircle(rpmCenter.x, rpmCenter.y, 210, BLACK);
    DrawNeedle(rpmCenter, rpm, rpmMax);
    DrawCircularGauge(rpmCenter);
    DrawSemiCircularGauge(rpmCenter, false);

    DrawTextEx(
        font,
        "RPM",
        (Vector2){ (((GetScreenWidth())/1.35f)-(MeasureTextEx(font, "RPM", 24, 2).x)/2.0f), (((GetScreenHeight())/2.0f)+30.0f)+heightOffset },
        24,
        2,
        RAYWHITE
    );
    
    DrawTextEx(
        font,
        TextFormat("%i", rpm),
        (Vector2){ (((GetScreenWidth())/1.35f)-(MeasureTextEx(font, TextFormat("%i", rpm), 64, 2).x)/2.0f), (((GetScreenHeight())/2.0f)-35.0f)+heightOffset },
        64,
        2,
        RAYWHITE
    );

    calculateRPMLocations(rpmCenter.x, rpmCenter.y-10, 160, -225.0f, 45.0f, &font);

    if (speed == speedMax && !maxAngle) {
        maxAngle = true;
    } else if (speed <= 0 && maxAngle) {
        speed = 0;
    } else if (speed <= speedMax && maxAngle) {
        speed -= 1;
    } else if(!maxAngle) {
        speed += 1;
    }
    DrawFPS(1, 1);
}

// Title Screen Unload logic
void UnloadTitleScreen(void) {
    // TODO: Unload TITLE screen variables here!
}

// Title Screen should finish?
int FinishTitleScreen(void) {
    return finishScreen;
}
