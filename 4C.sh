#!/bin/bash

echo "Enter filename:"
read file

echo "Lines: $(wc -l < $file)"
echo "Words: $(wc -w < $file)"
echo "Characters: $(wc -c < $file)"