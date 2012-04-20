
import tuio
tracking = tuio.Tracking(host='')

print "list functions to access tracked objects:", tracking.get_helpers()


obs=set()

obs2=set()
try:
    while 1:
        tracking.update()
        for obj in tracking.cursors():
            #print "cursor at %s %f %f "%(obj.sessionid, obj.xpos, obj.ypos)
            #add to the obs list
            obs.add(obj)
            #proccess obs objects to figure out events
            if len(obs) > 2:
            	for i in obs:
            		print "Blob %d at %f %f "%(obj.sessionid, obj.xpos, obj.ypos)
            	obs.clear()
            if len(obs) == 2:
            	#two finger => line
            	o1=list(obs)[0]
            	o2=list(obs)[1]
            	print "Line %d %d at %f %f %f %f "%(o1.sessionid, o2.sessionid, o1.xpos, o1.ypos, o2.xpos, o2.ypos)
            	
            if len(obs)==1:
            	#one finger => blob
            	obj=list(obs)[0]
            	print "Blob %d at %f %f "%(obj.sessionid, obj.xpos, obj.ypos)
            obs2=obs
            
            
            
except :
    tracking.stop()
    print "stopped Tracking"
    #print dir(obs[0])
    print len(obs)
    	

