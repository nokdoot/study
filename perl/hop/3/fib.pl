#!/usr/bin/env perl

use strict;
use warnings;

sub fib{
    my ($month) = @_; 
    if($month < 2){1}
    else{
        fib($month-1) + fib($month-2);
    }   
}

print fib(50);
