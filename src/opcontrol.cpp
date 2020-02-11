#include "main.h"
#include "motorfunc.cpp"

void opcontrol() {
	//DIGITAL_A = Lift Arms
	//ANALOG_LEFT_Y & ANALOG_RIGHT_Y = Tank Drive
	//DIGITAL_B = Lower Arms
	//DIGITAL_L1 = Intake In
	//DIGITAL_L2 = Intake Out
	//DIGITAL_R1 = Lift Ramp
	//DIGITAL_R2 = Lower Ramp

	r_ramp.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	l_ramp.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	while (true) {
	    left_wheels.move(-controller.get_analog(ANALOG_LEFT_Y));
   		right_wheels.move(-controller.get_analog(ANALOG_RIGHT_Y));

		if (controller.get_digital(DIGITAL_A)) {
			l_ramp.move_velocity(-45);
			r_ramp.move_velocity(-45);
		}
		else if (controller.get_digital(DIGITAL_X)) {
			l_ramp.move_velocity(45);
			r_ramp.move_velocity(45);
		}
		else {
			l_ramp.move_velocity(0);
			r_ramp.move_velocity(0);
		}

		if (controller.get_digital(DIGITAL_L1)) {
			l_arm.move_velocity(-90);
			r_arm.move_velocity(-90);
		}
		else if (controller.get_digital(DIGITAL_L2)) {
			l_arm.move_velocity(90);
			r_arm.move_velocity(90);
		}
		else {
			l_arm.move_velocity(0);
			r_arm.move_velocity(0);
		}

		if (controller.get_digital(DIGITAL_R1)) {
			l_intake.move_velocity(105);
			r_intake.move_velocity(105);
		}
		else if (controller.get_digital(DIGITAL_R2)) {
			l_intake.move_velocity(-105);
			r_intake.move_velocity(-105);
		}
		else {
			l_intake.move_velocity(0);
			r_intake.move_velocity(0);
		}

     	pros::delay(2);
   	}
}
