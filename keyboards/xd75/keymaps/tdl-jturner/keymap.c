/* Copyright 2018 Josh Turner (/u/tdl-jturner)
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
#include "xd75.h"

enum xd75_layers {
  _QWERTY,
  _COLEMAK,
  _LYMD,
  _LYFK,
  _LYMED,
  _LYNUM,
  _LYNAV,
  _LYMOS,
  _LYSYS,
  _LYLT
};

enum xd75_keycodes {
  HELP = SAFE_RANGE,
  KC_BSDEL,
  KC_FBSLH,
  KC_DOTQ,
  KC_CPIPE,
  COLEMAK,
  QWERTY,
  KC_LYDEF
};

//Tap Dance Declarations
enum {
  TD_LOCK_SLEEP,
  TD_ABK,
  TD_BRC,
  TD_CBR,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_LOCK_SLEEP]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_L), KC_SLEP),
  [TD_ABK] = ACTION_TAP_DANCE_DOUBLE(KC_LABK,KC_RABK),
  [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC,KC_RBRC),
  [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR,KC_RCBR)
// Other declarations would go here, separated by commas, if you have them
};

//remaps for pretty layouts
#define ________ KC_TRNS
#define ___XX___ KC_NO

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _QW 0
#define _LW 1
#define _RS 2
#define _FN 3
#define _ENTFN 4
#define _MEDIA 5
#define _MOUSE 6

#define M_BACK 0
#define M_FWRD 1
#define M_PTAB 2
#define M_NTAB 3
#define M_ZOUT 4
#define M_ZOIN 5
#define M_ENTR 6
#define M_SCRN 7
#define M_NSPC 8
#define M_PSPC 9



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 //QWERY - Base Layer
 [_QWERTY] = {
         {KC_GRV ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,________  ,________,________,  KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,KC_MINUS},
         {KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,________  ,________,________,  KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  ,KC_BSDEL}, //Custom shift Codes. Backspace ^ Delete
{LT(_LYMD,KC_ESC),  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,________  ,________,________,  KC_H  ,  KC_J  ,  KC_K  ,  KC_L  ,KC_SCLN ,KC_QUOT },
         {KC_LSPO,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,________  ,________,________,  KC_N  ,  KC_M  ,KC_CPIPE,KC_DOTQ ,KC_FBSLH,KC_RSPC }, // Custom Shift Codes. ,^| .^?  /^|
      { KC_MEH ,KC_LCTL ,KC_LGUI ,KC_LALT ,MO(_LYNUM), KC_SPC ,________  ,________,________, KC_ENT ,MO(_LYNAV),TD(TD_CBR) ,TD(TD_BRC),TD(TD_ABK),TD(TD_LOCK_SLEEP)}

 },

 //_COLEMAK - Colemak Layout - Identical to qwerty layer except for the layout changes
 [_COLEMAK] = {
         {KC_GRV ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,________  ,________,________,  KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,KC_MINUS},
         {KC_TAB ,  KC_Q  ,  KC_W  ,  KC_F  ,  KC_P  ,  KC_G  ,________  ,________,________,  KC_J  ,  KC_L  ,  KC_U  ,  KC_Y  ,KC_SCLN ,KC_BSDEL}, //Custom shift Codes. Backspace ^ Delete
{LT(_LYMD,KC_ESC),  KC_A  ,  KC_R  ,  KC_S  ,  KC_T  ,  KC_D  ,________  ,________,________,  KC_H  ,  KC_N  ,  KC_E  ,  KC_I  ,  KC_O  ,KC_QUOT },
         {KC_LSPO,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,________  ,________,________,  KC_K  ,  KC_M  ,KC_CPIPE,KC_DOTQ ,KC_FBSLH,KC_RSPC }, // Custom Shift Codes. ,^| .^?  /^|
     {  KC_MEH ,KC_LCTL ,KC_LGUI ,KC_LALT ,MO(_LYNUM), KC_SPC ,________  ,________,________, KC_ENT ,MO(_LYNAV),TD(TD_CBR) ,TD(TD_BRC),TD(TD_ABK),TD(TD_LOCK_SLEEP)}

 },

 // Decision Layer
 [_LYMD] =
    {
       {________,________  ,________  ,________  ,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
       {________,MO(_LYFK) ,MO(_LYMED),________  ,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,________},
       {________,MO(_LYNUM),MO(_LYNAV),________  ,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
       {________,MO(_LYMOS),MO(_LYSYS),MO(_LYLT) ,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
       {________,________  ,________  ,________  ,________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___}
     },

 //F Keys
 [_LYFK] =
    {
      {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
      {KC_LYDEF,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_F7   ,KC_F8   ,KC_F9   ,KC_F12  ,________},
      {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,___XX___},
      {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_F1   ,KC_F2   ,KC_F3   ,KC_F10  ,___XX___},
      {________,________,________,________,________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___}
    },
//Media Keys
[_LYMED] =
   {
     {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
     {KC_LYDEF,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,KC_VOLU ,___XX___,___XX___,________},
     {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_MPRV ,KC_MUTE ,KC_MNXT ,___XX___,___XX___},
     {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,KC_VOLD ,___XX___,KC_MSTP ,___XX___},
     {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_MPLY ,___XX___,___XX___,___XX___,___XX___}
   },
//Num Keys
[_LYNUM] =
  {
    {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_PEQL ,KC_PSLS ,KC_PAST ,KC_PMNS ,___XX___},
    {KC_LYDEF,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_7    ,KC_8    ,KC_9    ,KC_MINUS,________},
    {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_4    ,KC_5    ,KC_6    ,KC_PPLS ,KC_PSLS },
    {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_1    ,KC_2    ,KC_3    ,KC_PENT ,KC_PAST },
    {________,________,________,________,________,________,________,________,________,________,KC_0    ,KC_0    ,KC_PDOT ,KC_PEQL ,___XX___}
  },
//Navigation Keys
[_LYNAV] =
 {
   {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
   {KC_LYDEF,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_HOME ,KC_UP   ,KC_PGUP ,KC_PSCR ,________},
   {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_LEFT ,KC_F5   ,KC_RIGHT,KC_SLCK ,___XX___},
   {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_END  ,KC_DOWN ,KC_PGDN ,KC_PAUS ,___XX___},
   {________,________,________,________,________,________,________,________,________,________,________,KC_INS  ,KC_DEL  ,___XX___,___XX___}
 },
 //Mouse Keys
 [_LYMOS] =
  {
    {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
    {KC_LYDEF,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,KC_MS_U ,KC_WH_U ,KC_ACL2 ,________},
    {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,KC_MS_L ,KC_ACL0 ,KC_MS_R ,KC_ACL1 ,___XX___},
    {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,KC_MS_D ,KC_WH_D ,KC_BTN2 ,___XX___},
    {________,________,________,________,________,________,________,________,________,________,KC_BTN1 ,KC_BTN3 ,KC_BTN4 ,___XX___,___XX___}
  },
  //Systen Keys
  [_LYSYS] =
   {
     {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
     {KC_LYDEF,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,________},
     {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,QWERTY  ,COLEMAK ,___XX___,RESET   },
     {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
     {________,________,________,________,________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___}
   },

// Light Control
[_LYLT] =
  {
     {________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,___XX___},
     {KC_LYDEF,________,________,________,________,________,___XX___,___XX___,___XX___,RGB_HUD ,RGB_HUI ,RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI },
     {________,________,________,________,________,________,___XX___,___XX___,___XX___,RGB_TOG ,RGB_RMOD,RGB_MOD ,___XX___,___XX___,___XX___},
     {________,________,________,________,________,________,___XX___,___XX___,___XX___,BL_TOGG ,BL_DEC  ,BL_INC  ,BL_BRTG ,___XX___,___XX___},
     {________,________,________,________,________,________,________,________,________,________,___XX___,___XX___,___XX___,___XX___,___XX___}
  },

 [_QW] = { /* QWERTY */
  { KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_INSERT  },
  { KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(_MOUSE, KC_SCLN), LT(_MEDIA, KC_QUOT), LT(_ENTFN, KC_ENT),  LT(_ENTFN, KC_ENT), KC_PGUP  },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN  },
  { KC_LCTL, MO(_FN), KC_LALT, KC_LGUI, MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), LT(_ENTFN, KC_ENT), KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  },
 },

