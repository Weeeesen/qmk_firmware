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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layer {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

// Shift key action:
// Shift held down, then use as normal and use Shift Mode of key.
// Shift tapped, then Capitlize next keystroke only.
// Shift double-tapped, then CAPSLOCK
// Shift double-tapped again, CAPS UNLOCKED
// Fillers to make layering more clear
// #define _______ KC_TRNS
// #define XXXXXXX KC_NO
// MO(_LOWER)
// MO(_RAISE)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
// 7 ROWS 10 columns
  [_QWERTY] = LAYOUT(
  KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_CAPSLOCK, KC_TAB,           KC_ESCAPE,    KC_1,            KC_Q,         KC_A,     KC_Z,         KC_LEFT_GUI, 
  KC_LEFT_ALT,  KC_X,          KC_S,        KC_W,             KC_2,         KC_3,            KC_E,         KC_D,     KC_C,         KC_SPACE, 
  KC_V,         KC_F,          KC_R,        KC_4,             KC_4,         KC_T,            KC_G,         KC_B,     KC_N,         KC_H, 
  KC_SPACE,     KC_M,          KC_J,        KC_U,             KC_Y,         KC_6,            KC_7,         KC_8,     KC_I,         KC_K, 
  XXXXXXX,      KC_COMMA,      KC_DOT,      KC_L,             KC_O,         KC_9,            KC_0,         KC_P,     KC_SEMICOLON, XXXXXXX, 
  KC_RIGHT_ALT, KC_RIGHT_CTRL, XXXXXXX,     KC_RIGHT_SHIFT,   KC_GRAVE,     KC_LEFT_BRACKET, KC_MINUS,     KC_EQUAL, KC_BACKSPACE, KC_DELETE, 
  KC_LEFT,      KC_PAGE_UP,    KC_ENTER,    KC_RIGHT_BRACKET, KC_BACKSLASH, KC_PRINT_SCREEN, KC_PAGE_DOWN, KC_UP,    KC_DOWN,      KC_RIGHT
  ),
*/

// 10 ROWS 7 COLUMNS
  [_QWERTY] = LAYOUT(
  //─────────────┰─────────────┰─────────┰──────────┰──────────────┰─────────────────┰─────────────────┐
  KC_LEFT_CTRL,   KC_LEFT_ALT,  KC_V,     KC_SPACE,  XXXXXXX,       KC_RIGHT_ALT,     KC_LEFT,
  //─────────────╀─────────────╀─────────╀──────────╀──────────────╀─────────────────╀─────────────────┤
  KC_LEFT_SHIFT,  KC_X,         KC_F,     KC_M,      KC_COMMA,      KC_RIGHT_CTRL,    KC_PAGE_UP,
  //─────────────╀─────────────╀─────────╀──────────╀──────────────╀─────────────────╀─────────────────┤
  KC_CAPSLOCK,    KC_S,         KC_R,     KC_J,      KC_DOT,        XXXXXXX,          KC_ENTER,
  //─────────────╀─────────────╀─────────╀──────────╀──────────────╀─────────────────╀─────────────────┤
  KC_TAB,         KC_W,         KC_4,     KC_U,      KC_L,          KC_RIGHT_SHIFT,   KC_RIGHT_BRACKET,
  //─────────────╀─────────────╀─────────╀──────────╀──────────────╀─────────────────╀─────────────────┤
  KC_ESCAPE,      KC_2,         KC_5,     KC_Y,      KC_O,          KC_QUOTE,         KC_BACKSLASH,
  //─────────────╀─────────────╀─────────╀──────────╀──────────────╀─────────────────╀─────────────────┤
  KC_1,           KC_3,         KC_T,     KC_6,      KC_9,          KC_LEFT_BRACKET,  KC_PRINT_SCREEN,
  //─────────────╀─────────────╀─────────╀──────────╀──────────────╀─────────────────╀─────────────────┤
  KC_Q,           KC_E,         KC_G,     KC_7,      KC_0,          KC_MINUS,         KC_PAGE_DOWN,
  //─────────────╀─────────────╀─────────╀──────────╀──────────────╀─────────────────╀─────────────────┤
  KC_A,           KC_D,         KC_B,     KC_8,      KC_P,          KC_EQUAL,         KC_UP,    
  //─────────────╀─────────────╀─────────╀──────────╀──────────────╀─────────────────╀─────────────────┤
  KC_Z,           KC_C,         KC_N,     KC_I,      KC_SEMICOLON,  KC_BACKSPACE,     KC_DOWN,     
  //─────────────╀─────────────╀─────────╀──────────╀──────────────╀─────────────────╀─────────────────┤
  KC_LEFT_GUI,    KC_SPACE,     KC_H,     KC_K,      KC_SLASH,      KC_DELETE,        KC_RIGHT
  //─────────────┴─────────────┴─────────┴──────────┴──────────────┴─────────────────┴─────────────────┘
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_qwerty);
            #endif
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
          return false;
          break;
      }
    return true;
};

