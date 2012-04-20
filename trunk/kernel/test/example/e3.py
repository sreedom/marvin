import Tkinter
import threading
import tkMessageBox
import time
import sys
s='red'

def newt(*args):
	global s,C
	exec("C.create_arc(coord, start=0, extent=150, fill='"+s+"')")
	if s=='red':
		s='blue'
	else:
		s='red'

class MyApp(threading.Thread):
	def __init__(self):
		threading.Thread.__init__(self)
		self.start()
	def callback(self):
		self.top.quit()
	def run(self):
		self.top = Tkinter.Tk()
		self.top.protocol("WM_DELETE_WINDOW", self.callback)
		self.C = Tkinter.Canvas(self.top, bg="blue", height=250, width=300)
		coord = 10, 50, 240, 210
		self.arc = self.C.create_arc(coord, start=0, extent=150, fill="red")
		self.C.pack()
		self.top.bind("<<Foo>>",newt)
		self.top.mainloop()
	def change(self):
		exec(raw_input(">>"))
		time.sleep(0.5)

print "starting a new thread"
app=MyApp()
while 1:
	print "waddafuq"

