import example

# test enums
a = example.Brain()
a.state = 'CRAZY'
a.state = 'INSANE'
assert a.state == 'INSANE'

# test ints
a.iq = 100
assert a.iq == 100
