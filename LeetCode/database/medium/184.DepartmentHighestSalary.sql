

select b.name Department, a.name Employee, a.salary Salary
from Employee a
inner join Department b on a.departmentId = b.id
where Salary = 
(select max(c.salary) 
 from Employee c
 inner join Department d on c.departmentId = d.id
 where d.name = b.name);
