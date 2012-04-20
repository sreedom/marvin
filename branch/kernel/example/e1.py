#! /usr/bin/env python
import pygame
import time
y = 0
dir = 1
running = 1
width = 800
height = 600
screen = pygame.display.set_mode((width, height))
linecolor = 255, 0, 0
bgcolor = 0, 0, 0
def do_blob(s):
	global screen, linecolor, y, width,height
	# format: blob(x,y)
	x,y=s.split(',')
	x1=int(float(x)*width)
	y1=int(float(y)*height)
	screen.fill(bgcolor)
	pygame.draw.circle(screen,(0,0,255),(x1,y1),20,1)
	pygame.draw.line(screen, linecolor, (0, y1), (width-1, y1))
	pygame.draw.line(screen, linecolor, (x1, 0), (x1,height-1))
	pygame.display.flip()	

def do_line(s):
	global screen, linecolor, y, width,height
	x1,y1,x2,y2=s.split(',')
	x1=int(float(x1)*width)
	x2=int(float(x2)*width)
	y1=int(float(y1)*height)
	y2=int(float(y2)*height)
	screen.fill(bgcolor)
	pygame.draw.circle(screen,(0,0,255),(x1,y1),20,1)
	pygame.draw.circle(screen,(0,0,255),(x2,y2),20,1)
	pygame.draw.line(screen, linecolor, (x1, y1), (x2,y2))
	pygame.display.flip()	

	
event = pygame.event.poll()
if event.type == pygame.QUIT:
	running = 0
screen.fill(bgcolor)
pygame.display.flip()

