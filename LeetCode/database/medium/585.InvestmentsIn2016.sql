# Write your MySQL query statement below
select round(sum(a.tiv_2016), 2) tiv_2016
from Insurance a
where tiv_2015 in (
  select tiv_2015 
  from Insurance b
  where b.pid != a.pid)
and (lat, lon) not in (
  select lat, lon
  from Insurance c
  where c.pid != a.pid
);
