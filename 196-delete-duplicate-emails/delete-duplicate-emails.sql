# Write your MySQL query statement below
delete p1 
from person p1
inner join person p2
on p1.email=p2.email
and p1.id>p2.id

-- Think of INNER JOIN as saying:
-- "Show me only the people who are duplicates, not everyone else."