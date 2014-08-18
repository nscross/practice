#!/usr/bin/python
# Bogo sort

import sys, getopt, random

def shuffle(input):
    output = []
    l = list(input)
    random.shuffle(l)
    output = ''.join(l)
    
    return output

def shuffle2(input):
    return ''.join(random.sample(input,len(input)))

def Bogo(unsorted_string, expected_string):
    num_itr = 0

    while unsorted_string != expected_string:
        num_itr += 1
        unsorted_string = shuffle2(unsorted_string)

    return num_itr

def main(argv):
    random.seed();

    if len(sys.argv) < 2 : 
        print('No hostname specified.\nusage: crawler.py -n <hostname>')
        sys.exit(-1)

    unsorted_string = ''
    expected_string = ''

    try:
        opts, args = getopt.getopt(argv, "hu:e:",["ustring=","estring="]) 
    except getopt.GetoptError:
        print('GetoptError\nusage: bogo.py -u <unsorted string> -e <expected string>')
        sys.exit(2)

    for opt, arg in opts:
        if opt == '-h':
            print('help\nusage: bogo.py -u <unsorted string> -e <expected string>')
        elif opt in ("-u", "--ustring"):
            unsorted_string = arg
        elif opt in ("-e", "--estring"):
            expected_string = arg

    if unsorted_string == '':
        print('Unsorted string needed\nusage: bogo.py -u <unsorted string> -e <expected string>')
        sys.exit(2)
    
    if expected_string == '':
        print('expected string needed\nusage: bogo.py -u <unsorted string> -e <expected string>')
        sys.exit(2)
   
    print 'Bogo sort: ' + unsorted_string + ' into ' + expected_string

    times_shuffled = Bogo(unsorted_string, expected_string)

    print times_shuffled, ' iterations'

        
if __name__ == "__main__":
    main(sys.argv[1:])
