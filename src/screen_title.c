#include "raylib.h"
#include "screens.h"
#include <stdio.h> 
#include <math.h>

static int framesCounter = 0;
static int finishScreen = 0;
static float heightOffset = 50.0f;
int rpm = 800;
float rpmMax = 4000.0f;
int speed = 10;
float speedMax = 75.0f;
float temp = 0;
float voltage = 6;

void DrawCircularGauge(Vector2 gaugeCenter, Color colour, float gaugeValue, float gaugeMax) {
    float innerRadius = 195.0f;
    float outerRadius = 200.0f;
    float startAngle = -45.0f;
    float endAngle = -315.0f;
    int segments = 180;

    DrawRing(gaugeCenter, innerRadius, outerRadius, startAngle, endAngle, segments, SKYBLUE);
    DrawRing(gaugeCenter, innerRadius-10, outerRadius-10, startAngle, endAngle, segments, WHITE);
    DrawRing(gaugeCenter, innerRadius-100, outerRadius-100, startAngle+22.5, endAngle-22.5, segments, SKYBLUE);
}

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
    DrawTextEx(
        font,
        "KM/H",
        (Vector2){ ((GetScreenWidth())/4.0f)-(MeasureTextEx(font, "KM/H", 24, 2).x)/2.0f, (((GetScreenHeight())/2.0f)+25.0f)+heightOffset },
        24,
        2,
        RAYWHITE
    );
    DrawTextEx(
        font,
        TextFormat("%i", speed),
        (Vector2){ ((GetScreenWidth())/4.0f)-(MeasureTextEx(font, TextFormat("%i", speed), 64, 2).x)/2.0f, (((GetScreenHeight())/2.0f)-30.0f)+heightOffset },
        64,
        2,
        RAYWHITE
    );

    // if (IsKeyPressed(KEY_UP)) {
    //     rpm += 100;
    //     printf ("%i \n", rpm);
    // }
    // if (IsKeyPressed(KEY_DOWN)) {
    //     rpm -= 100;
    // }

    Vector2 rpmCenter = {(GetScreenWidth())/4.0f, (GetScreenHeight()/2.0f)+heightOffset };

    DrawCircularGauge(rpmCenter, RED, rpm, rpmMax);

    // DrawRectangleGradientH((GetScreenWidth()/4.0f) - 200.0f, ((GetScreenHeight()/2.0f) + 20.0f) + heightOffset, 400.0f, 20.0f, BLUE, RED);
    // DrawRectangle(((GetScreenWidth()/4.0f) - 200.0f) + ceil((voltage/12.0f)*400.0f), ((GetScreenHeight()/2.0f) + 20.0f) + heightOffset, 400.0f-(voltage/12.0f)*400.0f, 20.0f, EMPTYGAUGE);
    // DrawTextEx(
    //     font,
    //     TextFormat("%i", rpm),
    //     (Vector2){ ((GetScreenWidth()/4.0f) - 200.0f), ((GetScreenHeight()/2.0f) + 40.0f) + heightOffset },
    //     font.baseSize,
    //     2,
    //     RAYWHITE
    // );

    // RIGHT HAND SIDE ( SPEED )

    // DrawTextEx(
    //     font,
    //     "KM/H",
    //     (Vector2){ (((GetScreenWidth())/1.35f)-(MeasureTextEx(font, "KM/H", font.baseSize, 2).x)/2.0f), (((GetScreenHeight())/2.0f)-25.0f)+heightOffset },
    //     (float)font.baseSize,
    //     2,
    //     RAYWHITE
    // );
    // DrawTextEx(
    //     font,
    //     TextFormat("%i", speed),
    //     (Vector2){ (((GetScreenWidth())/1.35f)-(MeasureTextEx(font, TextFormat("%i", speed), font.baseSize, 2).x)/2.0f), (((GetScreenHeight())/2.0f)-55.0f)+heightOffset },
    //     font.baseSize,
    //     2,
    //     RAYWHITE
    // );

    // if (IsKeyPressed(KEY_W)) {
    //     speed += 1;
    // }
    // if (IsKeyPressed(KEY_S)) {
    //     speed -= 1;
    // }

    Vector2 speedCenter = { ((GetScreenWidth()) / 1.35f), (GetScreenHeight() / 2.0f) + heightOffset };

    DrawCircularGauge(speedCenter, SKYBLUE, speed, speedMax);

    // if (IsKeyPressed(KEY_D)) {
    //     voltage += 1;
    //     printf("%f", voltage);
    // }
    // if (IsKeyPressed(KEY_A)) {
    //     voltage -= 1;
    // }

    // DrawRectangleGradientH((GetScreenWidth()/1.35f) - 200.0f, ((GetScreenHeight()/2.0f) + 20.0f) + heightOffset, 400.0f, 20.0f, RED, GREEN);
    // DrawRectangle(((GetScreenWidth()/1.35f) - 200.0f) + ceil((voltage/12.0f)*400.0f), ((GetScreenHeight()/2.0f) + 20.0f) + heightOffset, 400.0f-(voltage/12.0f)*400.0f, 20.0f, EMPTYGAUGE);

    DrawFPS(10, 10);
}

// Title Screen Unload logic
void UnloadTitleScreen(void) {
    // TODO: Unload TITLE screen variables here!
}

// Title Screen should finish?
int FinishTitleScreen(void) {
    return finishScreen;
}
