static bool lower_pressed = false;
static bool raise_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode){
        case LOWER:
            if(record -> event.pressed){
                lower_pressed =true;

                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);

                if (lower_pressed){
                    register_code(KC_ENT);
                    unregister_code(KC_ENT);
                }
                lower_pressed = false;
            }
            return false;
            break;
        case RAISE:
            if(record -> event.pressed){
                raise_pressed =true;

                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);

                if (raise_pressed){
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                }
                raise_pressed = false;
            }
            return false;
            break;
        
        default:
            if (record -> event.pressed){
                lower_pressed = false;
                raise_pressed = false;
            }
            break;
    }

    return true;
}
