import itertools

def fix_wiring(cables, sockets, plugs):
   return filter(lambda z: z  != None, ["plug " + c + " into " + s + " using " + p if c and s and p else "weld " + c + " to " + s + " without plug" if c and s else None for c,s,p in itertools.zip_longest(filter(lambda n: type(n)  == type('str'), cables),filter(lambda n: type(n)  == type('str'), sockets),filter(lambda n: type(n)  == type('str'), plugs))])

'''plugs = ['plug1', 'plug2', 'plug3']
sockets = ['socket1', 'socket2', 'socket3', 'socket4']
cables = ['cable1', 'cable2', 'cable3', 'cable4']'''

plugs = ['plugZ', None, 'plugY', 'plugX']
sockets = [1, 'socket1', 'socket2', 'socket3', 'socket4']
cables = ['cable2', 'cable1', False]

for c in fix_wiring(cables, sockets, plugs):
    print(c)