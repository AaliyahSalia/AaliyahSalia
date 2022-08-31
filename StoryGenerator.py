import random
when = ['A few years ago', 'Yesterday', 'Last night', 'A long time ago', 'On a rainy day']
who = ['a killer', 'a detective', 'a tennis player', 'a robber', 'a cat']
name = ['Jade', 'Daniel', 'Ryan', 'Emily', 'Ross', 'Rachel']
residence = ['India', 'China', 'Korea', 'Malaysia', 'Singapore', 'Norway']
went = ['university', 'cinema', 'shopping mall', 'auditorium', 'laundry room', 'hotel']
happened = ['killed a woman', 'hunted for a prey', 'smoked a cigarette', 'witnessed something devastating', 'caught a robber', 'wrote a book']

print(random.choice(when) + ',' + random.choice(who) + ' named ' + random.choice(name) +  ' that lived in ' + random.choice(residence) + ', went to the ' + random.choice(went) + ' and ' + random.choice(happened))
