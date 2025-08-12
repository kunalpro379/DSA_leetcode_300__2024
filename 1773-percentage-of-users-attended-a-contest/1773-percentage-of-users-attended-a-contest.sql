# Write your MySQL query statement below

-- so here first lets calc distinct users from the Register table for particular contest 
-- SELECT 
-- r.contest_id,
-- r.user_id,
-- COUNT(DISTINCT r.user_id)as cnt
-- FROM Register r
-- GROUP BY r.contest_id

-- now total users from Users table
-- SELECT COUNT(DISTINCT u.user_id) as cnt,
-- u.user_id
-- FROM Users u;

SELECT r.contest_id,
-- ROUND(100* COUNT(DISTINCT r.user_id)/COUNT(DISTINCT u.user_id),2)as percentage
ROUND(100* COUNT(DISTINCT r.user_id)/(SELECT COUNT(DISTINCT user_id) FROM Users),2)as percentage

FROM Register r
LEFT JOIN
Users u
ON u.user_id=r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id ASC;