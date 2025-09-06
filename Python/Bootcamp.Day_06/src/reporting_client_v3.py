import pydantic
import grpc
from reporting_pb2_grpc import ShipsListStub
from reporting_pb2 import CoordinatesRequest
import argparse
from peewee import *

parser = argparse.ArgumentParser()
parser.add_argument("--scan", "-s", type=float, nargs="+")
parser.add_argument("--list_traitors", "-l", action="store_true")
args = parser.parse_args()

if args.scan != None and len(args.scan) != 6:
    print("Coordinates in wrong form, need to be six numbers")
    exit()

#db = SqliteDatabase('ships.db')
db = PostgresqlDatabase('my_app', user='postgres', password='secret', host='127.0.0.1', port=5432)


class Ship(Model):
    db_alignment = CharField()
    db_name = CharField()
    db_class = CharField()
    db_length = FloatField()
    db_crew_size = IntegerField()
    db_armed = BooleanField()

    class Meta:
        database = db


class CrewMember(Model):
    db_first_name = CharField()
    db_last_name = CharField()
    db_rank = CharField()
    db_ship_of_service = ForeignKeyField(Ship, related_name='db_crew_members')

    class Meta:
        database = db


class Corvette(pydantic.BaseModel):
    length: pydantic.confloat(gt=79, lt=251)
    crew: pydantic.conint(gt=3, lt=11)


class Frigate(pydantic.BaseModel):
    length: pydantic.confloat(gt=299, lt=601)
    crew: pydantic.conint(gt=9, lt=16)
    enemy: pydantic.conint(gt=0, lt=2)


class Cruiser(pydantic.BaseModel):
    length: pydantic.confloat(gt=499, lt=1001)
    crew: pydantic.conint(gt=14, lt=31)


class Destroyer(pydantic.BaseModel):
    length: pydantic.confloat(gt=799, lt=2001)
    crew: pydantic.conint(gt=49, lt=81)
    enemy: pydantic.conint(gt=0, lt=2)


class Carrier(pydantic.BaseModel):
    length: pydantic.confloat(gt=999, lt=4001)
    crew: pydantic.conint(gt=119, lt=251)
    armed: pydantic.conint(gt=1, lt=3)


class Dreadnought(pydantic.BaseModel):
    length: pydantic.confloat(gt=4999, lt=20001)
    crew: pydantic.conint(gt=299, lt=501)


if args.scan != None:
    Ship.drop_table()
    CrewMember.drop_table()
    Ship.create_table()
    CrewMember.create_table()
    channel = grpc.insecure_channel("localhost:50051")
    client = ShipsListStub(channel)
    request = CoordinatesRequest(
        asc_hour=args.scan[0], asc_min=args.scan[1], asc_sec=args.scan[2],
        dec_fir=args.scan[3], dec_sec=args.scan[4], dec_thi=args.scan[5]
    )
    all = client.ReturnShips(request)

    for unit in all.ship:
        validation = {
            'type': unit.classs,
            'length': unit.length,
            'crew': unit.crew_size,
            'armed': unit.armed,
            'enemy': unit.alignment
        }
        try:
            if validation['type'] == 1:
                valid_result = Corvette(**validation)
                print(unit)
                temp = Ship.create(db_alignment=unit.alignment,
                                   db_name=unit.name,
                                   db_class="Corvette",
                                   db_length=unit.length,
                                   db_crew_size=unit.crew_size,
                                   db_armed=unit.armed)
                for officer in unit.oficer_crew:
                    CrewMember.create(db_first_name=officer.firstName,
                                      db_last_name=officer.lastName,
                                      db_rank=officer.rank,
                                      db_ship_of_service=temp)
            elif validation['type'] == 2:
                valid_result = Frigate(**validation)
                print(unit)
                temp = Ship.create(db_alignment=unit.alignment,
                                   db_name=unit.name,
                                   db_class="Frigate",
                                   db_length=unit.length,
                                   db_crew_size=unit.crew_size,
                                   db_armed=unit.armed)
                for officer in unit.oficer_crew:
                    CrewMember.create(db_first_name=officer.firstName,
                                      db_last_name=officer.lastName,
                                      db_rank=officer.rank,
                                      db_ship_of_service=temp)
            elif validation['type'] == 3:
                valid_result = Cruiser(**validation)
                print(unit)
                temp = Ship.create(db_alignment=unit.alignment,
                                   db_name=unit.name,
                                   db_class="Cruiser",
                                   db_length=unit.length,
                                   db_crew_size=unit.crew_size,
                                   db_armed=unit.armed)
                for officer in unit.oficer_crew:
                    CrewMember.create(db_first_name=officer.firstName,
                                      db_last_name=officer.lastName,
                                      db_rank=officer.rank,
                                      db_ship_of_service=temp)
            elif validation['type'] == 4:
                valid_result = Destroyer(**validation)
                print(unit)
                temp = Ship.create(db_alignment=unit.alignment,
                                   db_name=unit.name,
                                   db_class="Destroyer",
                                   db_length=unit.length,
                                   db_crew_size=unit.crew_size,
                                   db_armed=unit.armed)
                for officer in unit.oficer_crew:
                    CrewMember.create(db_first_name=officer.firstName,
                                      db_last_name=officer.lastName,
                                      db_rank=officer.rank,
                                      db_ship_of_service=temp)
            elif validation['type'] == 5:
                valid_result = Carrier(**validation)
                print(unit)
                temp = Ship.create(db_alignment=unit.alignment,
                                   db_name=unit.name,
                                   db_class="Carrier",
                                   db_length=unit.length,
                                   db_crew_size=unit.crew_size,
                                   db_armed=unit.armed)
                for officer in unit.oficer_crew:
                    CrewMember.create(db_first_name=officer.firstName,
                                      db_last_name=officer.lastName,
                                      db_rank=officer.rank,
                                      db_ship_of_service=temp)
            elif validation['type'] == 6:
                valid_result = Dreadnought(**validation)
                print(unit)
                temp = Ship.create(db_alignment=unit.alignment,
                                   db_name=unit.name,
                                   db_class="Dreadnought",
                                   db_length=unit.length,
                                   db_crew_size=unit.crew_size,
                                   db_armed=unit.armed)
                for officer in unit.oficer_crew:
                    CrewMember.create(db_first_name=officer.firstName,
                                      db_last_name=officer.lastName,
                                      db_rank=officer.rank,
                                      db_ship_of_service=temp)
        except ValueError as e:
            #print(e.errors())
            pass


if args.list_traitors == True:
    traitor_dict = {}
    for friend in CrewMember.select().join(Ship).where(Ship.db_alignment == 1):
        for enemy in CrewMember.select().join(Ship).where(Ship.db_alignment == 2):
            if friend.db_first_name == enemy.db_first_name:# and friend.db_last_name == enemy.db_last_name and friend.db_rank == enemy.db_rank:
                traitor_dict[(friend.db_first_name + friend.db_last_name + friend.db_rank)] = {"First_name" : friend.db_first_name,
                                                                                               "Last_name" : friend.db_last_name,
                                                                                               "Rank" : friend.db_rank}
    for key, value in traitor_dict.items():
        print(value)

'''
#выводит базы данных
for ships in Ship.select():
    print(ships.db_name, ships.db_alignment, ships.db_class, ships.db_length, ships.db_crew_size, ships.db_armed)
for human in CrewMember.select():
    print(human.db_first_name, human.db_last_name, human.db_rank, human.db_ship_of_service.db_name)'''