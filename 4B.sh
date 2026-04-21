echo -e "5\n1\n9\n3\n7\n2\n8\n6\n4\n0" > nums.txt

sort nums.txt

echo "Top 3:"
sort -nr nums.txt | head -3