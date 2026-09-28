# Linux Service Process Supervisor

**Repository:** `KLH-CSE-2026-27-Team19-LinuxServiceProcessSupervisor`
**Branch:** CSE
**Academic Year:** 2026–27
**Team:** Team 19
**Supervisor:** Harika Mam

## Team Members

| Name         | Student ID |
| ------------ | ---------- |
| Yamini Katta | 2520030380 |
| Lekhana      | 2520030364 |
| Anikha       | 2520030613 |

## Abstract

The **Linux Service Process Supervisor** is a Linux-based systems programming project developed in C to demonstrate operating-system concepts related to process and service management. The system provides a command-line interface for starting, stopping, monitoring, restarting, and safely terminating a service process.

The project uses Linux process-control mechanisms such as `fork()`, `exec()`, `waitpid()`, process IDs, and POSIX signals. Service activity is recorded using Linux file I/O and logging mechanisms. The project will be progressively extended with inter-process communication using pipes and FIFOs, memory monitoring through `/proc`, file-system operations, and POSIX thread synchronization.

## Objectives

* Demonstrate Linux operating-system service abstraction.
* Understand process creation and process lifecycle.
* Implement service start, stop, status, and restart operations.
* Demonstrate POSIX signal handling.
* Implement IPC using pipes and named pipes (FIFOs).
* Monitor process and memory information using `/proc`.
* Demonstrate Linux file descriptors and file I/O.
* Implement POSIX threads and synchronization mechanisms.

## Syllabus Mapping

| CO       | Project Coverage                                                                           |
| -------- | ------------------------------------------------------------------------------------------ |
| **CO-1** | Linux architecture, user/kernel space, system calls, shell and command execution           |
| **CO-2** | Process creation, execution, synchronization, termination, `fork()`, `exec()`, `waitpid()` |
| **CO-3** | Pipes, FIFOs, signals, signal handlers, process groups and sessions                        |
| **CO-4** | Virtual memory concepts, `/proc`, process memory monitoring and analysis                   |
| **CO-5** | File descriptors, file I/O, logging, inodes and file-system concepts                       |
| **CO-6** | POSIX threads, mutexes, condition variables, semaphores and concurrency                    |

## Current Phase Status

### Phase 1 — Process and Service Supervisor

**Status: Completed**

Implemented:

* Service process creation
* Start Service
* Stop Service
* Service Status
* Restart Service
* Safe service termination
* POSIX signal handling
* PID and PPID monitoring
* Service logging
* `/proc` process inspection

### Upcoming Phases

* **Phase 2:** IPC using pipes/FIFOs and signal programming
* **Phase 3:** Memory monitoring and `/proc` analysis
* **Phase 4:** File-system and file-I/O operations
* **Phase 5:** POSIX threads and synchronization
* **Final Phase:** Integration, testing and final documentation

## Project Structure

```text
KLH-CSE-2026-27-Team19-LinuxServiceProcessSupervisor/
│
├── README.md
├── src/
│   ├── supervisor.c
│   └── service.c
│
├── docs/
│   ├── architecture.md
│   ├── design.md
│   ├── syllabus_mapping.md
│   └── testing.md
│
├── data/
│   └── README.md
│
├── results/
│   └── process_results.txt
│
├── reports/
│   ├── phase-1/
│   ├── phase-2/
│   └── final/
│
├── screenshots/
│   ├── phase-1/
│   ├── phase-2/
│   └── final/
│
├── config/
├── logs/
│   └── test_service.log
│
└── .gitignore
```

## Technologies

* Ubuntu/Linux
* C Programming
* GCC
* POSIX system calls
* POSIX signals
* Linux `/proc`
* Git
* GitHub

## Setup

Clone the repository:

```bash
git clone https://github.com/yaminikatta18/KLH-CSE-2026-27-Team19-LinuxServiceProcessSupervisor.git
cd KLH-CSE-2026-27-Team19-LinuxServiceProcessSupervisor
```

Compile:

```bash
gcc -Wall -Wextra src/supervisor.c -o supervisor
```

## Execution

Run:

```bash
./supervisor
```

The supervisor provides:

```text
1. Start Service
2. Stop Service
3. Service Status
4. Restart Service
5. Exit
```

## Process Testing

Check a service process:

```bash
ps -p <PID> -o pid,ppid,state,cmd
```

Check Linux process information:

```bash
cat /proc/<PID>/status
```

Check whether the service is running:

```bash
pgrep -a test_service
```

Service logs are stored in:

```text
logs/test_service.log
```

## Git Contribution

The project is developed progressively through Git commits. Each team member contributes using their own GitHub account so that individual contributions can be verified through the commit history.

Phase deliverables will be tagged progressively:

```text
review-1
review-2
final
```

## Repository Safety

The repository must not contain:

* Passwords
* GitHub Personal Access Tokens
* API keys
* Credentials
* Confidential institutional data
* Restricted or licensed datasets

## Project Status

**Current Status:** Phase 1 completed
**Next Target:** Phase 2 — Inter-Process Communication and Signal Programming
