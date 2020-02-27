#include "main.h"

#include <stdio.h>
#include "main.h"

typedef  FILE * pc_file_t;

static lv_fs_res_t pcfs_open( void * file_p, const char * fn, lv_fs_mode_t mode)
{
    errno = 0;
    const char * flags = "";
    if(mode == LV_FS_MODE_WR) flags = "wb";
    else if(mode == LV_FS_MODE_RD) flags = "rb";
    else if(mode == (LV_FS_MODE_WR | LV_FS_MODE_RD)) flags = "a+";

    char buf[256];
    sprintf(buf, "/%s", fn);
    pc_file_t f = fopen(buf, flags);

    if(f == NULL)
      return LV_FS_RES_UNKNOWN;
    else {
      fseek(f, 0, SEEK_SET);
      pc_file_t * fp = (pc_file_t *)file_p;
      *fp = f;
    }

    return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_close( void * file_p)
{
    pc_file_t * fp = (pc_file_t *)file_p;
    fclose(*fp);
    return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_read( void * file_p, void * buf, uint32_t btr, uint32_t * br)
{
    pc_file_t * fp =  (pc_file_t *)file_p;
    *br = fread(buf, 1, btr, *fp);
    return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_seek( void * file_p, uint32_t pos)
{
    pc_file_t * fp = (pc_file_t *)file_p;
    fseek(*fp, pos, SEEK_SET);
    return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_tell( void * file_p, uint32_t * pos_p)
{
    pc_file_t * fp =  (pc_file_t *)file_p;
    *pos_p = ftell(*fp);
    return LV_FS_RES_OK;
}

void opcontrol() {
    lv_fs_drv_t pcfs_drv;                         /*A driver descriptor*/
    memset(&pcfs_drv, 0, sizeof(lv_fs_drv_t));    /*Initialization*/

    pcfs_drv.file_size = sizeof(pc_file_t);       /*Set up fields...*/
    pcfs_drv.letter = 'S';
    pcfs_drv.open = pcfs_open;
    pcfs_drv.close = pcfs_close;
    pcfs_drv.read = pcfs_read;
    pcfs_drv.seek = pcfs_seek;
    pcfs_drv.tell = pcfs_tell;
    lv_fs_add_drv(&pcfs_drv);

    lv_obj_t * img_var = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img_var, "S:/usd/MHP8373.bin");
    lv_obj_set_pos(img_var, 0, 0);

    while (true) {
      pros::delay(20);
    }

	//DIGITAL_A = Lift Arms
	//ANALOG_LEFT_Y & ANALOG_RIGHT_Y = Tank Drive
	//DIGITAL_B = Lower Arms
	//DIGITAL_L1 = Intake In
	//DIGITAL_L2 = Intake Out
	//DIGITAL_R1 = Lift Ramp
	//DIGITAL_R2 = Lower Ramp

    // pros::Controller controller (CONTROLLER_MASTER);
    //
    // int arm_target = 0;

	while (true) {
        // move_tank(controller.get_analog(ANALOG_LEFT_Y), controller.get_analog(ANALOG_RIGHT_Y));
        //
		// if (controller.get_digital(DIGITAL_X)) {
		// 	move_tray(127);
		// }
        // else if (controller.get_digital(DIGITAL_A)) {
		// 	move_tray(-127);
		// }
		// else {
		// 	move_tray(0);
		// }
        //
        //
		// if (controller.get_digital(DIGITAL_L1)) {
        //     move_arms(-90);
		// }
		// else if (controller.get_digital(DIGITAL_L2)) {
        //     move_arms(90);
		// }
		// else {
        //     move_arms(0);
		// }
        //
        //
		// if (controller.get_digital(DIGITAL_R1)) {
		// 	move_intake(105);
		// }
		// else if (controller.get_digital(DIGITAL_R2)) {
		// 	move_intake(-105);
		// }
		// else {
		// 	move_intake(0);
		// }

     	pros::delay(20);
   	}
}
