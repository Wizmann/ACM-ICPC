read n
awk '{ total += $0; count++ } END { printf("%.3f", total/count) }'