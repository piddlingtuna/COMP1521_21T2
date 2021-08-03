# Process Management

## Parallelism

A CPU can only do one thing at a time.

dual-core == 2x CPUs
quad-core == 4x CPUs

A computer that can only do one thing at a time is pretty useless.

The answer: pseudo-parallelism. Quickly switch between different processes.

The '-' represents a process being run in the CPU.

Process 1 -----         ----- <- Chrome

Process 2      -----         ----- <- dcc

Process 3           -----         -----

Mouse      -              -      -   -

Processes must be switched so they don't notice their execution is constantly being paused and restarted.


## What is a process?

Execution state (what you need to run something in the CPU)
- CPU registers (like your 32 MIPS registers)
- Program counter

A thread consists of:
- Execution state

A process consists of:
- Execution state (i.e. a thread)
- Memory in RAM
- other resources (like file handles)

A process may contain multiple threads.

Memory and other resources can be shared with other threads.
