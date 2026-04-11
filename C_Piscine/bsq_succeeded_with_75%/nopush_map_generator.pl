# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    nopush_map_generator.pl                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 22:44:25 by jshim             #+#    #+#              #
#    Updated: 2025/11/09 16:27:34 by jshim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/env perl

use warnings;
use strict;
die "Usage: program x y density" unless (scalar (@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            print "o";
        }
        else {
            print ".";
        }
    }
    print "\n";
}