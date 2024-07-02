#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include "Config.h"

extern int32_t countdownSecondsLeft;

void startCountdown(int seconds);
void stopCountdown();
void finishCountdown();
boolean isCountdownActive();

#endif