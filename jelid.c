#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

void scan_bus( int bus );

int main( int c, char** s ) {
        printf( "JELID \n" );

        scan_bus( 0 );
        scan_bus( 2 );
        scan_bus( 5 );
}

void scan_bus( int bus ) {
        int file;
        char filename[20];

        printf( "BUS  %2d\n", bus );

        snprintf(filename, 19, "/dev/i2c-%d", bus);
        file = open(filename, O_RDWR);
        if (file < 0) {
                printf( " Failed to open\n\n" );  
        }

        char* buffer[ 10 ];

        for ( int address = 0x00; address < 0x80; address++ ) {

                if (ioctl( file, I2C_SLAVE, address ) < 0) {
                        /* ERROR HANDLING; you can check errno to see what went wrong */
                        printf( "%02x*", address );
                } else {

                        if (read(file, buffer, 1) != 1) {
                                printf( "-- " );
                        } else {
                                printf( "%02x ", address );
                        }

                }

                if ( ( address + 1 ) % 16 == 0 )
                        printf( "\n" );
        }

        printf( "\n" );
        close( file );
}


