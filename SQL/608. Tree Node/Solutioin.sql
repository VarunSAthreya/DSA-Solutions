-- Using IF
SELECT id , (IF(p_id IS NULL, 'Root',
IF(id IN (SELECT p_id from Tree), 'Inner', 'Leaf')))
AS type FROM Tree ORDER BY id ASC

-- Using CASE
SELECT id,
CASE WHEN p_id IS NULL THEN 'Root'
     WHEN id IN (SELECT p_id FROM tree) THEN 'Inner'
     ELSE 'Leaf' END AS TYPE
FROM tree
