This project implements an electronic safe, powered by an Arduino Uno.

The safe has three main components:
An [16x02 LCD Monitor](https://wokwi.com/playground/lcd1602)
and a [Membrane Keypad](https://wokwi.com/playground/keypad) for the
user interface, and a Servo motor that powers the lock mechanism.

The state of the safe (locked/unlocked), as well as the secret code
are stored in the Arduino's [EEPROM](https://wokwi.com/playground/eeprom), so
the code isn't wiped even when the power goes off.

=====Fork======
v1.2 

1. Arbitrary secret code length. Minimum and maximum symbols can be configured. Symbol '#' should be entered at the very end if code length is less then maximum.

v1.1

1. Alpha symbols available for the code
2. Rate Limiter implemented with sliding window policy. Can set the number of attemtps and window range (in milliseconds).
