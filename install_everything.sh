
#!/bin/sh

set -e

DEST_FOLDER=${LOCAL_PREFIX}/x264_install

./configure \
	--prefix=${DEST_FOLDER} \
	--enable-cli \
	--enable-static

make -j32 install

