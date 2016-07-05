awk '{
    ave = ($2 + $3 + $4) / 3.0

    if (ave >= 80) 
        print $0 " : A"
    else if (ave >= 60)
        print $0 " : B"
    else
        print $0 " : FAIL"
}'
