# Write your MySQL query statement below
-- SELECT
-- E.employee_id,
-- E.name,
-- COUNT(*) AS reports_count,
-- -- ROUND(SUM(E.age)*100/COUNT(E.age),2)  AS average_age
-- ROUND(AVG(J.age)) AS average_age
-- FROM Employees  E
-- RIGHT JOIN
-- Employees  J
-- ON(J.reports_to=E.employee_id)
-- WHERE J.reports_to IS NOT NULL
-- GROUP BY employee_id

SELECT
    E.employee_id,
    E.name,
    COUNT(*) AS reports_count,
    ROUND(AVG(J.age)) AS average_age
FROM Employees AS E
JOIN Employees AS J
  ON J.reports_to = E.employee_id
GROUP BY E.employee_id, E.name
ORDER BY E.employee_id;