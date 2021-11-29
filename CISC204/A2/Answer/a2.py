
# This is your unique solution file

from config import *
from lib204 import semantic_interface

# Assignment for 20cjbs

# Note: All of these answers are almost certainly wrong

a2q12 = [[s1], [s2, s4], [s3]]


a2q13 = {
    P: False,
    R: True,
    T: False
}

a2s5nnf = [
    [(((R|Q)&S)>>~(Q|~R)), 'starting formula'],
    [(~((R|Q)&S)|~(Q|~R)), 'implication free'],
    [(((~R&~Q)|~S)|(~Q&~~R)), 'deMorgans law'],
    [(((~R&~Q)|~S)|(~Q&R)), 'double negation']
]

a2s6nnf = [
    [((~S&Q)|(R>>~(~S|Q))), 'starting formula'],
    [((~S&Q)|(~R|~(~S|Q))), 'implication free'],
    [((~S&Q)|(~R|(~~S&~Q))), 'deMorgans law'],
    [((~S&Q)|(~R|(S&~Q))), 'double negation']
]

a2s5cnf = [
    [(((R|Q)&S)>>~(Q|~R)), 'starting formula'],
    [(~((R|Q)&S)|~(Q|~R)), 'implication free'],
    [(((~R&~Q)|~S)|(~Q&~~R)), 'deMorgans law'],
    [(((~R&~Q)|~S)|(~Q&R)), 'double negation'],
    [((((~R&~Q)|~S)|~Q)&(((~R&~Q)|~S)|R)), 'distribution']
]

a2s6cnf = [
    [((~S&Q)|(R>>~(~S|Q))), 'starting formula'],
    [((~S&Q)|(~R|~(~S|Q))), 'implication free'],
    [((~S&Q)|(~R|(~~S&~Q))), 'deMorgans law'],
    [((~S&Q)|(~R|(S&~Q))), 'double negation'],
    [((~S|(~R|(S&~Q)))&(Q|(~R|(S&~Q)))), 'distribution']
]

a2s5tseitin = semantic_interface.Encoding()
x1 = a2s5tseitin.tseitin(R&Q, 'x1')
x2 = a2s5tseitin.tseitin(~R, 'x2')
x3 = a2s5tseitin.tseitin(x1&S, 'x3')
x4 = a2s5tseitin.tseitin(Q&x2, 'x4')
x5 = a2s5tseitin.tseitin(~x4, 'x5')
x6 = a2s5tseitin.tseitin(x3>>x5, 'x6')
a2s5tseitin.finalize(x6)

a2s6tseitin = semantic_interface.Encoding()
x1 = a2s6tseitin.tseitin(~S, 'x1')
x2 = a2s5tseitin.tseitin(x1|Q, 'x2')
x3 = a2s5tseitin.tseitin(~S, 'x3')
x4 = a2s5tseitin.tseitin(~x2, 'x4')
x5 = a2s5tseitin.tseitin(x3&Q, 'x5')
x6 = a2s5tseitin.tseitin(R>>x4, 'x6')
x7 = a2s5tseitin.tseitin(x5|x6, 'x7')
a2s6tseitin.finalize(x7)

