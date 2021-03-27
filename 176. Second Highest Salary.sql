with h(a) as(
    select max(salary) from Employee
)
--select * from h
select max(salary) as SecondHighestSalary from Employee where salary not in(select top(1) a from h);
