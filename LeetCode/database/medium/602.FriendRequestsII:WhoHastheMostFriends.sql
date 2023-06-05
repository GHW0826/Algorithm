# Write your MySQL query statement below
select a.id, sum(a.cnt) num
from (
  select requester_id id, count(*) cnt
  from RequestAccepted
  group by requester_id
  union all
  select accepter_id id, count(*) cnt
  from RequestAccepted
  group by accepter_id
) a
group by a.id
order by sum(cnt) desc limit 1;
