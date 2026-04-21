#!/bin/bash

echo "OS Name:"
uname -o

echo "Kernel Version:"
uname -r

echo "Current User:"
whoami

echo "Current Directory:"
pwd

echo "Top 5 Memory Processes:"
ps -eo pid,cmd,%mem --sort=-%mem | head -6

echo "Logged in users:"
who