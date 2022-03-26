
select a.name, b.balance
from Users a
inner join (select account, sum(amount) balance from Transactions group by account) b
on a.account = b.account
where b.balance > 10000;
