# Write your MySQL query statement below
SELECT cur_w.Id
FROM Weather as cur_w
JOIN Weather as pre_w
ON 
    TO_DAYS(cur_w.Date) = TO_DAYS(pre_w.Date) + 1
    AND
    cur_w.Temperature > pre_w.Temperature;
