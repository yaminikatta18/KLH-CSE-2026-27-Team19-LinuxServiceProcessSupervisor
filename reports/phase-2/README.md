# Phase 2 Report

## Linux Service Process Supervisor

### Objective
To extend the supervisor with service monitoring, signal-based control, restart functionality and process memory monitoring.

### Implemented Features
- Service status checking
- Service stop using SIGTERM
- Service restart functionality
- Process PID tracking
- Process memory monitoring
- Reading process information from /proc/<PID>/status
- VmSize monitoring
- VmRSS monitoring
- Service execution logging

### Memory Monitoring Test

The process_monitor program was tested with the test service.

Example:

PID: 719
Name: test_service
State: S (sleeping)
Pid: 719
PPid: 718
VmSize: 2772 kB
VmRSS: 2016 kB

### Restart Test

The supervisor was tested using the Restart Service option. The service was restarted successfully and received a new PID. The status command confirmed that the restarted service was RUNNING.

Screenshot:
screenshots/phase-2/Output_Restart_Status.png

### Result

Phase 2 successfully demonstrates service lifecycle management, signal-based process termination, restart functionality and Linux process memory monitoring.
