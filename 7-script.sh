#!/bin/bash

echo "Top 5 Processes using Highest Memory:"
ps -eo pid,ppid,cmd,%mem --sort=-%mem | head -6

echo ""
echo "Currently Logged-in Users:"
who