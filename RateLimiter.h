#ifndef RATELIMITER_H
#define RATELIMITER_H

#define RATE_LIMITER_LIMIT 5
#define RATE_LIMITER_WINDOW 300000

long rateLimiterCheckAndUpdateAttempts(long*);
void rateLimiterShiftAttempts(long*);
void rateLimiterIsNotAccepted();
//void rateLimiterFix50DaysIssue(long);

#endif 