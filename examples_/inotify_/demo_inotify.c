#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <wordexp.h>

#define EVENT_SIZE ( sizeof ( struct inotify_event) )
#define EVENT_BUF_LEN ( 1024 * ( EVENT_SIZE + 16 ) )

int main() {
    int length, i = 0;
    int fd;
    int wd;
    char buffer[EVENT_BUF_LEN];

    /*creating the INOTIFY instance*/
    fd = inotify_init();
    if ( fd < 0 ) {
        perror( "inotify_init" );
    }

    /*adding "~/tmp" into watch list.*/
    wordexp_t exp;
    wordexp("~/tmp", &exp, 0);
    wd = inotify_add_watch( fd, exp.we_wordv[0], IN_CREATE|IN_DELETE );
    
    /* read to determine the event change happens on "~/tmp".*/
    length = read(fd, buffer, EVENT_BUF_LEN );

    /*checking for error*/
    if ( length < 0 ) {
        perror( "read" );
    }

    /* actually read return the list of change events happens. Read the change event one by one and process it accordingly*/
    while ( i < length ) {
        struct inotify_event *event = ( struct inotify_event *) &buffer[ i ];
        if ( event->len ) {
            if ( event->mask & IN_CREATE) {
                if ( event -> mask & IN_ISDIR ) {
                    printf("New directory %s created.\n", event->name);
                } else {
                    printf("New file %s created.\n", event->name);
                }
            } else if ( event->mask & IN_DELETE ) {
                if ( event->mask & IN_ISDIR ) {
                    printf("Directory %s deleted.\n", event->name);
                } else {
                    printf("File %s delete.\n", event->name);
                }
            }
        }
        i += EVENT_SIZE + event->len;

        /*removing the "~/tmp" from the watch list.*/
        inotify_rm_watch( fd, wd );

        /*closing the INOTIFY instance*/
        close( fd );
    }
}
