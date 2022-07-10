SELECT ANIMAL_TYPE, count(*) count
from animal_ins
group by ANIMAL_TYPE
order by ANIMAL_TYPE;
