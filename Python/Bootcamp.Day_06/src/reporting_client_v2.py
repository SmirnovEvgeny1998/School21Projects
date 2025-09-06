import pydantic
import grpc
from reporting_pb2_grpc import ShipsListStub
from reporting_pb2 import CoordinatesRequest, Ships
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("a_h", type=float, default=0)
parser.add_argument("a_m", type=float, default=0)
parser.add_argument("a_s", type=float, default=0)
parser.add_argument("d_f", type=float, default=0)
parser.add_argument("d_s", type=float, default=0)
parser.add_argument("d_t", type=float, default=0)
args = parser.parse_args()

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


channel = grpc.insecure_channel("localhost:50051")
client = ShipsListStub(channel)
request = CoordinatesRequest(
    asc_hour=args.a_h, asc_min=args.a_m, asc_sec=args.a_s,dec_fir=args.d_f, dec_sec=args.d_s, dec_thi=args.d_t
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
        elif validation['type'] == 2:
            valid_result = Frigate(**validation)
            print(unit)
        elif validation['type'] == 3:
            valid_result = Cruiser(**validation)
            print(unit)
        elif validation['type'] == 4:
            valid_result = Destroyer(**validation)
            print(unit)
        elif validation['type'] == 5:
            valid_result = Carrier(**validation)
            print(unit)
        elif validation['type'] == 6:
            valid_result = Dreadnought(**validation)
            print(unit)
    except ValueError as e:
        #print(e.errors())
        pass
