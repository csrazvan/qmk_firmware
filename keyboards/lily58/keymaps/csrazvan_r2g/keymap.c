 /* Copyright 2020 Razvan Alecsandrescu
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
#include <stdio.h>
#include "quantum.h"

//extern uint8_t is_master;
enum layer_number {
  _QWERTY = 0,
  _POE,
  _SGN,
  _NAV,
  _DUO,
};

#define NAV MO(_NAV)
#define SGN MO(_SGN)
#define POE DF(_POE)
#define QWERTY DF(_QWERTY)
#define ALFRED LALT(KC_SPC)
#define SWITCH LGUI(KC_GRAVE)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |RShift|
 * |------+------+------+------+------+------|SWITCH |    | ALFRED|------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Del  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LGUI  | Alt  | SGN  | / Space /       \Enter \  | NAV  | BSPC | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, SWITCH,  ALFRED,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL,
                      KC_LGUI, KC_LALT,SGN, KC_SPC,   KC_ENT,   NAV, KC_BSPC,  KC_RGUI
),
/* POE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |RShift|
 * |------+------+------+------+------+------|  ESC  |    |QWERTY |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Del  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LGUI  | Alt  | SGN  | / Space /       \Enter \  |NAV   | BSPC | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

 [_POE] = LAYOUT(
  KC_GRAVE, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_ESC,  QWERTY,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL,
                          _______, _______, _______, _______, _______, _______, _______, _______
  ),
/* SGN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   |  |   [  |   ]  |   ~  |                    |      |   "  |   -  |   +  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   \  |   (  |   )  |   `  |-------.    ,-------|      |   '  |   _  |   =  |   :  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |   {  |   }  |      |-------|    |-------|      |      |   <  |   >  |   ?  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |SGN | LGUI | Alt  |   / Space /       \Enter \  |BackSP| RGUI |  NAV |
 *                   |    |      |      | /       /          \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_SGN] = LAYOUT(
  _______, KC_EXLM, KC_AT,     KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR,  KC_ASTR,       KC_LPRN,  KC_RPRN, _______,
  _______, _______, KC_PIPE,   KC_LBRC, KC_RBRC, KC_TILDE,                   _______, KC_DQUO,  KC_MINUS,      KC_PLUS,  _______, _______,
  _______, _______, KC_BSLS,   KC_LPRN, KC_RPRN, KC_GRAVE,                   _______, KC_QUOTE, KC_UNDERSCORE, KC_EQUAL, KC_COLN, _______,
  _______, _______, _______,   KC_LCBR, KC_RCBR, _______, _______, _______,  _______, _______,  KC_LABK,       KC_RABK,  KC_QUES, _______,
                               _______, _______, _______, _______, _______,  _______, _______,  _______
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      | Home | PgUp |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBTOG|RGBHUI|RGBSAI|RGBVAI|      |      |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |RGBMOD|RGBHUD|RGBSAD|RGBVAD|      |      |-------|    |-------|      |      | End  |PgDwn |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |SGN | LGUI | Alt  |   /Space  /       \Enter \  |BackSP| RGUI |NAV |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

[_NAV] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______,                     _______, _______, KC_HOME, KC_PGUP,   _______, _______,
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT, XXXXXXX,
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,  _______, _______,  _______, _______, KC_END,  KC_PGDN,   _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

/* DUO
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | BOOT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  UL  |  U   |   UR |      |                    |VOL_UP|      |      |      |      |EE_CLR|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  LS  |   L  |  FS  |   R  |  RS  |-------.    ,-------| MUTE | P/P  | STOP |      |      |      |
 * |------+------+------+------+------+------|  POE  |    | QWERTY|------+------+------+------+------+------|
 * |      |      |  LL  |   D  |  LR  |      |-------|    |-------|VOL_DN| PREV | NEXT |      |      | LOCK |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  SGN | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |  NAV |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_DUO] = LAYOUT(
  XXXXXXX, XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,        XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  XXXXXXX, XXXXXXX,      MEH(KC_LEFT),  LCAG(KC_UP),    MEH(KC_UP),     XXXXXXX,                           KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,
  XXXXXXX, LCA(KC_LEFT), LCAG(KC_LEFT), LCAG(KC_M),     LCAG(KC_RIGHT), LCA(KC_RIGHT),                     KC_MUTE, KC_MPLY, KC_MSTP, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,      MEH(KC_DOWN),  LCAG(KC_DOWN),  MEH(KC_RIGHT),  XXXXXXX,         POE, QWERTY,      KC_VOLD, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, LCTL(LGUI(KC_Q)),
                                                            _______, _______, _______, _______, _______,  _______, _______, _______
  ),
};
#ifdef OLED_ENABLE

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
      case _QWERTY:
        oled_write_ln_P(PSTR("DEF"), false);
        break;
      case _NAV:
          oled_write_ln_P(PSTR("NAV"), false);
          break;
      case _SGN:
          oled_write_ln_P(PSTR("SGN"), false);
          break;
      case _DUO:
          oled_write_ln_P(PSTR("DUO"), false);
          break;
      case _POE:
          oled_write_ln_P(PSTR("POE"), false);
          break;
      default:
          oled_write_ln_P(PSTR("UNDEF!"), false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM mb_logo[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f,
0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff,
0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0x83, 0x83, 0x83,
0x83, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0xff, 0xff, 0x82, 0x82, 0x82, 0x82,
0x82, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff, 0x83, 0x83, 0x83, 0x83, 0x83, 0xff, 0xff,
0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0xfc, 0xfc,
0x9c, 0x9c, 0xfc, 0xfc, 0xf8, 0xf8, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x78, 0x7c, 0x3c,
0x9c, 0xfc, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0x3c, 0x3c,
0x9c, 0xbc, 0xfc, 0xb8, 0xb8, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41,
0x41, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0x41, 0x41, 0x41, 0x41, 0x41, 0xff, 0xff,
0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f,
0x03, 0x07, 0x0f, 0x3f, 0x3f, 0x3e, 0x38, 0x20, 0x00, 0x00, 0x00, 0x00, 0x38, 0x3c, 0x3e, 0x3f,
0x3f, 0x3f, 0x3b, 0x39, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f, 0x3f, 0x3c, 0x38,
0x3b, 0x3b, 0x3f, 0x1f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0,
0xf0, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff,
0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
    oled_write_raw_P(mb_logo, sizeof(mb_logo));
    //oled_set_cursor(oled_max_chars()/2,oled_max_lines()/2);
    //oled_write_P(PSTR("R2G"), false);
}
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

char key_name = ' ';
uint16_t last_keycode;
uint8_t last_row;
uint8_t last_col;

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    key_name = ' ';
    last_keycode = keycode;
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { last_keycode = keycode & 0xFF; }
    if (keycode < 60) {
      key_name = code_to_name[keycode];
    }
    last_row = record->event.key.row;
    last_col = record->event.key.col;
}

const char *depad_str_r2g(const char *depad_str, char depad_char) {
    while (*depad_str == depad_char) ++depad_str;
    return depad_str;
}

void oled_render_keylog(void) {
    //oled_write(keylog_str, false);
    const char *last_row_str = get_u8_str(last_row, ' ');
    oled_write(depad_str_r2g(last_row_str, ' '), false);
    oled_write_P(PSTR("x"), false);
    const char *last_col_str = get_u8_str(last_col, ' ');
    oled_write(depad_str_r2g(last_col_str, ' '), false);
    oled_write_P(PSTR(", k"), false);
    const char *last_keycode_str = get_u16_str(last_keycode, ' ');
    oled_write(depad_str_r2g(last_keycode_str, ' '), false);
    oled_write_P(PSTR(":"), false);
    oled_write_char(key_name, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}


#endif // OLED_ENABLE

layer_state_t layer_state_set_user(layer_state_t state){
  return update_tri_layer_state(state,  _SGN, _NAV,_DUO);
}
