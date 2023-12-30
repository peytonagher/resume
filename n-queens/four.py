from z3 import *

# 4 x 4
def four():

    mySolver = Solver()
    p11 = Bool('p(1,1)') #a 
    p12 = Bool('p(1,2)') #b 
    p13 = Bool('p(1,3)') #c 
    p14 = Bool('p(1,4)') #d 
    p21 = Bool('p(2,1)') #e 
    p22 = Bool('p(2,2)') #f 
    p23 = Bool('p(2,3)') #g 
    p24 = Bool('p(2,4)') #h 
    p31 = Bool('p(3,1)') #i 
    p32 = Bool('p(3,2)') #j 
    p33 = Bool('p(3,3)') #k 
    p34 = Bool('p(3,4)') #l 
    p41 = Bool('p(4,1)') #m 
    p42 = Bool('p(4,2)') #n 
    p43 = Bool('p(4,3)') #o 
    p44 = Bool('p(4,4)') #p 

# at least one queen in each row
    mySolver.add( Or(p11, p12, p13, p14) )
    mySolver.add( Or(p21, p22, p23, p24) )
    mySolver.add( Or(p31, p32, p33, p34) )
    mySolver.add( Or(p41, p42, p43, p44) )

# two queens never in the same row
    mySolver.add( Not(Or(And(p11, p12), And(p11, p13), And(p12, p13), And(p11, p14), And(p12, p14), And(p13, p14))) )
    mySolver.add( Not(Or(And(p21, p22), And(p21, p23), And(p22, p23), And(p21, p24), And(p22, p24), And(p23, p24))) )
    mySolver.add( Not(Or(And(p31, p32), And(p31, p33), And(p32, p33), And(p31, p34), And(p32, p34), And(p33, p34))) )
    mySolver.add( Not(Or(And(p41, p42), And(p41, p43), And(p42, p43), And(p41, p44), And(p42, p44), And(p43, p44))) )

# two queens never in the same column
    mySolver.add( Not(Or(And(p11, p21), And(p11, p31), And(p21, p31), And(p11, p41), And(p21, p41), And(p31, p41))) )
    mySolver.add( Not(Or(And(p12, p22), And(p12, p32), And(p22, p32), And(p12, p42), And(p22, p42), And(p32, p42))) )
    mySolver.add( Not(Or(And(p13, p23), And(p13, p33), And(p23, p33), And(p13, p43), And(p23, p43), And(p33, p43))) )
    mySolver.add( Not(Or(And(p14, p24), And(p14, p34), And(p24, p34), And(p14, p44), And(p24, p44), And(p34, p44))) )

# two queens never on the same diagonal
    mySolver.add( Not(Or(And(p12, p21))) )
    mySolver.add( Not(Or(And(p13, p24))) )
    mySolver.add( Not(Or(And(p31, p42))) )
    mySolver.add( Not(Or(And(p34, p43))) )
    mySolver.add( Not(Or(And(p12, p23), And(p12, p34), And(p23, p34))) )
    mySolver.add( Not(Or(And(p21, p32), And(p21, p43), And(p32, p43))) )
    mySolver.add( Not(Or(And(p33, p42), And(p24, p42), And(p24, p33))) )
    mySolver.add( Not(Or(And(p22, p31), And(p13, p31), And(p13, p22))) )
    mySolver.add( Not(Or(And(p11, p22), And(p11, p33), And(p11, p44), And(p22, p33), And(p22, p44), And(p33, p44))) )
    mySolver.add( Not(Or(And(p32, p41), And(p23, p41), And(p14, p41), And(p23, p32), And(p14, p32), And(p14, p23))) )

    print(mySolver.check()) # prints satisfiability
    print('\n')
    print(mySolver.model()) # prints p & q values if above is satisfiable


def main():
    print("\nn = 4:")
    four()
    print("\n")


if __name__ == "__main__":
    main()
    