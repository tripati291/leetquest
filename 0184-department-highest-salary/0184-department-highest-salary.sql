# Write your MySQL query statement below
SELECT d.name as department,
        e.name as Employee,
        e.salary as Salary
FROM (
    SELECT * ,
        RANK() OVER(
            PARTITION BY departmentId
            ORDER BY salary DESC
        ) as rnk
    FROM Employee
) e
JOIN department as d
ON e.departmentId = d.id
WHERE rnk = 1 ;