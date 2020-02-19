#include "main.h"

void opcontrol() {
	//DIGITAL_A = Lift Arms
	//ANALOG_LEFT_Y & ANALOG_RIGHT_Y = Tank Drive
	//DIGITAL_B = Lower Arms
	//DIGITAL_L1 = Intake In
	//DIGITAL_L2 = Intake Out
	//DIGITAL_R1 = Lift Ramp
	//DIGITAL_R2 = Lower Ramp

    pros::Controller controller (CONTROLLER_MASTER);

    int arm_target = 0;

	while (true) {
        move_tank(controller.get_analog(ANALOG_LEFT_Y), controller.get_analog(ANALOG_RIGHT_Y));

		if (controller.get_digital(DIGITAL_A)) {
			move_tray(90);
		}
		else if (controller.get_digital(DIGITAL_X)) {
			move_tray(-90);
		}
		else {
			move_tray(0);
		}


		if (controller.get_digital(DIGITAL_L1)) {
            move_arms(-90);
            //arm_target = get_arms();
		}
		else if (controller.get_digital(DIGITAL_L2)) {
            move_arms(90);
            //arm_target = get_arms();
		}
		else {
            move_arms(0);
			//set_arms(arm_target, 90);
		}

        // while (!((get_arms() < arm_target + 5) && (get_arms() > arm_target - 5))) {
        //     pros::delay(2);
        // }
        //controller.print(0, 0, "Counter: %d", arm_target);

		if (controller.get_digital(DIGITAL_R1)) {
			move_intake(105);
		}
		else if (controller.get_digital(DIGITAL_R2)) {
			move_intake(-105);
		}
		else {
			move_intake(0);
		}

     	pros::delay(5);
   	}
}
