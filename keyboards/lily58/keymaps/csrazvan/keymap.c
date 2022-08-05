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
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Del  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LGUI  | Alt  | SGN  | Space /       \Enter \  |NAV | BSPC | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL,
                      KC_LGUI, KC_LALT,SGN, KC_SPC,   KC_ENT,   NAV, KC_BSPC,  KC_RGUI
),
/* POE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  ESC  |    |QWERTY |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Del  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LGUI  | Alt  | SGN  | Space /       \Enter \  |NAV | BSPC | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

 [_POE] = LAYOUT(
  KC_GRAVE, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_ESC,  QWERTY,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL,
                              KC_LGUI, KC_LALT,SGN,   KC_SPC,  KC_ENT,   NAV, KC_BSPC,  KC_RGUI
  ),
/* SGN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   |  |   [  |   ]  |   ~  |                    |      |   "  |   _  |   +  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   \  |   (  |   )  |   `  |-------.    ,-------|      |   '  |   _  |   =  |   :  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |   {  |   }  |      |-------|    |-------|      |      |   <  |   >  |   ?  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |SGN | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |NAV |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_SGN] = LAYOUT(
  _______, KC_EXLM, KC_AT,     KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR,  KC_ASTR,       KC_LPRN,  KC_RPRN, _______,
  _______, _______, KC_PIPE,   KC_LBRC, KC_RBRC, KC_TILDE,                   _______, KC_DQUO,  KC_UNDERSCORE, KC_PLUS,  _______, _______,
  _______, _______, KC_BSLASH, KC_LPRN, KC_RPRN, KC_GRAVE,                   _______, KC_QUOTE, KC_MINUS,      KC_EQUAL, KC_COLN, _______,
  _______, _______, _______,   KC_LCBR, KC_RCBR, _______, _______, _______,  _______, _______,  KC_LABK,       KC_RABK,  KC_QUES, _______,
                               _______, _______, _______, _______, _______,  _______, _______,  _______
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      | Home | PgUp |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | End  |PgDwn |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |SGN | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |NAV |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

[_NAV] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______,                     _______, _______, KC_HOME, KC_PGUP,   _______, _______,
  _______, _______, _______, _______, _______, _______,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT, XXXXXXX,
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, KC_END,  KC_PGDOWN, _______, _______,
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
 *                   |SGN | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |NAV |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_DUO] = LAYOUT(
  XXXXXXX, XXXXXXX,      XXXXXXX,       XXXXXXX,        XXXXXXX,        XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  XXXXXXX, XXXXXXX,      MEH(KC_LEFT),  LCAG(KC_UP),    MEH(KC_UP),     XXXXXXX,                           KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,
  XXXXXXX, LCA(KC_LEFT), LCAG(KC_LEFT), LCAG(KC_M),     LCAG(KC_RIGHT), LCA(KC_RIGHT),                     KC_MUTE, KC_MPLY, KC_MSTP, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,      MEH(KC_DOWN),  LCAG(KC_DOWN),  MEH(KC_RIGHT),  XXXXXXX,         POE, QWERTY,      KC_VOLU, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, LCTL(LGUI(KC_Q)),
                                                            _______, _______, _______, _______, _______,  _______, _______, _______
  ),
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _SGN, _DUO);
    return state;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(logo, false);
}
char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}
//new

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("[cs] Layer: "), false);

    switch (get_highest_layer(layer_state | default_layer_state)) {
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

    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);

  } else {
      render_logo();
  }
    return false;
}
#endif // OLED_ENABLE


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
