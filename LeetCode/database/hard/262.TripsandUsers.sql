# Write your MySQL query statement below

select request_at Day, round(avg(if (status != "completed", 1, 0)), 2) as 'Cancellation Rate'
from Trips a
where 
    client_id in (select users_id from Users where banned = "No") and
    driver_id in (select users_id from Users where banned = "No") and
    request_at >= '2013-10-01' and request_at <= '2013-10-03'
group by request_at
