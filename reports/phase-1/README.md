# Phase 1 Report

## Linux Service Process Supervisor

### Objective
To develop a Linux-based service process supervisor that demonstrates process creation, process execution and basic process control.

### Implemented Features
- Process creation using fork()
- Program execution using exec()
- Process identification using PID and PPID
- Service start operation
- Service status monitoring
- Service stop operation
- Service termination using SIGTERM
- Safe supervisor shutdown

### Testing Performed
The supervisor was compiled and executed successfully. The test service was started and its PID was displayed. The service status was checked and reported as RUNNING. The service was stopped using SIGTERM and the status was subsequently reported as STOPPED.

### Result
Phase 1 successfully demonstrates Linux process creation, execution and process control concepts.
