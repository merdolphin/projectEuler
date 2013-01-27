#!/usr/bin/env perl

## written by lina <lina.oahz@gmail.com> on Sun Jan 27 14:10:03 SGT 2013

use strict;
use warnings;
use autodie qw(open close);
use 5.012;

my $filename = "names.txt";

open my $fh, '<', $filename;

my %dict;
my $number = 1;
foreach('A'..'Z'){
    $dict{$_} = $number;
    $number++;
}
my @letters;
my $Tsum;

while(<$fh>){
    
    my @names;    
    my @namesss = split /,/,$_;

    foreach(@namesss){
         push @names, $1 if($_=~ m/"(.*)"/);
        
    }
        my $count=1;

        foreach(sort @names){
            my @letter = split //,$_;
            my $sum = 0;
            $sum += $dict{$_} foreach(@letter);
            $Tsum += $sum*$count;
            $count++;
        }
        printf("%d\n",$Tsum);

 }

