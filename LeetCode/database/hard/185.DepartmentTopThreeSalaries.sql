
select b.name Department, a.name Employee, a.salary Salary
from Employee a
inner join Department b on a.departmentId = b.id
where (
    select count(distinct salary)
    from Employee
    where departmentId = a.departmentId  and salary > a.salary
) < 3;
