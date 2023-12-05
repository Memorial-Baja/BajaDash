#include "raylib.h"
#include "rlgl.h"
#include "screens.h"
#include <stdio.h> 
#include <math.h>

static int framesCounter = 0;
static int finishScreen = 0;
static float heightOffset = 30.0f;
int rpm = 0;
float rpmMax = 4000.0f;
int speed = 0;
float speedMax = 75.0f;
float temp = 0;
float voltage = 6;
float angle = 225;
bool maxAngle = false;

void calculateSpeedLocations(double centerX, double centerY, double radius, double startAngle, double endAngle) {
	// Convert angles to radians
	startAngle = startAngle * M_PI / 180.0;
	endAngle = endAngle * M_PI / 180.0;

    int initSpeed = 0;

	// Calculate the number of steps
	int numSteps = 10;

	// Calculate the angle increment per step
	double angleIncrement = (endAngle - startAngle) / numSteps;

	// Calculate and print the coordinates
	for (int i = 0; i <= numSteps; i++) {
		double angle = startAngle + i * angleIncrement;
		double x = centerX + radius * cos(angle);
		double y = centerY + radius * sin(angle);

		DrawTextEx(
            font,
            TextFormat("%i", initSpeed),
            (Vector2){ x-(MeasureTextEx(font, TextFormat("%i", initSpeed), 24, 2).x)/2.0f, y },
            24,
            2,
            RAYWHITE
        );
        initSpeed += 5;
	}
}

void calculateRPMLocations(double centerX, double centerY, double radius, double startAngle, double endAngle) {
	// Convert angles to radians
	startAngle = startAngle * M_PI / 180.0;
	endAngle = endAngle * M_PI / 180.0;

    int initRPM = 0;

	// Calculate the number of steps
	int numSteps = 5;

	// Calculate the angle increment per step
	double angleIncrement = (endAngle - startAngle) / numSteps;

	// Calculate and print the coordinates
	for (int i = 0; i <= numSteps; i++) {
		double angle = startAngle + i * angleIncrement;
		double x = centerX + radius * cos(angle);
		double y = centerY + radius * sin(angle);

		DrawTextEx(
            font,
            TextFormat("%i", initRPM),
            (Vector2){ x-(MeasureTextEx(font, TextFormat("%i", initRPM), 24, 2).x)/2.0f, y },
            24,
            2,
            RAYWHITE
        );
        initRPM += 1;
	}
}

void DrawCircularGauge(Vector2 gaugeCenter) {
    float innerRadius = 195.0f;
    float outerRadius = 200.0f;
    float startAngle = -40.0f;
    float endAngle = -320.0f;
    int segments = 180;

    DrawRing(gaugeCenter, innerRadius, outerRadius, startAngle, endAngle, segments, SKYBLUE);
    DrawRing(gaugeCenter, innerRadius-10, outerRadius-10, startAngle, endAngle, segments, WHITE);
    DrawRing(gaugeCenter, innerRadius-100, outerRadius-100, startAngle+22.5, endAngle-22.5, segments, SKYBLUE);
}

void DrawNeedle(Vector2 gaugeCenter) {
    rlPushMatrix();
        rlTranslatef(gaugeCenter.x, gaugeCenter.y, 0);
        rlRotatef(angle, 0, 0, -1);
        DrawRectangle(0, 0, 165, 5, RED);
    rlPopMatrix();
    DrawCircle(gaugeCenter.x, gaugeCenter.y, 95, BLACK);
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
    Vector2 rpmCenter = { (GetScreenWidth() / 4.0f), (GetScreenHeight() / 2.0f) + heightOffset };
    Vector2 speedCenter = { (GetScreenWidth() / 1.35f), (GetScreenHeight() / 2.0f) + heightOffset };

    DrawRectangle(rpmCenter.x, rpmCenter.y-160, speedCenter.x-rpmCenter.x, 320, (Color){102, 191, 255, 155});

    DrawCircle(rpmCenter.x, rpmCenter.y, 210, BLACK);
    DrawNeedle(rpmCenter);
    DrawCircularGauge(rpmCenter);

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
    calculateSpeedLocations(rpmCenter.x, rpmCenter.y-10, 160, -225.0f, 45.0f);
    // calculateSemiCircle(rpmCenter.x, rpmCenter.y-10, 150, 360, 0, 10);

    DrawCircle(speedCenter.x, speedCenter.y, 210, BLACK);
    DrawNeedle(speedCenter);
    DrawCircularGauge(speedCenter);

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

    calculateRPMLocations(speedCenter.x, speedCenter.y-10, 160, -225.0f, 45.0f);

    // Gauge Sweep
    if (angle >= -40.0f && maxAngle == false) {
        // printf("%f \n", angle);
        angle -= 3.5;
    } else {
        maxAngle = true;
    }
    if (angle <= 225 && maxAngle == true) {
        angle += 3.5;
    } 
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
