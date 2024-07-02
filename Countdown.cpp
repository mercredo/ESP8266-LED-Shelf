#include "Countdown.h"
#include "Config.h"

int32_t countdownSecondsLeft = -1;
int32_t countdownBuffer = -1;

void startCountdown(int seconds) {
  if (countdownSecondsLeft > -1) return; // skip on active
  if (seconds < 0) return;

  countdownSecondsLeft = seconds;
  countdownBuffer = seconds * FRAMES_PER_SECOND;

  Serial.printf("\rStarting countdown with %d seconds", countdownSecondsLeft);

  while(countdownBuffer > 0) {
    countdownBuffer--;

    if ((countdownBuffer % FRAMES_PER_SECOND) == 0) {
      countdownSecondsLeft--;
      Serial.printf("\rCountdown - Time remaining: %d seconds", countdownSecondsLeft);
    }
  }

  Serial.printf("\rCountdown stopped");
}

void stopCountdown() {
  countdownSecondsLeft = -1;
}

void finishCountdown() {
  
}

boolean isCountdownActive() {
  return (countdownSecondsLeft > 0) && (countdownSecondsLeft < 1200);
}