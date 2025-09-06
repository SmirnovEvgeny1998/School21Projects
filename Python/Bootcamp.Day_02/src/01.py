from collections import Counter

class Game(object):


    def __init__(self, matches = 10):
        self.matches = matches
        self.registry = Counter()
        self.results = []


    def play(self, player1, player2):
        if isinstance(player1, Player) and isinstance(player2, Player):
            p1_prev_move = None
            p2_prev_move = None
            for i in range(0, self.matches, 1):
                p1_choise = player1.move(i, p2_prev_move)
                p2_choise = player2.move(i, p1_prev_move)
                p1_prev_move = p1_choise
                p2_prev_move = p2_choise
                if p1_choise == "Cooperate":
                    if p2_choise == "Cheat":
                        player1.score -= 1
                        player2.score += 3
                    else:
                        player1.score += 2
                        player2.score += 2
                else:
                    if p2_choise == "Cheat":
                        player1.score -= 0
                        player2.score += 0
                    else:
                        player1.score += 3
                        player2.score -= 1
            if (player1.score >= player2.score):
                self.results.append(player1.player_type())
            if (player2.score >= player1.score):
                self.results.append(player2.player_type())
            #print(player1.name, player1.score , player2.name, player2.score)
            player1.score = 0
            player2.score = 0
        else:
            print("One or both parametrs arent Players")


    def top3(self):
        self.registry = Counter(self.results)
        print(self.registry.most_common(3))


    def empty_top(self):
        self.results = []


class Player(object):
    def __init__ (self):
        self.score = 0
        
class Cheater(Player):


    def __init__ (self):
        Player.__init__(self)
        self.name = "Cheater"


    def __eq__ (self, other):
        return self.name == other


    def __hash__ (self):
        return 1


    def move(self, stage, opponent_move):
        return "Cheat"


    def player_type(self):
        return self.name

class Cooperator(Player):


    def __init__ (self):
        Player.__init__(self)
        self.name = "Cooperator"


    def __eq__ (self, other):
        return self.name == other


    def __hash__ (self):
        return 2


    def move(self, stage, opponent_move):
        return "Cooperate"


    def player_type(self):
        return self.name

class Copycat(Player):


    def __init__ (self):
        Player.__init__(self)
        self.name = "Copycat"


    def __eq__ (self, other):
        return self.name == other


    def __hash__ (self):
        return 3


    def move(self, stage, opponent_move):
        if stage == 0:
            return "Cooperate"
        else:
            return opponent_move


    def player_type(self):
        return self.name

class Grudger(Player):


    def __init__ (self):
        Player.__init__(self)
        self.name = "Grudger"
        self.gruge = False


    def __eq__ (self, other):
        return self.name == other


    def __hash__ (self):
        return 4


    def move(self, stage, opponent_move):
        if stage == 0:
            self.gruge = False
            return "Cooperate"
        elif self.gruge == True or opponent_move == "Cheat":
            self.gruge = True
            return "Cheat"
        else:
            return "Cooperate"


    def player_type(self):
        return self.name

class Detective(Player):


    def __init__ (self):
        Player.__init__(self)
        self.name = "Detective"
        self.gruge = False


    def __eq__ (self, other):
        return self.name == other


    def __hash__ (self):
        return 5


    def move(self, stage, opponent_move):
        if stage == 0:
            self.gruge = False
        if stage in [0, 1, 2, 3] and opponent_move == "Cheat":
            self.gruge = True
        if stage in [0, 2, 3]:
            return "Cooperate"
        elif stage == 1:
            return "Cheat"
        elif self.gruge == True:
            return opponent_move
        else:
            return "Cheat"


    def player_type(self):
        return self.name

game = Game()
p1 = Cheater()
p2 = Cooperator()
p3 = Copycat()
p4 = Grudger()
p5 = Detective()
p11 = Cheater()
p21 = Cooperator()
p31 = Copycat()
p41 = Grudger()
p51 = Detective()
set = list(set([p1, p2, p3, p4, p5, p11, p21, p31, p41, p51]))
for t in range (0,10):
    for i in range(0, len(set) - 1, 1):
        for j in range(1, len(set), 1):
            if i < j:
                game.play(set[i], set[j])
game.top3()
game.empty_top()
game.top3()
