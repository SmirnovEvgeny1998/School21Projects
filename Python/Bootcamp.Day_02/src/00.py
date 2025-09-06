class Key:
    def __init__(self):
        self.passphrase = "zax2rulez"
        self.power = 20000


    def __len__(self):
        return 1337


    def __getitem__(self, ind):
        return 3


    def __eq__ (self, number):
        return self.power == number


    def __gt__ (self, number):
        return self.power > number


    def __str__ (self):
        return "GeneralTsoKeycard"

key = Key()
print(len(key) == 1337)
print(key[404] == 3)
print(key > 9000)
print(key.passphrase == "zax2rulez")
print(str(key) == "GeneralTsoKeycard")
