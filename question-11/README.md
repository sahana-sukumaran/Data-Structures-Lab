Problem statement:
An operating system allocates a fixed time slot CPU time for processes using a round-robin scheduling algorithm. The fixed time slot will be initialized before the start of the menu-driven program. Implement the round-robin scheduling algorithm using the circular linked list.
Implement the program by including the appropriate header file. It consists of the following operations.
1. Insert Process
2. Execute
3. Exit
The "Insert Process" will get an integer time from the user and add it to the queue.
The "Execute" operation will execute a deletion in the beginning operation and subtract the fixed time from the process. If the processing time falls below 0 then the process is considered to have completed its execution, otherwise, the remaining time after subtraction is inserted at the end of the circular linked list.
