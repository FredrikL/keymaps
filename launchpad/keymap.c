
#include "launchpad.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Needs Unicode Hex Input enabled in MacOS


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0

#define _FUNC 15

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LANG_SWITCH LCTL(KC_SPC)

enum custom_keycodes {
  PLUS1,
  GRUNT,
  NODE
};
enum unicode_names {
  BANG,
  IRONY,
  SNEK,
};

const uint32_t PROGMEM unicode_map[] = {
  [BANG]  = 0x203D,  // ‽
  [IRONY] = 0x2E2E,  // ⸮
  [SNEK]  = 0x1F40D, // 🐍
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
  * ,-------------.
  * |   1  |  2   |  // UC(0x2764), \
  * |------+------|
  * |   3  |  4   |
  * |------+------|
  * |   5  |  6   |
  * |------+------|
  * | FUNC |  8   |
  * `-------------'
  */
  [_QWERTY] = LAYOUT( \
      LANG_SWITCH,     X(SNEK), \
      GRUNT,  NODE, \
      KC_MEDIA_REWIND,      KC_MEDIA_FAST_FORWARD, \
      MO(_FUNC), PLUS1  \
  ),

  /* Function
  * ,-------------.
  * |   Q  |CALDEL|
  * |------+------|
  * |   A  |TSKMGR|
  * |------+------|
  * |   Z  |  X   |
  * |------+------|
  * |      |  C   |
  * `-------------'
  */
  [_FUNC] = LAYOUT( \
      X(SNEK),    KC_A, \
      KC_A,    KC_A, \
      KC_Z,    KC_X, \
      _______, KC_C \
  )

};

void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case PLUS1:
          SEND_STRING(":+1:");
        break;
      case GRUNT:
        SEND_STRING("grunt" SS_TAP(X_ENTER));
        break;
      case NODE:
        SEND_STRING("node server.js" SS_TAP(X_ENTER));
        break;
    }
  }
  return true;
};
