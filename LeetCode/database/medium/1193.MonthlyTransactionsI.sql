# Write your MySQL query statement below

select date_format(trans_date,'%Y-%m') month, country, 
count(*) trans_count , sum(state = 'approved') approved_count, 
sum(amount) trans_total_amount, sum(if (state = 'approved', amount, 0)) approved_total_amount 
from Transactions
group by country, year(trans_date), month(trans_date);
