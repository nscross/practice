import sys, getopt, random, urllib2
from time import sleep

def main(argv):
    random.seed();

    if len(sys.argv) < 2 : 
        print('No hostname specified.\nusage: crawler.py -n <hostname>')
        sys.exit(-1)

    hostname = ''

    try:
        opts, args = getopt.getopt(argv, "hn",["hname="])
    except getopt.GetoptError:
        print('usage: crawler.py -n <hostname>')
        sys.exit(2)
        
    for opt, arg in opts:
        if opt == '-h':
            print('usage: crawler.py -n <hostname>')
            sys.exit()
        elif opt in ("-n", "--hname"):
            hostname = arg
            
    print 'Hostname is "', hostname    


    list_of_files = ['jargon-wl\common.lst', 'jargon-wl\common-base.lst', 'jargon-wl\other.lst', 'jargon-wl\word.lst', 'jargon-wl\en_US.dic']
    for filename_to_open in list_of_files:
        with open(filename_to_open) as fp:
            for line in fp:
                sleep(random.randrange(1, 5))
                try:
                    print('\nTrying ' + hostname + line)
                    urllib2.urlopen('' + hostname + line)
                    print('' + hostname + line.rstrip('\n') + 'exists')
                except urllib2.HTTPError, e:
                    print(e.code )
                except urllib2.URLError, e:
                    print(e.args )

                
if __name__ == "__main__":
    main(sys.argv[1:])