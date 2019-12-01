#include "code.h"
#include <iostream>

using namespace std;

Code::Code() {
	ifCounter = 0;
	whileCounter = 0;
	forCounter = 0;
	blockCounter = 0;
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
	";============================ BEGIN STANDARD PROCEDURES\n\n" <<
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
	";============================ END STANDARD PROCEDURES\n";
}

void Code::r2(string lex) {
	lastID = lex;
	cout <<
	lex << 
	" proc\n";
};

void Code::r3() {
	cout <<
	lastID << 
	" endp\n\n";
};

void Code::r4() {
	cout <<
	"BLOCO" << 
	to_string(++blockCounter) <<
	":\n";
};

void Code::r5(string lex) {
	cout <<
	"mov cx, " <<
	lex <<
	"\nFOR" << 
	to_string(++forCounter) <<
	":\n";
};

void Code::r6() {
	cout <<
	"loop FOR" << 
	to_string(++forCounter) <<
	"\n";
};

void Code::r7() {

};

void Code::r8() {

};

void Code::r9() {

};

void Code::r10() {

};

void Code::r11() {

};

void Code::r12() {

};

void Code::r13() {

};

void Code::r14() {

};

void Code::r15() {

};

void Code::r16() {

};

void Code::r17() {

};

void Code::r18() {

};

void Code::r19() {

};

void Code::r20() {

};

void Code::r21() {

};

void Code::r22() {

};

void Code::r23() {

};

void Code::r24() {

};

void Code::r25() {

};

void Code::generateCode(string action, string lex) {
	if(action.compare("r0") == 0) r0();
	else if (action.compare("r1") == 0) r1();
	else if (action.compare("r2") == 0) r2(lex);
	else if (action.compare("r3") == 0) r3();
	else if (action.compare("r4") == 0) r4();
	else if (action.compare("r5") == 0) r5(lex);
	else if (action.compare("r6") == 0) r6();
	else if (action.compare("r7") == 0) r7();
	else if (action.compare("r8") == 0) r8();
	else if (action.compare("r9") == 0) r9();
	else if (action.compare("r10") == 0) r10();
	else if (action.compare("r11") == 0) r11();
	else if (action.compare("r12") == 0) r12();
	else if (action.compare("r13") == 0) r13();
	else if (action.compare("r14") == 0) r14();
	else if (action.compare("r15") == 0) r15();
	else if (action.compare("r16") == 0) r16();
}