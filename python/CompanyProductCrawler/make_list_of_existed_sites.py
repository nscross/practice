import urllib2
import random
from time import sleep

random.seed();
last_line = 'blah'
list_of_files = ['what_exists2.txt']
for filename_to_open in list_of_files:
    with open(filename_to_open) as fp:
        for line in fp:            
            if 'exists' in line: print(last_line)
                
                    
            last_line = line
                
