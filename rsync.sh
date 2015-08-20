#!/bin/sh

#  rsync.sh
#  ByteBuffer
#
#  Created by Jeroen Jonkman on 23-06-15.
#
MAC020="/Users/jeroenjonkman/Developer/ByteBuffer/"
MAC001="/Volumes/jeroenjonkman/Developer/ByteBuffer/"
rsync -taruvg ${MAC020} ${MAC001}
rsync -taruvg ${MAC001} ${MAC020}
