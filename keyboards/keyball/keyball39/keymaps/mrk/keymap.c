/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
#define LAYOUT_right_ball( \
    L00, L01, L02, L03, L04,              R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14,              R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24,              R24, R23, R22, R21, R20, \
    L30, L31, L32, L33, L34, L35,    R35, R34,                R30  \
    ) \
    { \
        {   L00,   L01,   L02,   L03,   L04, KC_NO }, \
        {   L10,   L11,   L12,   L13,   L14, KC_NO }, \
        {   L20,   L21,   L22,   L23,   L24, KC_NO }, \
        {   L30,   L31,   L32,   L33,   L34,   L35 }, \
        {   R00,   R01,   R02,   R03,   R04, KC_NO }, \
        {   R10,   R11,   R12,   R13,   R14, KC_NO }, \
        {   R20,   R21,   R22,   R23,   R24, KC_NO }, \
        {   R30, KC_NO, KC_NO, KC_NO,   R34,   R35 }, \
    }

#define LAYOUT_left_ball( \
    L00, L01, L02, L03, L04,              R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14,              R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24,              R24, R23, R22, R21, R20, \
    L30,                L34, L35,    R35, R34, R33, R32, R31, R30  \
    ) \
    { \
        {   L00,   L01,   L02,   L03,   L04, KC_NO }, \
        {   L10,   L11,   L12,   L13,   L14, KC_NO }, \
        {   L20,   L21,   L22,   L23,   L24, KC_NO }, \
        {   L30, KC_NO, KC_NO, KC_NO,   L34,   L35 }, \
        {   R00,   R01,   R02,   R03,   R04, KC_NO }, \
        {   R10,   R11,   R12,   R13,   R14, KC_NO }, \
        {   R20,   R21,   R22,   R23,   R24, KC_NO }, \
        {   R30,   R31,   R32,   R33,   R34,   R35 }, \
    }

#define LAYOUT_dual_ball( \
    L00, L01, L02, L03, L04,              R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14,              R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24,              R24, R23, R22, R21, R20, \
    L30,                L34, L35,    R35, R34,                R30  \
    ) \
    { \
        {   L00,   L01,   L02,   L03,   L04, KC_NO }, \
        {   L10,   L11,   L12,   L13,   L14, KC_NO }, \
        {   L20,   L21,   L22,   L23,   L24, KC_NO }, \
        {   L30, KC_NO, KC_NO, KC_NO,   L34,   L35 }, \
        {   R00,   R01,   R02,   R03,   R04, KC_NO }, \
        {   R10,   R11,   R12,   R13,   R14, KC_NO }, \
        {   R20,   R21,   R22,   R23,   R24, KC_NO }, \
        {   R30, KC_NO, KC_NO, KC_NO,   R34,   R35 }, \
    }

#define LAYOUT_no_ball( \
    L00, L01, L02, L03, L04,              R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14,              R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24,              R24, R23, R22, R21, R20, \
    L30, L31, L32, L33, L34, L35,    R35, R34, R33, R32, R31, R30  \
    ) \
    { \
        {   L00,   L01,   L02,   L03,   L04, KC_NO }, \
        {   L10,   L11,   L12,   L13,   L14, KC_NO }, \
        {   L20,   L21,   L22,   L23,   L24, KC_NO }, \
        {   L30,   L31,   L32,   L33,   L34,   L35 }, \
        {   R00,   R01,   R02,   R03,   R04, KC_NO }, \
        {   R10,   R11,   R12,   R13,   R14, KC_NO }, \
        {   R20,   R21,   R22,   R23,   R24, KC_NO }, \
        {   R30,   R31,   R32,   R33,   R34,   R35 }, \
    }

// clang-format on

