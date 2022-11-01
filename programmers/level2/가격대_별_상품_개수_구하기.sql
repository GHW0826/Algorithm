SELECT truncate(PRICE, -4) PRICE_GROUP, count(*) PRODUCTS
from PRODUCT
group by PRICE_GROUP
order by PRICE_GROUP asc;
