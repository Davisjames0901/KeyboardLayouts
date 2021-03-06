#include QMK_KEYBOARD_H

#define _DVORAK 0
#define _QWERTY 1
#define _FN 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  CLL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  Ins |   1  |   2  |   3  |   4  |   5  |   6  |      |   7  |   8  |   9  |   0  |   -  |   =  |  Del |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   `  |   '  |   ,  |   .  |   P  |   Y  |   [  |      |   ]  |   F  |   G  |   C  |   R  |   L  |   \  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  Tab |   A  |   O  |   E  |   U  |   I  | HOME |      |  END |   D  |   H  |   T  |   N  |   S  | Enter|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   (  |      |   )  |   B  |   M  |   W  |   V  |   Z  |  TOG |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Ctrl | Super|  Alt |  FN  |  Del | Copy | Paste|      |   ?  | Space|  FN  | Blank| PgUp | PgDn |  CLL |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_DVORAK] = LAYOUT_ortho_5x14(
    KC_ESC  , KC_1     , KC_2    , KC_3   , KC_4   , KC_5   , KC_6    ,     KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
    KC_GRAVE, KC_QUOTE , KC_COMMA, KC_DOT , KC_P   , KC_R   , KC_LCBR ,     KC_RCBR, KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_BSLS,
    KC_TAB  , KC_A     , KC_O    , KC_E   , KC_U   , KC_I   , KC_HOME ,     KC_END , KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_ENT ,
    KC_LSFT , KC_SCOLON, KC_Q    , KC_J   , KC_K   , KC_X   , KC_LPRN ,     KC_RPRN, KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , _______,
    KC_LCTRL, KC_LGUI  , KC_LALT , MO(_FN), KC_DEL , KC_COPY, KC_PASTE,     KC_SLSH, KC_SPC , MO(_FN), _______, KC_PGUP, KC_PGDN, CLL
  ),

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  Ins |   1  |   2  |   3  |   4  |   5  |   6  |      |   7  |   8  |   9  |   0  |   -  |   =  |  Del |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   E  |   R  |   T  |   [  |      |   ]  |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  | HOME |      |  END |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   (  |      |   )  |   N  |   M  |   ,  |   .  |   '  |  TOG |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Ctrl | Super|  Alt |  FN  |  Del | Copy | Paste|      |   ?  | Space|  FN  | Blank| PgUp | PgDn |  CLL |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
    KC_ESC  , KC_1   , KC_2   , KC_3   , KC_4  , KC_5   , KC_6    ,     KC_7   , KC_8  , KC_9   , KC_0    , KC_MINS, KC_EQL   , KC_BSPC,
    KC_GRAVE, KC_Q   , KC_W   , KC_E   , KC_R  , KC_T   , KC_LCBR ,     KC_RCBR, KC_Y  , KC_U   , KC_I    , KC_O   , KC_P     , KC_BSLS,
    KC_TAB  , KC_A   , KC_S   , KC_D   , KC_F  , KC_G   , KC_HOME ,     KC_END , KC_H  , KC_J   , KC_K    , KC_L   , KC_SCOLON, KC_ENT ,
    KC_LSFT , KC_Z   , KC_X   , KC_C   , KC_V  , KC_B   , KC_LPRN ,     KC_RPRN, KC_N  , KC_M   , KC_COMMA, KC_DOT , KC_QUOTE , _______,
    KC_LCTRL, KC_LGUI, KC_LALT, MO(_FN), KC_DEL, KC_COPY, KC_PASTE,     KC_SLSH, KC_SPC, MO(_FN), _______ , KC_PGUP, KC_PGDN  , CLL
  ),

/* FN
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |  F7  |  F8  |  F9  |  F10 | F11  | F12  |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      | Vol- | Play | Next | Vol+ | Mute |      |      |      |      | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |DVORAK|
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_FN] = LAYOUT_ortho_5x14(
    _______, KC_F1   , KC_F2  , KC_F3  , KC_F4   , KC_F5  , KC_F6  ,     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12  , _______ ,
    _______, _______ , _______, _______, _______ , _______, _______,     _______, _______, _______, _______, _______, _______ , _______ ,
    _______, KC_VOLD , KC_MPLY, KC_MNXT, KC_VOLU , KC_MUTE, _______,     _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______ ,
    _______, _______ , _______, _______, _______ , _______, _______,     _______, _______, _______, _______, _______, _______ , DF(_QWERTY),
    _______, _______ , _______, _______, _______ , _______, _______,     _______, _______, _______, _______, _______, _______ , DF(_DVORAK)
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