/* LOWERED
 */
 
 [_LW] = { /* LOWERED */
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL  },
  { _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, KC_INS   },
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, ___T___, ___T___, _______  },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, ___T___, ___T___, KC_PGUP, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END  },
 },

/* RAISED
 */
 
 [_RS] = { /* RAISED */
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL  },
  { _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, KC_INS   },
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, ___T___, ___T___, _______  },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, ___T___, ___T___, KC_PGUP, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END  },
 },
 
/* FUNCTION
 */
 
 [_FN] = { /* FUNCTION */
  { RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL  },
  { KC_SLCK, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_PAUS, KC_PSCR  },
  { KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, _______, _______  },
  { RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, BL_TOGG, BL_INC,  BL_DEC,   ___T___, ___T___, KC_PGUP, KC_WH_D  },
  { _______  , _______, AG_SWAP, AG_NORM, _______, KC_BTN1, KC_BTN1, _______, AG_NORM, AG_SWAP, _______, _______, KC_HOME, KC_PGDN, KC_END  },
 },

 [_ENTFN] = { /* Enter FN */
  { _______, _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______, _______  },
  { _______, M(M_PTAB), M(M_NTAB), M(M_PSPC), M(M_NSPC),  _______,  _______,  _______,  _______,  M(M_ZOUT), M(M_ZOIN),  _______,  _______,  _______, _______  },
  { _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______, _______, _______  },
  { _______, M(M_BACK),  M(M_FWRD), _______, _______, _______, _______, _______, _______, _______,  _______,   _______, _______, _______, _______  },
  { _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
 [_MEDIA] = { /* Media */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, KC_VOLU, _______, _______, _______, _______, _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, _______, _______, _______  },
  { _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
 [_MOUSE] = { /* Mouse */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
};

//Define layer colors
#define rgblight_setrgb_user_base()  rgblight_sethsv(325,255,255)
#define rgblight_setrgb_user_LYFK()  rgblight_sethsv_red()
#define rgblight_setrgb_user_LYMED() rgblight_sethsv_blue()
#define rgblight_setrgb_user_LYNUM() rgblight_sethsv_purple()
#define rgblight_setrgb_user_LYNAV() rgblight_sethsv_cyan()
#define rgblight_setrgb_user_LYMOS() rgblight_sethsv_orange()
#define rgblight_setrgb_user_LYSYS() rgblight_sethsv_green()
#define rgblight_setrgb_user_LYLT()  rgblight_sethsv_yellow()
#define rgblight_setrgb_user_LYMD()  rgblight_sethsv_white()

//initialize rgb
void matrix_init_user(void) {
  rgblight_enable();
  rgblight_mode(1);
  rgblight_setrgb_user_base();
}

//Set a color based on the layer
uint32_t layer_state_set_user(uint32_t state) {
  switch(biton32(state)) {
    case _LYFK:
      rgblight_setrgb_user_LYFK();
      break;
    case _LYMED:
      rgblight_setrgb_user_LYMED();
      break;
    case _LYNUM:
      rgblight_setrgb_user_LYNUM();
      break;
    case _LYNAV:
      rgblight_setrgb_user_LYNAV();
      break;
    case _LYMOS:
      rgblight_setrgb_user_LYMOS();
      break;
    case _LYSYS:
      rgblight_setrgb_user_LYSYS();
      break;
    case _LYLT:
      rgblight_setrgb_user_LYLT();
      break;
    case _LYMD:
      rgblight_setrgb_user_LYMD();
      break;
    default:
      rgblight_setrgb_user_base();
      break;
  }
  return state;
}


//Const for shift
const uint8_t shift = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {
    case KC_LYDEF:
      layer_clear();
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case KC_BSDEL:
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
          if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
            unregister_code(KC_LSHIFT);
          }
          else {
            unregister_code(KC_RSHIFT);
          }
          register_code(KC_DEL);
        }
        else {
          register_code(KC_BSPC);
        }
      }
      else {
        unregister_code(KC_DEL);
        unregister_code (KC_BSPC);
      }
      return false;
      break;
    case KC_FBSLH:
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
              unregister_code(KC_LSHIFT);
            }
            else {
              unregister_code(KC_RSHIFT);
            }
          register_code(KC_BSLASH);
        }
        else {
          register_code(KC_SLSH);
        }
      }
      else {
        unregister_code(KC_BSLASH);
        unregister_code (KC_SLSH);
      }
      return false;
      break;
    case KC_DOTQ:
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
          register_code(KC_SLSH); // shifted slash = ?
        }
        else {
          register_code(KC_DOT);
        }
      }
      else {
        unregister_code(KC_SLSH); // shifted slash = ?
        unregister_code (KC_DOT);
      }
      return false;
      break;
    case KC_CPIPE:
      if (record->event.pressed) {
        if (keyboard_report->mods & shift) {
          register_code(KC_BSLS);
        }
        else {
          register_code(KC_COMM);
        }
      }
      else {
        unregister_code(KC_BSLS);
        unregister_code (KC_COMM);
      }
      return false;
      break;
    }
    return true;
};
