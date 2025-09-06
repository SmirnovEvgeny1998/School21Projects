-- DROP table if EXISTS Peers, Tasks, Checks, P2P, Verter, TransferredPoints, Friends, Recommendations, XP, TimeTracking, Peers_import;
-- DROP type if EXISTS v$Check;

create table Peers
( Nickname varchar primary key not null,
  Birthday date not null
  );

insert into Peers values ('burnerwa', '1998-12-14');
insert into Peers values ('margertf', '2001-02-22');
insert into Peers values ('clamsmil', '1997-06-10');
insert into Peers values ('rightspo', '2002-09-23');
insert into Peers values ('zulemaka', '1995-01-01');
insert into Peers values ('serpenat', '1895-01-01');

create table Tasks
( Title varchar primary key not null,
  ParentTask varchar,
  MaxXP bigint not null,
  constraint fk_tasks_parent_task foreign key (ParentTask) references Tasks(Title)
  );

insert into Tasks values ('CI1_SimpleBashUtils', NULL, 250);
insert into Tasks values ('CI2_s21_string+', 'CI1_SimpleBashUtils', 500);
insert into Tasks values ('CI3_s21_math', 'CI1_SimpleBashUtils', 300);
insert into Tasks values ('CI4_s21_decimal', 'CI2_s21_string+', 350);
insert into Tasks values ('CI5_s21_matrix', 'CI4_s21_decimal', 200);
insert into Tasks values ('SQL1', NULL, 1500);
insert into Tasks values ('SQL2', 'SQL1', 500);
insert into Tasks values ('SQL3', 'SQL2', 600);

create table Checks
( ID SERIAL primary key not null,
  Peer varchar not null,
  Task varchar not null,
  Date date not null,
  constraint fk_checks_peer foreign key (Peer) references Peers(Nickname),
  constraint fk_checks_task foreign key (Task) references Tasks(Title)
  );

insert into Checks values (DEFAULT, 'burnerwa', 'CI1_SimpleBashUtils', '2023-12-14');
insert into Checks values (DEFAULT, 'burnerwa', 'CI2_s21_string+', '2023-07-01');
insert into Checks values (DEFAULT, 'rightspo', 'CI1_SimpleBashUtils', '2023-09-23');
insert into Checks values (DEFAULT, 'clamsmil', 'CI1_SimpleBashUtils', '2023-07-12');
insert into Checks values (DEFAULT, 'zulemaka', 'CI1_SimpleBashUtils', '2023-10-18');
insert into Checks values (DEFAULT, 'burnerwa', 'CI2_s21_string+', '2023-11-01');
insert into Checks values (DEFAULT, 'rightspo', 'CI1_SimpleBashUtils', '2023-11-13');
insert into Checks values (DEFAULT, 'clamsmil', 'CI1_SimpleBashUtils', '2023-11-12');
insert into Checks values (DEFAULT, 'zulemaka', 'CI1_SimpleBashUtils', '2023-11-18');
insert into Checks values (DEFAULT, 'zulemaka', 'CI2_s21_string+', '2023-11-30');
insert into Checks values (DEFAULT, 'rightspo', 'CI3_s21_math', '2023-11-30');
insert into Checks values (DEFAULT, 'clamsmil', 'CI3_s21_math', '2023-11-30');
insert into Checks values (DEFAULT, 'burnerwa', 'CI4_s21_decimal', '2023-12-14');
insert into Checks values (DEFAULT, 'burnerwa', 'CI5_s21_matrix', '2023-11-11');
insert into Checks values (DEFAULT, 'margertf', 'SQL1', '2023-11-12');
insert into Checks values (DEFAULT, 'burnerwa', 'SQL1', '2023-11-12');

create type v$Check AS enum ('Start', 'Success', 'Failure');

create table P2P
( ID SERIAL primary key not null,
  v$Check bigint not null,
  CheckingPeer varchar not null,
  State v$Check not null,
  Time time not null,
  constraint fk_p2p_checking_peer foreign key (CheckingPeer) references Peers(Nickname),
  constraint fk_p2p_check foreign key (v$Check) references Checks(ID)
  );

