#!/bin/sh -e

#type tcc >/dev/null && CC=tcc
#export CC=${CC:-gcc}
export CFLAGS='-O3 -pipe -s -pedantic -std=c99 \
-fstack-protector-strong -fstack-clash-protection -fexceptions'
export LDFLAGS=-s
export PREFIX=/usr

[ "$1" ] || set -- dwm st surf tabbed

START_PWD="$PWD"
for name in $@ ; do
    cd $name
    if [ ! -d $name ] ; then
        git clone http://git.suckless.org/$name
    else
        cd $name
        git clean -df
        git fetch --all
        git reset --hard
        cd - >/dev/null
    fi
    ls patches | while read -r patch ; do
		echo "===> applying $patch..."
        patch -l -p0 <patches/$patch
    done
    echo
    cp -f config/config.h $name/config.h 2>/dev/null ||:
    cp -f config/config.mk $name/config.mk 2>/dev/null ||:
    cd $name
    make clean
    
    sudo make PREFIX="$PREFIX" install
    make clean
    cd "$START_PWD"
done
