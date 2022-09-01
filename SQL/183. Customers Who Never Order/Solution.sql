SELECT A.name as "Customers" from Customers A
WHERE NOT EXISTS (SELECT 1 FROM Orders B WHERE A.id = B.customerid)

SELECT A.name as "Customers" from Customers A
LEFT JOIN Orders B on  a.id = B.customerId
WHERE b.customerId is NULL

SELECT A.name as "Customers" from Customers A
WHERE A.id NOT IN (SELECT B.customerid from Orders B)
