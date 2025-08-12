# Write your MySQL query statement below


-- SELECT R.product_id,R.first_year,L.quantity,L.price
-- FROM
-- Sales as L
-- RIGHT JOIN
-- (
-- SELECT product_id, MIN(year) AS first_year
-- FROM Sales
-- GROUP BY product_id;
-- AS R
-- )
-- ON((L.product_id=R.product_id)&&(L.year=R.first_year));
SELECT 
    R.product_id,
    R.first_year,
    L.quantity,
    L.price
FROM Sales AS L
RIGHT JOIN (
    SELECT 
        product_id, 
        MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
) AS R
ON L.product_id = R.product_id 
   AND L.year = R.first_year;

/*

+---------+------------+------+----------+-------+
| sale_id | product_id | year | quantity | price |
+---------+------------+------+----------+-------+
| 1       | 100        | 2008 | 10       | 5000  |
| 2       | 100        | 2009 | 12       | 5000  |
| 7       | 200        | 2011 | 15       | 9000  |
+---------+------------+------+----------+-------+
SELECT product_id, MIN(year) AS first_year
FROM Sales
GROUP BY product_id;
+------------+------------+
| product_id | first_year |
+------------+------------+
| 100        | 2008       |
| 200        | 2011       |
+------------+------------+


Ouptut
+------------+------------+----------+-------+
| product_id | first_year | quantity | price |
+------------+------------+----------+-------+
| 100        | 2008       | 10       | 5000  |
| 200        | 2011       | 15       | 9000  |
+------------+------------+----------+-------+



*/