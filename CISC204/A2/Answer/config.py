
# DO NOT EDIT

# Assignment for 20cjbs

from lib204 import wff
P, Q, R, S, T = map(wff.Variable, 'PQRST')
s1 = ((~T|P)>>~R)
s2 = ((P>>~T)|~R)
s3 = ((~R|T)&(~P|~R))
s4 = ((~R|~T)|(P>>~T))

s5 = (((R|Q)&S)>>~(Q|~R))
s6 = ((~S&Q)|(R>>~(~S|Q)))
