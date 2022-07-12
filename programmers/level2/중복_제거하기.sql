SELECT count(*)
from (select name from animal_ins where name is not null group by name) b
