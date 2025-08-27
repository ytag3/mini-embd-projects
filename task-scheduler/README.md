# Task Scheduler (STM32)

## Project Goal
Built a cooperative task scheduler on the STM32F4 Discovery board using SysTick and PendSV exceptions to toggle four LEDs concurrently.

It also includes custom startup code, a linker script, and a Makefile, highlighting bare-metal build and linking processes.

## Diagram
![Task Scheduler Execution Flow](./docs/task_schedule.execution.png)
*Execution flow showing task switching between SysTick, PendSV, and user tasks.*

## What I Learned
- **SysTick and PendSV Usage**: Implemented periodic system ticks and context-switching exceptions to manage multiple tasks.  
- **Context Switching & Scheduling**: Gained hands-on understanding of what context switching entails, how a processor saves and restores state, and how round-robin scheduling operates at the bare-metal level.  
- **Stack Management & Execution Flow**: Learned how to set up individual task stacks, manage execution entry and exit, and observe how the ARM Cortex-M core handles task contexts.  
- **Debugging Faults**: Used step-through debugging, disassembly inspection, and fault registers to identify and resolve runtime errors.  
- **Task States Management**: Learned how to track and manage task states using structured tables for each type of state (e.g., ready, running, waiting).  
- **Bare-Metal Build & Linking**: Developed custom startup code, a linker script, and a Makefile to fully understand how a program is built and loaded onto the MCU

