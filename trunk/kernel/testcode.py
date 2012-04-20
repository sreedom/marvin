from sys import stdin

while 1:
	try:
		exec(stdin.readline())
	except EOFError:
		break

