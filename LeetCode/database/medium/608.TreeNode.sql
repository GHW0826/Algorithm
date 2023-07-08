# Write your MySQL query statement below

select a.id, if (a.p_id is null, "Root", 
              if((select count(*) from Tree where p_id in (a.id)) > 0, "Inner", "Leaf")) type
from Tree a
