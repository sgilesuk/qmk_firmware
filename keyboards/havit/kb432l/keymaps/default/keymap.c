/* Copyright 2020 Dimitris Mantzouranis <d3xter93@gmail.com>
 * Copyright 2022 Eduardo Fernandes
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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Windows layout
    +-----------------------------------------------------------------------------------------------------------------+
    | ESC |  | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9| F10| F11| F12|  | |PSCR|CORT| BL |                     |
    +--------------------------------------------------------------------------+ +--------------+ +-------------------+
    |  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP | |INS |HOME|PGUP| |NLCK| P/ | P* | P- |
    +--------------------------------------------------------------------------+ +--------------+ +-------------------+
    |  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | |DEL |END |PGDN| | P7 | P8 | P9 |    |
    +--------------------------------------------------------------------------+ +--------------+ +--------------+ P+ |
    | CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  RETURN  |                  | P4 | P5 | P6 |    |
    +--------------------------------------------------------------------------+      +----+      +-------------------+
    | LSHIFT | \ |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT    |      | UP |      | P1 | P2 | P3 |    |
    +--------------------------------------------------------------------------+ +--------------+ +---------------PRET|
    |LCTRL| LGUI| LALT |            SPACE            | RALT| RGUI | FN | RCTRL | |LFT |DWN |RGT | |   P0    | .  |    |
    +-----------------------------------------------------------------------------------------------------------------+
    */

    /*  Row:        0           1           2           3        4           5        6        7           8           9           10          11          12          13          14          15          16          17          18          19          20     */
    [_BASE] = { {   KC_ESC,     KC_F1,      KC_F2,      KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_NO,      KC_NO,      KC_NO,      KC_NO   },
                {   KC_GRV,     KC_1,       KC_2,       KC_3,    KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_INS,     KC_HOME,    KC_PGUP,    KC_NLCK,    KC_PSLS,    KC_PAST,    KC_PMNS },
                {   KC_TAB,     KC_Q,       KC_W,       KC_E,    KC_R,       KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DEL,     KC_END,     KC_PGDN,    KC_P7,      KC_P8,      KC_P9,      KC_PPLS },
                {   KC_CAPS,    KC_A,       KC_S,       KC_D,    KC_F,       KC_G,    KC_H,    KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_NUHS,    KC_ENT,     KC_NO,      KC_NO,      KC_NO,      KC_P4,      KC_P5,      KC_P6,      KC_NO   },
                {   KC_LSFT,    KC_NUBS,    KC_Z,       KC_X,    KC_C,       KC_V,    KC_B,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NO,      KC_RSFT,    KC_NO,      KC_NO,      KC_UP,      KC_P1,      KC_P2,      KC_P3,      KC_PENT },
                {   KC_LCTL,    KC_LGUI,    KC_LALT,    KC_NO,   KC_SPC,     KC_NO,   KC_RALT,    MO(_FN), KC_APP,     KC_RCTL,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_P0,      KC_PDOT,}
              },
    [_FN]   = { {   RESET,      KC_MSTP,    KC_MPRV,    KC_MPLY, KC_MNXT,    KC_MYCM, KC_WHOM, KC_MAIL,    KC_CALC,    KC_MSEL,    KC_VOLD,    KC_VOLU,    KC_MUTE,    _______,    _______,    _______,   _______,    _______,    _______,    _______,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    BL_DEC,     BL_INC,     _______,    BL_STEP,    BL_STEP,   BL_STEP,    _______,    _______,    _______,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    BL_STEP,    BL_STEP,   BL_TOGG,    _______,    _______,    _______,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   BL_INC,     _______,    _______,    _______,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   BL_STEP,    BL_DEC,    BL_STEP,    _______,    _______ }
             }
};
