# System Architecture

## Project Overview

The Linux Service Process Supervisor is a command-line based Linux systems programming project. It manages the lifecycle of a test service process using Linux process management and POSIX system calls.

## Architecture

```text
                    +----------------------+
                    |      User / Shell    |
                    +----------+-----------+
                               |
                               v
                    +----------------------+
                    |  Service Supervisor  |
                    |    supervisor.c      |
                    +----------+-----------+
                               |
                 +-------------+-------------+
                 |             |             |
                 v             v             v
              START          STOP         RESTART
                 |             |             |
                 +-------------+-------------+
                               |
                               v
                    +----------------------+
                    |     Service Process  |
                    |       service.c      |
                    +----------+-----------+
                               |
                +--------------+--------------+
                |                             |
                v                             v
        POSIX Signal Handling            Service Logging
                |                             |
                v                             v
          SIGTERM / SIGINT             test_service.log
