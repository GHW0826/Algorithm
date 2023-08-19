# Write your MySQL query statement below

select a.product_id, a.year first_year, a.quantity, a.price
from Sales a
inner join Product b on a.product_id = b.product_id
where (a.product_id, a.year) in 
(select c.product_id, min(year) from Sales c group by c.product_id);
