# SmartLock component interface

## Synopsis

```c
// Folder: `components`

// Button – `button.h`
bool getButtonState(void);

// Buzzer – `buzzer.h`.
void buzzerPlay(const uint32_t duration, const uint32_t gap, const uint32_t count);
void buzzerStop(void);

// Clock – `clock.h`.
uint64_t getCurrentTime(void);

// Light – `light.h`.
void lightsOn(void);
void lightsOff(void);

// Lock – `lock.h`.
void setLockState(const bool open);
void getLockState(void);

// OLED – `oled.h`.
extern unsigned char oled_blankBuffer[129];
void oled_sendI2CData(uint8_t *const restrict data, const uint8_t size);
void oled_clearScreen(void);
void oled_clearRow(const int row);
void oled_drawImage(const int startX, const int row, const unsigned char *const restrict image, int width);
void oled_drawTextSingleLine(const int startX, const int startRow, const char *const restrict text);
void oled_drawTextMultiline(const int startX, const int row, const char *const restrict text);
int oled_getTextWidth(const char *const restrict text);

// Proximity sensor – `proximitySensor.h`.
bool getProximitySensorState(void);

// Temperature sensor – `temperatureSensor.h`.
float readObjectTempC(void);
float readAmbientTempC(void);
```

## Button

`#include "components/button.h"`

`bool getButtonState(void)`

Get the pressed state of the onboard button.

## Buzzer

`#include "components/buzzer.h"`

`void buzzerPlay(const uint32_t duration, const uint32_t gap, const uint32_t count)`

Make the buzzer play a series of beeps.

- `uint32_t duration`: The duration of each beep.
- `uint32_t gap`: The gap of silence between beeps.
- `uint32_t count`: The number of beeps to play.

`duration` and `gap` are in `TIMER4` ticks, the number of ticks for one second is saved as `uint32_t buzzerOneSecond`.

`void buzzerStop(void)`

Stop any ongoing sounds on the buzzer.

## Clock

`#include "components/clock.h"`

`uint64_t getCurrentTime(void);`

Get the current steady clock time in ticks, the number of ticks for one second is saved as `uint64_t clockOneSecond`.

## Light

`#include "components/light.h"`

`void lightsOn(void)`

Turn on the lights.

`void lightsOff(void)`

Turn off the lights.

## Lock

`#include "components/lock.h"`

`void setLockState(const bool open)`

Set whether the lock is open or closed.

`bool getLockState(void)`

Get whether the lock is open or closed.

## OLED

`#include "components/oled.h"`

`extern unsigned char oled_blankBuffer[129];`

A blank image data buffer for clearing a section of a screen row. Feed to `oled_sendI2CData`.

`void oled_sendI2CData(uint8_t *const restrict data, const uint8_t size)`

Send raw I2C datagram to the screen.

`void oled_clearScreen(void)`

Clear the screen to blank.

`void oled_clearRow(const int row)`

Clear one row on the screen.

- `row`: The index of the row to clear from 0 to 7.

`void oled_drawImage(const int startX, const int row, const unsigned char *const restrict image, int width)`

Draw an one row high image to a row on the screen.

`void oled_drawTextSingleLine(const int startX, const int startRow, const char *const restrict text)`

Draw text to a specific row on the screen, clipping the text if it goes beyond the right edge.

`void oled_drawTextMultiline(const int startX, const int row, const char *const restrict text)`

Draw text starting from the specified position on the screen, wrapping the text to the beginning of the next row when it
goes to the right edge or clipping it if the bottom row has been reached.

`int oled_getTextWidth(const char *const restrict text)`

Get the width of the specified text if drawn on a single row.

## Proximity sensor

`#include "components/proximitySensor.h"`

`bool getProximitySensorState(void)`

Read the current detection state of the proximity sensor: `true` if there is an object in front of the sensor or
`false` if there isn't.

## Temperature sensor

`#include "components/temperatureSensor.h"`

`float readObjectTempC(void)`

Read the temperature of the object in front of the sensor in degrees Celcius.

`float readAmbientTempC(void)`

Read the temperature of the air around the sensor in degrees Celcius.