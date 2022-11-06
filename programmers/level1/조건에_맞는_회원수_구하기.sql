SELECT count(*) USERS
from USER_INFO 
where JOINED >= '2021-01-01' and JOINED < '2022-01-01' and AGE >= 20 and AGE <= 29;
