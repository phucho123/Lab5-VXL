/*
 * fsm_automatic.c
 *
 *  Created on: Dec 14, 2022
 *      Author: ADMIN
 */
#include "fsm_automatic.h"

int state1 = INIT;
int state2 = 0;
int flag_uart = 0;

void command_parser_fsm(int temp){
	switch(state1){
		case INIT:
			if(temp == '!') state1 = START;
			break;
		case START: //!
			if(temp == 'R') state1 = R;
			else if(temp == 'O') state1 = O;
			else state1 = INIT;
			break;
		case R:
			if(temp == 'S') state1 = S;
			else if(temp == '!') state1 = START;
			else state1 = INIT;
			break;
		case S:
			if(temp == 'T') state1 = T;
			else if(temp == '!') state1 = START;
			else state1 = INIT;
			break;
		case T:
			if(temp == '#'){
				setTimer1(10);
				state2 = 1;
				state1 = INIT;
			}
			else if(temp == '!'){
				state1 = START;
			}
			else state1 = INIT;
			break;
		case O:
			if(temp == 'K') state1 = K;
			else if(temp == '!') state1 = START;
			else state1 = INIT;
			break;
		case K:
			if(temp == '#'){
				setTimer1(10);
				state2 = 0;
				state1 = INIT;
			}
			else if(temp == '!') state1 = START;
			else state1 = INIT;
			break;
		default:
			break;
	}
}

void uart_communication_fsm (){
	switch(state2){
		case 0:
			//do nothing
			break;
		case 1:
			if(timer_flag1){
				flag_uart = 1; //flag for print ADC value to console
			}
			break;
		default:
			break;
	}
}





