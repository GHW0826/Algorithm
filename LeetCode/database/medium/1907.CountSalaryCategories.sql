# Write your MySQL query statement below


select "High Salary" category, count(*) accounts_count 
from Accounts
where income > 50000
union all
select "Low Salary" category, count(*) accounts_count 
from Accounts
where income < 20000
union all
select "Average Salary" category, count(*) accounts_count 
from Accounts
where income >= 20000 and income <= 50000;
