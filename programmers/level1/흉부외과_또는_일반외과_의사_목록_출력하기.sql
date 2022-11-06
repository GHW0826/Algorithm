SELECT DR_NAME, DR_ID, MCDP_CD, date_format(HIRE_YMD, '%Y-%m-%d')
from DOCTOR
where MCDP_CD in ('CS', 'GS')
order by HIRE_YMD desc, DR_NAME asc;
