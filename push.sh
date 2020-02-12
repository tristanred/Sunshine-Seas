#!/bin/sh

rsync -r -h -z --progress --exclude-from=rsync_exclude . tristan@lerouxtechnologies.com:/home/tristan/drop/sunshine-seas