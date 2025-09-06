def split_booty(*args):
    ingots = 0
    for purse in args:
        if isinstance(purse, dict):
            if "gold_ingots" in purse and isinstance(purse["gold_ingots"], int):
                ingots += purse["gold_ingots"]
    purse_1 = {"gold_ingots" : ingots // 3}
    ingots -= ingots // 3
    purse_2 = {"gold_ingots" : ingots // 2}
    ingots -= ingots // 2
    purse_3 = {"gold_ingots" : ingots}
    booty = [purse_3, purse_2, purse_1]
    return booty
