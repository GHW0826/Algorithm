
select employee_id, if (employee_id % 2 = 0 or name like 'M%', 0, salary) bonus
from Employees;
