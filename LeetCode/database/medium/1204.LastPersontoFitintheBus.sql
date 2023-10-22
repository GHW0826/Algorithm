# Write your MySQL query statement below

select person_name
from (
    select person_name, sum(weight) over(order by turn) accWeight
    from queue
) t
where accWeight <= 1000
order by accWeight desc limit 1;
