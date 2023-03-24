SELECT id, name
FROM departments
WHERE
  id in ( SELECT department_id FROM sales WHERE price > 98.00 )
