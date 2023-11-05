# Write your MySQL query statement below

select *
from (
  select b.name results
  from MovieRating a
  inner join Users b on a.user_id = b.user_id
  group by a.user_id
  order by count(*) desc, b.name asc limit 1
) t
union all
select *
from (
  select d.title results
  from MovieRating c
  inner join Movies d on c.movie_id = d.movie_id
  where c.created_at >= "2020-02-01" and c.created_at < "2020-03-01"
  group by c.movie_id
  order by avg(c.rating) desc, d.title asc limit 1
) t2;
