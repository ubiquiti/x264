
#!/bin/sh

set -e


./configure \
	--prefix=${LOCAL_PREFIX} \
	--enable-cli \
	--enable-static

make -j32 install

