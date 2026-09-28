# System Design

## Project Title
Linux Service Process Supervisor

## Objective

The objective of this project is to develop a Linux-based service process supervisor in C. The supervisor manages the lifecycle of a test service and demonstrates Linux process management, signals, system calls, process monitoring and file logging.

## Main Components

### 1. Supervisor

File: `src/supervisor.c`

The supervisor provides a command-line menu to:

- Start the service
- Stop the service
- Check service status
- Restart the service
- Exit safely

It manages the service process using PID information and Linux system calls.

### 2. Service

File: `src/service.c`

The service process:

- Displays its PID and PPID
- Runs continuously
- Handles shutdown signals
- Terminates safely
- Provides output for testing process management

### 3. Process Management

The project demonstrates:

- `fork()`
- `exec()`
- `waitpid()`
- `kill()`
- PID and PPID management
- Process creation and termination

### 4. Signal Handling

POSIX signals are used for communication between the supervisor and service.

Signals include:

- `SIGTERM`
- `SIGINT`

The service catches shutdown signals and performs safe termination.

### 5. Logging

Service activity is recorded in:

`logs/test_service.log`

The log contains service startup, PID, PPID, running status and shutdown information.

## Working Flow

User / Shell
    |
    v
Service Supervisor
    |
    +---- Start
    +---- Stop
    +---- Status
    +---- Restart
    |
    v
Service Process
    |
    +---- PID / PPID
    +---- Signal Handling
    +---- Service Logging

## Future Extensions

Future phases may include:

- Process memory monitoring using `/proc`
- CPU and process monitoring
- Multiple service management
- POSIX threads
- Mutexes
- Semaphores
- Concurrent service monitoring

## Technologies Used

- C Programming
- Linux / Ubuntu
- POSIX System Calls
- POSIX Signals
- Git and GitHub
- `/proc` filesystem
