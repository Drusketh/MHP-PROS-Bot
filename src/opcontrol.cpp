#include "main.h"
#include "motorfunc.hpp"
#include "motorfunc.cpp"

void opcontrol() {
	//DIGITAL_A = Lift Arms
	//ANALOG_LEFT_Y & ANALOG_RIGHT_Y = Tank Drive
	//DIGITAL_B = Lower Arms
	//DIGITAL_L1 = Intake In
	//DIGITAL_L2 = Intake Out
	//DIGITAL_R1 = Lift Ramp
	//DIGITAL_R2 = Lower Ramp

    pros::Controller controller (CONTROLLER_MASTER);

	while (true) {
        move_tank(-controller.get_analog(ANALOG_LEFT_Y), -controller.get_analog(ANALOG_RIGHT_Y));

		if (controller.get_digital(DIGITAL_A)) {
			move_tray(-45);
		}
		else if (controller.get_digital(DIGITAL_X)) {
			move_tray(45);
		}
		else {
			move_tray(0);
		}

		if (controller.get_digital(DIGITAL_L1)) {
			move_arms(-90);
		}
		else if (controller.get_digital(DIGITAL_L2)) {
			move_arms(90);
		}
		else {
			move_arms(0);
		}

		// if (controller.get_digital(DIGITAL_R1)) {
		// 	l_intake.move_velocity(105);
		// 	r_intake.move_velocity(105);
		// }
		// else if (controller.get_digital(DIGITAL_R2)) {
		// 	l_intake.move_velocity(-105);
		// 	r_intake.move_velocity(-105);
		// }
		// else {
		// 	l_intake.move_velocity(0);
		// 	r_intake.move_velocity(0);
		// }

     	pros::delay(2);
   	}
}
