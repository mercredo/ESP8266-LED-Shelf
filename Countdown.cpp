#include "Countdown.h"
#include "Config.h"

int32_t countdownSecondsLeft = -1;

void startCountdown(int seconds) {
  if (countdownSecondsLeft > -1) return; // skip on active
  if (seconds < 0) return;

  // Serial.printf("Starting countdown with %d seconds", seconds);

  countdownSecondsLeft = seconds;

  Serial.printf("\rStarting countdown with %d seconds", countdownSecondsLeft);

  delay(1000);
  
  while (countdownSecondsLeft > -1) {
    Serial.printf("\rCountdown - Time remaining: %d seconds", countdownSecondsLeft);
    delay(1000);
    countdownSecondsLeft--;
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