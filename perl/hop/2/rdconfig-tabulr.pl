#!/usr/bin/env perl

use strict;
use warnings;

sub read_config {
  my ($filename, $actions) = @_;        
  open my($CF), $filename or return;  # Failure
  while (<$CF>) {
    chomp;
    my ($directive, $rest) = split /\s+/, $_, 2;
    if (exists $actions->{$directive}) {
      $actions->{$directive}->($rest);
    } else {
      die "Unrecognized directive $directive on line $. of $filename; aborting";
    }
  }
  return 1;  # Success
}

