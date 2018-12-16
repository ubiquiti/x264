#/bin/sh

set -e

./configure \
	--prefix=/Users/shiretu/work/evostream/builders/cmake/external_libs/libav \
	--disable-cli \
    --enable-static \
	--extra-cflags="-mmacosx-version-min=10.11 -g"

make -j32 install

