select event_day day, emp_id, sum(out_time - in_time) total_time
from Employees
group by 1, 2;
