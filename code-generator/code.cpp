#include "code.h"
#include <iostream>

using namespace std;

Code::Code() {
	ifCounter = 0;
	whileCounter = 0;
	forCounter = 0;
	labelCounter = 0;
}

void Code::generateCode(string action) {
	if(action.compare("r0") == 0) r0();
	else if (action.compare("r1") == 0) r1();
}

void Code::r0() {
	cout <<
	"; MATA60 - Robot-L intermediate code - Mateus Barbosa\n" <<
	"; base code for controlling the robot with few procedures\n\n" <<
	"#start=robot.exe#\n\n" <<
	"name \"robot\"\n\n" <<
	"#make_bin#\n" <<
	"#cs = 500#\n" <<
	"#ds = 500#\n" <<
	"#ss = 500#\n" <<
	"#sp = ffff#\n" <<
	"#ip = 0#\n\n" <<
	"; robot base i/o port:\n" <<
	"r_port equ 9\n\n";
}

void Code::r1() {
	cout <<
	";=================================== BEGIN PROCEDURES\n\n" <<
	"; do nothing procedure:\n" <<
	"do_nothing proc\n" <<
	"mov al, 0\n" <<
	"out r_port, al\n" <<
	"ret\n" <<
	"do_nothing endp\n\n" <<
	"; move robot forward:\n" <<
	"move_forward proc\n" <<
	"mov al, 1\n" <<
	"out r_port, al\n" <<
	"ret\n" <<
	"move_forward endp\n\n" <<
	"; turn robot left:\n" <<
	"turn_left proc\n" <<
	"mov al, 2\n" << 
	"out r_port, al\n" << 
	"ret\n" <<
	"turn_left endp\n\n" <<
	"; turn robot right:\n"<<
	"turn_right proc\n" <<
	"mov al, 3\n" <<
	"out r_port, al\n" <<
	"ret\n" <<
	"turn_right endp\n\n" <<
	"; examines an object in front using sensor:\n" <<
	"exam_front proc\n" <<
	"mov al, 4\n" <<
	"out r_port, al\n" <<
	"ret\n" <<
	"exam_front endp\n\n" <<
	"; switch on the lamp:\n" <<
	"switch_on_lamp proc\n" <<
	"mov al, 5\n" <<
	"out r_port, al\n" <<
	"ret\n" <<
	"switch_on_lamp endp\n\n" <<
	"; switch off the lamp:\n" <<
	"switch_off_lamp proc\n" <<
	"mov al, 6\n" <<
	"out r_port, al\n" <<
	"ret\n" <<
	"switch_off_lamp endp\n\n" <<
	"; this procedure does not\n" <<
	"; return until robot is ready\n" <<
	"; to receive next command:\n" <<
	"wait_robot proc\n" <<
	"; check if robot busy:\n" <<
	"busy1: in al, r_port + 2\n" <<
	"      test al, 00000010b\n" <<
	"      jnz busy1 ; busy, so wait.\n" <<
	"ret    \n" <<
	"wait_robot endp\n\n" <<
	"; this procedure does not\n" <<
	"; return until robot completes\n" <<
	"; the examination:\n" <<
	"wait_exam proc\n" <<
	"; check if has new data:\n" <<
	"busy2: in al, r_port + 2\n" <<
	"       test al, 00000001b\n" <<
	"       jz busy2 ; no new data, so wait.\n" <<
	"ret    \n" <<
	"wait_exam endp\n\n" <<
	";=================================== END PROCEDURES\n";
}