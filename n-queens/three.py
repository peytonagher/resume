from z3 import *


# 3 x 3
def three():

    mySolver = Solver()
    p11 = Bool('p(1,1)') #a 
    p12 = Bool('p(1,2)') #b 
    p13 = Bool('p(1,3)') #c 
    p21 = Bool('p(2,1)') #d 
    p22 = Bool('p(2,2)') #e 
    p23 = Bool('p(2,3)') #f 
    p31 = Bool('p(3,1)') #g 
    p32 = Bool('p(3,2)') #h 
    p33 = Bool('p(3,3)') #i 

    # top row
    mySolver.add( And((Or(p11, p12, p13)), (Not(And(p11, p12))), (Not(And(p11, p13))), (Not(And(p12, p13)))) )
    # middle row
    mySolver.add( And((Or(p21, p22, p23)), (Not(And(p21, p22))), (Not(And(p21, p23))), (Not(And(p22, p23)))) )
    # bottom row
    mySolver.add( And((Or(p31, p32, p33)), (Not(And(p31, p32))), (Not(And(p31, p33))), (Not(And(p32, p33)))) )
    # left column
    mySolver.add( And((Or(p11, p21, p31)), (Not(And(p11, p21))), (Not(And(p11, p31))), (Not(And(p21, p31)))) )
    # middle column
    mySolver.add( And((Or(p12, p21, p32)), (Not(And(p11, p21))), (Not(And(p11, p32))), (Not(And(p21, p32)))) )
    # right column
    mySolver.add( And((Or(p13, p22, p32)), (Not(And(p13, p22))), (Not(And(p13, p32))), (Not(And(p22, p32)))) )
    # no two queens on the same diagonal
    mySolver.add( And((Not(Or(p11, p22, p33))) , (Not(And(p13, p22))), (Not(And(p13, p21))), (Not(And(p22, p21)))) )

    print(mySolver.check()) # prints satisfiability
    # print(mySolver.model()) # wont print unless satisfiable


def main():
    print("\nCSE260 programming project")
    print("\nn = 3:")
    three()
    print("\n")


if __name__ == "__main__":
    main()
