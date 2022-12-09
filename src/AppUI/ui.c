// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void Up_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_StartupScreen(lv_event_t * e);
lv_obj_t * ui_StartupScreen;
lv_obj_t * ui_Logo;
lv_obj_t * ui_StartupLabel;
lv_obj_t * ui_StartupSpinner;
lv_obj_t * ui_Screen;
lv_obj_t * ui_Temperature_Arc_Group;
void ui_event_TemperatureArc(lv_event_t * e);
lv_obj_t * ui_TemperatureArc;
lv_obj_t * ui_DisplayContainer;
lv_obj_t * ui_TemperatureDisplay;
lv_obj_t * ui_CurrentTemperature;
lv_obj_t * ui_CurrentHumidity;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void Up_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, -30, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 100);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_1, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, true);
    lv_anim_start(&PropertyAnimation_1);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_StartupScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        Up_Animation(ui_Logo, 100);
        Up_Animation(ui_StartupLabel, 200);
        _ui_screen_change(ui_Screen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 1400);
    }
}
void ui_event_TemperatureArc(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_CurrentTemperature, target, "", "°C");
    }
}

///////////////////// SCREENS ////////////////////
void ui_StartupScreen_screen_init(void)
{
    ui_StartupScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_StartupScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_StartupScreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StartupScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Logo = lv_img_create(ui_StartupScreen);
    lv_img_set_src(ui_Logo, &ui_img_sls_logo_png);
    lv_obj_set_width(ui_Logo, LV_SIZE_CONTENT);   /// 127
    lv_obj_set_height(ui_Logo, LV_SIZE_CONTENT);    /// 127
    lv_obj_set_x(ui_Logo, 0);
    lv_obj_set_y(ui_Logo, 25);
    lv_obj_set_align(ui_Logo, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_Logo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Logo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_StartupLabel = lv_label_create(ui_StartupScreen);
    lv_obj_set_width(ui_StartupLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_StartupLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_StartupLabel, 0);
    lv_obj_set_y(ui_StartupLabel, 45);
    lv_obj_set_align(ui_StartupLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_StartupLabel, "System startup...");
    lv_obj_set_style_text_color(ui_StartupLabel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StartupLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StartupSpinner = lv_spinner_create(ui_StartupScreen, 1000, 90);
    lv_obj_set_width(ui_StartupSpinner, 20);
    lv_obj_set_height(ui_StartupSpinner, 20);
    lv_obj_set_x(ui_StartupSpinner, 0);
    lv_obj_set_y(ui_StartupSpinner, 75);
    lv_obj_set_align(ui_StartupSpinner, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_StartupSpinner, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_arc_width(ui_StartupSpinner, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_width(ui_StartupSpinner, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_StartupSpinner, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_StartupScreen, ui_event_StartupScreen, LV_EVENT_ALL, NULL);

}
void ui_Screen_screen_init(void)
{
    ui_Screen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Temperature_Arc_Group = lv_obj_create(ui_Screen);
    lv_obj_set_width(ui_Temperature_Arc_Group, 240);
    lv_obj_set_height(ui_Temperature_Arc_Group, 240);
    lv_obj_set_align(ui_Temperature_Arc_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Temperature_Arc_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Temperature_Arc_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Temperature_Arc_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Temperature_Arc_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Temperature_Arc_Group, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Temperature_Arc_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TemperatureArc = lv_arc_create(ui_Temperature_Arc_Group);
    lv_obj_set_width(ui_TemperatureArc, 240);
    lv_obj_set_height(ui_TemperatureArc, 240);
    lv_obj_set_align(ui_TemperatureArc, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_TemperatureArc, 0, 40);
    lv_arc_set_value(ui_TemperatureArc, 25);
    lv_obj_set_style_radius(ui_TemperatureArc, 280, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TemperatureArc, lv_color_hex(0x1E232D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TemperatureArc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_TemperatureArc, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_TemperatureArc, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_TemperatureArc, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_TemperatureArc, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_TemperatureArc, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_TemperatureArc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_TemperatureArc, 15, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_TemperatureArc, lv_color_hex(0x36B9F6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_TemperatureArc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_TemperatureArc, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_TemperatureArc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TemperatureArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_DisplayContainer = lv_obj_create(ui_Temperature_Arc_Group);
    lv_obj_set_width(ui_DisplayContainer, 175);
    lv_obj_set_height(ui_DisplayContainer, 175);
    lv_obj_set_align(ui_DisplayContainer, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_DisplayContainer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DisplayContainer, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DisplayContainer, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DisplayContainer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_DisplayContainer, lv_color_hex(0x3C414B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_DisplayContainer, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_DisplayContainer, lv_color_hex(0x2D323C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_DisplayContainer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DisplayContainer, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_DisplayContainer, lv_color_hex(0x050A0F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_DisplayContainer, 200, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TemperatureDisplay = lv_obj_create(ui_DisplayContainer);
    lv_obj_set_width(ui_TemperatureDisplay, 120);
    lv_obj_set_height(ui_TemperatureDisplay, 120);
    lv_obj_set_align(ui_TemperatureDisplay, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_TemperatureDisplay, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TemperatureDisplay, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TemperatureDisplay, lv_color_hex(0x0C191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TemperatureDisplay, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_TemperatureDisplay, lv_color_hex(0x191C26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_TemperatureDisplay, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_TemperatureDisplay, lv_color_hex(0x5A646E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_TemperatureDisplay, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CurrentTemperature = lv_label_create(ui_TemperatureDisplay);
    lv_obj_set_width(ui_CurrentTemperature, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_CurrentTemperature, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_CurrentTemperature, 0);
    lv_obj_set_y(ui_CurrentTemperature, 15);
    lv_obj_set_align(ui_CurrentTemperature, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_CurrentTemperature, "25°C");
    lv_obj_set_style_text_color(ui_CurrentTemperature, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CurrentTemperature, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CurrentTemperature, &ui_font_Number, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CurrentHumidity = lv_label_create(ui_TemperatureDisplay);
    lv_obj_set_width(ui_CurrentHumidity, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_CurrentHumidity, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_CurrentHumidity, 0);
    lv_obj_set_y(ui_CurrentHumidity, -15);
    lv_obj_set_align(ui_CurrentHumidity, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_CurrentHumidity, "30%RH");
    lv_obj_set_style_text_color(ui_CurrentHumidity, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CurrentHumidity, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CurrentHumidity, &ui_font_Number, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_TemperatureArc, ui_event_TemperatureArc, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_StartupScreen_screen_init();
    ui_Screen_screen_init();
    lv_disp_load_scr(ui_StartupScreen);
}
