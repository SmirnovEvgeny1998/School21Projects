-- 1)
begin;
select * FROM Checks;
select * FROM P2P;

call add_P2P_check ('clamsmil', 'burnerwa', 'SQL1', 'Start', '20:00:00');

select * FROM Checks;
select * FROM P2P;

call add_P2P_check ('clamsmil', 'burnerwa', 'SQL1', 'Success', '21:00:00');
call add_P2P_check('clamsmil', 'burnerwa', 'CI4_s21_decimal', 'Start', '22:00:00');
call add_P2P_check('clamsmil', 'burnerwa', 'CI4_s21_decimal', 'Success', '22:00:01');

select * FROM Checks;
select * FROM P2P;

-- 2)

-- call add_Verter_check ('clamsmil' , 'SQL1', 'Success' , '21:01:00');
-- call add_Verter_check ('clamsmil' , 'CI4_s21_decimal', 'Success' , '22:01:00');

-- select * from Verter;

-- -- 3)

-- select * from TransferredPoints where CheckingPeer = 'rightspo' and CheckedPeer = 'clamsmil';

-- call add_P2P_check('clamsmil', 'rightspo', 'CI4_s21_decimal', 'Start', '23:00:00');

-- select * from TransferredPoints where CheckingPeer = 'rightspo' and CheckedPeer = 'clamsmil';

-- -- 4)
commit