
select MCDP_CD 진료과코드, count(*) 5월예약건수
from APPOINTMENT
where APNT_YMD >= '2022-05-01' and APNT_YMD < '2022-06-01'
group by MCDP_CD
order by count(*) asc, MCDP_CD asc;
