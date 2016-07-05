awk '{
    ave = ($2 + $3 + $4) / 3.0
    if (ave >= 60)
        print $1 " : Pass"
    else
        print $1 " : Fail"
}'
