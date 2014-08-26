$arg = "ABCD";
$arg2 = $arg."'\x1D\x14\x40'";
$cmd = "C:/cygwin64/home/Nick/dev/practice/c/buffer_overflow/a.exe ".$arg2;

#system($cmd);
system($cmd);