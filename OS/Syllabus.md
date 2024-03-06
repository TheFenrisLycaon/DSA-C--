# Syllabus

## Basic

- [Introduction of Operating System](./Basic/01-Introduction.md)
- [Types of Operating Systems](./Basic/02-TypesOfOS.md)
- [Functions of Operating System](./Basic/03-Functions.md)
- [Real time systems](./Basic/04-RTOS.md)
- [Types of computer memory (RAM and ROM)](./Basic/06-TypesOfMemory.md)
- [Differences](./Basic/07-Differences.md)
  - [Multi-tasking VS Multi-threading VS Multi-processing](./Basic/07-Differences.md#multi-tasking-vs-multi-threading-vs-multi-processing)
  - [32-bit and 64-bit](./Basic/07-Differences.md#32-bit-vs-64-bit)
- [What happens when we turn on computer?](./Basic/08-BootUp.md)
- [Boot Block](./Basic/09-BootBlock.md)
- [UEFI](./Basic/10-UEFI.md)

## System Structure

- Microkernel
- Kernel I/O Subsystem (I/O System)
- Monolithic Kernel and key differences from Microkernel
- Introduction of System Call
- Get/Set process resource limits in C
- Dual Mode operations in OS
- Privileged and Non-Privileged Instructions

## CPU Scheduling

- Process
- States of a process
- Process Table and Process Control Block (PCB)
- Process Scheduler
- CPU Scheduling
- Preemptive and Non-Preemptive Scheduling
- Measure the time spent in context switch?
- Difference between dispatcher and scheduler
- FCFS Scheduling
- Convoy Effect in Operating Systems
- Belady’s Anomaly
- Shortest Job First (or SJF) scheduling
- Program for Shortest Job First (SJF) scheduling
- Shortest Job First scheduling with predicted burst time
- Longest Remaining Time First (LRTF) Program
- Longest Remaining Time First (LRTF) algorithm
- Round Robin scheduling
- Selfish Round Robin Scheduling
- Round Robin Scheduling with different arrival times
- Priority Scheduling
- Program for Preemptive Priority CPU Scheduling
- Priority Scheduling with different arrival time
- Starvation and Aging in Operating Systems
- Highest Response Ratio Next (HRRN) Scheduling
- Multilevel Queue Scheduling
- Multilevel Feedback Queue Scheduling
- Lottery Process Scheduling
- Multiple-Processor Scheduling

## Process Synchronization

- Process Synchronization
- Critical Section
- Inter Process Communication
  - Methods
- IPC through shared memory
- IPC using Message Queues
- Message based Communication in IPC (inter process communication)
- Communication between two process using signals in C
- Semaphores in operating system
- Mutex vs. Semaphore
- Process Synchronization | Monitors
- Peterson’s Algorithm for Mutual Exclusion
  - Basic C implementation
  - CPU Cycles and Memory Fence
  - Using processes and shared memory
- Dekker’s algorithm
- Bakery Algorithm
- Producer Consumer Problem using Semaphores | Set 1
- Dining Philosopher
  - Using Semaphores
  - Using Monitors
- Readers-Writers Problem
  - Introduction
  - Readers Preference Solution
  - Using Monitors
- Sleeping Barber problem
- Lock variable synchronization mechanism
- Mutex lock for Linux Thread Synchronization
- Priority Inversion : What the heck !
- What’s difference between Priority Inversion and Priority Inheritance ?
- Process Synchronization
- Interprocess Communication: Methods

## Deadlock

- Introduction
- Detection And Recovery
- Deadlock detection algorithm
- Starvation, and Livelock
- Prevention And Avoidance
- Banker’s Algorithm
  - Program for Banker’s Algorithm
  - Print all the safe state (or safe sequences)
- Resource Allocation Graph (RAG)
- Methods of resource allocation to processes by operating system
- Program for Deadlock free condition in Operating System
- Deadlock detection in Distributed systems
- Techniques used in centralized approach of deadlock detection in distributed systems

## Processes & Threads

- Thread
- Threads and its types
- User Level thread Vs Kernel Level thread
- Process-based and Thread-based Multitasking
- Multi threading models
- Benefits of Multithreading
- Zombie Processes and their Prevention
- Maximum number of Zombie process a system can handle
- Remote Procedure call (RPC)

## Memory Management

- Memory Hierarchy Design and its Characteristics
- Introduction to memory and memory units
- Different Types of RAM (Random Access Memory)
- Buddy System: Memory allocation technique
- Partition Allocation Method
- Fixed (or static) Partitioning in Operating System
- Variable (or dynamic) Partitioning in Operating System
- Non-Contiguous Allocation in Operating System
- Logical vs Physical Address in Operating System
- Paging
- Requirements of memory management system
- Mapping virtual address to physical addresses
- Page Table Entries
- Virtual Memory
- Memory Interleaving
- Virtual Memory Questions
- Virtualization
- Inverted Page Table
- Swap Space
- Page Fault Handling
- Fixed (or static) Partitioning in Operating System
- Segmentation
- Memory Segmentation in 8086 Microprocessor
- Program for Next Fit algorithm in Memory Management
- Overlays in Memory Management
- Page Replacement Algorithms
- Program for Page Replacement Algorithms | Set 1 ( LRU)
- Program for Optimal Page Replacement Algorithm
- LFU (Least Frequently Used) Cache Implementation
- Second Chance (or Clock) Page Replacement Policy
- Techniques to handle Thrashing
- Allocating kernel memory (buddy system and slab system)
- Program for buddy memory allocation scheme in Operating Systems |
  - Allocation
  - Deallocation
- Static and Dynamic Libraries
- Working with Shared Libraries
- Named Pipe or FIFO with example C program
- Tracing memory usage in Linux

## Disk Management

- File Systems
- Unix File System
- Implementing Directory Management using Shell Script
- File Directory & Path Name
- Structures of Directory
- File Allocation Methods
- File Access Methods
- Secondary memory
- Disk Scheduling Algorithms
- Program for SSTF disk scheduling algorithm
- What exactly Spooling is all about?
- Difference between Spooling and Buffering
- Free space management

## Misc

- Introduction to UNIX System
- Important Linux Commands (leave, diff, cal, ncal, locate and ln)
- Process states and Transitions in a UNIX Process
- Introduction to Linux Shell and Shell Scripting
- ‘crontab’ in Linux with Examples
- indepth and maxdepth in Linux find() command for limiting search to a specific directory.
