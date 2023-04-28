

select distinct(a.num) ConsecutiveNums 
from Logs a
inner join Logs b on b.id = a.id - 1
inner join Logs c on c.id = a.id - 2
where a.num = b.num and b.num = c.num;
