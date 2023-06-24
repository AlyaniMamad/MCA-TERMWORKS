create table supplier (
    sid varchar(6) primary key check (sid like 'S%'),
    s_name varchar(20),
    address varchar(50)
);

create table parts(
    pid varchar(6) primary key check (pid like 'P%'),
    pname varchar(20),
    color varchar(15)
);

create table catalogue(
    sid varchar(6),
    pid varchar(6),
    cost decimal(8,2),
    foreign key(sid) references supplier(sid),
    foreign key(pid) references parts(pid)
);

insert into supplier values('S1','Suresh','Hyderabad');
insert into supplier values('S2','Kiran','Delhi');
insert into supplier values('S3','Mohan','');
insert into supplier values('S4','Ramesh','Banglore');
insert into supplier values('S5','Manish','Mumbai');
insert into supplier values('S6','Srikanth','chennai');
insert into supplier values('S7','rakesh','');

INSERT INTO parts VALUES ('P1','Bonnet','Red'),
('P2','Hood','Yellow'),
('P3','Decklid','Blue'),
('P4','Screen','Pink'),
('P5','Fascia','Maroon');

INSERT INTO catalogue VALUES ('S1','P1',1000),
('S1','P2',400),
('S1','P3',600),
('S1','P4',1500),
('S1','P5',100),
('S3','P5',100),
('S3','P2',400),
('S4','P1',1000),
('S5','P3',600),
('S5','P1',1000);


QUERIES : -

1) select * from supplier where s_name like 'S%';

+-----+----------+-----------+
| sid | s_name   | address   |
+-----+----------+-----------+
| S1  | Suresh   | Hyderabad |
| S6  | Srikanth | chennai   |
+-----+----------+-----------+

2) select * from supplier where address="";

+-----+--------+---------+
| sid | s_name | address |
+-----+--------+---------+
| S3  | Mohan  |         |
| S7  | rakesh |         |
+-----+--------+---------+

3) select s_name from supplier where sid in(select sid from catalogue where pid in(select pid from parts where color='red'));

+--------+
| s_name |
+--------+
| Suresh |
| Ramesh |
| Manish |
+--------+

4)  select pname from parts where pid =(select pid from catalogue where cost =(Select MAX(cost) from catalogue));

+--------+
| pname  |
+--------+
| Screen |
+--------+

5)  select sum(cost) from catalogue where pid in(select pid from parts where pid in(select pid from parts where color='red'));

+-----------+
| sum(cost) |
+-----------+
|   3000.00 |
+-----------+

6) select pname from parts where pid in(select pid from catalogue
 where
sid in(select sid from supplier where s_name='rakesh'));

-->Empty set (0.00 sec)

7) select pid,sum(cost) as total from catalogue group by pid having total>2000;

+------+---------+
| pid  | total   |
+------+---------+
| P1   | 3000.00 |
+------+---------+

8) update catalogue set cost=cost+200 where sid='s1';

-->Query OK, 5 rows affected (0.00 sec)
-->Rows matched: 5  Changed: 5  Warnings: 0

 select * from catalogue where sid='s1';
+------+------+---------+
| sid  | pid  | cost    |
+------+------+---------+
| S1   | P1   | 1200.00 |
| S1   | P2   |  600.00 |
| S1   | P3   |  800.00 |
| S1   | P4   | 1700.00 |
| S1   | P5   |  300.00 |
+------+------+---------+

9) delimiter $$
    create procedure proc1(in pname varchar(20),out totalcost varchar(10))
        begin
        select sum(c1.cost) as totalcost from catalogue c1,parts p1 where c1.pid=p1.pid and p1.pname=pname;
        end $$

-->        Query OK, 0 rows affected (0.01 sec)
    
    delimiter ;

call proc1('Bonnet',@totalcost);

+-----------+
| totalcost |
+-----------+
|   3200.00 |
+-----------+

10) delimiter $$

    create function myfun(color varchar(100))
    returns varchar(100)
    DETERMINISTIC
    begin
	    declare res varchar(100);
	    select s1.s_name into res from supplier s1,parts p1,catalogue c1 where c1.sid=s1.sid and c1.pid=p1.pid and p1.color=color;
	    return (res);
    end $$

-->    Query OK, 0 rows affected (0.00 sec)

    delimiter ;

select myfun('Pink');

+---------------+
| myfun('Pink') |
+---------------+
| Suresh        |
+---------------+

select myfun('Yellow');

ERROR 1172 (42000): Result consisted of more than one row 

select c1.cost p1.pname from catalogue c1 , parts p1 where c1.pid=c1.pname;


select c.cost,p.pname from parts p,catalogue c where c.pid=p.pid; --and c1.pid=p1.pid and p1.color=color;
