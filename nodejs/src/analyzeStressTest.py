import csv
import datetime
import traceback
from collections import defaultdict
import numbers
from optparse import OptionParser
import math

parser = OptionParser()
parser.add_option("-f", "--filename", dest="filename", type="string", action="store", help="Filename is analyze")

(options, args) = parser.parse_args()

filename = options.filename

ifile  = open(filename, "rb")
reader = csv.reader(ifile)

rownum = 0
totaltime = 0
totalapptime = 0
list = []
applist = []
seq = []
endTime = datetime.datetime.strptime("1900-01-01 00:00:00", "%Y-%m-%d %H:%M:%S")
minTime = 0
maxTime = 0
for row in reader:
    # Save header row.
    if rownum == 0:
        header = row
    else:
        colnum = 0
        try:
			for col in row:
				if header[colnum] == 'totalTimeMs':
					totaltime = totaltime+int(col);
					list.append(int(col))
				if header[colnum] == 'applicationTimeMs':
					totalapptime = totaltime+int(col);
					applist.append(int(col))	
				if 	header[colnum] == 'time' and rownum ==1:
					startTime = datetime.datetime.strptime(col.replace('T',' ')[:-5], "%Y-%m-%d %H:%M:%S")
					print startTime
				if 	header[colnum] == 'time':
					if endTime < datetime.datetime.strptime(col.replace('T',' ')[:-5], "%Y-%m-%d %H:%M:%S"):
						endTime = datetime.datetime.strptime(col.replace('T',' ')[:-5], "%Y-%m-%d %H:%M:%S")
				#print '%-8s: %s' % (header[colnum], col)
				if header[colnum] == 'receiptType':	
					if isinstance( col, int ):
						seq.append(col)
				colnum += 1
        except Exception, err:
			pass#print traceback.format_exc() 
		
    rownum += 1

set = {}
map(set.__setitem__, seq, [])

d = defaultdict(int)
for word in seq:
    d[word] += 1
print d
   
print "Total submitted:",rownum
avgs = totaltime/len(list)
print "Average Time:",avgs
variance = map(lambda x: (x - avgs)**2, list)
ver = reduce(lambda x, y: x + y, variance) / len(variance)
print "Std Deveation:",math.sqrt(ver)
print "Minimum Time",min(list)
print "Maximum Time",max(list)

print "------ Application Time ----"

avga = totalapptime/len(applist)
print "Average Time:",avga
variancea = map(lambda x: (x - avga)**2, applist)
vera = reduce(lambda x, y: x + y, variancea) / len(variancea)
print "Std Deveation:",math.sqrt(vera)
print "Minimum Time",min(applist)
print "Maximum Time",max(applist)
 
print "Total time of run",endTime - startTime

ifile.close()