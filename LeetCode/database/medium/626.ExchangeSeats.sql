
select if(a.id % 2 = 0, 
        if (exists(select * from Seat b where b.id = a.id - 1), id - 1, id),
        if (exists(select * from Seat c where c.id = a.id + 1), id + 1, id)
        ) id, student
from Seat a
order by id;
