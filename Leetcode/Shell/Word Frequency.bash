cat words.txt | tr -s "[:blank:]" "\n" | sort | uniq -c | sort -r | awk '{ print $2, $1}'
