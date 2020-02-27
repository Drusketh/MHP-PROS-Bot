#include "main.h"
#include "gui.h"
#include "display/lvgl.h"

int autonmode = 0;

lv_obj_t * autonBtn;
lv_obj_t * autonBtnLabel;
lv_obj_t * testBtn;
lv_obj_t * testBtnLabel;
lv_obj_t * myLabel;

lv_style_t autonBtnStyleREL;
lv_style_t autonBtnStylePR;

static lv_res_t btn_click_action(lv_obj_t * btn)
{
	uint8_t id = lv_obj_get_free_num(btn);

    if(id == 0)
    {
    	char buffer[100];
 		sprintf(buffer, "button was clicked %i milliseconds from start", pros::millis());
 		//lv_label_set_text(myLabel, buffer);
    }

    return LV_RES_OK;
}

void initialize()
{
	//gui();
	/*Set a non-white background color for the screen to see the alpha is working on the image*/
	static lv_style_t background;
	lv_style_copy(&background, &lv_style_scr);
	background.body.main_color = LV_COLOR_MAKE(0, 0, 100);
	background.body.grad_color = LV_COLOR_MAKE(0, 0, 100);
	lv_obj_set_style(lv_scr_act(), &background);


	lv_style_copy(&autonBtnStyleREL, &lv_style_plain);
    autonBtnStyleREL.body.main_color = LV_COLOR_MAKE(133, 45, 37);
	autonBtnStyleREL.body.grad_color = LV_COLOR_MAKE(133, 45, 37);
    autonBtnStyleREL.body.radius = 0;
    autonBtnStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&autonBtnStylePR, &lv_style_plain);
    autonBtnStylePR.body.main_color = LV_COLOR_MAKE(161, 80, 72);
	autonBtnStylePR.body.grad_color = LV_COLOR_MAKE(161, 80, 72);
    autonBtnStylePR.body.radius = 0;
    autonBtnStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);


    autonBtn = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_free_num(autonBtn, 0);
    lv_btn_set_action(autonBtn, LV_BTN_ACTION_CLICK, btn_click_action);
	lv_btn_set_style(autonBtn, LV_BTN_STATE_INA, &autonBtnStyleREL);
    lv_btn_set_style(autonBtn, LV_BTN_STYLE_REL, &autonBtnStyleREL);
    lv_btn_set_style(autonBtn, LV_BTN_STYLE_PR, &autonBtnStylePR);
    lv_obj_set_size(autonBtn, 200, 105);
    lv_obj_align(autonBtn, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 10);

    autonBtnLabel = lv_label_create(autonBtn, NULL);
    lv_label_set_text(autonBtnLabel, "Autonomous");

	testBtn = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_free_num(testBtn, 0);
    lv_btn_set_action(testBtn, LV_BTN_ACTION_CLICK, btn_click_action);
	lv_btn_set_style(testBtn, LV_BTN_STATE_INA, &autonBtnStyleREL);
    lv_btn_set_style(testBtn, LV_BTN_STYLE_REL, &autonBtnStyleREL);
	lv_btn_set_style(testBtn, LV_BTN_STYLE_PR, &autonBtnStylePR);
    lv_obj_set_size(testBtn, 200, 105);
    lv_obj_align(testBtn, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -10, -10);

    testBtnLabel = lv_label_create(testBtn, NULL);
    lv_label_set_text(testBtnLabel, "Settings");

    // myLabel = lv_label_create(lv_scr_act(), NULL);
    // lv_label_set_text(myLabel, "Button has not been clicked yet");
    // lv_obj_align(myLabel, NULL, LV_ALIGN_IN_LEFT_MID, 0, 0);
}

void disabled() {}

void competition_initialize() {}
