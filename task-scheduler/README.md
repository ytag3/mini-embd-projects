# Task Scheduler (STM32)

## Project Goal
Build a cooperative task scheduler on the STM32F4 Discovery board using SysTick and PendSV exceptions to toggle four LEDs concurrently.

## Diagram
*TODO*

## Key Lessons
- Using SysTick as a system timer and PendSV for context switching  
- Interrupt prioritization with NVIC  
- Low-level GPIO control for multitasking without an RTOS  
- Debugging at the register and assembly level to resolve faults  

---

*Developed alongside the **FastBit Embedded Academy** ARM Cortex-M course.*
