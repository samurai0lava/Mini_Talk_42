# Mini_Talk_42

## Overview
The purpose of this project is to code a small data exchange program using UNIX signals.

## Setup

### Compilation

#### Compile the server and client programs using the Makefile

make 

#### and for cleaning use fclean and clean

make fclean

## Running the Programs

### 1.Start the server in one terminal:

./server

### 2.Obtain the PID of the server process.
### 3. Start the client in another terminal, replacing <server_pid> with the actual PID of the server process:

./client <server_pid> "message to send"