insert into P2P values (DEFAULT, 1, 'zulemaka', 'Start', '10:23:54');
insert into P2P values (DEFAULT, 1, 'zulemaka', 'Success', '11:03:54');
insert into P2P values (DEFAULT, 2, 'zulemaka', 'Start', '11:23:54');
insert into P2P values (DEFAULT, 2, 'zulemaka', 'Failure', '12:03:54');
insert into P2P values (DEFAULT, 3, 'burnerwa', 'Start', '13:23:54');
insert into P2P values (DEFAULT, 3, 'burnerwa', 'Failure', '15:03:54');
insert into P2P values (DEFAULT, 4, 'rightspo', 'Start', '03:22:56');
insert into P2P values (DEFAULT, 4, 'rightspo', 'Success', '12:03:24');
insert into P2P values (DEFAULT, 5, 'margertf', 'Start', '13:43:44');
insert into P2P values (DEFAULT, 5, 'margertf', 'Failure', '13:57:24');
insert into P2P values (DEFAULT, 6, 'zulemaka', 'Start', '12:23:54');
insert into P2P values (DEFAULT, 6, 'zulemaka', 'Success', '13:03:54');
insert into P2P values (DEFAULT, 7, 'burnerwa', 'Start', '14:23:54');
insert into P2P values (DEFAULT, 7, 'burnerwa', 'Success', '16:03:54');
insert into P2P values (DEFAULT, 8, 'rightspo', 'Start', '04:22:56');
insert into P2P values (DEFAULT, 8, 'rightspo', 'Success', '13:03:24');
insert into P2P values (DEFAULT, 9, 'margertf', 'Start', '14:43:44');
insert into P2P values (DEFAULT, 9, 'margertf', 'Success', '14:57:24');
insert into P2P values (DEFAULT, 10, 'burnerwa', 'Start', '14:43:44');
insert into P2P values (DEFAULT, 10, 'burnerwa', 'Success', '14:57:24');
insert into P2P values (DEFAULT, 11, 'burnerwa', 'Start', '15:43:44');
insert into P2P values (DEFAULT, 11, 'burnerwa', 'Success', '15:57:24');
insert into P2P values (DEFAULT, 12, 'burnerwa', 'Start', '16:43:44');
insert into P2P values (DEFAULT, 12, 'burnerwa', 'Success', '16:57:24');
insert into P2P values (DEFAULT, 13, 'zulemaka', 'Start', '16:43:44');
insert into P2P values (DEFAULT, 13, 'zulemaka', 'Success', '16:57:24');
insert into P2P values (DEFAULT, 14, 'zulemaka', 'Start', '17:43:44');
insert into P2P values (DEFAULT, 14, 'zulemaka', 'Success', '17:57:24');
insert into P2P values (DEFAULT, 15, 'zulemaka', 'Start', '11:43:44');
insert into P2P values (DEFAULT, 15, 'zulemaka', 'Success', '11:57:24');
insert into P2P values (DEFAULT, 16, 'zulemaka', 'Start', '12:43:44');
insert into P2P values (DEFAULT, 16, 'zulemaka', 'Success', '12:57:24');

create table Verter
( ID SERIAL primary key not null,
  v$Check bigint not null,
  State v$Check not null,
  Time time not null,
  constraint fk_verter_check foreign key (v$Check) references Checks(ID)
  );

insert into Verter values (DEFAULT, 1, 'Start', '11:03:55');
insert into Verter values (DEFAULT, 1, 'Success', '11:03:59');
insert into Verter values (DEFAULT, 2, 'Start', '12:03:55');
insert into Verter values (DEFAULT, 2, 'Failure', '12:03:59');
insert into Verter values (DEFAULT, 4, 'Start', '12:03:25');
insert into Verter values (DEFAULT, 4, 'Failure', '12:03:59');
insert into Verter values (DEFAULT, 6, 'Start', '13:03:54');
insert into Verter values (DEFAULT, 6, 'Success', '13:03:59');
insert into Verter values (DEFAULT, 7, 'Start', '16:03:54');
insert into Verter values (DEFAULT, 7, 'Success', '16:03:59');
insert into Verter values (DEFAULT, 8, 'Start', '13:03:24');
insert into Verter values (DEFAULT, 8, 'Success', '13:03:44');
insert into Verter values (DEFAULT, 9, 'Start', '14:57:24');
insert into Verter values (DEFAULT, 9, 'Success', '14:57:34');
insert into Verter values (DEFAULT, 10, 'Start', '14:57:24');
insert into Verter values (DEFAULT, 10, 'Success', '14:57:34');
insert into Verter values (DEFAULT, 11, 'Start', '15:57:24');
insert into Verter values (DEFAULT, 11, 'Failure', '15:57:34');
insert into Verter values (DEFAULT, 12, 'Start', '16:57:24');
insert into Verter values (DEFAULT, 12, 'Success', '16:57:34');
insert into Verter values (DEFAULT, 13, 'Start', '16:57:24');
insert into Verter values (DEFAULT, 13, 'Success', '16:57:34');
insert into Verter values (DEFAULT, 14, 'Start', '17:57:24');
insert into Verter values (DEFAULT, 14, 'Success', '17:57:34');
insert into Verter values (DEFAULT, 15, 'Start', '11:57:24');
insert into Verter values (DEFAULT, 15, 'Success', '11:57:34');
insert into Verter values (DEFAULT, 16, 'Start', '12:57:24');
insert into Verter values (DEFAULT, 16, 'Success', '12:57:34');

create table TransferredPoints
( ID SERIAL primary key not null,
  CheckingPeer varchar not null,
  CheckedPeer varchar not null,
  PointsAmount bigint not null,
  constraint fk_transferred_points_checking_peer foreign key (CheckingPeer) references Peers(Nickname),
  constraint fk_transferred_points_checked_peer foreign key (CheckedPeer) references Peers(Nickname)
  );

