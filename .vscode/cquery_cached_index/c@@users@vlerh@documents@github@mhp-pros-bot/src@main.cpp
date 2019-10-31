#include "main.h"

lv_obj_t * autonBtn;
lv_obj_t * autonBtnLabel;
lv_obj_t * myLabel;

lv_style_t autonBtnStyleREL; //relesed style
lv_style_t autonBtnStylePR; //pressed style

static lv_res_t btn_click_action(lv_obj_t * btn)
{
	uint8_t id = lv_obj_get_free_num(btn); //id usefull when there are multiple buttons

    if(id == 0)
    {
    	char buffer[100];
 		sprintf(buffer, "button was clicked %i milliseconds from start", pros::millis());
 		lv_label_set_text(myLabel, buffer);
    }

    return LV_RES_OK;
}

void initialize()
{
	lv_style_copy(&autonBtnStyleREL, &lv_style_plain);
    autonBtnStyleREL.body.main_color = LV_COLOR_MAKE(200, 200, 255);
	autonBtnStyleREL.body.grad_color = LV_COLOR_MAKE(200, 200, 255);
    autonBtnStyleREL.body.radius = 0;
    autonBtnStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&autonBtnStylePR, &lv_style_plain);
    autonBtnStylePR.body.main_color = LV_COLOR_MAKE(255, 255, 255);
	autonBtnStylePR.body.grad_color = LV_COLOR_MAKE(255, 255, 255);
    autonBtnStylePR.body.radius = 0;
    autonBtnStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);

    autonBtn = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_obj_set_free_num(autonBtn, 0); //set button is to 0
    lv_btn_set_action(autonBtn, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
    lv_btn_set_style(autonBtn, LV_BTN_STYLE_REL, &autonBtnStyleREL); //set the relesed style
    lv_btn_set_style(autonBtn, LV_BTN_STYLE_PR, &autonBtnStylePR); //set the pressed style
    lv_obj_set_size(autonBtn, 200, 50); //set the button size
    lv_obj_align(autonBtn, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 10); //set the position to top mid

    autonBtnLabel = lv_label_create(autonBtn, NULL); //create label and puts it inside of the button
    lv_label_set_text(autonBtnLabel, "Autonomous"); //sets label text

    myLabel = lv_label_create(lv_scr_act(), NULL); //create label and puts it on the screen
    lv_label_set_text(myLabel, "Button has not been clicked yet"); //sets label text
    lv_obj_align(myLabel, NULL, LV_ALIGN_IN_LEFT_MID, 0, 0); //set the position to center
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
*/
#define LEFT_WHEELS_PORT 1
#define RIGHT_WHEELS_PORT 10

void opcontrol() {
 	pros::Motor left_wheels (LEFT_WHEELS_PORT);
   	pros::Motor right_wheels (RIGHT_WHEELS_PORT, true);
   	pros::Controller controller (CONTROLLER_MASTER);

   	while (true) {
     	left_wheels.move(controller.get_analog(ANALOG_LEFT_Y));
     	right_wheels.move(controller.get_analog(ANALOG_RIGHT_Y));

     	pros::delay(2);
   	}
}
