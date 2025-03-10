from random import choice, randint

FROM = 2
TO = 10

alph = 'abcdefghijklmnopqrstuvwxyz'

for i in range(FROM, TO):
    size = randint(1, 12)
    quantity = randint(5, 20)
    strs = [''.join([choice(alph) for _ in range(size)]) for __ in range(quantity)]
    with open("tests/{:02}-input.txt".format(i), 'w', encoding='utf8') as file:
        file.write(f"{quantity} {size}\n")
        file.write(' '.join(strs))
    strs.sort()
    with open("tests/{:02}-expected.txt".format(i), 'w', encoding='utf8') as file:
        file.write(' '.join(strs) + '\n')

    
    