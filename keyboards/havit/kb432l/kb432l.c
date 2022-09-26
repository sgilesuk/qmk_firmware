/* Copyright 2021 IsaacDynamo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "kb432l.h"
#include "config.h"

// Manage Windows and Mac LEDs
// - Show status of mode switch
// - Turn LEDs off durring USB suspend
static bool mode_leds_show = true;

static void mode_leds_update(void) {

}


void keyboard_pre_init_kb(void) {
    // Setup Win & Mac LED Pins as output


    // Set status leds pins

    keyboard_pre_init_user();
}

void suspend_power_down_kb(void) {
    // Turn leds off
    mode_leds_show = false;
    mode_leds_update();

    // Suspend backlight
    led_matrix_set_suspend_state(true);

    suspend_power_down_user();
}

void led_matrix_indicators_kb(void) {
if (host_keyboard_led_state().num_lock) {
        led_matrix_set_value(106, 255);
} else {
        led_matrix_set_value(106, 0);
}
if (host_keyboard_led_state().caps_lock) {
        led_matrix_set_value(107, 255);
} else {
        led_matrix_set_value(107, 0);
}
if (host_keyboard_led_state().scroll_lock) {
        led_matrix_set_value(108, 255);
} else {
        led_matrix_set_value(108, 0);
}
}


#define XX NO_LED

// Mark keys that are black with the default keychron keycaps.
// This is used but the custom rgb matrix effect to create a high contrast mode that only lights up black keys. To make them better readable.
#define B (128 | 4)

/// Force g_led_config into flash, because there is no space in RAM.
/// This should be safe because g_led_config should never be written to.
/// We cannot make g_led_config const, because rgb_matrix.h, exports it as mutable.
led_config_t g_led_config = { {
  {   0,      1,   2,   3,   4,   5,   6,      7,   8,      9,     10,     11,     12,   NO_LED,   13,     14,     15,      106,    107,   108, NO_LED },
  {  16,     17,  18,  19,  20,  21,  22,     23,  24,     25,     26,     27,     28,     29,     30,     31,     32,      33,     34,     35,     36 },
  {  37,     38,  39,  40,  41,  42,  43,     44,  45,     46,     47,     48,     49,     50,     51,     52,     53,      54,     55,     56,     57 },
  {  58,     59,  60,  61,  62,  63,  64,     65,  66,     67,     68,     69,     70,     71, NO_LED, NO_LED, NO_LED,      72,     73,     74, NO_LED },
  {  75,     76,  77,  78,  79,  80,  81,     82,  83,     84,     85,     86, NO_LED,     87, NO_LED,   NO_LED,   88,       89,     90,     91,    92 },
  {  93,     94,  95, NO_LED, 96, NO_LED, 97,  98,  99,  100,  NO_LED, NO_LED, NO_LED, NO_LED,   NO_LED, NO_LED,  101,    102,    103,      104,    105 }
}, {
    { 0 *12, 0  }, { 2 *12, 0  }, { 3 *12, 0  }, { 4 *12, 0  }, { 5 *12,  0  }, { 6 *12,  0  }, { 7 *12,  0  }, { 8 *12, 0  }, { 9 *12,  0  }, { 10*12, 0  }, { 11*12, 0  }, { 12*12, 0  }, { 14*12, 0  },                { 15*12, 0  }, { 16*12, 0  }, { 17*12, 0  },
    { 1 *12, 11 }, { 2 *12, 11 }, { 3 *12, 11 }, { 4 *12, 11 }, { 5 *12,  11 }, { 6 *12,  11 }, { 7 *12,  11 }, { 8 *12, 11 }, { 9 *12,  11 }, { 10*12, 11 }, { 11*12, 11 }, { 12*12, 11 }, { 13*12, 11 }, { 14*12, 11 }, { 15*12, 11 }, { 16*12, 11 }, { 17*12, 11 }, { 18*12, 11 }, { 19*12, 11 }, { 20*12, 11 }, { 21*12, 11 },
    { 1 *12, 22 }, { 2 *12, 22 }, { 3 *12, 22 }, { 4 *12, 22 }, { 5 *12,  22 }, { 6 *12,  22 }, { 7 *12,  22 }, { 8 *12, 22 }, { 9 *12,  22 }, { 10*12, 22 }, { 11*12, 22 }, { 12*12, 22 }, { 13*12, 22 }, { 14*12, 22 }, { 15*12, 22 }, { 16*12, 22 }, { 17*12, 22 }, { 18*12, 22 }, { 19*12, 22 }, { 20*12, 22 }, { 21*12, 22 },
    { 1 *12, 33 }, { 2 *12, 33 }, { 3 *12, 33 }, { 4 *12, 33 }, { 5 *12,  33 }, { 6 *12,  33 }, { 7 *12,  33 }, { 8 *12, 33 }, { 9 *12,  33 }, { 10*12, 33 }, { 11*12, 33 }, { 12*12, 33 }, { 13*12, 33 }, { 14*12, 33 },                                              { 18*12, 33 }, { 19*12, 33 }, { 20*12, 33 },
    { 1 *12, 44 }, { 2 *12, 44 }, { 3 *12, 44 }, { 4 *12, 44 }, { 5 *12,  44 }, { 6 *12,  44 }, { 7 *12,  44 }, { 8 *12, 44 }, { 9 *12,  44 }, { 10*12, 44 }, { 11*12, 44 }, { 12*12, 44 },                { 14*12, 44 },                { 16*12, 44 },                { 18*12, 44 }, { 19*12, 44 }, { 20*12, 44 }, { 21*12, 44 },
    { 1 *12, 64 }, { 2 *12, 64 }, { 3 *12, 64 }, { 6 *12, 64 }, { 11 *12, 64 }, { 12 *12, 64 }, { 13 *12, 64 },                { 14 *12, 64 },                                                                            { 15*12, 64 }, { 16*12, 64 }, { 17*12, 64 },                { 19*12, 64 }, { 20*12, 64 },
}, {
   4,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,          4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,    4,    4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4,    4,                4, 4, 4,    4, 4,
} };
