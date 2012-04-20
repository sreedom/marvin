
from socket import *
def print_data(data):
	print data

class TuioReceiver:
	def __init__(self,sock=None,host="",port=3333):
		self.socket=sock or socket(AF_INET,SOCK_DGRAM)
		self.socket.bind((host,port))
		self.data=[]
	def start_recv(self):
		try:
			while True:
				self.data.append(self.socket.recvfrom(1000)[0])
				if self.data[-1]!='':
					print self.data[-1]
					pass
		except:
			print "Not receiving anymore"
		print map(lambda x: str(x), self.data)
	def stop(self):
		self.socket.close()
		pass


if __name__=='__main__':
	t=TuioReceiver()
	t.start_recv()
	t.stop()
			
