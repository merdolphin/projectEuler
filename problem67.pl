## problem67.pl 
## written by lina on Sat Mar  2 21:37:37 SGT 2013
##
#!/usr/bin/env perl

use strict;
use warnings;
use autodie qw(open close);
use Carp qw(croak);
use 5.012;

my $infile = "triangle.txt";

open my $fh, '<', $infile;

my @triangle;
my $i = 0;

while(my $line = <$fh>){
    my @eachrows;
    push @eachrows, split / /,$line;
    $triangle[$i] = [ @eachrows ];
    $i++;
}

my $j;
for($i=98; $i>=0; $i--){
    for($j=0; $j <= $i; $j++){
        $triangle[$i][$j] += $triangle[$i+1][$j] > $triangle[$i+1][$j+1] ? $triangle[$i+1][$j] : $triangle[$i+1][$j+1];
    }
}

say $triangle[0][0];
