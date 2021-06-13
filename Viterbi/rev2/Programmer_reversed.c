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
    KC_ESC  , KC_1     , KC_2    , KC_3   , KC_4  , KC_5   , KC_6    ,    KC_BSPC, KC_EQL , KC_MINS, KC_0   , KC_9   , KC_8  , KC_7   , 
    KC_GRAVE, KC_QUOTE , KC_COMMA, KC_DOT , KC_P  , KC_Y   , KC_LBRC ,    KC_BSLS, KC_L   , KC_R   , KC_C   , KC_G   , KC_F  , KC_RBRC, 
    KC_TAB  , KC_A     , KC_O    , KC_E   , KC_U  , KC_I   , KC_HOME ,    KC_ENT , KC_S   , KC_N   , KC_T   , KC_H   , KC_D  , KC_END ,
    KC_LSFT , KC_SCOLON, KC_Q    , KC_J   , KC_K  , KC_X   , KC_LPRN ,    _______, KC_Z   , KC_V   , KC_W   , KC_M   , KC_B  , KC_RPRN, 
    KC_LCTRL, KC_LGUI  , KC_LALT , MO(_FN), KC_DEL, KC_COPY, KC_PASTE,    CLL    , KC_PGDN, KC_PGUP, _______, MO(_FN), KC_SPC, KC_SLSH
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
    KC_ESC  , KC_1   , KC_2    , KC_3   , KC_4  , KC_5    , KC_6   ,     KC_BSPC, KC_EQL   , KC_MINS, KC_0    , KC_9   , KC_8  , KC_7   , 
    KC_GRAVE, KC_Q   , KC_W    , KC_E   , KC_R  , KC_T    , KC_LCBR,     KC_BSLS, KC_P     , KC_O   , KC_I    , KC_U   , KC_Y  , KC_RBRC, 
    KC_TAB  , KC_A   , KC_S    , KC_D   , KC_F  , KC_G    , KC_HOME,     KC_ENT , KC_SCOLON, KC_L   , KC_K    , KC_J   , KC_H  , KC_END ,
    KC_LSFT , KC_Z   , KC_X    , KC_C   , KC_V  , KC_B    , KC_LPRN,     _______, KC_QUOTE , KC_DOT , KC_COMMA, KC_M   , KC_N  , KC_RPRN, 
    KC_LCTRL, KC_LGUI, KC_LALT , MO(_FN), KC_DEL, KC_PASTE, KC_COPY,     CLL    , KC_PGDN  , KC_PGUP, _______ , MO(_FN), KC_SPC, KC_SLSH
  ),

/* FN
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |
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
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     KC_F7      , KC_F8   , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
    _______, _______, _______, _______, _______, _______, _______,     _______    , _______ , _______, _______, _______, _______, _______,
    _______, KC_VOLD, KC_MPLY, KC_MNXT, KC_VOLU, KC_MUTE, _______,     _______    , KC_RIGHT, KC_UP  , KC_DOWN, KC_LEFT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     DF(_QWERTY), _______ , _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     DF(_DVORAK), _______ , _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