insert into TransferredPoints values (DEFAULT, 'zulemaka', 'burnerwa', 6);
insert into TransferredPoints values (DEFAULT, 'burnerwa', 'rightspo', 3);
insert into TransferredPoints values (DEFAULT, 'rightspo', 'clamsmil', 2);
insert into TransferredPoints values (DEFAULT, 'margertf', 'zulemaka', 2);
insert into TransferredPoints values (DEFAULT, 'burnerwa', 'zulemaka', 1);
insert into TransferredPoints values (DEFAULT, 'burnerwa', 'clamsmil', 1);
insert into TransferredPoints values (DEFAULT, 'zulemaka', 'margertf', 1);

create table Friends
( ID SERIAL primary key not null,
  Peer1 varchar not null,
  Peer2 varchar not null,
  constraint fk_friends_peer_1 foreign key (Peer1) references Peers(Nickname),
  constraint fk_friends_peer_2 foreign key (Peer2) references Peers(Nickname)
  );

insert into Friends values (DEFAULT, 'burnerwa', 'rightspo');
insert into Friends values (DEFAULT, 'zulemaka', 'rightspo');
insert into Friends values (DEFAULT, 'margertf', 'rightspo');
insert into Friends values (DEFAULT, 'clamsmil', 'burnerwa');
insert into Friends values (DEFAULT, 'clamsmil', 'zulemaka');

create table Recommendations
( ID SERIAL primary key not null,
  Peer varchar not null,
  RecommendedPeer varchar not null,
  constraint fk_recommendations_peer foreign key (Peer) references Peers(Nickname),
  constraint fk_recommendations_recommended_peer foreign key (RecommendedPeer) references Peers(Nickname)
  );

insert into Recommendations values (DEFAULT, 'burnerwa', 'rightspo');
insert into Recommendations values (DEFAULT, 'burnerwa', 'zulemaka');
insert into Recommendations values (DEFAULT, 'burnerwa', 'clamsmil');
insert into Recommendations values (DEFAULT, 'clamsmil', 'burnerwa');
insert into Recommendations values (DEFAULT, 'rightspo', 'clamsmil');
insert into Recommendations values (DEFAULT, 'rightspo', 'zulemaka');
insert into Recommendations values (DEFAULT, 'rightspo', 'burnerwa');

create table XP
( ID SERIAL primary key not null,
  v$Check bigint not null,
  XPAmount bigint not null,
  constraint fk_xp_check foreign key (v$Check) references Checks(ID)
  );

insert into XP values (DEFAULT, 1, 250);
insert into XP values (DEFAULT, 6, 454);
insert into XP values (DEFAULT, 7, 230);
insert into XP values (DEFAULT, 8, 230);
insert into XP values (DEFAULT, 9, 250);
insert into XP values (DEFAULT, 10, 350);
insert into XP values (DEFAULT, 12, 300);
insert into XP values (DEFAULT, 13, 200);
insert into XP values (DEFAULT, 14, 200);
insert into XP values (DEFAULT, 15, 1500);
insert into XP values (DEFAULT, 16, 1300);

create table TimeTracking
( ID SERIAL primary key not null,
  Peer varchar not null,
  Date date not null,
  Time time not null,
  State bigint not null,
  constraint fk_time_tracking_peer foreign key (Peer) references Peers(Nickname),
  constraint ch_state check (State between 1 and 2)
  );

insert into TimeTracking values (DEFAULT, 'burnerwa', '2023-11-23', '16:28:25', 1);
insert into TimeTracking values (DEFAULT, 'burnerwa', '2023-11-23', '21:55:55', 2);
insert into TimeTracking values (DEFAULT, 'margertf', '2023-11-23', '17:28:25', 1);
insert into TimeTracking values (DEFAULT, 'margertf', '2023-11-23', '21:55:55', 2);
insert into TimeTracking values (DEFAULT, 'rightspo', '2023-11-25', '13:18:15', 1);
insert into TimeTracking values (DEFAULT, 'rightspo', '2023-11-26', '01:30:33', 2);

create or replace procedure import_csv(
  table_name text,
  files_name text,
  separator text
)
language plpgsql    
as $$
declare
    request text;
begin
    request := FORMAT(
            'COPY %s FROM %L WITH (FORMAT CSV, HEADER, DELIMITER %L)',
            table_name,
            files_name,
            separator
        );
    EXECUTE request;
end;$$;

create or replace procedure export_csv(
  table_name text,
  files_name text,
  separator text
)
language plpgsql    
as $$
declare
    request text;
begin
    request := FORMAT(
            'COPY %s TO %L WITH (FORMAT CSV, HEADER, DELIMITER %L)',
            table_name,
            files_name,
            separator
        );
    EXECUTE request;
end;$$;

-- call export_csv('Peers', '/Users/burnerwa/SQL2_Info21_v1.0-1/src/peers.csv', ',');

create table Peers_import
( Nickname varchar primary key,
  Birthday date
  );

-- call import_csv('Peers_import', '/Users/burnerwa/SQL2_Info21_v1.0-1/src/peers.csv', ',');

-- SELECT * from Peers_import;


