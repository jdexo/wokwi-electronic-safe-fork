#include "Arduino.h"
#include "RateLimiter.h"

long RateLimiterAttempts[RATE_LIMITER_LIMIT];
int RateLimiterAttemptsIndex = -1;

long rateLimiterCheckAndUpdateAttempts(long* currentMillis) {
    
    if (RateLimiterAttemptsIndex < (RATE_LIMITER_LIMIT - 1) ) {
        return 0;
    }
    
    if (*currentMillis < RATE_LIMITER_WINDOW + RateLimiterAttempts[0]) {
        return RATE_LIMITER_WINDOW + RateLimiterAttempts[0] - *currentMillis;
    }
    
    //rateLimiterCheck50DaysIssue(currentMillis);
    return 0;
}

void rateLimiterShiftAttempts(long* currentMillis) {
    if(RateLimiterAttemptsIndex == -1){
        return;
    }
    byte numShifts = 0;
    for (byte i = 0; i <= RateLimiterAttemptsIndex; i++){
        if(*currentMillis - RateLimiterAttempts[i] < RATE_LIMITER_WINDOW) {
            break;
        }
        numShifts++;
    }
    if (numShifts > 0) {
        for (byte i = 0; i < RATE_LIMITER_LIMIT - numShifts; i++){
            RateLimiterAttempts[i] = RateLimiterAttempts[i + numShifts];
        }
        RateLimiterAttemptsIndex -= numShifts;
    }
}

void rateLimiterIsNotAccepted() {
    RateLimiterAttempts[++RateLimiterAttemptsIndex] = millis();
}


