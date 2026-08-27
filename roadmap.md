# Embedded Systems Roadmap

## 1. C Programming

- Data types and operators
- Control flow
- Functions
- Arrays and strings
- Pointers
- Memory layout
- Bitwise operations
- `const`, `static`, and `volatile`
- `struct` and `enum`
- Header and source file organization

## 2. Microcontroller Fundamentals

- CPU, registers, RAM, and Flash
- Datasheets and pin configuration
- GPIO
- Button debouncing
- Non-blocking timing
- Interrupts
- Timers
- PWM
- ADC
- Watchdog

## 3. Communication Protocols

Learning order: UART → I2C → SPI → CAN

- UART communication
- I2C communication
- SPI communication
- CAN communication
- Baud rate and clock timing
- Data framing
- Device addressing
- ACK, NACK, and error handling
- Protocol debugging with a logic analyzer
- ESP32 implementation
- STM32 implementation

## 4. RTOS

- Tasks and task states
- Scheduler
- Task priorities
- Task delay
- Queues
- Semaphores
- Mutexes
- Interrupt-to-task communication
- Race conditions
- Stack usage

## 5. Embedded Linux

- Linux command line
- Filesystem and permissions
- Processes and threads
- GPIO from userspace
- UART from userspace
- I2C from userspace

## 6. Debugging

- Serial logging
- Compiler warnings
- Reading datasheets
- Reading schematics
- Logic analyzer
- Systematic debugging

## 7. Projects

- GPIO and button controller
- Non-blocking traffic light
- UART command-line interface
- I2C sensor node
- FreeRTOS sensor system
- STM32 CAN node
- ESP32 and Raspberry Pi communication
