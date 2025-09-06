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


channel = grpc.insecure_channel("localhost:50051")
client = ShipsListStub(channel)
request = CoordinatesRequest(
    asc_hour=args.a_h, asc_min=args.a_m, asc_sec=args.a_s,dec_fir=args.d_f, dec_sec=args.d_s, dec_thi=args.d_t
)
print(client.ReturnShips(request))
