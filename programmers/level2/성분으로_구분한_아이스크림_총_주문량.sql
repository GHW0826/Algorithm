SELECT 'sugar_based' INGREDIENT_TYPE, sum(TOTAL_ORDER) TOTAL_ORDER
from FIRST_HALF a
inner join ICECREAM_INFO b on a.FLAVOR = b.FLAVOR
where INGREDIENT_TYPE = 'sugar_based'
union
SELECT 'fruit_based' INGREDIENT_TYPE, sum(TOTAL_ORDER) TOTAL_ORDER
from FIRST_HALF a
inner join ICECREAM_INFO b on a.FLAVOR = b.FLAVOR
where INGREDIENT_TYPE = 'fruit_based';
