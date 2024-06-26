#ifndef PWM_INIT_SERVO_CONFIG_H
#define PWM_INIT_SERVO_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

// <<< Use Configuration Wizard in Context Menu >>>

// <h>PWM configuration

// <o SL_PWM_SERVO_FREQUENCY> PWM frequency [Hz]
// <i> Default: 10000
#define SL_PWM_SERVO_FREQUENCY       10000

// <o SL_PWM_SERVO_POLARITY> Polarity
// <PWM_ACTIVE_HIGH=> Active high
// <PWM_ACTIVE_LOW=> Active low
// <i> Default: PWM_ACTIVE_HIGH
#define SL_PWM_SERVO_POLARITY        PWM_ACTIVE_HIGH
// </h> end pwm configuration

// <<< end of configuration section >>>

// <<< sl:start pin_tool >>>

// <timer channel=OUTPUT> SL_PWM_SERVO
// $[TIMER_SL_PWM_SERVO]
//#warning "PWM Driver TIMER peripheral not configured"
#define SL_PWM_SERVO_PERIPHERAL              TIMER0
#define SL_PWM_SERVO_PERIPHERAL_NO           0

#define SL_PWM_SERVO_OUTPUT_CHANNEL          0
#define SL_PWM_SERVO_OUTPUT_PORT             gpioPortB
#define SL_PWM_SERVO_OUTPUT_PIN              4
// [TIMER_SL_PWM_SERVO]$

// <<< sl:end pin_tool >>>

#ifdef __cplusplus
}
#endif

#endif // PWM_INIT_SERVO_CONFIG_H
