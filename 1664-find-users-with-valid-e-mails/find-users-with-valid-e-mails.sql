# Write your MySQL query statement below
SELECT *
FROM Users
WHERE REGEXP_LIKE(mail, '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$', 'c');



-- ^ → Start of the string.
-- [a-zA-Z] → The email must start with an English letter (uppercase or lowercase).
-- [a-zA-Z0-9_.-]* → After the first letter, it can contain:
-- letters (a-z, A-Z)
-- digits (0-9)
-- underscore (_), dot (.), or hyphen (-)
-- * means zero or more occurrences.
-- @leetcode → The domain must literally be @leetcode.
-- [.]com → Escaped dot ([.]) ensures it matches a literal period, followed by com.
-- $ → End of the string.