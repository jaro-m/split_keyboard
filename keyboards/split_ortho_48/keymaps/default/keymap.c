/* Copyright 2021 jar0
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _WORKMAN,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY,
  WORKMAN = SAFE_RANGE,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | Alt  |Adjust| GUI  |Lower |Space | |RShift| Raise|   /  | Left | Down |Right |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT(
   KC_ESC,  KC_Q,    KC_W,   KC_E,    KC_R,  KC_T,   KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_TAB,  KC_A,    KC_S,   KC_D,    KC_F,  KC_G,   KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,  KC_B,   KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_UP,   KC_ENT , \
   KC_LCTL, KC_LALT, ADJUST, KC_LGUI, LOWER, KC_SPC, KC_RSFT, RAISE, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT  \
),

/* Workman
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Esc  |   Q  |   D  |   R  |   W  |   B  | |   J  |   F  |   U  |   P  |   ;  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   H  |   T  |   G  | |   Y  |   N  |   E  |   O  |   I  |  '   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   M  |   C  |   V  | |   K  |   L  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | Alt  |Adjust| GUI  |Lower |Space | |RShift| Raise|   /  | Left | Down |Right |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_WORKMAN] = LAYOUT( \
  KC_ESC,  KC_Q,    KC_D,   KC_R,    KC_W,  KC_B,   KC_J,    KC_F,  KC_U,    KC_P,    KC_SCLN, KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,   KC_H,    KC_T,  KC_G,   KC_Y,    KC_N,  KC_E,    KC_O,    KC_I,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,   KC_M,    KC_C,  KC_V,   KC_K,    KC_L,  KC_COMM, KC_DOT,  KC_UP,   KC_ENT , \
  KC_LCTL, KC_LALT, ADJUST, KC_LGUI, LOWER, KC_SPC, KC_RSFT, RAISE, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |ISO ~ |ISO | |KC_APP| PGUP |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      | PSCR |L_BEG |PGDOWN| L_END|
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN,       KC_RPRN,   KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR,       KC_RCBR,   KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_APP,        KC_PGUP,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_PSCR,    LCTL(KC_LEFT), KC_PGDOWN, LCTL(KC_RGHT) \
),

/* Raise
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |ISO # |ISO / |KC_APP| HOME |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |YKUAKE|L_BEG |  END | L_END|
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,          KC_9,          KC_0,    KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,        KC_LBRC,       KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS,       KC_APP,        KC_HOME, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, RCTL(KC_BSLS), LCTL(KC_LEFT), KC_END,  LCTL(KC_RIGHT) \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      | Reset|      |      |      |      | |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm| |AGswap|Workmn|Qwerty|      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, WORKMAN,  QWERTY, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      // when keycode is released
      if (!record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    case WORKMAN:
      // when keycode is released
      if (!record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      break;
  }
  return true;
}
