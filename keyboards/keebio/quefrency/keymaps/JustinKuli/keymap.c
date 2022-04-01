#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _L1 1
#define _L2 2

static bool repeat_is_on = false;
static uint16_t repeat_timer;
static bool repeat_state_r = false;
static bool repeat_state_enter = false;

enum custom_keycodes {
  JK_NA01 = SAFE_RANGE,
  JK_NA02,
  JK_SHRG,
  JK_TBL1,
  JK_TBL2,
  JK_FACE,
  JK_SHDS,
  JK_RREP,
  JK_EREP,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        // Only do macros on key press, not key release.
        return true;
    }

    switch (keycode) {
    case JK_NA01:
        SEND_STRING("Unexpected key 1");
        break;
    case JK_NA02:
        SEND_STRING("Unexpected key 2");
        break;
    case JK_SHRG:
        send_unicode_string("¯\\_(ツ)_/¯");
        break;
    case JK_TBL1:
        send_unicode_string("(ヘ･_･)ヘ┳━┳");
        break;
    case JK_TBL2:
        send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
        break;
    case JK_FACE:
        send_unicode_string("( ͡° ͜ʖ ͡°)");
        break;
    case JK_SHDS:
        send_unicode_string("(つ▀¯▀)つ");
        break;
    case JK_RREP:
        repeat_is_on = !repeat_is_on;
        repeat_state_r = true;
        repeat_state_enter = false;
        if (repeat_is_on) {
            repeat_timer = timer_read();
        } else {
            repeat_timer = 0;
        }
        break;
    case JK_EREP:
        repeat_is_on = !repeat_is_on;
        repeat_state_enter = true;
        repeat_state_r = false;
        if (repeat_is_on) {
            repeat_timer = timer_read();
        } else {
            repeat_timer = 0;
        }
        break;
    }
    return true;
};

enum unicode_names {
    HAPP,
    UPSD,
    SADD,
    THNK,
    ANXS,
    SPRK,
    THMB,
    ZLG0,
    ZLG1,
    ZLG2,
    ZLG3,
    ZLG4,
    ZLG5,
    ZLG6,
    ZLG7,
    ZLG8,
    ZLG9,
    ZLGA,
    ZLGB,
    ZLGC,
    ZLGD,
    ZLGE,
    ZLGF,
};

const uint32_t PROGMEM unicode_map[] = {
    [HAPP] = 0x1F601,  // 😁
    [UPSD] = 0x1F643,  // 🙃
    [SADD] = 0x1F613,  // 😓
    [THNK] = 0x1F914,  // 🤔
    [ANXS] = 0x1F630,  // 😰
    [SPRK] = 0x2728,   // ✨
    [THMB] = 0x1F44D,  // 👍
    [ZLG0] = 0x0303,   // zalgo above
    [ZLG1] = 0x0305,   // zalgo above
    [ZLG2] = 0x0309,   // zalgo above
    [ZLG3] = 0x0306,   // zalgo above
    [ZLG4] = 0x0310,   // zalgo above
    [ZLG5] = 0x031A,   // zalgo above
    [ZLG6] = 0x034A,   // zalgo above
    [ZLG7] = 0x034B,   // zalgo above
    [ZLG8] = 0x0318,   // zalgo below
    [ZLG9] = 0x0321,   // zalgo below
    [ZLGA] = 0x0327,   // zalgo below
    [ZLGB] = 0x0330,   // zalgo below
    [ZLGC] = 0x033C,   // zalgo below
    [ZLGD] = 0x0356,   // zalgo below
    [ZLGE] = 0x0347,   // zalgo below
    [ZLGF] = 0x0362,   // zalgo below
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    TG(_L1), KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  JK_NA01, KC_BSPC, KC_DEL,
    X(HAPP), X(UPSD), KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    X(SADD), X(ANXS), KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
    X(SPRK), X(THMB), KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_MPLY,
    KC_F4,   X(THNK), KC_LCTL, MO(_L1), KC_LALT, KC_LGUI,          KC_SPC,               KC_BSPC, MO(_L1), MO(_L1), KC_HOME, KC_END,           KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_L1] = LAYOUT_65_with_macro(
    TG(_L1), UC_MOD,  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,
    _______, _______, _______, X(ZLG1), X(ZLG2), X(ZLG3), X(ZLG4), X(ZLG5),               JK_RREP, _______, KC_UP,   _______, _______, _______, _______, _______, _______,
    JK_SHDS, JK_FACE, X(ZLG6), X(ZLG7), X(ZLG0), X(ZLG9), X(ZLGA), X(ZLGB),               _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          JK_EREP, _______,
    JK_SHRG, _______, _______,          X(ZLGC), X(ZLGD), X(ZLGE), X(ZLGF), X(ZLG8),      DM_REC1, DM_PLY1, DM_PLY2, DM_REC2, _______,          _______, _______, _______,
    JK_TBL2, JK_TBL1, _______, KC_TRNS, _______, _______,          KC_ENT,                DM_RSTP, KC_TRNS, KC_TRNS, _______, _______,          _______, _______, _______
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index != 0) {
        SEND_STRING("Unexpected encoder update");
        return true; // lets keyboard level code run...
        // which seems reasonable to help debug if something is going wrong?
    }

    if (get_highest_layer(layer_state|default_layer_state) > 0) {
        if (clockwise) {
            tap_code_delay(KC_AUDIO_VOL_UP, 10);
        } else {
            tap_code_delay(KC_AUDIO_VOL_DOWN, 10);
        }
    } else {
        if (clockwise) {
            tap_code_delay(KC_AUDIO_VOL_UP, 10);
        } else {
            tap_code_delay(KC_AUDIO_VOL_DOWN, 10);
        }
    }
    return false; // so this encoder behavior overrides keyboard level code.
}

static int repeat_delay = 100;

void matrix_scan_user(void) {
    if (repeat_is_on) {
        if (timer_elapsed(repeat_timer) > repeat_delay) {
            if (repeat_state_r) {
                tap_code_delay(KC_R, 30);
            } else {
                tap_code_delay(KC_ENT, 30);
            }
            if (!repeat_state_enter) {
                repeat_state_r = !repeat_state_r;
            }
            repeat_timer = timer_read();
        }
    }
}
