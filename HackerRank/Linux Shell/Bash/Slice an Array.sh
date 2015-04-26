i=0
while read arr[$i]; do
    i=$(( i + 1))
done
echo ${arr[@]:3:5}