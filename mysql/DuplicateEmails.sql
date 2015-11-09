 Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+

For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+

Note: All emails are in lowercase.

# 用自连接和DISTINCT
SELECT DISTINCT a.Email FROM Person a
INNER JOIN Person b
WHERE a.Email=b.Email AND a.Id < b.Id
# 用group by
SELECT Email FROM Person GROUP BY Email HAVING count(*)>1
#第三种不懂
Basic idea is this query:

SELECT DISTINCT Email FROM Person MINUS (SELECT Id, Email FROM Person GROUP BY Email)

But since MySQL does not support MINUS, we use LEFT JOIN:

SELECT DISTINCT a.Email FROM Person a LEFT JOIN (SELECT Id, Email from Person GROUP BY Email) b ON (a.email = b.email) AND (a.Id = b.Id) WHERE b.Email IS NULL
