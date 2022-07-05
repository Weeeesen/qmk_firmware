/* Copyright 2021 Richard Nunez <antebios1@gmail.com>
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

#define _BASE 0
#define _LAYER1 1
#define _LAYER2 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// 10 ROWS 7 COLUMNS
  [_BASE] = LAYOUT(
  //────COL1─────┰────COL2─────┰──COL3───┰──COL4──────┰──COL5────────┰────COL6─────────┰───COL7──────────┐
  //────LCTRL────┰────LALT─────┰────V────┰─R-SPACE────┰────FN-LEFT───┰────RALT─────────┰───LEFT-ARROW────┐
  KC_LEFT_CTRL,   KC_LEFT_ALT,  KC_V,     KC_BACKSPACE,MO(_LAYER1),   KC_RIGHT_ALT,     KC_LEFT,          //ROW1
  //────LSHFT────╀─────X───────╀────F────╀────M───────╀─────,────────╀────RCTRL────────╀───PG-UP─────────┤
  KC_LEFT_SHIFT,  KC_X,         KC_F,     KC_M,        KC_COMMA,      KC_RIGHT_CTRL,    KC_PAGE_UP,       //ROW2
  //────CAPS─────╀─────S───────╀────R────╀────J───────╀─────.────────╀────FN2-RIGHT────╀───ENTER─────────┤
  KC_CAPSLOCK,    KC_S,         KC_R,     KC_J,        KC_DOT,        TG(_LAYER2),      KC_ENTER,         //ROW3
  //────TAB──────╀─────W───────╀────4────╀────U───────╀─────L────────╀────RSHFT────────╀────]────────────┤
  KC_TAB,         KC_W,         KC_4,     KC_U,        KC_L,          KC_RIGHT_SHIFT,   KC_RIGHT_BRACKET, //ROW4
  //────ESC──────╀─────2───────╀────5────╀────Y───────╀─────O────────╀─────'───────────╀────\────────────┤
  KC_ESCAPE,      KC_2,         KC_5,     KC_Y,        KC_O,          KC_QUOTE,         KC_BACKSLASH,     //ROW5
  //─────1───────╀─────3───────╀────T────╀────6───────╀─────9────────╀─────[───────────╀───PRTSC─────────┤
  KC_1,           KC_3,         KC_T,     KC_6,        KC_9,          KC_LEFT_BRACKET,  KC_PRINT_SCREEN,  //ROW6
  //─────Q───────╀─────E───────╀────G────╀────7───────╀─────0────────╀─────-───────────╀───PG-DOWN───────┤
  KC_Q,           KC_E,         KC_G,     KC_7,        KC_0,          KC_MINUS,         KC_PAGE_DOWN,     //ROW7
  //─────A───────╀─────D───────╀────B────╀────8───────╀─────P────────╀─────=───────────╀───UP-ARROW──────┤
  KC_A,           KC_D,         KC_B,     KC_8,        KC_P,          KC_EQUAL,         KC_UP,            //ROW8
  //─────Z───────╀─────C───────╀────N────╀────I───────╀─────;────────╀────BKSPC────────╀───DOWN-ARROW────┤
  KC_Z,           KC_C,         KC_N,     KC_I,        KC_SEMICOLON,  KC_BACKSPACE,     KC_DOWN,          //ROW9
  //────LGUI─────╀──L-SPACE────╀────H────╀────K───────╀─────/────────╀────DEL──────────╀───RIGHT-ARROW───┤
  KC_LEFT_GUI,    KC_SPACE,     KC_H,     KC_K,        KC_SLASH,      KC_DELETE,        KC_RIGHT          //ROW10
  //─────────────┴─────────────┴─────────┴────────────┴──────────────┴─────────────────┴─────────────────┘
  ),

// 10 ROWS 7 COLUMNS - MO layer
  [_LAYER1] = LAYOUT(
  //────COL1─────┰────COL2─────┰──COL3───┰──COL4─────────┰──COL5──────────────┰────COL6─────────┰───COL7──────────┐
  //────LCTRL────┰────LALT─────┰────V────┰─R-SPACE───────┰────FN-LEFT─────────┰────RALT─────────┰───LEFT-ARROW────┐
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_TRNS,       KC_TRNS,             KC_TRNS,          KC_MEDIA_PREV_TRACK,//ROW1
  //────LSHFT────╀─────X───────╀────F────╀────M──────────╀─────,──────────────╀────RCTRL────────╀───PG-UP─────────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_AUDIO_MUTE,  KC_TRNS,             KC_TRNS,          KC_HOME,          //ROW2
  //────CAPS─────╀─────S───────╀────R────╀────J──────────╀─────.──────────────╀────FN2-RIGHT────╀───ENTER─────────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_TRNS,       KC_TRNS,             KC_TRNS,          KC_TRNS,          //ROW3
  //────TAB──────╀─────W───────╀────4────╀────U──────────╀─────L──────────────╀────RSHFT────────╀────]────────────┤
  KC_TRNS,        KC_TRNS,      KC_F4,    KC_TRNS,       KC_TRNS,             KC_TRNS,          KC_TRNS,          //ROW4
  //────ESC──────╀─────2───────╀────5────╀────Y──────────╀─────O──────────────╀─────'───────────╀────\────────────┤
  KC_GRAVE,       KC_F2,        KC_F5,    KC_TRNS,       KC_TRNS,             KC_TRNS,          KC_TRNS,          //ROW5
  //─────1───────╀─────3───────╀────T────╀────6──────────╀─────9──────────────╀─────[───────────╀───PRTSC─────────┤
  KC_F1,          KC_F3,        KC_TRNS,  KC_F6,         KC_F9,               KC_TRNS,          KC_TRNS,          //ROW6
  //─────Q───────╀─────E───────╀────G────╀────7──────────╀─────0──────────────╀─────-───────────╀───PG-DOWN───────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_F7,         KC_F10,              KC_F11,           KC_END,           //ROW7
  //─────A───────╀─────D───────╀────B────╀────8──────────╀─────P──────────────╀─────=───────────╀───UP-ARROW──────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_F8,         KC_MEDIA_PLAY_PAUSE, KC_F12,           KC_AUDIO_VOL_UP	,  //ROW8
  //─────Z───────╀─────C───────╀────N────╀────I──────────╀─────;──────────────╀────BKSPC────────╀───DOWN-ARROW────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_TRNS,       KC_TRNS,             KC_TRNS,          KC_AUDIO_VOL_DOWN,//ROW9
  //────LGUI─────╀──L-SPACE────╀────H────╀────K──────────╀─────/──────────────╀────DEL──────────╀───RIGHT-ARROW───┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_TRNS,       KC_TRNS,             KC_TRNS,          KC_MEDIA_NEXT_TRACK//ROW10
  //─────────────┴─────────────┴─────────┴───────────────┴────────────────────┴─────────────────┴─────────────────┘
  ),

// 10 ROWS 7 COLUMNS - TG layer
  [_LAYER2] = LAYOUT(
  //────COL1─────┰────COL2─────┰──COL3───┰──COL4──────┰──COL5────────┰────COL6─────────┰───COL7──────────┐
  //────LCTRL────┰────LALT─────┰────V────┰─R-SPACE────┰────FN-LEFT───┰────RALT─────────┰───LEFT-ARROW────┐
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_TRNS,       KC_TRNS,          KC_TRNS,          //ROW1
  //────LSHFT────╀─────X───────╀────F────╀────M───────╀─────,────────╀────RCTRL────────╀───PG-UP─────────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_KP_0,     KC_TRNS,       KC_TRNS,          KC_TRNS,          //ROW2
  //────CAPS─────╀─────S───────╀────R────╀────J───────╀─────.────────╀────FN2-RIGHT────╀───ENTER─────────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_KP_1,     KC_TRNS,       KC_TRNS,          KC_TRNS,          //ROW3
  //────TAB──────╀─────W───────╀────4────╀────U───────╀─────L────────╀────RSHFT────────╀────]────────────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_KP_4,     KC_KP_3,       KC_TRNS,          KC_TRNS,          //ROW4
  //────ESC──────╀─────2───────╀────5────╀────Y───────╀─────O────────╀─────'───────────╀────\────────────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_TRNS,     KC_KP_6,       KC_TRNS,          KC_TRNS,          //ROW5
  //─────1───────╀─────3───────╀────T────╀────6───────╀─────9────────╀─────[───────────╀───PRTSC─────────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_TRNS,     KC_KP_9,       KC_TRNS,          KC_TRNS,          //ROW6
  //─────Q───────╀─────E───────╀────G────╀────7───────╀─────0────────╀─────-───────────╀───PG-DOWN───────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_KP_7,     KC_TRNS,       KC_TRNS,          KC_TRNS,          //ROW7
  //─────A───────╀─────D───────╀────B────╀────8───────╀─────P────────╀─────=───────────╀───UP-ARROW──────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_KP_8,     KC_TRNS,       KC_TRNS,          KC_TRNS,          //ROW8
  //─────Z───────╀─────C───────╀────N────╀────I───────╀─────;────────╀────BKSPC────────╀───DOWN-ARROW────┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_KP_5,     KC_TRNS,       KC_TRNS,          KC_TRNS,          //ROW9
  //────LGUI─────╀──L-SPACE────╀────H────╀────K───────╀─────/────────╀────DEL──────────╀───RIGHT-ARROW───┤
  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_KP_2,     KC_TRNS,       KC_TRNS,          KC_TRNS           //ROW10
  //─────────────┴─────────────┴─────────┴────────────┴──────────────┴─────────────────┴─────────────────┘
  )
};

// initialise onboard LED
void matrix_init_kb(void) {
    led_init_ports();
};
void led_init_ports(void) {
    setPinOutput(B0);
    writePinLow(B0);
};
// if Caps lock is on, turn on the left onboard LED
void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        writePinLow(B0);
    } else {
        writePinHigh(B0);
    }
};

// Runs constantly in the background, in a loop. Source [https://jayliu50.github.io/qmk-cheatsheet/]
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _BASE:
            writePinHigh(D5); 	//toggle LED off
            break;
        case _LAYER2:
            writePinLow(D5);	//toggle LED on
            break;
    }
};