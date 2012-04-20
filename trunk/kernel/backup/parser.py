import re

filename=None

def input_file(s):
	global filename
	filename=s
	

def event_map():
	with open(filename) as f:
		glob=re.compile(r'\w*\s*->\w*\s*')
		match=glob.findall(''.join(filename.readlines()))
		print match

	
