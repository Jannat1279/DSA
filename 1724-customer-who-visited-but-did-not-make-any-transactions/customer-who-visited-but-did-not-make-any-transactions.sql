# Write your MySQL query statement below
select v.customer_id, count(v.visit_id) as count_no_trans
from visits v
left join transactions t
on v.visit_id=t.visit_id
where t.transaction_id is NULL
group by v.customer_id;


-- from visits v
-- We start with the visits table because every visit (with or without a transaction) must be considered.
-- left join transactions t on v.visit_id = t.visit_id
-- We join the transactions table to visits.
-- LEFT JOIN ensures we keep all rows from visits — if no transaction exists for a visit, the transaction columns become NULL.
-- where t.transaction_id is NULL
-- This filters out visits that actually had transactions.
-- We only keep rows where no matching transaction exists.
-- group by v.customer_id
-- Since a customer can have multiple visits, we group by customer_id.
-- count(v.visit_id) counts how many of their visits had no transactions.
-- as count_no_trans
-- Renames the column to clearly indicate it’s the count of visits without transactions.