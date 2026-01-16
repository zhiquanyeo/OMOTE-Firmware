#include <lvgl.h>
#include "applicationInternal/hardware/hardwarePresenter.h"
#include "applicationInternal/gui/guiBase.h"
#include "applicationInternal/gui/guiRegistry.h"
#include "applicationInternal/omote_log.h"
#include "devices/mediaPlayer/device_roku/gui_roku.h"

#include "applicationInternal/commandHandler.h"
#include "devices/mediaPlayer/device_roku/device_rokuMQTT.h"

// LVGL declarations

// Roku Event Handler
static void rokuButton_event_cb(lv_event_t* e) {
    int user_data = *((int*)(&(e->user_data)));

    omote_log_i("rokuButton_event_cb: Event Id: '%d'.\r\n", user_data);

    if (user_data == 1) {
        // Netflix
        executeCommand(ROKU_APP, "NETFLIX");
    }
    else if (user_data == 2) {
        // Disney+
        executeCommand(ROKU_APP, "DISNEY+");
    }
    else if (user_data == 3) {
        // HBO Max
        executeCommand(ROKU_APP, "HBO");
    }
    else if (user_data == 4) {
        // Prime Video
        executeCommand(ROKU_APP, "PRIME");
    }
    else if (user_data == 5) {
        // Youtube
        executeCommand(ROKU_APP, "YOUTUBE");
    }
    else if (user_data == 6) {
        // AppleTV
        executeCommand(ROKU_APP, "APPLETV");
    }
}

void create_tab_content_roku(lv_obj_t* tab) {
    // Add content to the Roku tab
    // Add Roku logo

    // lv_obj_t* rokuImg = lv_img_create(tab);
    // lv_img_set_src(rokuImg, &rokuIcon);
    // lv_obj_align(rokuImg, LV_ALIGN_CENTER, 0, -110);

    // Netflix Button
    lv_obj_t* button = lv_btn_create(tab);
    lv_obj_align(button, LV_ALIGN_TOP_MID, -60, 20);
    lv_obj_set_size(button, 90, 50);
    lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button, lv_color_hex(0xE50914), LV_PART_MAIN);
    lv_obj_add_event_cb(button, rokuButton_event_cb, LV_EVENT_CLICKED, (void*)1);

    lv_obj_t* buttonLabel = lv_label_create(button);
    lv_label_set_text(buttonLabel, "Netflix");
    lv_obj_set_style_text_font(buttonLabel, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_style_text_color(buttonLabel, lv_color_white(), LV_PART_MAIN);
    lv_obj_center(buttonLabel);

    // Disney+ Button
    button = lv_btn_create(tab);
    lv_obj_align(button, LV_ALIGN_TOP_MID, 60, 20);
    lv_obj_set_size(button, 90, 50);
    lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button, lv_color_hex(0x113CCF), LV_PART_MAIN);
    lv_obj_add_event_cb(button, rokuButton_event_cb, LV_EVENT_CLICKED, (void*)2);

    buttonLabel = lv_label_create(button);
    lv_label_set_text(buttonLabel, "Disney+");
    lv_obj_set_style_text_font(buttonLabel, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_style_text_color(buttonLabel, lv_color_white(), LV_PART_MAIN);
    lv_obj_center(buttonLabel);

    // HBO Button
    button = lv_btn_create(tab);
    lv_obj_align(button, LV_ALIGN_TOP_MID, -60, 90);
    lv_obj_set_size(button, 90, 50);
    lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button, lv_color_hex(0x05B2C82), LV_PART_MAIN);
    lv_obj_add_event_cb(button, rokuButton_event_cb, LV_EVENT_CLICKED, (void*)3);

    buttonLabel = lv_label_create(button);
    lv_label_set_text(buttonLabel, "HBO Max");
    lv_obj_set_style_text_font(buttonLabel, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_style_text_color(buttonLabel, lv_color_white(), LV_PART_MAIN);
    lv_obj_center(buttonLabel);

    // Prime Video Button
    button = lv_btn_create(tab);
    lv_obj_align(button, LV_ALIGN_TOP_MID, 60, 90);
    lv_obj_set_size(button, 90, 50);
    lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button, lv_color_hex(0x00A8E1), LV_PART_MAIN);
    lv_obj_add_event_cb(button, rokuButton_event_cb, LV_EVENT_CLICKED, (void*)4);

    buttonLabel = lv_label_create(button);
    lv_label_set_text(buttonLabel, "Prime\nVideo");
    lv_obj_set_style_text_font(buttonLabel, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_style_text_color(buttonLabel, lv_color_white(), LV_PART_MAIN);
    lv_obj_center(buttonLabel);

    // Youtube Button
    button = lv_btn_create(tab);
    lv_obj_align(button, LV_ALIGN_TOP_MID, -60, 160);
    lv_obj_set_size(button, 90, 50);
    lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button, lv_color_hex(0xFF0000), LV_PART_MAIN);
    lv_obj_add_event_cb(button, rokuButton_event_cb, LV_EVENT_CLICKED, (void*)5);

    buttonLabel = lv_label_create(button);
    lv_label_set_text(buttonLabel, "YouTube");
    lv_obj_set_style_text_font(buttonLabel, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_style_text_color(buttonLabel, lv_color_white(), LV_PART_MAIN);
    lv_obj_center(buttonLabel);

    // Apple TV Button
    button = lv_btn_create(tab);
    lv_obj_align(button, LV_ALIGN_TOP_MID, 60, 160);
    lv_obj_set_size(button, 90, 50);
    lv_obj_set_style_radius(button, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button, color_primary, LV_PART_MAIN);
    lv_obj_add_event_cb(button, rokuButton_event_cb, LV_EVENT_CLICKED, (void*)6);

    buttonLabel = lv_label_create(button);
    lv_label_set_text(buttonLabel, "Apple TV+");
    lv_obj_set_style_text_font(buttonLabel, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_style_text_color(buttonLabel, lv_color_white(), LV_PART_MAIN);
    lv_obj_center(buttonLabel);
}

void notify_tab_before_delete_roku(void) {

}

void register_gui_roku(void) {
    register_gui(std::string(tabName_roku), & create_tab_content_roku, & notify_tab_before_delete_roku);
}
