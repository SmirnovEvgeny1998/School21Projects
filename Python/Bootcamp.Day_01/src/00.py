def add_ingot(purse):
    dict_copy = None
    if isinstance(purse, dict):
        if "gold_ingots" in purse and isinstance(purse["gold_ingots"], int):
            dict_copy = purse.copy()
            if dict_copy["gold_ingots"] < 0:
                            dict_copy["gold_ingots"] = 0
            dict_copy["gold_ingots"] += 1
        elif "gold_ingots" in purse:
            dict_copy = purse.copy()
            print("Purse have non-integer amount of gold ingots, cant add 1 to it")
        else:
            dict_copy = purse.copy()
            dict_copy["gold_ingots"] = 1
    return dict_copy


def get_ingot(purse):
    dict_copy = None
    if isinstance(purse, dict):
        if "gold_ingots" in purse and isinstance(purse["gold_ingots"], int):
            dict_copy = purse.copy()
            dict_copy["gold_ingots"] -= 1
            if dict_copy["gold_ingots"] <= -1:
                dict_copy["gold_ingots"] = 0
        elif "gold_ingots" in purse:
            dict_copy = purse.copy()
            print("Purse have non-integer amount of gold ingots, cant get 1 from it")
        else:
            dict_copy = purse.copy()
            dict_copy["gold_ingots"] = 0
    return dict_copy


def empty(purse):
    emptyDict = dict()
    return emptyDict