#define LAYOUT LAYOUT_right_ball
#define LAYOUT_universal LAYOUT_no_ball

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    TAP_DANCE_0, KC_W   , KC_E     , KC_R     , LT(7,KC_T),                           KC_Y     , KC_U     , KC_I     , KC_O     , TAP_DANCE_2,
    KC_A     , KC_S     , KC_D     , MOD_TAP(MOD_LSFT,KC_F), KC_G     ,               KC_H   , MOD_TAP(MOD_RSFT,KC_J), KC_K     , KC_L     , LT(3,KC_ENTER),
    MOD_TAP(MOD_LSFT,KC_Z) , KC_X  , KC_C     , KC_V     , LT(4,KC_B) ,              LT(4,KC_N), KC_M     , KC_COMM  , KC_DOT   , MOD_TAP(MOD_LSFT,KC_SLASH),
    KC_LCTL  , KC_LGUI  , KC_LALT  ,LT(6,KC_LNG2),LT(2,KC_TAB),LT(3,KC_LNG1), LT(3,KC_BSPC),LT(2,KC_SPC),_______,_______,_______, TO(1)
  ),

  [1] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , SCRL_TO  , _______  , _______  , 
    _______  , _______  , _______  , _______  , _______  ,                            _______  , KC_BTN1  , MO(3)    , KC_BTN2  , _______  , 
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , TO(0)    , _______  , _______  , 
    _______  , _______  , _______  , _______  , _______  , _______  ,      KC_BSPC  , KC_DEL   , _______  , _______  , _______  , TO(2)
  ),

  [2] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                            KC_6     , KC_7     , KC_8     , KC_9     , KC_0  ,
    KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,        MODS(MOD_LSFT,KC_SEMICOLON)  , KC_BTN1  , KC_UP    , KC_BTN2  , MODS(MOD_LALT,KC_ENTER) ,
    MODS(MOD_LSFT,KC_8) , KC_SLASH , MODS(MOD_LSFT,KC_EQUAL) , KC_MINUS, KC_EQUAL,    KC_HOME  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_END ,
    KC_F2    , _______  , _______  , MODS(MOD_LALT,KC_LEFT   , _______  , MODS(MOD_LALT,KC_RIGHT) , KC_BSPC  , KC_DEL , _______ , _______, _______  , TO(3)
  ),

  [3] = LAYOUT_universal(
    KC_CAPS_LOCK, KC_F2 , KC_F3    , KC_F4    , KC_F5    ,                            KC_F6  , KC_F7  , KC_F8  , KC_F9 , KC_F10 ,
    MODS(MOD_LCTL,KC_A) , MODS(MOD_LGUI,KC_S) , MODS(MOD_LCTL,KC_D) , MODS(MOD_LCTL,KC_F) , _______ ,  KC_BSPC , KC_BTN1 , KC_UP , KC_BTN2 , _______ ,
    MODS(MOD_LCTL,KC_Z) , MODS(MOD_LCTL,KC_X) , MODS(MOD_LCTL,KC_C) , MODS(MOD_LCTL,KC_V) , MODS(MOD_LCTL|MOD_LSFT,KC_V),  _______ , KC_LEFT , KC_DOWN , KC_RIGHT , KC_F12 ,
    KC_F1 , _______  , _______  , MODS(MOD_LCTL|MOD_LALT,KC_DELETE) , _______  , _______  ,      _______  , KC_DEL  , _______  , _______  , _______  , TO(6)
  ),

  [4] = LAYOUT_universal(
    KC_NO    , RGB_TOG  , SCRL_DVI , RGB_HUI  , QK_MAGIC_SWAP_LCTL_LGUI  ,            _______ , _______ , _______ , KC_PRINT_SCREEN , KC_PRINT_SCREEN ,
    KC_KB_VOLUME_UP  , SSNP_VRT, SSNP_FRE , SSNP_HOR  , _______ ,                     CPI_D1K , CPI_D100  , CPI_I100  , CPI_I1K  , _______ ,
    KC_KB_VOLUME_DOWN, KC_NO   , SCRL_DVD , KC_NO     , _______ ,                     _______ , AML_D50   , AML_TO    , AML_I50  , _______ ,
    KC_AUDIO_MUTE  , _______ , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [5] = LAYOUT_universal(
    _______  , ADV3   , ADV2  , ADV1  , ADV0  ,                            ADV0  , ADV1  , ADV2 , ADV3 , _______,
    ADV4     , DEL3   , DEL2  , DEL1  , DEL0  ,                            DEL0  , DEL1  , DEL2 , DEL3  , ADV4,
    DEL4     , BATT   , SEL_USB  , SEL_BLE  , AD_WO_L ,                 AD_WO_L  , SEL_BLE, SEL_USB, BATT , DEL4,
    DEL_ALL  , _______  , _______  , _______  , KBC_SAVE  , KBC_RST  ,      KBC_RST  , KBC_SAVE  , _______  , _______  , _______  , DEL_ALL
  ),

  [6] = LAYOUT_universal(
    MODS(MOD_LSFT,KC_1)  , MODS(MOD_LSFT,KC_2) , MODS(MOD_LSFT,KC_3)  , MODS(MOD_LSFT,KC_4)  , MODS(MOD_LSFT,KC_5)  ,        MODS(MOD_LSFT,KC_6)  , MODS(MOD_LSFT,KC_7) , MODS(MOD_LSFT,KC_8)  , MODS(MOD_LSFT,KC_9)  , MODS(MOD_LSFT,KC_0)  , 
    KC_MINUS , MODS(MOD_LSFT,KC_MINUS)  , KC_EQUAL  , MODS(MOD_LSFT,KC_EQUAL)  , KC_LEFT_BRACKET,                            KC_RIGHT_BRACKET  , KC_NO , KC_SEMICOLON  , MODS(MOD_LSFT,KC_SEMICOLON)  , MODS(MOD_LSFT,KC_ENTER) ,
    KC_BACKSLASH , MODS(MOD_LSFT,KC_BACKSLASH)  , MODS(MOD_LSFT,KC_GRAVE)  , KC_GRAVE, MODS(MOD_LSFT,KC_LEFT_BRACKET) ,      MODS(MOD_LSFT,KC_RIGHT_BRACKET), KC_NO, KC_QUOTE, MODS(MOD_LSFT,KC_QUOTE)  , MODS(MOD_LSFT,KC_SLASH),
    _______  , _______  , _______  , _______  , _______  , _______  ,      KC_BSPC  , KC_DEL , _______  , _______  , _______  , TO(0)
  ), 

  [7] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  , 
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  , 
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  , 
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t highest_layer = get_highest_layer(state);
    
    // レイヤー3ではスクロールモードを有効化
    if (highest_layer == 3) {
        keyball_set_scroll_mode(true);
    } else {
        keyball_set_scroll_mode(false);
    }

    // Auto enable scroll mode when the highest layer is 3
    // keyball_set_scroll_mode(get_highest_layer(state) == 3);
    #ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
      keyball_handle_auto_mouse_layer_change(state);
    #endif
    
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
