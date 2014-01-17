#!/usr/bin/perl

#########################
##       CONFIG        ##

## Your Name
my $name = "A LOSER WHO CAN'T READ DIRECTIONS";

## Your Class Section
my $section = "FAILURE";

##      END CONFIG     ##
#########################

use strict;
use warnings;
use LWP::UserAgent;

my $FILE;
my $filename;
my $extension;
my $code     = undef;
my $template = undef;
my $classname;
my @webpage;
my @params;

#open( WEBPAGE, "<$ARGV[0]" );

#my (@webpage) = <WEBPAGE>;
unless ( $ARGV[0] && $ARGV[0] =~ /http[s]?:\/\// ) {
    print "Use: cshw.pl <URL of webpage>\n";
    die "No URL or invalid URL given.";
}

my $ua       = LWP::UserAgent->new;
my $response = $ua->get( $ARGV[0] );
if ( $response->is_success ) {
    @webpage = split( "\n", $response->decoded_content );

    print $webpage[0];

}
else {
    die $response->status_line;
}

LOOP: for ( my $i = 0; $i < scalar(@webpage); $i++ ) {
    my $line = $webpage[$i];

    $line =~ s/\cM\n//g;

    if ($code) {
        if ( $line =~ m/\s*<\/p>/ ) {
            close($FILE);
            $code = undef;
            next LOOP;
        }

        $line =~ s/\s+//;
        $line =~ s/&nbsp;/ /g;
        $line =~ s/<br>/\n/g;
        $line =~ s/&#822[0,1];/"/g;
        $line =~ s/&lt;/</g;
        $line =~ s/&gt;/>/g;
        $line =~ s/&amp;/&/g;

        #header file
        if ( $extension =~ m/^h$/ ) {

            #class documentation
            if ( $line =~ /^\s*class (\w+)/ ) {
                $classname = $1;

                print $FILE
                    "//////////////////////////////////////////////////////////////////////\n";
                print $FILE "///\@class $classname\n";
                print $FILE "///\@brief \n";
                print $FILE
                    "//////////////////////////////////////////////////////////////////////\n";

                #if ( defined($temp) ) {
                #                    print $FILE $temp;
                #                    undef $temp;
                #                }

            }

            #destructor
            elsif ( $classname && $line =~ m/~$classname\s?\(\);/ ) {
                print $FILE
                    "\n//////////////////////////////////////////////////////////////////////\n";
                print $FILE "///\@fn ~$classname\n";
                print $FILE "///\@brief Destructor for the $classname class";
                print $FILE
                    "\n//////////////////////////////////////////////////////////////////////\n";
            }

            #constructor
            elsif ( $classname && $line =~ m/$classname\s?\((.*)\);/ ) {

                #        print "Constructor: $classname\n";
                @params = ();
                unless ( $1 eq "" ) {
                    @params = split( ',', $1 );
                }

                print $FILE
                    "\n//////////////////////////////////////////////////////////////////////\n";
                print $FILE "///\@fn $classname\n";
                print $FILE
                    "///\@brief Constructor for the $classname class\n";
                if($1 eq "")
                {
                        print $FILE "///\@pre none\n";
                }
                else
                {
                        print $FILE "///\@pre \n";
                }
                print $FILE "///\@post \n";
                for ( my $j = 0; $j < scalar(@params); $j++ ) {
                    my $param = "///\@param $params[$j] ";

                    #if ( $params[$j] =~ m/unsigned/ ) {
                    #                       $param += "$params[++$j] ";
                    #                   }
                    $param =~ s/^\s*//;
                    print $FILE "$param\n";
                }
                print $FILE
                    "//////////////////////////////////////////////////////////////////////\n";
            }

            #function definition
            elsif (
                $line =~ m/^\s*(\w[\S&\s]*?\s)(\S+)\s?\(([^\(\)]*)\)\s?\w*;/ )
            {
                @params = ();
                my $return   = $1;
                my $funcname = $2;
                unless ( $3 eq "" ) {
                    @params = split( ',', $3 );
                }

                print $FILE
                    "\n//////////////////////////////////////////////////////////////////////\n";
                print $FILE "///\@fn $funcname\n";
                print $FILE "///\@brief \n";
                if($3 eq "")
                {
                        print $FILE "///\@pre none\n";
                }
                else
                {
                        print $FILE "///\@pre \n";
                }
                print $FILE "///\@post \n";
                for ( my $j = 0; $j < scalar(@params); $j++ ) {
                    my $param = "///\@param $params[$j] ";

                    #if ( $params[$j] =~ /unsigned/ ) {
                    #                       $param .= "$params[++$j] ";
                    #                   }
                    $param =~ s/^\s*//;
                    print $FILE "$param\n";
                }
                unless ( $return =~ /void/ ) {
                    print $FILE "///\@return $return \n";
                }
                print $FILE
                    "//////////////////////////////////////////////////////////////////////\n";
            }

            #     print the acutal function line
            #print $FILE $line;
        }

        #.cpp or .hpp
        else {

            if ( $line
                =~ m/^\s*([\w&\s<>]*?)\s?[\w<>]*?::(\S+)\s?\(([^\(\)]*)\)\s?\w*\s*/
                )
            {
                @params = ();
                my $return   = $1;
                my $funcname = $2;

                unless ( $3 eq "" ) {
                    @params = split( ',', $3 );
                }

                #        if($file[$#file] =~ m/template <.+>/)
                #        {
                #          $temp = $file[$#file];
                #        }

                print $FILE
                    "\n//////////////////////////////////////////////////////////////////////\n";
                print $FILE "///\@fn $funcname\n";
                if ( $return eq "" ) {
                    print $FILE "///\@brief Constructor for $classname\n";
                }
                else {
                    print $FILE "///\@brief \n";
                }
                if($3 eq "")
                {
                        print $FILE "///\@pre none\n";
                }
                else
                {
                        print $FILE "///\@pre \n";
                }
                print $FILE "///\@post \n";
                for ( my $j = 0; $j < scalar(@params); $j++ ) {
                    my $param = "///\@param $params[$j]";

                    #if ( $params[$j] =~ m/unsigned/ ) {
                    #                       $param .= " $params[$j+1]";
                    #                       $j++;
                    #                    }
                    $param =~ s/^\s*//;
                    $param .= " \n";
                    print $FILE $param;
                }
                unless ( ( $return =~ m/void/ ) || ( $return eq "" ) ) {
                    print $FILE "///\@return $return \n";
                }
                print $FILE
                    "//////////////////////////////////////////////////////////////////////\n";

                #if ( defined($temp) ) {
                #                   print $FILE $temp;
                #                   undef $temp;
                #               }
            }

        }

        if ( defined($template) ) {
            print $FILE $template;
            $template = undef;
        }

        chop($line);
        if ( $line =~ m/template\s?<.+>/ ) {
            $template = $line;
        }
        else {
            print $FILE $line;
        }
    }

    if ( $line =~ m/<p class="code">/ ) {
        $filename = $webpage[ $i - 1 ];
        $filename =~ /<[^<]+>.*?\s?(\S+)\.(\S{1,3}):<\/[^>]+>/;
        $filename  = $1;
        $extension = $2;
        open( $FILE, ">", "$filename.$extension" );
        print $FILE
            "//////////////////////////////////////////////////////////////////////\n";
        print $FILE "///\@file $filename.$extension\n";
        print $FILE "///\@author $name Section $section\n";
        print $FILE "///\@brief \n";
        print $FILE
            "//////////////////////////////////////////////////////////////////////\n\n";
        $code = 1;
    }
}

#close(WEBPAGE);

