# Write your MySQL query statement below
-- SELECT
-- D.name AS Department,
-- E.name  AS Employee  ,
-- E.salary AS Salary
-- FROM
-- Department D
-- LEFT JOIN
-- Employee E
-- ON
-- E.id=D.departmentId 
-- GROUP BY D.name
-- HAVING
-- (
--     DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
--     FROM employees
-- ) <= 3;

# Write your MySQL query statement below
SELECT
    D.name AS Department,
    E.name AS Employee,
    E.salary AS Salary
FROM (
    SELECT 
        E.*,
        DENSE_RANK() OVER (
            PARTITION BY departmentId
            ORDER BY salary DESC
        ) AS rnk
    FROM Employee E
) E
JOIN Department D
    ON E.departmentId = D.id
WHERE E.rnk <= 3
ORDER BY D.name, E.salary DESC;

