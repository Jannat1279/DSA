# Write your MySQL query statement below
select e.name, b.bonus
from employee e
left join bonus b
on e.empId=b.empId
where b.bonus<1000
|| b.bonus is null;


-- from employee e
-- We start with the employee table, since we need to show all employees.
-- left join bonus b on e.empId = b.empId
-- We join the bonus table to employee.
-- LEFT JOIN is crucial: it ensures that employees without a bonus record still appear in the results (their bonus will show as NULL).
-- where b.bonus < 1000 or b.bonus is null

-- This filters the result:
-- If an employee has a bonus, keep them only if it’s less than 1000.
-- If an employee has no bonus record, b.bonus becomes NULL, and they are included because of OR b.bonus is null.
-- select e.name, b.bonus

-- Finally, we output the employee’s name and their bonus amount (or NULL if no bonus exists).