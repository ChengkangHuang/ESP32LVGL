// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

void Up_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_StartupScreen(lv_event_t * e);
extern lv_obj_t * ui_StartupScreen;
extern lv_obj_t * ui_Logo;
extern lv_obj_t * ui_StartupLabel;
extern lv_obj_t * ui_StartupSpinner;
extern lv_obj_t * ui_Screen;
extern lv_obj_t * ui_Temperature_Arc_Group;
void ui_event_TemperatureArc(lv_event_t * e);
extern lv_obj_t * ui_TemperatureArc;
extern lv_obj_t * ui_DisplayContainer;
extern lv_obj_t * ui_TemperatureDisplay;
extern lv_obj_t * ui_CurrentTemperature;
extern lv_obj_t * ui_CurrentHumidity;


LV_IMG_DECLARE(ui_img_sls_logo_png);    // assets\sls_logo.png


LV_FONT_DECLARE(ui_font_Number);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
