#include "main.h"
#include "display/lvgl.h"

#define LEFT_WHEELS_PORT 10
#define RIGHT_WHEELS_PORT 1
#define L_ARM_PORT 9
#define R_ARM_PORT 2
#define L_INTAKE_PORT 8
#define R_INTAKE_PORT 3
#define RAMP_PORT 5

//#include "logo.c"

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
	lv_style_copy(&autonBtnStyleREL, &lv_style_plain);
    autonBtnStyleREL.body.main_color = LV_COLOR_MAKE(0, 255, 0);
	autonBtnStyleREL.body.grad_color = LV_COLOR_MAKE(0, 255, 0);
    autonBtnStyleREL.body.radius = 0;
    autonBtnStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&autonBtnStylePR, &lv_style_plain);
    autonBtnStylePR.body.main_color = LV_COLOR_MAKE(255, 255, 255);
	autonBtnStylePR.body.grad_color = LV_COLOR_MAKE(255, 255, 255);
    autonBtnStylePR.body.radius = 0;
    autonBtnStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);


    autonBtn = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_free_num(autonBtn, 0);
    lv_btn_set_action(autonBtn, LV_BTN_ACTION_CLICK, btn_click_action);
    lv_btn_set_style(autonBtn, LV_BTN_STYLE_REL, &autonBtnStyleREL);
    lv_btn_set_style(autonBtn, LV_BTN_STYLE_PR, &autonBtnStylePR);
    lv_obj_set_size(autonBtn, 200, 105);
    lv_obj_align(autonBtn, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 10);

    autonBtnLabel = lv_label_create(autonBtn, NULL);
    lv_label_set_text(autonBtnLabel, "Autonomous");

	testBtn = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_free_num(testBtn, 0);
    lv_btn_set_action(testBtn, LV_BTN_ACTION_CLICK, btn_click_action);
    lv_btn_set_style(testBtn, LV_BTN_STYLE_REL, &autonBtnStyleREL);
	lv_btn_set_style(testBtn, LV_BTN_STYLE_PR, &autonBtnStylePR);
    lv_obj_set_size(testBtn, 200, 105);
    lv_obj_align(testBtn, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -10, -10);

    testBtnLabel = lv_label_create(testBtn, NULL);
    lv_label_set_text(testBtnLabel, "Settings");

    myLabel = lv_label_create(lv_scr_act(), NULL);
    //lv_label_set_text(myLabel, "Button has not been clicked yet");
    lv_obj_align(myLabel, NULL, LV_ALIGN_IN_LEFT_MID, 0, 0);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
 	pros::Motor left_wheels (LEFT_WHEELS_PORT);
   	pros::Motor right_wheels (RIGHT_WHEELS_PORT, true);
   	pros::Controller controller (CONTROLLER_MASTER);
	pros::Motor l_arm (L_ARM_PORT);
	pros::Motor r_arm (R_ARM_PORT);
	pros::Motor l_intake (L_INTAKE_PORT);
	pros::Motor r_intake (R_INTAKE_PORT, true);
	pros::Motor ramp (RAMP_PORT);

   	while (true) {
     	left_wheels.move(controller.get_analog(ANALOG_LEFT_Y));
     	right_wheels.move(controller.get_analog(ANALOG_RIGHT_Y));

		if (controller.get_digital(DIGITAL_R1)) {
			l_arm.move_velocity(100);
			r_arm.move_velocity(100);
		}

		else if (controller.get_digital(DIGITAL_R2)) {
			l_arm.move_velocity(-100);
			r_arm.move_velocity(-100);
		}

		else {
			l_arm.move_velocity(0);
			r_arm.move_velocity(0);
		}

		if (controller.get_digital(DIGITAL_L1)) {
			l_intake.move_velocity(100);
			r_intake.move_velocity(100);
		}

		else if (controller.get_digital(DIGITAL_L2)) {
		l_intake.move_velocity(-100);
		r_intake.move_velocity(-100);
		}

		else {
			l_intake.move_velocity(0);
			r_intake.move_velocity(0);
		}

		if (controller.get_digital(DIGITAL_A)) {
			ramp.move_velocity(100);
		}
		else if (controller.get_digital(DIGITAL_B)) {
			ramp.move_velocity(-100);
		}
		else {
			ramp.move_velocity(0);
		}

     	pros::delay(2);
   	}
}
