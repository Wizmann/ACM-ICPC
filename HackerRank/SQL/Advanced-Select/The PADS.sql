SELECT CONCAT(Name, "(", LEFT(Occupation, 1), ")") FROM OCCUPATIONS ORDER BY Name;
SELECT CONCAT("There are total ", COUNT(*), " ", LOWER(Occupation), "s.") FROM OCCUPATIONS GROUP BY Occupation ORDER BY COUNT(*), LOWER(Occupation);
