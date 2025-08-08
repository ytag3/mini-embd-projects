/*
 * main.h
 *
 *  Created on: Aug 4, 2025
 *      Author: oogi
 */

#ifndef MAIN_H_
#define MAIN_H_


#define CONF_FAULT_REG		0xE000ED24U
#define ICSR_REG			0xE000ED04U

#define MAX_TASKS			5
//Stack Memory Calculations
//need to reserve space for each task in the stack as well as the scheduler
#define SIZE_TASK_STACK		1024U //1kB
#define SIZE_SCHED_STACK	1024U //1kB

#define SRAM_START 			0x20000000U //start of SRAM in processor
#define SRAM_SIZE 			( (128) * 1024) //total size of SRAM region
#define SRAM_END 			( (SRAM_START) + (SRAM_SIZE) )

//each region next to each other descending as: stack start / t1->t2->t3->t4->scheduler
#define T1_STACK_START           SRAM_END
#define T2_STACK_START           ( (SRAM_END) - (1 * SIZE_TASK_STACK) )
#define T3_STACK_START           ( (SRAM_END) - (2 * SIZE_TASK_STACK) )
#define T4_STACK_START           ( (SRAM_END) - (3 * SIZE_TASK_STACK) )
#define IDLE_STACK_START         ( (SRAM_END) - (4 * SIZE_TASK_STACK) )
#define SCHED_STACK_START        ( (SRAM_END) - (5 * SIZE_TASK_STACK) )

//timer definitions
#define TICK_HZ 			1000U
#define HSI_CLOCK			16000000U
#define SYSTICK_TIM_CLK		HSI_CLOCK
#define SYSTICK_SVR_REG		0xE000E014U //reload value register
#define SYSTICK_CSR_REG		0xE000E010U //control status register

//task definitions
#define INIT_XPSR			0x01000000U //all but T bit
#define INIT_LR				0xFFFFFFFDU  //based on EXC_RETURN to threadmode w PSP
#define TASK_RUNNING_STATE	0x00
#define TASK_BLOCKED_STATE	0xFF

//interrupts
//can use do-while loop to write multiline macro
#define INTERRUPT_DISABLE() do{__asm volatile ("MOV R0, #0x1"); __asm volatile("MSR PRIMASK, R0");} while(0)	//use primask register
#define INTERRUPT_ENABLE() 	do{__asm volatile ("MOV R0, #0x0"); __asm volatile("MSR PRIMASK, R0");} while(0)

//LED
#define LED_GREEN  			12
#define LED_ORANGE 			13
#define LED_RED    			14
#define LED_BLUE   			15

#define DELAY_COUNT_1MS 	1250U
#define DELAY_COUNT_1S  	(1000U * DELAY_COUNT_1MS)
#define DELAY_COUNT_500MS  	(500U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_250MS 	(250U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_125MS 	(125U  * DELAY_COUNT_1MS)

#endif /* MAIN_H_ */
