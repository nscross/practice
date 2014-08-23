import sys, fileinput

unique_tower_nums = []
all_tower_info = []
kTowerNumLoc = 0
kDayOfWeekLoc = 1
kKiloWattLoc = 2
kDaysInWeek = 7
kPivotTableColumnCount = kDaysInWeek + 1
kPivotTableRowMinCount = 1

for line in fileinput.input():
	tower_info =  line.split( );
	all_tower_info.append(tower_info)

	if tower_info[kTowerNumLoc] not in unique_tower_nums:
		unique_tower_nums.append(tower_info[kTowerNumLoc])

unique_tower_nums.sort()
num_of_rows = kPivotTableRowMinCount + len(unique_tower_nums)

pivot_table = [[0 for y in xrange(kPivotTableColumnCount)] for x in xrange(num_of_rows)]

days_of_week = [" ", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
pivot_table[0] = days_of_week

for ii in range(0, len(unique_tower_nums)):
	pivot_table[ii+1][0] = unique_tower_nums[ii]

for tower_info in all_tower_info:
	try:
		tower_ndx = unique_tower_nums.index(tower_info[kTowerNumLoc]) + 1
		day_ndx = days_of_week.index(tower_info[kDayOfWeekLoc])		
		curr_val = int (pivot_table[tower_ndx][day_ndx]) + int(tower_info[kKiloWattLoc])
		pivot_table[tower_ndx][day_ndx] = str(curr_val)
	except ValueError:
		print "invalid input data detected, exiting"
		sys.exit()

for ii in range(0,num_of_rows):		
	for jj in range(0,kPivotTableColumnCount):
		print '%4s' % pivot_table[ii][jj],
	print ""