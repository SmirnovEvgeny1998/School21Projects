from concurrent import futures
import random

import grpc

from reporting_pb2 import (
    CoordinatesRequest,
    Ships,
    ShipsResponse,
    ClassName,
    Officers
)

import reporting_pb2_grpc

ship_classes_pool = ["Corvette", "Frigate", "Cruiser", "Destroyer", "Carrier", "Dreadnought"]
ship_classes_data = {"Corvette" : [80, 250, 4, 10],
                     "Frigate" : [300, 600, 10, 15],
                     "Cruiser" : [500, 1000, 15, 30],
                     "Destroyer" : [800, 2000, 50, 80],
                     "Carrier" : [1000, 4000, 120, 250],
                     "Dreadnought" : [5000, 20000, 300, 500]
                     }
ship_alignment_pool = ["Ally", "Enemy"]
ship_name_pool = ["Абрек",
                  "Августа Виктория",
                  "Авось",
                  "Авраамий",
                  "Аврора",
                  "Аврора",
                  "Автроил",
                  "Агатополь",
                  "АГ-15",
                  "Адзума",
                  "Адмирал Грейг",
                  "Адмирал Макаров",
                  "Адмирал Нахимов",
                  "Адмирал Сенявин",
                  "Адмирал Ушаков",
                  "Адрианополь",
                  "Азард",
                  "Азимут",
                  "Asia",
                  "Азия",
                  "Азов",
                  "Ак-Дениз",
                  "Акаги",
                  "Акару",
                  "Акаси",
                  "Акацуки",
                  "Акебоно",
                  "Unknown"]
crew_first_name_pool = ["Абагор", "Абакум", "Абамон", "Абдаикл", "Абия", "Абнодий", "Абрам", "Абрамий", "Абросим", "Абсей", "Аввакир", "Аввакум", "Авгурий", "Август", "Августа", "Августин", "Августина", "Авда", "Авдей", "Авделай", "Авдиес", "Авдий"]
crew_second_name_pool = ["ПАВЕЛЕВ", "ПАВЕЛЬЕВ", "ПАВЕНКО", "ПАВИН", "ПАВКИН", "ПАВЛЕЕВ", "ПАВЛЕНКО", "ПАВЛЕНКОВ", "ПАВЛЕНОВ", "ПАВЛЕНОК", "ПАВЛИК", "ПАВЛИКОВ", "ПАВЛИНИН", "ПАВЛИНОВ", "ПАВЛИС", "ПАВЛИХИН", "ПАВЛИШИНЦЕВ", "ПАВЛИЩЕВ", "ПАВЛОВ", "ПАВЛОВИЧ", "ПАВЛОВСКИЙ"]
crew_rank_pool = ["Старшина", "Главный старшина", "Мичман", "Старший мичман", "Младший лейтенант", "Лейтенант", "Старший лейтенант", "Капитан-лейтенант", "Капитан", "Контр-адмирал", "Вице-адмирал", "Адмирал"]
armed_state_pool = ["True", "False"]


class ShipsListService(
    reporting_pb2_grpc.ShipsListServicer
):

    def ReturnShips(self, request, context):
        list_of_the_ships = []
        num = random.randint(1, 10)
        num_2 = random.randint(0, 10)
        for ship in range(num):
            '''
            full random
            list_of_the_ships.append(
                Ships(alignment=random.choice(ship_alignment_pool),
                      name=random.choice(ship_name_pool),
                      classs=random.choice(ship_classes_pool),
                      length=random.uniform(1, 20000),
                      crew_size=random.randint(1, 500),
                      armed=random.choice(armed_state_pool),
                      oficer_crew=list_of_officers))'''
            ship_class_name = random.choice(ship_classes_pool)
            ship_length = random.uniform(ship_classes_data[ship_class_name][0], ship_classes_data[ship_class_name][1])
            ship_crew_number = random.randint(ship_classes_data[ship_class_name][2], ship_classes_data[ship_class_name][3])
            ship_alignment = random.choice(ship_alignment_pool)
            ship_name = random.choice(ship_name_pool)
            if ship_name == "Unknown":
                ship_alignment = "Enemy"
            if ship_alignment == 'Ally' and num_2 == 0:
                num_2 = 1
            list_of_officers = []
            if num_2 == 0:
                list_of_officers.append(Officers(firstName="Unknown"))
            for member in range(num_2):
                list_of_officers.append(
                    Officers(firstName=random.choice(crew_first_name_pool),
                             lastName=random.choice(crew_second_name_pool),
                             rank=random.choice(crew_rank_pool)))

            list_of_the_ships.append(
                Ships(alignment=ship_alignment,
                      name=ship_name,
                      classs=ship_class_name,
                      length=ship_length + ship_length / 10,
                      crew_size=ship_crew_number + ship_crew_number // 10,
                      armed=random.choice(armed_state_pool),
                      oficer_crew=list_of_officers))

        return ShipsResponse(ship=list_of_the_ships)


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    reporting_pb2_grpc.add_ShipsListServicer_to_server(
        ShipsListService(), server
    )
    server.add_insecure_port("[::]:50051")
    server.start()
    server.wait_for_termination()


if __name__ == "__main__":
    serve()
