# Syllabus Mapping

## CO-1: The OS as a Service Layer

The project demonstrates Linux as a service abstraction through process execution and system calls.

Project components:
- Linux user space and kernel space concepts
- System calls
- Shell-based command execution
- fork()
- exec()
- Process identification using PID and PPID

## CO-2: Processes and Process Control

The supervisor manages the lifecycle of a service process.

Project components:
- Process creation
- Process execution
- Process states
- Process termination
- fork()
- exec()
- waitpid()
- kill()
- Service start, stop, status and restart

## CO-3: Inter-Process Communication

The project uses POSIX signals for communication between the supervisor and service process.

Project components:
- POSIX signals
- Signal handlers
- SIGTERM
- SIGINT
- Asynchronous notifications
- Process control
- Planned extension: Named Pipes (FIFOs)

## CO-4: Memory Management

The project monitors Linux process memory information using the /proc filesystem.

Project components:
- Virtual memory
- Linux process address space
- /proc/<PID>/status
- Virtual memory size
- Resident memory
- Demand paging concepts
- Copy-on-Write concepts
- Memory analysis

## CO-5: File Systems and File I/O in Linux

The project uses Linux file operations for service logging and process information.

Project components:
- File descriptors
- File I/O
- Service log files
- Linux file-system concepts
- /proc filesystem
- Buffered and unbuffered I/O concepts

## CO-6: Concurrency and Synchronization

The final development phase will extend the supervisor with concurrent service monitoring.

Planned components:
- POSIX threads
- Threads and processes
- Race conditions
- Shared data
- Mutexes
- Condition variables
- Counting semaphores
- Deadlocks
- Thread coordination

## Overall Syllabus Relevance

The Linux Service Process Supervisor directly applies operating-system concepts including process creation, process control, signals, system calls, Linux process monitoring, file I/O and concurrency.

The project will be developed progressively to cover concepts from CO-1 through CO-6.
