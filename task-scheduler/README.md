# Task Scheduler (STM32)

## Project Goal  
Implement a simple cooperative task scheduler from scratch on an STM32F4 Discovery board using SysTick and PendSV exceptions to toggle four LEDs concurrently.

## Diagram  
*TODO*

## Key Lessons  
- Bare-metal startup and linker script setup  
- SysTick as system timer and PendSV for context switching  
- Interrupt prioritization and NVIC configuration  
- Low-level GPIO control and multitasking without using a RTOS  
- Debugging with breakpoints, stepping through assembly, and disassembly inspection to fix faults  

## Notes  
Part of a mini-project series from FastBit Academy’s ARM Cortex-M Udemy course demonstrating embedded fundamentals.  
