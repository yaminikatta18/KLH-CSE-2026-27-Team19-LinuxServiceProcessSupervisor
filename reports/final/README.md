# Final Project Report

## Linux Service Process Supervisor

### Project Overview

The Linux Service Process Supervisor is a Linux-based application developed to demonstrate important Operating System concepts through practical service and process management.

### Main Features

- Process creation using fork()
- Process execution using exec()
- PID and PPID identification
- Service start, stop and status operations
- Service restart functionality
- SIGTERM-based process termination
- Safe supervisor shutdown
- Linux process memory monitoring
- /proc/<PID>/status analysis
- VmSize and VmRSS monitoring
- Service execution logging

### Testing Summary

The supervisor was successfully tested for:

1. Starting the service
2. Checking service status
3. Stopping the service
4. Checking stopped status
5. Restarting the service
6. Checking restarted service status
7. Monitoring process memory
8. Safely terminating the service

### Memory Monitoring Result

The process monitor successfully obtained process information from the Linux /proc filesystem.

Example:

PID: 719
Name: test_service
State: S (sleeping)
VmSize: 2772 kB
VmRSS: 2016 kB

### Restart and Status Evidence

The restart functionality was tested successfully. The service received a new PID after restart and the supervisor reported the service as RUNNING.

Evidence:
screenshots/phase-2/Output_Restart_Status.png

### Syllabus Coverage

The project demonstrates concepts related to:

- CO-1: OS service layer and system calls
- CO-2: Processes and process control
- CO-3: Inter-process communication and signals
- CO-4: Memory management
- CO-5: File systems and file I/O
- CO-6: Concurrency and synchronization concepts

### Conclusion

The Linux Service Process Supervisor successfully demonstrates practical Linux Operating System concepts including process creation, process execution, process control, signal handling, service lifecycle management, process memory monitoring and safe process termination.

The project provides a practical foundation for further extensions involving concurrent monitoring, synchronization and advanced service management.

