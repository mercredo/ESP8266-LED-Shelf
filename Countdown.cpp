#include "Countdown.h"
#include "Config.h"

int32_t countdownSecondsLeft = -1;

void startCountdown(int seconds) {
  if (countdownSecondsLeft > -1) return; // skip on active
  if (seconds < 0) return;

  Serial.printf("\nCountdown starting with %d seconds", seconds);

  countdownSecondsLeft = seconds;
  
  /**
   * countdown counts down to -1, but is inactive when it reaches 0
   */
  long previousMillis = 0;
  while(countdownSecondsLeft > -1) {
    if (millis() - previousMillis > 1000)
    {
      previousMillis = millis();

      Serial.printf("\nCountdown %d seconds left", countdownSecondsLeft);

      countdownSecondsLeft--;
    }
  }

  Serial.printf("\nCountdown finished");
}

void stopCountdown() {
  countdownSecondsLeft = -1;
}

void finishCountdown() {
  
}

boolean isCountdownActive() {
  return (countdownSecondsLeft > 0) && (countdownSecondsLeft < 1200);
}