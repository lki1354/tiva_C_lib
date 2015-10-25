/*
 * timer.c
 *
 *  Created on: Oct 12, 2015
 *      Author: lukas
 */


#define TIMER_0_BASE             0x40030000  // Timer0
#define TIMER_1_BASE             0x40031000  // Timer1
#define TIMER_2_BASE             0x40032000  // Timer2
#define TIMER_3_BASE             0x40033000  // Timer3
#define TIMER_4_BASE             0x40034000  // Timer4
#define TIMER_5_BASE             0x40035000  // Timer5
#define TIMER_0_WIDE_BASE 		 0x40036000
#define TIMER_1_WIDE_BASE 		 0x4003.7000
#define TIMER_2_WIDE_BASE 		 0x4004.C000
#define TIMER_3_WIDE_BASE 		 0x4004.D000
#define TIMER_4_WIDE_BASE 		 0x4004.E000
#define TIMER_5_WIDE_BASE 		 0x4004.F000


//Register 4: GPTM Control (GPTMCTL), offset 0x00C
#define GPTMCTL_OFFSET 0x00C

//typedef enum {TAEN,TASTALL,TAEVENT1,TAEVNT2,RTCEN,TAOTE,TAPWML,reserved1,TBEN=8,TBSTALL,TBEVENT1,TBEVENT2,,TBOTE,TBPWML}GPTMCTL_TYPES;

