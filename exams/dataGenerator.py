import random
import string
import sys
import time

for x in range(1000):
	_id = ''.join(random.choice(string.ascii_lowercase + string.digits) for x in range(10))
	good = random.randint(10,10000)
	bad = 10000-good;
	timestamp = random.randint(1293850800, 1320116400)
	print _id, timestamp, good, bad
